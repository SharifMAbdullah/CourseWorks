#include<bits/stdc++.h>
using namespace std;
int current_state = 0;
stack<char> s;
string states[3] = {"q0","q1","qf"};

void delta_function_pop(char input, char topp)
{
    if (current_state == 0 && input == 'a')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[++current_state] << "," << "E" << ")" << endl;
    }
    else if (current_state == 0 && input == 'b')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[++current_state] << "," << "E" << ")" << endl;
    }
    else if (current_state == 0 && input == 'z')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[++current_state] << "," << "E" << ")" << endl;
    }
    else if (current_state == 1 && input == 'a')
    {        
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[++current_state] << "," << "E" << ")" << endl;
    }
    else if (current_state == 1 && input == 'b')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[++current_state] << "," << "E" << ")" << endl;
    }
    else if (current_state == 1 && input == 'z')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[++current_state] << "," << "E" << ")" << endl;
    }    
}

void delta_function_push(char input, char topp)
{
if (current_state == 0 && topp == 'z' && input == 'a')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[current_state] << "," << "az" << ")" << endl;
    }
    else if (current_state == 0 && topp == 'a' && input == 'a')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[current_state] << "," << "aa" << ")" << endl;
    }
    else if (current_state == 0 && topp == 'z' && input == 'b')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[current_state] << "," << "bz" << ")" << endl;
    }
    else if (current_state == 0 && topp == 'b' && input == 'b')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[current_state] << "," << "bb" << ")" << endl;
    }
    else if (current_state == 0 && topp == 'a' && input == 'b')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[current_state] << "," << "ba" << ")" << endl;
    }
    else if (current_state == 0 && topp == 'b' && input == 'a')
    {
        cout << "(" << states[current_state] << ", " << input << ", " << topp << ")" << "->" << "(" << states[current_state] << "," << "ab" << ")" << endl;
    }
}

int main()
{
    string input;
    cin >> input;

    int temp = 0;
    for(int current_mid = 1; current_mid< input.size(); current_mid++)
    {
        s.push('z');
        for(int i=0; i<current_mid; i++)
        {
            delta_function_push(input[i], s.top());
            s.push(input[i]);
            temp = i;
        }

        puts(" ");
        for(int j = temp; j<input.size(); j++)
        {
            if(s.top() == input[j])
            {
                delta_function_pop(input[j], s.top());
                s.pop();
            }
            else break;
        }

        if(s.top()=='z' && temp == input.size())
        {
            cout << "Accepted" << endl;
            return 0;
        }
        else
        {
            while (!s.empty())
                s.pop();

            current_state = 0;
        }
    }

    cout << "Rejected" << endl;
}