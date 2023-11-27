package Java_Experiment;

public class Person {
    public String name;
    protected int age;
    private String address;

    public void introduce(){
        System.out.println("Hi, I'm "+name+". I am "+age+" years old.");
    }
    protected void updateAddress(String newAddress){
        this.address=newAddress;
        System.out.println("Address updated to: "+address);
    }
    private void privateMethod(){
        System.out.println("This is a private method.");
    }
    public void someOtherMethod() {
        // 调用 privateMethod()
        privateMethod();
    }
}

class Student extends Person {
    public void introduce(){
        System.out.println("Hi, I'm a student named "+name+". I am "+age+" years old.");
    }
    public void changeAddress(String newAdress){
        updateAddress(newAdress);
    }    

}

class Main {
    public static void main(String[] args) {
        Person person=new Person();
        person.name="LFNL";
        person.age=19;
        person.introduce();

        person.age=26;
        person.updateAddress("1421 Main St");

        Student student=new Student();
        student.name="Nancy";
        student.age=22;
        student.introduce();
        student.changeAddress("473 College Ave");
        
    }
}
