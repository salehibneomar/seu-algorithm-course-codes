#include <iostream>
#include <queue>

#define SIZE 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1

using namespace std;
//STL queue
queue <int> Q;
int Graph[SIZE][SIZE], Color[SIZE], Distance[SIZE], Vertex, Edge, Start, Destination;

//Connection depends on number of Edge
void Connection(int E){
    for(int i=1; i<=Edge; i++){
        int v1, v2;
        cout<<"Connection: "<<i<<endl;
        cin>>v1>>v2;
        Graph[v1][v2]=1;
        Graph[v2][v1]=1;
    }
}


void BFS(){
    //Mark all all the colors and distance of vertex as default
    for(int i=1; i<=Vertex; i++){
        Color[i] = WHITE;
        Distance[i] = INF;
    }

    //Discover the first vertex/starting vertex
    Color[Start] = GRAY;
    Distance[Start] = 0;

    Q.push(Start);

    //Loop will continue until all the elements have their color and distance
    while(!(Q.empty())){
        int u = Q.front();
        Q.pop();

        for(int v=1; v<=Vertex; v++){
            if(Graph[u][v]==1 && Color[v]==WHITE){
                Color[v] = GRAY;
                Distance[v] = Distance[u]+1;
                Q.push(v);
            }
        }

        Color[u] = BLACK;
    }

}


int main(){

    cout <<"Enter number of Vertex and Edge:"<<endl;
    cin>>Vertex>>Edge;
    Connection(Edge);
    cout<<endl;
    cout<<"From-To:"<<endl;
    cin>>Start>>Destination;

    BFS();
    cout <<"Distance is: "<<Distance[Destination]<<endl;

return 0;

}
