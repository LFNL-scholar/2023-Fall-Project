#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArry(int val){
    cout<<val<<" ";
}

// vector存放内置数据类型
void test01(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin=v.begin(); // 起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd=v.end(); // 结束迭代器，指向容器中最后一个元素的下一个位置

    // 第一种遍历方式
    while(itBegin!=itEnd){
        cout<<*itBegin<<" ";
        itBegin++;
    }
    cout<<endl;

    // 第二种遍历方式
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // 第三种遍历方式，利用STL提供的遍历算法
    for_each(v.begin(),v.end(),printArry);
    cout<<endl;
    
}

class Person{
public:
    string m_Name;
    int m_Age;

    Person(string name,int age):m_Name(name),m_Age(age) {}
};

// vector存放自定义数据类型
void test02(){
    vector<Person> v;
    Person p1("A",18);
    Person p2("B",19);
    Person p3("C",20);
    Person p4("D",18);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    // 遍历容器中的数据
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        // cout<<"Name: "<<(*it).m_Name<<"  Age: "<<(*it).m_Age<<endl;
        cout<<"Name: "<<it->m_Name<<"  Age: "<<it->m_Age<<endl;
    }
}

void test03(){
    vector<Person*> v;
    Person p1("A",18);
    Person p2("B",19);
    Person p3("C",20);
    Person p4("D",18);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    // 遍历容器
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++){
        cout<<"Name: "<<(*it)->m_Name<<"  Age: "<<(*it)->m_Age<<endl;
    }
}

// vector存放
void test04(){
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for(int i=0;i<4;i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++){
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++){
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}


int main(){
    test01();
    test02();
    test03();
    test04();
    return 0;
}
