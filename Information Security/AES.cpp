#include<bits/stdc++.h>
#include"AEStables.h"
using namespace std;
void keyExpansion()
{
    int i;
    unsigned char temp[4]; //temporarily holds a one word key

    //first round key is the same as original key
    for(i=0;i<keySize;i++)
    {
        roundKey[i*4] = key[i*4];
        roundKey[i*4+1] = key[i*4+1];
        roundKey[i*4+2] = key[i*4+2];
        roundKey[i*4+3] = key[i*4+3];
    }

    while(i < columns*(totalRounds+1))
    {
        for(int j=0;j<4;j++)
        {
            temp[j] = roundKey[(i-1) * 4 +j];
        }
        if(i%keySize == 0) //for entries of 4's multiple
        {
            //rotWord()
            int k = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = k;

            //subWord()
            temp[0] = getSBoxValue(temp[0]);
            temp[1] = getSBoxValue(temp[1]);
            temp[2] = getSBoxValue(temp[2]);
            temp[3] = getSBoxValue(temp[3]);

            temp[0] = temp[0] ^ Rcon[i/keySize];
        }
        else if(i%keySize==4)
        {
            //subWord()
            temp[0] = getSBoxValue(temp[0]);
            temp[1] = getSBoxValue(temp[1]);
            temp[2] = getSBoxValue(temp[2]);
            temp[3] = getSBoxValue(temp[3]);
        }
        roundKey[i*4+0] = roundKey[(i-keySize)*4+0] ^ temp[0];
        roundKey[i*4+1] = roundKey[(i-keySize)*4+1] ^ temp[1];
        roundKey[i*4+2] = roundKey[(i-keySize)*4+2] ^ temp[2];
        roundKey[i*4+3] = roundKey[(i-keySize)*4+3] ^ temp[3];
        i++;
    }
}

void addRoundKey(int round)
{
    for(int i=0;i<columns;i++)
    {
        for(int j=0;j<4;j++)
        {
            state[j][i] ^= roundKey[round*columns*4 + i*columns +j];
        }
    }
}

void SubBytes() 
{
   for(int i=0;i<4;i++) 
   {
      for(int j=0;j<columns;j++) 
      {
	    state[i][j] = getSBoxValue(state[i][j]);
      }
   }
}

void shiftRows()
{
   unsigned char temp;

   // Rotate(circular left shift) first row 1 columns to left	
   temp = state[1][0];
   state[1][0] = state[1][1];
   state[1][1] = state[1][2];
   state[1][2] = state[1][3];
   state[1][3] = temp;

   // Rotate(circular left shift) second row 2 columns to left	
   temp = state[2][0];
   state[2][0] = state[2][2];
   state[2][2] = temp;

   temp = state[2][1];
   state[2][1] = state[2][3];
   state[2][3] = temp;

   // Rotate(circular left shift) third row 3 columns to left
   temp = state[3][0];
   state[3][0] = state[3][3];
   state[3][3] = state[3][2];
   state[3][2] = state[3][1];
   state[3][1] = temp;
}

void mixColumns()
{
    unsigned char t1,t2,t3;
    for(int i=0;i<columns;i++)
    {
        t1 = state[0][i];
        t2 = state[0][i] ^ state[1][i] ^ state[2][i] ^ state[3][i];
        t3 = state[0][i] ^ state[1][i];
        t3 = modulo(t3);
        state[0][i] ^= t2^t3;

        t3 = state[1][i] ^ state[2][i];
        t3 = modulo(t3);
        state[1][i] ^= t2^t3;

        t3 = state[2][i] ^ state[3][i];
        t3 = modulo(t3);
        state[2][i] ^= t2^t3;

        t3 = state[3][i] ^ t1;
        t3 = modulo(t3);
        state[3][i] ^= t2^t3;
    }
}

void encrypt()
{
    int round = 0;
    for(int i=0;i<columns;i++)
        for(int j=0;j<4;j++)
            state[j][i] = in[i*4+j];
    
    addRoundKey(0); //round=0, for the initial round key

    for(round = 1; round< totalRounds; round++)
    {
        SubBytes();
        shiftRows();
        mixColumns();
        addRoundKey(round);
    }

        SubBytes();
        shiftRows();
        addRoundKey(totalRounds);

    for(int i=0;i<columns;i++)
        for(int j=0;j<4;j++)
            out[i*4+j] = state[j][i];
}

int fillBlock (int sz, char *str, unsigned char *in)
{
   int j=0;
   while (sz < strlen(str)) 
   {
      if (j >= keySize*4) break;
      in[j++] = (unsigned char)str[sz];
      sz++;
   }
   // Pad the block with 0s, if necessary
   if (sz >= strlen(str)) 
    for ( ; j < keySize*4 ; j++) 
        in[j] = 0;
   return sz;   
}

int main()
{

    keyExpansion();
    int sz=0;
    char str[3000];
    fgets(str,3000,stdin);
    while (sz < strlen(str)) 
    {
        // Fill the array 'in' with the next plaintext block
        sz = fillBlock (sz, str, in);
        encrypt();
        for (int i=0 ; i < columns*4 ; i++) 
        cout << /*hex <<*/(int)out[i] << " ";
    }
}