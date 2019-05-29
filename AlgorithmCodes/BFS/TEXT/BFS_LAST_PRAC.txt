#include <bits/stdc++.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1
#define NONE -1
#define SIZE 100

using namespace std;

queue <int> Q;

int graph[SIZE][SIZE], color[SIZE], dist[SIZE], parent[SIZE], path[SIZE], V, E, S, D;

void conn(){
    for(int i=1; i<=E; i++){
        int v1, v2;
        cin>>v1>>v2;
        graph[v1][v2]=graph[v2][v1]=1;
    }
}

void adjList(){
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void bfs(){
    for(int i=1; i<=V; i++){
        color[i]=WHITE;
        dist[i]=INF;
        parent[i]=NONE;
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
    int p=D, i=1;
    while(p!=parent[p]){
        path[i]=p;
        p=parent[p];
        i++;
    }
    path[i]=p;
}

void showPath(){
    for(int i=E; i>=1; i--){
        if(path[i]!=0){
            if(i!=1){
                cout<<path[i]<<" -> ";
            }
            else{
                cout<<path[i]<<endl;
            }
        }
    }
}

int main(){

    cin>>V>>E;
    conn();
    adjList();
    cin>>S>>D;
    bfs();
    cout<<dist[D]<<endl;
    findPath();
    showPath();

return 0;

}
