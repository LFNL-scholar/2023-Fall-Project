#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

// 弗洛伊德-沃舍尔算法，用于查找加权图中所有顶点对之间的最短路径

void floydWarshall(vector<vector<int>>& graph, int V) {
    // 创建一个二维数组来存储每对顶点之间的最短距离
    vector<vector<int>> dist(graph);

    // 应用弗洛伊德-沃舍尔算法更新最短距离
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // 防止溢出
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 打印最短距离
    cout << "每对顶点之间的最短距离：\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    // 示例图，表示为邻接矩阵
    vector<vector<int>> graph = {
        {0, INF, INF, 5},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    int V = graph.size();

    floydWarshall(graph, V);

    return 0;
}
