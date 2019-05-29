#include <bits/stdc++.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1
#define NONE -1
#define SIZE 100

using namespace std;

queue <int> Q;
int graph[SIZE][SIZE], clr[SIZE], dist[SIZE], prnt[SIZE], V, E, S;

void conn(){
    int v1, v2;
    for(int i=1; i<=E; i++){
        cout<<"Connection: "<<i<<"\n";
        cin>>v1>>v2;
        graph[v1][v2] = graph[v2][v1] = 1;
    }
}

void BFS(){
    for(int i=1; i<=V; i++){
        dist[i]=INF;
        clr[i]=WHITE;
        prnt[i]=NONE;
    }

    dist[S]=0;
    clr[S]=GRAY;
    prnt[S]=S;

    Q.push(S);

    while(!(Q.empty())){
        int u = Q.front();
        Q.pop();
        for(int v=1; v<=V; v++){
            if(graph[u][v]==1 && clr[v]==WHITE){
                dist[v]=dist[u]+1;
                clr[v]=GRAY;
                prnt[v]=u;
                Q.push(v);
            }
        }
        clr[u]=BLACK;
    }
}

int main(){

    cout<<"Enter vertex and edge [max 100]:\n";
    cin>>V>>E;
    cout<<"\n";
    conn();
    cout<<"Starting vertex: ";
    cin>>S;
    BFS();
    int F, T;
    cout<<"From-To [Connection check]: \n";
    cin>>F>>T;

    if(graph[T][F]==1 && graph[F][T]==1){
        cout<<"They are connected!\n";
    }
    else{
        cout<<"They are not connected!\n";
    }

    int v;
    cout<<"Which vertex discovery time you want to know?:\n";
    cin>>v;
    cout<<"Discovery time = "<<dist[v]<<"\n";

    cout<<"Want to know connections of specific vertex? enter:\n";
    cin>>v;
    for(int i=1; i<=V; i++){
        cout<<i<<" = "<<graph[v][i]<<"\n";
    }

    cout<<"Want to know distance of one vertex to another?\nEnter the vertex you want to go:\n";
    cin>>v;
    cout<<"Distance = "<<dist[v]<<"\n";

    cout<<"Want to know parent of a specific vertex?\nEnter:\n";
    cin>>v;
    cout<<"Parent = "<<prnt[v]<<"\n";

return 0;

}
