#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include"AEStables.h"
using namespace std;

unsigned char input[1024];
// This function produces keySize(totalRounds+1) round keys. The round keys are used 
// in each round to decrypt the states. 
void KeyExpansion() 
{
   int i,j;
   unsigned char temp[4],k;
	
   // The first round key is the key itself.
   for ( i=0 ; i < columns ; i++) 
   {
      roundKey[i*4]=key[i*4];
      roundKey[i*4+1]=key[i*4+1];
      roundKey[i*4+2]=key[i*4+2];
      roundKey[i*4+3]=key[i*4+3];
   }

   // All other round keys are found from the previous round keys.
   while (i < (keySize * (totalRounds+1))) 
   {
        for ( j=0 ; j < 4 ; j++) 
        {
	        temp[j] = roundKey[(i-1) * 4 + j];
        }
        if (i % columns == 0) 
        {
            // This function rotates the 4 bytes in a word to the left once.
            // [a0,a1,a2,a3] becomes [a1,a2,a3,a0]

            // Function RotWord()
            k = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = k;

            // SubWord() is a function that takes a four-byte input word and 
            // applies the S-box to each of the four bytes to produce an output word.

            // Function Subword()
            temp[0]=getSBoxValue(temp[0]);
            temp[1]=getSBoxValue(temp[1]);
            temp[2]=getSBoxValue(temp[2]);
            temp[3]=getSBoxValue(temp[3]);

            temp[0] =  temp[0] ^ Rcon[i/columns];
        } 
        else if (columns > 6 && i % columns == 4) 
        {
            // Function Subword()
            temp[0] = getSBoxValue(temp[0]);
            temp[1] = getSBoxValue(temp[1]);
            temp[2] = getSBoxValue(temp[2]);
            temp[3] = getSBoxValue(temp[3]);
        }

    roundKey[i*4+0] = roundKey[(i-columns)*4+0] ^ temp[0];
    roundKey[i*4+1] = roundKey[(i-columns)*4+1] ^ temp[1];
    roundKey[i*4+2] = roundKey[(i-columns)*4+2] ^ temp[2];
    roundKey[i*4+3] = roundKey[(i-columns)*4+3] ^ temp[3];
    i++;
   }
}

// This function adds the round key to state.
// The round key is added to the state by an XOR function.
void AddRoundKey(int round)
{
   int i,j;
   for (i=0 ; i < keySize ; i++) 
   {
      for ( j=0 ; j < 4 ; j++) 
      {
	    state[j][i] ^= roundKey[round * keySize * 4 + i * keySize + j];
      }
   }
}

// The SubBytes Function Substitutes the values in the
// state matrix with values in an S-box.
void InvSubBytes() 
{
   int i,j;
   for (i=0 ; i < 4 ; i++) {
      for (j=0 ; j < keySize ; j++) {
	 state[i][j] = getSBoxInvert(state[i][j]);
      }
   }
}

// The ShiftRows() function shifts the rows in the state to the left.
// Each row is shifted with different offset.
// Offset = Row number. So the first row is not shifted.
void InvShiftRows() 
{
   unsigned char temp;

   // Rotate first row 1 columns to right	
   temp = state[1][3];
   state[1][3] = state[1][2];
   state[1][2] = state[1][1];
   state[1][1] = state[1][0];
   state[1][0] = temp;

   // Rotate second row 2 columns to right	
   temp = state[2][0];
   state[2][0] = state[2][2];
   state[2][2] = temp;
   
   temp = state[2][1];
   state[2][1] = state[2][3];
   state[2][3] = temp;

   // Rotate third row 3 columns to right
   temp = state[3][0];
   state[3][0] = state[3][1];
   state[3][1] = state[3][2];
   state[3][2] = state[3][3];
   state[3][3] = temp;
}



// Multiplty is a macro used to multiply numbers in the field GF(2^8)
#define Multiply(x,y) (((y & 1) * x) ^ ((y>>1 & 1) * modulo(x)) ^ ((y>>2 & 1) * modulo(modulo(x))) ^ ((y>>3 & 1) * modulo(modulo(modulo(x)))) ^ ((y>>4 & 1) * modulo(modulo(modulo(modulo(x))))))


void InvMixColumns() 
{
   int i;
   unsigned char a,b,c,d;
   for (i=0 ; i < keySize ; i++) 
   {	
	
      a = state[0][i];
      b = state[1][i];
      c = state[2][i];
      d = state[3][i];
		
      state[0][i] = Multiply(a, 0x0e) ^ Multiply(b, 0x0b) ^ Multiply(c, 0x0d) ^ Multiply(d, 0x09);
      state[1][i] = Multiply(a, 0x09) ^ Multiply(b, 0x0e) ^ Multiply(c, 0x0b) ^ Multiply(d, 0x0d);
      state[2][i] = Multiply(a, 0x0d) ^ Multiply(b, 0x09) ^ Multiply(c, 0x0e) ^ Multiply(d, 0x0b);
      state[3][i] = Multiply(a, 0x0b) ^ Multiply(b, 0x0d) ^ Multiply(c, 0x09) ^ Multiply(d, 0x0e);
   }
}

// InvCipher is the main function that decrypts the CipherText.
void InvCipher() 
{
   int i,j,round=0;

   //Copy the input CipherText to state array.
   for (i=0 ; i < keySize ; i++) 
   {
      for (j=0 ; j < 4 ; j++) 
      {
	    state[j][i] = in[i*4 + j];
      }
   }

   // Add the First round key to the state before starting the rounds.
   AddRoundKey(totalRounds); 

   // There will be totalRounds rounds.
   // The first totalRounds-1 rounds are identical.
   // These totalRounds-1 rounds are executed input the loop below.
   for (round=totalRounds-1 ; round > 0 ; round--) {
      InvShiftRows();
      InvSubBytes();
      AddRoundKey(round);
      InvMixColumns();
   }
	
   // The last round is given below.
   // The MixColumns function is not here in the last round.
   InvShiftRows();
   InvSubBytes();
   AddRoundKey(0);

   // The decryption process is over.
   // Copy the state array to output array.
   for(i=0 ; i < keySize ; i++) {
      for(j=0 ; j < 4 ; j++) {
	 out[i*4+j] = state[j][i];
      }
   }
}

bool fillBlock() {
   int number;

   for (int j=0 ; j < keySize*4 ; j++) 
   {
      if (!(cin >> number)) {
	 cout << "\n";
	 return false;
      }
      input[j] = (unsigned char)number;
   }
   return true;
}

int main(int argc, char **argv)
{
 
    KeyExpansion();
    while (fillBlock())
    {
        InvCipher();
        for (int i=0 ; i < keySize*4 && out[i] != 0 ; i++) 
        printf("%c",(char)out[i]);
   }
}
