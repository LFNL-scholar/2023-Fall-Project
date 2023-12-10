#include<iostream>
#include<fstream>
using namespace std;

void test01(){
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    ofs<<"LJH"<<endl;
    ofs<<"LJX"<<endl;
    ofs<<"LFNL YYDS!"<<endl;
    ofs.close();
}

void test02(){
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open()){
        cout<<"Error opening file for reading."<<endl;
        return;
        // or this
        // cerr<<"Error opening file for reading."<<endl;
    }

    // first type
    char buf[1024]={0};
    while(ifs>>buf){
        cout<<buf<<endl;
    }

    // second type
    // char buf[1024]={0};
    // while(ifs.getline(buf,sizeof(buf))){
    //     cout<<buf<<endl;
    // }

    // third type
    // string buf;
    // while(getline(ifs,buf)){
    //     cout<<buf<<endl;
    // }

    // fourth type
    // Not really recommended, but it works.
    // char c;
    // while((c=ifs.get()) !=EOF){ // EOF end of file
    //     cout<<c;
    // }

    ifs.close();
}

int main(){
    //test01();
    test02();
    return 0;
}