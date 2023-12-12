#include <iostream>
#include <vector>

using namespace std;

// 自定义节点结构
struct HuffmanNode {
    char data;
    int weight;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d, int w) : data(d), weight(w), left(nullptr), right(nullptr) {}
};

// 自定义最小堆
class MinHeap {
private:
    vector<HuffmanNode*> heap;

    // 最小堆调整
    void heapify(int i);

public:
    // 插入节点
    void insert(HuffmanNode* node);

    // 弹出堆顶节点
    HuffmanNode* pop();

    // 获取堆顶节点
    HuffmanNode* top();

    // 获取堆的大小
    int size();
};

// 堆的插入操作
void MinHeap::insert(HuffmanNode* node) {
    heap.push_back(node);
    int index = heap.size() - 1;
    while (index > 0 && heap[index]->weight < heap[(index - 1) / 2]->weight) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// 堆的弹出操作
HuffmanNode* MinHeap::pop() {
    if (heap.empty()) {
        return nullptr;
    }

    HuffmanNode* topNode = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify(0);

    return topNode;
}

// 堆的堆顶节点
HuffmanNode* MinHeap::top() {
    return heap.empty() ? nullptr : heap[0];
}

// 堆的大小
int MinHeap::size() {
    return heap.size();
}

// 堆的最小堆调整
void MinHeap::heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap.size() && heap[left]->weight < heap[smallest]->weight) {
        smallest = left;
    }

    if (right < heap.size() && heap[right]->weight < heap[smallest]->weight) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(smallest);
    }
}

// 哈夫曼编码类
class HuffmanCoding {
private:
    HuffmanNode* root;
    vector<pair<char, string>> huffmanCodes;

    // 构建哈夫曼树
    void buildHuffmanTree(const vector<pair<char, int>>& charFrequency);

    // 递归生成哈夫曼编码
    void generateCodes(HuffmanNode* node, string code);

public:
    // 构造函数
    HuffmanCoding();

    // 析构函数
    ~HuffmanCoding();

    // 设置字符集和权值，构建哈夫曼树
    void setCharacterFrequency(const vector<pair<char, int>>& charFrequency);

    // 打印哈夫曼编码
    void printHuffmanCodes();

    // 编码
    string encode(const string& input);

    // 译码
    string decode(const string& input);
};

// 构造函数
HuffmanCoding::HuffmanCoding() : root(nullptr) {}

// 析构函数
HuffmanCoding::~HuffmanCoding() {
    // 释放哈夫曼树的内存
    // 通过后序遍历删除每个节点
    function<void(HuffmanNode*)> deleteTree = [&](HuffmanNode* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    };

    deleteTree(root);
}

// 构建哈夫曼树
void HuffmanCoding::buildHuffmanTree(const vector<pair<char, int>>& charFrequency) {
    // 使用最小堆存储节点，按权值升序排列
    MinHeap minHeap;

    // 初始化节点并加入最小堆
    for (const auto& pair : charFrequency) {
        minHeap.insert(new HuffmanNode(pair.first, pair.second));
    }

    // 构建哈夫曼树
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.pop();
        HuffmanNode* right = minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('\0', left->weight + right->weight);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.insert(internalNode);
    }

    // 根节点即为哈夫曼树的根
    root = minHeap.top();
}

// 递归生成哈夫曼编码
void HuffmanCoding::generateCodes(HuffmanNode* node, string code) {
    if (node->data != '\0') {
        huffmanCodes.push_back({node->data, code});
    }

    if (node->left) {
        generateCodes(node->left, code + '0');
    }

    if (node->right) {
        generateCodes(node->right, code + '1');
    }
}

// 设置字符集和权值，构建哈夫曼树
void HuffmanCoding::setCharacterFrequency(const vector<pair<char, int>>& charFrequency) {
    buildHuffmanTree(charFrequency);
    generateCodes(root, "");
}

// 打印哈夫曼编码
void HuffmanCoding::printHuffmanCodes() {
    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// 编码
string HuffmanCoding::encode(const string& input) {
    string encodedString = "";
    for (char c : input) {
        for (const auto& codePair : huffmanCodes) {
            if (codePair.first == c) {
                encodedString += codePair.second;
                break;
            }
        }
    }
    return encodedString;
}

// 译码
string HuffmanCoding::decode(const string& input) {
    string decodedString = "";
    HuffmanNode* current = root;
    for (char bit : input) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->data != '\0') {
            decodedString += current->data;
            current = root;
        }
    }
    return decodedString;
}

int main() {
    int n;
    cout << "Enter the size of the character set: ";
    cin >> n;

    vector<pair<char, int>> charFrequency;
    for (int i = 0; i < n; ++i) {
        char character;
        int weight;
        cout << "Enter character and weight for element " << i + 1 << ": ";
        cin >> character >> weight;
        charFrequency.emplace_back(character, weight);
    }

    HuffmanCoding huffman;
    huffman.setCharacterFrequency(charFrequency);
    huffman.printHuffmanCodes();

    string input;
    cout << "Enter the string to be encoded: ";
    cin >> input;

    string encoded = huffman.encode(input);
    cout << "Encoded string: " << encoded << endl;

    string decoded = huffman.decode(encoded);
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
