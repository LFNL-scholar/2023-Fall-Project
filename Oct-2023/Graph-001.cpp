#include<iostream>
#include<stack>
#include<queue>
using namespace std;

const int MAX_VERTICES=100; // 最大顶点数

class Graph{
private:
    int vertexCount;
    int vertexValues[MAX_VERTICES]; // 存储顶点的值
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    // 构造函数，用于创建图
    Graph(int V){
        vertexCount=V;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adjacencyMatrix[i][j]=0;
            }
        }
    }

    // 销毁图
    void DestoryGraph(){}

    // 查看顶点v是否存在
    bool LocateVex(int v){
        return v>=0 && v<vertexCount;
    }

    // 设置顶点的值
    int PutVex(int v,int value){
        if(LocateVex(v)){
            vertexValues[v]=value;
        }
    }

    // 获取顶点的值
    int GetVex(int v){
        if(LocateVex(v)){
            return vertexValues[u];
        }
        return -1; // 顶点不存在
    }

    // 返回顶点v相对于顶点w的下一个邻接顶点
    int NextAdjVex(int v,int w){
        if(LocateVex(v) && LocateVex(w)){
            for(int i=w+1)
        }
    }
}