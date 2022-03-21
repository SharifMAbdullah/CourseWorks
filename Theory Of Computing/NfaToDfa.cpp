#include <iostream>
using namespace std;

string dfa_transition_table[100][100];
string nfa_transition_table[100][100];
string inputs[100];
int offset = 'a' - '0';

int find(int states, char c)
{
	for(int i=0;i<states;i++)
	   {
		if(c==nfa_transition_table[i][0])
		  {
			return i;
		  }
	   }
return 0;
}

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
            for(int j=0;j<3;j++)
            {
                cin >> nfa_transition_table[i][j];
            }
        }
        
    //first row of dfa will be same as nfa
    dfa_transition_table[0][0] = nfa_transition_table[0][0];
    dfa_transition_table[0][1] = nfa_transition_table[0][1];
    dfa_transition_table[0][2] = nfa_transition_table[0][2];
    
    //const bool is_in = container.find(element) != container.end();
    set<string> temp;
    temp.insert(dfa_transition_table[0][1]);
    temp.insert(dfa_transition_table[0][2]);
    
    for(int i=1;!temp.empty();i++)
    {
        int k = 0;
        for(int j=0;j<3;j++)
            {
                dfa_transition_table[i][j] = temp[k];
                string t;
                for(int l=0;l<temp[k].size();l++)
                {
                    int index = find(n,temp[k][l]);
                    t += nfa_transition_table[index][j+1]
                }
                
            dfa_transition_table[][] = t;
            }
    }
    /*int i = 0;
    while(!temp.empty())
    {
        for(int j=0;j<3;j++)
        {
            temp.insert(dfa_transition_table[i][j]);
        }
        i++;
    }*/
    
    cout << "DFA table : " <<endl;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout << dfa_transition_table[i][j] << "";
            }
            printf("\n");
        }
        
    return 0;
}