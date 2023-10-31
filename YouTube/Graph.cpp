// 无向网图构建代码
#include<iostream>
using namespace std;

#define MAXVEX 100
#define INFINITY 65535

struct MGraph{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes,numEdges;
};

void CreateMGraph(MGraph *G){
    cout<<"输入顶点数和边数："<<endl;
    cin>>G->numVertexes>>G->numEdges;
    for(int i=0;i<G->numVertexes;i++){
        cin>>G->vexs[i];
    }
    for(int i=0;i<G->numVertexes;i++){
        for(int j=0;j<G->numVertexes;j++){
            G->arc[i][j]=INFINITY;
        }
    }
    for(int k=0;k<G->numEdges;k++){
        int wight;
        cout<<"输入边(vi,vj)上的下标i,下标j和权:"<<endl;
        cin>>&i>>&j>>&wight;
        G->arc[i][j]=wight;
        G->arc[j][i]=G->arc[i][j]; // 无向图，矩阵对称
    }
} 