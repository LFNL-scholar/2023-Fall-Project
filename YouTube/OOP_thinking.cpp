// YouTube Class
// Object Oriented Programming (OOP) in C++ Course
// 2023/9/24
/*Notes:
    封装 抽象 继承 多态
*/
#include <iostream>
using std::string;

class AbstractEmployee{
    virtual void AskForPromotion()=0;

};

class Employee:AbstractEmployee{
 private:
    string Company;
    int Age;

protected:
    string Name;

public:
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }

    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }

    void setAge(int age){
        if(age>=18)
        Age = age;
    }
    int getAge(){
        return Age;
    }

    void IntroduceYourself(){
        std::cout<<"Name - "<<Name<<std::endl;
        std::cout<<"Company - "<<Company<<std::endl;
        std::cout<<"Age - "<<Age<<std::endl;
    }

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;

    }

    void AskForPromotion(){
        if(Age>30)
            std::cout<<Name<<" got promoted!"<<std::endl;
        else
            std::cout<<Name<<", sorry NO promotion for you!"<<std::endl;
    }

    virtual void Work(){
        std::cout<<Name<<" is checking email, task backlog, performing tasks..."<<std::endl;
    }
};

class Developer:public Employee {
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }

    void FixBug(){
        std::cout<<Name<<" fixed bug using "<<FavProgrammingLanguage<<std::endl;
    }

    void Work(){
        std::cout<<Name<<" is writing "<<FavProgrammingLanguage<<" code"<<std::endl;
    }

};

class Teacher:public Employee {
public:
    string Subject;
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    
    void PrepareLesson(){
        std::cout<<Name<<" is preparing "<<Subject<<" lesson"<<std::endl;
    }

    void Work(){
        std::cout<<Name<<" is teaching "<<Subject<<std::endl;
    }

};

int main(){
    Employee employee1 = Employee("Like", "LFNL-TECH", 19);
    employee1.IntroduceYourself();

    Employee employee2 = Employee("JiaXin", "LFNL", 19);
    employee2.IntroduceYourself();

    employee1.AskForPromotion(); 
    employee2.AskForPromotion();

    Developer Scholar = Developer("LiKe", "LFNL-TECH", 19, "C++");
    Scholar.FixBug();
    Scholar.AskForPromotion();

    Teacher Jiaxin = Teacher("JiaXin", "LFNL", 19, "Art");
    Jiaxin.PrepareLesson();
    Jiaxin.AskForPromotion();

    Scholar.Work();
    Jiaxin.Work();

    Employee* e1 = &Scholar;
    Employee* e2 = &Jiaxin;

    e1->Work();
    e2->Work();

}