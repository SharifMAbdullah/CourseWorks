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
        
    //first row of dfa will be same as nfa
    dfa_transition_table[0][0] = nfa_transition_table[0][0];
    dfa_transition_table[0][1] = nfa_transition_table[0][1];
    
    std::set<string> temp_nfa;
    
    cout << "DFA table : " <<endl;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout << nfa_transition_table[i][j] << "";
            }
            printf("\n");
        }
        
    return 0;
}
