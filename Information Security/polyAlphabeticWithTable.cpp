#include<bits/stdc++.h>
using namespace std;

char table[26][26];
void create_table()
{
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            table[i][j] = 'a' + (i+j)%26;   
        }
    }
}

string encrypt(string s)
{
    string enc = "";
    for(int i=0;i<s.size();i++)
    {
        enc += table[s[i] - ' '][i%26];
    }
return enc;
}

string decrypt(string s)
{
    string dec = "";

    for(int i=0; i<s.length(); i++)
    {
        for(int j=0; j<26; j++)
        {
            if(s[i]==table[j][i%26])
            {
                dec += ' ' + j;
            }
        }
    }
return dec;
}

int main()
{
    string s;
    getline(cin,s);
    create_table();
    string encryptedText = encrypt(s);
    cout << encryptedText <<"\n";
    string decryptedText = decrypt(encryptedText);
    cout << decryptedText;
}
