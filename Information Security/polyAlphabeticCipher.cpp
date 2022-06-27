#include<bits/stdc++.h>
using namespace std;

string encrypt(string s)
{
    string enc = "";
    for(int i=0;i<s.size();i++)
    {
        if(i%2)
        {
            int t = s[i] -'0' + 35;
            char c = t;
            enc += c;
        }
        else
        {
            int t = s[i] -'0' + 32;
            char c = t;
            enc += c;
        }
    }
return enc;
}

string decrypt(string s)
{
    string dec;
    for(int i=0;i<s.size();i++)
    {
        if(i%2)
        {
            int t = s[i] + '0' - 35;
            char c = t;
            dec += c;
        }
        else
        {
            int t = s[i] +'0' - 32;
            char c = t;
            dec += c;
        }
    }
return dec;
}

int main()
{
    string s;
    getline(cin,s);
    string encryptedText = encrypt(s);
    cout << encryptedText <<"\n";
    string decryptedText = decrypt(encryptedText);
    cout << decryptedText;
}