#include <iostream>
#include <queue>

#define SIZE 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1
#define NONE -1

using namespace std;

queue <int> Q;
int graph[SIZE][SIZE], color[SIZE], parent[SIZE], dist[SIZE], path[SIZE], V, E, S, D, P;

void conn(){
    cout<<"Connections:\n";
    for(int v=1; v<=E; v++){
        int v1, v2;
        cin>>v1>>v2;
        graph[v1][v2] = graph[v2][v1] = 1;
    }
}

void bfs(){

    for(int v=1; v<=V; v++){
        color[v]=WHITE;
        dist[v]=INF;
        parent[v]=NONE;
    }

    color[S]=GRAY;
    dist[S]=0;
    parent[S]=S;

    Q.push(S);

    while(!(Q.empty())){
        int u=Q.front();
        Q.pop();

        for(int v=1; v<=V; v++){
            if(graph[u][v]==1 && color[v]==WHITE){
                color[v]=GRAY;
                dist[v]=dist[u]+1;
                parent[v]=u;
                Q.push(v);
            }
        }
        color[u]=BLACK;
    }
}

void findPath(){
    int i=1, p=D;
    while(p!=parent[p]){
        path[i]=p;
        p=parent[p];
        i++;
    }
    path[i]=p;
}

int main(){

    cout<<"Vertex Edge:\n";
    cin>>V>>E;
    conn();
    cout<<"From To:\n";
    cin>>S>>D;
    bfs();
    cout<<dist[D]<<"\n";
    cout<<"Parent:\n";
    cin>>P;
    cout<<parent[P]<<"\n";

    findPath();

    for(int i=E; i>=1; i--){
        if(path[i]!=0){
            if(i!=1){
                cout<<path[i]<<"->";
            }
            else{
                cout<<path[i]<<"\n";
            }
        }
    }

return 0;

}
