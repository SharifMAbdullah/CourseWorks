#include <bits/stdc++.h>
using namespace std;
vector<pair<char, vector<char>>> matrix;

int main()
{

    vector<char> states,sym,temp;
    int n;
    cout << "Enter number of states in DFA: " << endl;
    cin >> n;
    
    for (int i=0;i<n;i++)
    {
        char ch;
        cout << "state " << i + 1 << ": ";
        cin >> ch;
        fflush(stdin);
        states.push_back(ch);
    }
    
    char start_state, current_state;
    char finish_state[100];
    int num_finish_state;
    
    cout << "Enter start state: " <<endl;
    cin >> start_state;
    cout << "Enter number of finish states: "<<endl;
    cin >> num_finish_state;
    
    cout << "Enter the finish states: "<<endl;
    for(int i=0;i<num_finish_state;i++)
        cin >> finish_state;
    current_state = start_state;

    int num_sym;
    cout << "Enter number of symbol in DFA: " <<endl;
    cin >> num_sym;

    for (int i=0;i<num_sym;i++)
    {
        char k;
        cout << "Symbol: " << i + 1 << ": ";
        cin >> k;
        sym.push_back(k);
    }
    
    cout << "Enter the state transition table as a matrix: "<<endl;
    for (int i = 0; i < n; i++)
    {
        char start;
        cin >> start;

        for (int j = 0; j < num_sym; j++)
        {
            char ch;
            cin >> ch;
            temp.push_back(ch);
        }

        matrix.push_back({start, temp});
        temp.clear();
    }
    
    cout << "Enter -1 to quit" <<endl;
    string input;
    while (1)
    {
        cout << "Enter string: " <<endl;
        cin >> input;
        current_state = start_state;

        if (input == "-1")
            return 0;
        
        cout << "Traversed states from starting state " << start_state <<" : " <<endl;
        for (int i=0; i<input.size(); i++) 
        {
            for (int j=0;j<matrix.size();j++)   
            {
                if (current_state==matrix[j].first) 
                {
                    for (int temp=0;temp<num_sym;temp++)  
                    {
                        if (input[i]==sym[temp]) 
                        {
                            if (i==input.size()-1)
                                cout<<matrix[j].second[temp] <<"("<<input[i]<<")" << endl;
                            else
                            {
                                cout<<matrix[j].second[temp] <<"("<< input[i] <<")"<< "->";  
                                current_state = matrix[j].second[temp];
                            }
                        }
                    }
                    
                    break;	
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<num_finish_state;i++)
            {
                if (current_state == finish_state[i])
                    {
                        count++;
                        cout << "ok, accepted" <<endl;
                        break;
                    }
            }
        
        if(count==0)
            cout << "not accepted" <<endl; 
    }
}
