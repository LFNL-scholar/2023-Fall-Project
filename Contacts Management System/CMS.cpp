#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
#define MAX 1000

//菜单界面
void showMenu(){
    cout<<"*************************"<<endl;
    cout<<"***** 1. 添加联系人 *****"<<endl;
    cout<<"***** 2. 显示联系人 *****"<<endl;
    cout<<"***** 3. 删除联系人 *****"<<endl;
    cout<<"***** 4. 查找联系人 *****"<<endl;
    cout<<"***** 5. 修改联系人 *****"<<endl;
    cout<<"***** 6. 清空联系人 *****"<<endl;
    cout<<"***** 0. 退出通讯录 *****"<<endl;
    cout<<"*************************"<<endl;
}

struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBooks{
    struct Person personArray[MAX];
    int m_Size;
};

void addPerson(AddressBooks *abs){
    if(abs->m_Size==MAX){
        cout<<"通讯录已满，无法添加！"<<endl;
        return;
    }else{
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;
    }
}

int main(){
    SetConsoleOutputCP(65001);

    AddressBooks abs;
    abs.m_Size=0;

    int select=0;
    while(true){
        showMenu();
        cin>>select;

        switch(select){
            case 1: // 添加联系人
                addPerson(&abs); // 地址传递
                break;
            case 2: // 显示联系人
                break;
            case 3: // 删除联系人
                break;
            case 4: // 查找联系人
                break;
            case 5: // 修改联系人
                break;
            case 6: // 清空联系人
                break;
            case 0: // 退出通讯录
                cout<<"欢迎下次使用"<<endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }
    
    system("pause");
    return 0;
}