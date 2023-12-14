#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_LANDMARKS = 100;  // 假设最多有100个景点
const int INF = 1e9;  // 代表无穷大

// 定义景点结构体
struct Landmark {
    int id;
    string name;
    string description;
    // 可根据需要添加其他信息
};

// 定义边的结构体
struct Edge {
    int from;
    int to;
    int distance;
};

class CampusGuide {
private:
    vector<Landmark> landmarks;  // 存储景点信息
    vector<vector<Edge>> adjacencyList;  // 无向图的邻接表

public:
    // 添加景点
    void addLandmark(int id, const string& name, const string& description) {
        landmarks.push_back({id, name, description});
        adjacencyList.resize(landmarks.size());
    }

    // 添加道路
    void addRoad(int from, int to, int distance) {
        if (from >= 0 && from < landmarks.size() && to >= 0 && to < landmarks.size() && distance > 0) {
            adjacencyList[from].push_back({from, to, distance});
            adjacencyList[to].push_back({to, from, distance});
            cout << "添加道路成功" << endl;
        } else {
            cout << "添加道路失败：无效的景点编号或道路距离" << endl;
        }
    }

    // 从文件加载景点信息
    void loadLandmarksFromFile(const string& filename) {
        ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            cout << "无法打开文件: " << filename << endl;
            return;
        }

        int id;
        string name, description;

        while (inputFile >> id >> name >> ws && getline(inputFile, description)) {
            addLandmark(id, name, description);
        }

        inputFile.close();
    }

    // 查询景点信息
    void getLandmarkInfo(int id) {
        if (id >= 0 && id < landmarks.size()) {
            cout << "景点编号：" << landmarks[id].id << endl;
            cout << "景点名称：" << landmarks[id].name << endl;
            cout << "景点简介：" << landmarks[id].description << endl;
        } else {
            cout << "找不到编号为" << id << "的景点信息" << endl;
        }
    }

    // 查询最短路径及长度
    void getShortestPath(int from, int to) {
        if (from >= 0 && from < landmarks.size() && to >= 0 && to < landmarks.size()) {
            vector<int> distance(landmarks.size(), INF);
            vector<int> parent(landmarks.size(), -1);
            vector<bool> visited(landmarks.size(), false);

            distance[from] = 0;

            for (int i = 0; i < landmarks.size() - 1; ++i) {
                int current = findMinDistance(distance, visited);
                visited[current] = true;

                for (const Edge& edge : adjacencyList[current]) {
                    if (!visited[edge.to] && distance[current] + edge.distance < distance[edge.to]) {
                        distance[edge.to] = distance[current] + edge.distance;
                        parent[edge.to] = current;
                    }
                }
            }

            printShortestPath(from, to, distance, parent);
        } else {
            cout << "查询失败：无效的景点编号" << endl;
        }
    }

private:
    int findMinDistance(const vector<int>& distance, const vector<bool>& visited) {
        int minDistance = INF;
        int minIndex = -1;

        for (int i = 0; i < landmarks.size(); ++i) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    void printShortestPath(int from, int to, const vector<int>& distance, const vector<int>& parent) {
        if (distance[to] == INF) {
            cout << "无法从景点" << from << "到达景点" << to << endl;
            return;
        }

        cout << "从景点" << from << "到景点" << to << "的最短路径为：" << endl;
        int current = to;
        vector<int> path;

        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }

        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i];
            if (i != 0) {
                cout << " -> ";
            }
        }

        cout << "\n路径长度为：" << distance[to] << endl;
    }
};

int main() {
    CampusGuide campus;

    // 从文件加载景点信息
    campus.loadLandmarksFromFile("1.txt");

    int choice;
    while (true) {
        cout << "\n请选择操作：" << endl;
        cout << "1. 查询景点信息" << endl;
        cout << "2. 查询道路" << endl;
        cout << "3. 查询两个景点的信息和道路" << endl;
        cout << "4. 退出查询" << endl;
        cout << "输入对应的数字：";
        cin >> choice;

        switch (choice) {
            case 1: {
                int landmarkId;
                cout << "请输入要查询的景点编号: ";
                cin >> landmarkId;
                campus.getLandmarkInfo(landmarkId);
                break;
            }
            case 2: {
                int start, end;
                cout << "请输入道路的起始景点编号和目标景点编号: ";
                cin >> start >> end;
                campus.getShortestPath(start, end);
                break;
            }
            case 3: {
                int landmarkId1, landmarkId2;
                cout << "请输入第一个景点编号: ";
                cin >> landmarkId1;
                cout << "请输入第二个景点编号: ";
                cin >> landmarkId2;

                // 查询景点信息
                campus.getLandmarkInfo(landmarkId1);
                campus.getLandmarkInfo(landmarkId2);

                // 查询道路
                campus.getShortestPath(landmarkId1, landmarkId2);
                break;
            }
            case 4:
                cout << "退出查询，谢谢使用！" << endl;
                return 0;
            default:
                cout << "无效的选项，请重新输入。" << endl;
        }
    }

    return 0;
}
