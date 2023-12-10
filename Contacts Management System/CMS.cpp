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

        cout<<"请输入性别："<<endl;
        cout<<"1--=男"<<endl;
        cout<<"2---女"<<endl;
        int sex=0;
        while(true){
            cin>>sex;
            if(sex==1 || sex==2){
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        
        cout<<"请输入年龄："<<endl;
        int age=0;
        while(true){
            cin>>age;
            if(age>=1 &&age<=150){
                abs->personArray[abs->m_Size].m_Age=age;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }

        cout<<"请输入联系电话："<<endl;
        string phone;
        while(true){
            cin>>phone;
            if(phone.size()==11){
                abs->personArray[abs->m_Size].m_Phone=phone;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }

        cout<<"请输入家庭住址："<<endl;
        string address;
        cin>>address;
        abs->personArray[abs->m_Size].m_Addr=address;

        abs->m_Size++;
        cout<<"添加成功！"<<endl;

        system("pause"); // 请按任意键继续
        system("cls"); //清屏操作
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