#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Person{
public:
    string m_Name;
    int m_Age;

    Person(string name,int age):m_Name(name),m_Age(age) {}
};

void test01(){
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

void test02(){
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

int main(){
    test01();
    test02();
    return 0;
}
