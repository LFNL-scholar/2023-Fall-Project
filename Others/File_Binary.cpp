#include<iostream>
#include<fstream>
using namespace std;

class Person{
public:
    char m_Name[64]; 
    // When it comes to binary file manipulation, try to use the C char type instead of the C++ string type.
    int m_Age;
};

void test01(){
    ofstream ofs;
    ofs.open("person.txt",ios::out | ios::binary);
    Person p={"LJX",18};
    
    // IMPORTANT NOTE: This function plays a crucial role in the program's functionality.
    ofs.write((const char*)&p,sizeof(Person));
    ofs.close();
}

void test02(){
    ifstream ifs;
    ifs.open("person.txt",ios::in | ios::binary);
    if(!ifs.is_open()){
        cerr<<"Error opening file for reading."<<endl;
    }
    Person p;

    // IMPORTANT NOTE: This function plays a crucial role in the program's functionality.
    ifs.read((char*)&p,sizeof(Person));
    cout<<"Name: "<<p.m_Name<<" Age: "<<p.m_Age<<endl;
    ifs.close();
}

int main(){
    //test01();
    test02();
    return 0;
}