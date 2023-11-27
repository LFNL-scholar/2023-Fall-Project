//创建一个无向图（采用邻接矩阵或者邻接表方式存储）；分别输出从结点0开始的一个深度优先遍历序列和一个广度优先遍历序列。
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
private:
    int vertices; //顶点数
    vector<vector<int>> adjacencyMatrix; //邻接矩阵

public:
    Graph(int v):vertices(v),adjacencyMatrix(v,vector<int>(v,0)) {}

    void addEdge(int start,int end){
        adjacencyMatrix[start][end]=1;
        adjacencyMatrix[end][start]=1;
    }

    void DFS(int start,vector<bool>& visited){
        cout<<start<<" ";
        visited[start]=true;
        for(int i=0;i<vertices;i++){
            if(adjacencyMatrix[start][i]==1 && !visited[i]){
                DFS(i,visited);
            }
        }
    }

    void BFS(int start){
        vector<bool> visited(vertices,false);
        queue<int> q;
        cout<<"BFS Traversal: ";
        visited[start]=true;
        q.push(start);

        while(!q.empty()){
            int current=q.front();
            cout<<current<<" ";
            q.pop();

            for(int i=0;i<vertices;i++){
                if(adjacencyMatrix[current][i]==1 && !visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        cout<<endl;
    }

};

int main(){
    Graph graph(6);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,5);
    graph.addEdge(1,2);
    graph.addEdge(5,3);
    graph.addEdge(3,2);
    graph.addEdge(3,4);
    graph.addEdge(2,4);

    cout<<"DFS Traversal: ";
    vector<bool> visitedDFS(6,false);
    graph.DFS(0,visitedDFS);
    cout<<endl;

    graph.BFS(0);

    return 0; 
}