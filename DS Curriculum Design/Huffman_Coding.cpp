#include <iostream>
#include <vector>
using namespace std;

// 定义HuffmanNode结构
struct HuffmanNode{
    char data;
    int weight;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char d,int w):data(d),weight(w),left(NULL),right(NULL) {}
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

void swap(HuffmanNode*& a,HuffmanNode*& b){
    HuffmanNode* temp=a;
    a=b;
    b=temp;
}

// 堆的插入操作
void MinHeap::insert(HuffmanNode* node){
    heap.push_back(node);
    int index=heap.size()-1;
    // 通过比较新节点与其父节点的权重，维护最小堆性质
    // 如果新节点的权重小于其父节点的权重，交换它们的位置，直到满足最小堆性质
    while(index>0 && heap[index]->weight<heap[(index-1)/2]->weight){
        swap(heap[index],heap[(index-1)/2]);
        index=(index-1)/2;
    }
}

// 堆的弹出操作
HuffmanNode* MinHeap::pop(){
    // 如果堆为空，返回空指针
    if(heap.empty()){
        return NULL;
    }

    // 获取堆顶节点（最小节点）
    HuffmanNode* topNode=heap[0];
    // 将堆尾节点移到堆顶
    heap[0]=heap.back();
    // 移除堆尾节点
    heap.pop_back();
    // 通过调用堆的最小堆调整函数，维护最小堆性质
    heapify(0);
    // 返回之前的堆顶节点（最小节点）
    return topNode;
}

// 堆的堆顶节点
HuffmanNode* MinHeap::top(){
    return heap.empty() ? NULL : heap[0];
}

// 堆的大小
int MinHeap::size(){
    return heap.size();
}

// 堆的最小堆调整
void MinHeap::heapify(int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<heap.size() && heap[left]->weight<heap[smallest]->weight){
        smallest=left;
    }

    if(right<heap.size() && heap[right]->weight<heap[smallest]->weight){
        smallest=right;
    }

    if(smallest!=i){
        swap(heap[i],heap[smallest]);
        heapify(smallest);
    }
}

// 哈夫曼编码类
class HuffmanCoding {
private:
    HuffmanNode* root;
    vector<pair<char,string>> huffmanCodes;

    // 构建哈夫曼树
    void buildHuffmanTree(const vector<pair<char,int>>& charFrequency);

    // 递归删除哈夫曼树节点的成员函数
    void deleteTree(HuffmanNode* node);

    // 递归生成哈夫曼编码
    void generateCodes(HuffmanNode* node,string code);

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
HuffmanCoding::HuffmanCoding() : root(NULL) {}

// 递归删除哈夫曼树节点的成员函数的实现
void HuffmanCoding::deleteTree(HuffmanNode* node){
    if(node){
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// 析构函数调用成员函数
HuffmanCoding::~HuffmanCoding(){
    deleteTree(root);
}

// 构建哈夫曼树
void HuffmanCoding::buildHuffmanTree(const vector<pair<char,int>>& charFrequency){
    // 使用最小堆存储节点，按权值升序排列
    MinHeap minHeap;

    // 初始化节点并加入最小堆
    for (const auto& pair : charFrequency) {
        minHeap.insert(new HuffmanNode(pair.first,pair.second));
    }

    // 构建哈夫曼树
    while(minHeap.size()>1){
        HuffmanNode* left=minHeap.pop();
        HuffmanNode* right=minHeap.pop();

        HuffmanNode* internalNode=new HuffmanNode('\0',left->weight+right->weight);
        internalNode->left=left;
        internalNode->right=right;

        minHeap.insert(internalNode);
    }

    // 根节点即为哈夫曼树的根
    root=minHeap.top();
}

// 递归生成哈夫曼编码
void HuffmanCoding::generateCodes(HuffmanNode* node,string code){
    if(node->data!='\0'){
        huffmanCodes.push_back({node->data,code});
    }
    if(node->left){
        generateCodes(node->left,code+'0');
    }
    if(node->right){
        generateCodes(node->right, code +'1');
    }
}

// 设置字符集和权值，构建哈夫曼树
void HuffmanCoding::setCharacterFrequency(const vector<pair<char,int>>& charFrequency){
    buildHuffmanTree(charFrequency);
    generateCodes(root, "");
}

// 打印哈夫曼编码
void HuffmanCoding::printHuffmanCodes() {
    cout<<"Huffman Codes:"<<endl;
    for(const auto& pair : huffmanCodes){
        cout<<pair.first<<": "<<pair.second<<endl;
    }
}

// 编码
string HuffmanCoding::encode(const string& input){
    // 用于存储编码后的字符串
    string encodedString="";
    // 遍历输入字符串的每个字符
    for(char c : input){
        // 遍历哈夫曼编码列表
        for(const auto& codePair : huffmanCodes){
            // 如果找到字符对应的哈夫曼编码
            if(codePair.first==c) {
                // 将该字符的哈夫曼编码追加到编码后的字符串中
                encodedString+=codePair.second;
                // 跳出内层循环，继续处理下一个输入字符
                break;
            }
        }
    }
    // 返回编码后的字符串
    return encodedString;
}

// 译码
string HuffmanCoding::decode(const string& input){
    string decodedString="";
    // 当前节点初始化为哈夫曼树的根节点
    HuffmanNode* current=root;
    // 遍历输入的哈夫曼编码字符串
    for(char bit : input){
        // 根据当前 bit 的值，移动到左子节点或右子节点
        if(bit=='0'){
            current=current->left;
        }else{
            current=current->right;
        }

        // 如果当前节点是叶子节点（包含字符信息）
        if(current->data!='\0'){
            // 将叶子节点的字符追加到译码后的字符串中
            decodedString+=current->data;
            current=root;
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

    system("pause");
    return 0;
}
