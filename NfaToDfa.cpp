#include <iostream>
using namespace std;

string dfa_transition_table[100][100];
string nfa_transition_table[100][100];
string inputs[100];
int offset = 'a' - '0';
int main()
{
    int n;
    cout << "Enter the number of states: " << endl;
    cin >> n;
    cout << "Enter the states: " << endl;
    for(int i=0;i<n;i++)
    cin >> inputs[i];
    
    cout << "Enter input table : " << endl;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                cin >> nfa_transition_table[i][j];
            }
        }
        
    ///###############//
    for(int i=0;i<n;i++) //tracks row
        {
            for(int j=0;j<2;j++) //tracks column
            {
                string result = "";
                string temp = nfa_transition_table[i][j]; //stores content of transition table temporarily
                for(int k=0;k<temp.size();k++)
                {
                    int index = temp[k] - '0';  //goes through
                    result += nfa_transition_table[index][j];
                }
                dfa_transition_table[i][j] = result;
            }
        }
    
    cout << "DFA table : " <<endl;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout << nfa_transition_table[i][j] << "";
            }
            puts("");
        }
        
    return 0;
}
