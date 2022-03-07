#include <bits/stdc++.h>
using namespace std;

vector<pair<char, vector<char>>> matrix;
vector<char> states;
vector<char> symbols, temp;

int main()
{

    int n;
    cout << "Enter number of states in DFA: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char ch;
        cout << "State " << i + 1 << ": ";
        cin >> ch;

        states.push_back(ch);
    }

    int num_sym;
    cout << "Enter number of symbols: " <<endl;
    cin >> num_sym;

    for (int i = 0; i < num_sym; i++)
    {
        char k;
        cout << "Symbol " << i + 1 << ": ";
        cin >> k;

        symbols.push_back(k);
    }

    cout << "Enter the transition table as a matrix:" <<endl;
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

    char start_state, finish_state, current_state;
    cout << "Enter starting state: " <<endl;
    cin >> start_state;
    cout << "Enter finishing state: "<<endl;
    cin >> finish_state;
    current_state = start_state;

    cout << "Enter -1 to terminate the program" <<endl;

    string input;
    while (1)
    {
        cout << "Enter your string: " <<endl;
        cin >> input;

        current_state = start_state;

        if (input == "-1")
            break;

        cout << "Transition states: ";

        for (int i = 0; i < input.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (current_state == matrix[j].first)
                {
                    for (int st = 0; st < num_sym; st++)
                    {
                        if (input[i] == symbols[st])
                        {
                            cout << matrix[j].second[st] << " " << "(" << input[i] << ") -> ";
                            current_state = matrix[j].second[st];
                        }
                    }

                    break;
                }
            }
        }

        cout << endl;


        if (current_state == finish_state)
            cout << "ok, accepted" <<endl;
        else
            cout << "rejected" <<endl;
    }
}
