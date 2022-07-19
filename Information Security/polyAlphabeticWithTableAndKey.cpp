#include<bits/stdc++.h>
using namespace std;

char table[26][26];
void create_table(int key)
{
    for(int i=0;i<26+key;i++)
    {
        for(int j=0;j<26+key;j++)
        {
            table[i][j] = 'a' + (i+j+key)%26;   
        }
    }
}

string encrypt(string s, int key)
{
    string enc = "";
    for(int i=0;i<s.size();i++)
    {
        enc += table[s[i] - 'a'-key][i%26];
    }
return enc;
}

string decrypt(string s,int key)
{
    string dec = "";

    for(int i=0; i<s.length(); i++)
    {
        for(int j=0; j<26+key; j++)
        {
            if(s[i]==table[j][i%26])
            {
                dec += 'a' + j + key;
            }
        }
    }
return dec;
}

int main()
{
    string s;
    int key = 3;
    getline(cin,s);
    create_table(key);
    string encryptedText = encrypt(s,key);
    cout << encryptedText <<"\n";
    string decryptedText = decrypt(encryptedText,key);
    cout << decryptedText;
}
