#include<bits/stdc++.h>
using namespace std;
string s;
bool balancedTerminalCheck()
{
    int countTerminal,countSymbol;
    for(int i=0;i<s.size();i++)
        {
        if(s[i]=='0' || s[i]=='1')
            countTerminal++;
        else if(s[i]=='+' || s[i]=='*')
            countSymbol++;
        }
        
if(countSymbol>=countTerminal)
    return 0;
else 
    return 1;
}

bool adjacentBracket()
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' && s[i+1]==')')
            return 0;
        else if(s[i]==')' && s[i+1]=='(')
            return 0;
    }
return 1;
}

bool repeatedTerminalCheck()
{
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]=='0' && s[i+1]=='1') 
            return 0;
        else if(s[i]=='1' && s[i+1]=='0') 
            return 0;
        else if(s[i]=='1' && s[i+1]=='1') 
            return 0;
        else if(s[i]=='0' && s[i+1]=='0') 
            return 0;  
        else if(s[i]=='*' && s[i+1]=='+') 
            return 0;
        else if(s[i]=='+' && s[i+1]=='*') 
            return 0;
        else if(s[i]=='+' && s[i+1]=='+') 
            return 0;
        else if(s[i]=='*' && s[i+1]=='*') 
            return 0;
    }
return 1;
}

bool unbalancedParanthesis()
{
    stack<char> paranthesis;
    int counter = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            paranthesis.push(s[i]);
        else if(s[i]==')')
            paranthesis.pop();
    }

    if(paranthesis.empty())
        return 1;
    else 
        return 0;
}

int main()
{
        cin >> s;
        if(repeatedTerminalCheck() && adjacentBracket() && 
            unbalancedParanthesis() &&balancedTerminalCheck())
            cout << "Accepted" << endl;
        else 
            cout << "Rejected" <<endl;

}