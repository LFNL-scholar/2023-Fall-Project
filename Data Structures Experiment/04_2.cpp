//创建一个无向图（采用邻接表的方式存储）；分别输出从结点0开始的一个深度优先遍历序列和一个广度优先遍历序列
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{
private:
    int vertices;
    vector<vector<int>> adjacencyList; // 邻接表

public:
    Graph(int v):vertices(v),adjacencyList(v) {}

    void addEdge(int start,int end){
        adjacencyList[start].push_back(end);
        adjacencyList[end].push_back(start);
    }

    void addEdges(const vector<vector<int>>& edges){
        for(const auto& edge : edges){
            if(edge.size()==2){
                addEdge(edge[0],edge[1]);
            }
        }
    }

    void DFS(int start,vector<bool>& visited){
        cout<<start<<" ";
        visited[start]=true;
        for(int neighbor:adjacencyList[start]){
            if(!visited[neighbor]){
                DFS(neighbor,visited);
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

            for(int neighbor:adjacencyList[current]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph graph(6);
    vector<vector<int>> edges={{0,1},{0,2},{0,5},{1,2},{5,3},{3,2},{3,4},{2,4}};
    graph.addEdges(edges);

    cout << "DFS Traversal: ";
    vector<bool> visitedDFS(6, false);
    graph.DFS(0, visitedDFS);
    cout << endl;

    graph.BFS(0);
    return 0;
}
