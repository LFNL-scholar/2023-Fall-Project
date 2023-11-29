//设计顺序表的顺序查找算法，将哨兵设在下标高端
#include<iostream>
#include<vector>
using namespace std;

class SequentialSearch{
private:
    vector<int> data;

public:
    SequentialSearch(const vector<int>& input):data(input) {}

    int search(int key){
        int n=data.size();
        data.push_back(key); // 在数组末尾添加哨兵元素

        int i=0;
        while(data[i]!=key){
            i++;
        }
        data.pop_back(); // 恢复原始数组

        return (i<n) ? i:-1;
    }

    void call(int key){
        int result=this->search(key);
        if(result!=-1){
            cout<<"元素："<<key<<"在数组中的位置是："<<result<<endl;
        }else{
            cout<<"元素："<<key<<"不再数组中。"<<endl;
        }
    }
};

int main(){
    vector<int> vector={1,2,6,3,4,5,7,8,9};
    SequentialSearch SeqSearch(vector);
    SeqSearch.call(6);
    return 0;
}