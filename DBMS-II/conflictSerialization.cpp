#include<bits/stdc++.h>
using namespace std;
string transactions[2][4]=
{
    {"R2","W3","W2","W1"},
    {"R3","R1","W1"}
};

#define N 100
#define WHITE 1
#define GREY 2
#define BLACK 3
#define NIL -1
#define INF 1e8 + 5
int prevv[N + 1];
int color[N + 1];
int node = N;
bool flag = false;
int graph[N][N];

void DFS_Visit(int graph[][N], int u)
{
    color[u] = GREY;

    for (int v = 0; v < node; v++)
    {

        if (graph[u][v] == 1 && color[v] == GREY)
        {
            flag = true;
        }

        if (graph[u][v] == 1 && color[v] == WHITE)
        {
            prevv[v] = u;
            DFS_Visit(graph, v);
        }
    }

    color[u] = BLACK;
}
void DFS(int graph[][N])
{

    for (int u = 0; u < node; u++)
    {
        color[u] = WHITE;
        prevv[u] = -1;
    }
    for (int u = 0; u < node; u++)
    {

        if (color[u] == WHITE)
        {
            DFS_Visit(graph, u);
        }
    }
}

int main()
{
    
    int u=0,v=0;
    for(int i=0;i<2;i++)
    {
        int size;
        if(i==0) size=4;
        else size=3;
        for(int j=0;j<size;j++)
        {
            for(int k=j+1;k<size;k++)
            {    
                if( transactions[i][j][0] != transactions[i][k][0] || 
                    (transactions[i][j][0] == transactions[i][k][0] && transactions[i][k][0]=='W') )
                {
                    u = transactions[i][j][1] - '0' -1 ;
                    v = transactions[i][k][1] - '0' -1;
                    
                    cout<<u<<v<<"\n";
                    cout <<transactions[i][j][0] <<" " <<transactions[i][k][0]<<"\n";
                    graph[u][v]++;
                }
            }
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout <<"\n";
    }
    
    DFS(graph);
    if (flag == true) cout << "Cycle exists, serialization not possible";
    else cout << "Serialization possible";
}
