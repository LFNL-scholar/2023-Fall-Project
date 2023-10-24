#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);

    cout<<"Front of the queue: "<<myQueue.front()<<endl;
    cout<<"Back of the queue: "<<myQueue.back()<<endl;

    myQueue.pop();
    cout<<"Front of the queue after pop: "<<myQueue.front()<<endl;

    if(myQueue.empty()){
        cout<<"Queue is empty."<<endl;
    }else{
        cout<<"Queue is not empty."<<endl;
    }

    cout<<"Size of the queue: "<<myQueue.size()<<endl;

    return 0;
}