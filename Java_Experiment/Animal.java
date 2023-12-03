
public class Animal {
    private String species;
    private int age;
    private static int numberOfAnimals = 0;  // 使用static定义静态变量

    // Constants
    public static final String SOUND = "Animal makes a sound";  // 使用final定义常量

    // Constructors
    public Animal() {
        numberOfAnimals++;
    }

    public Animal(String species, int age) {
        this.species = species;
        this.age = age;
        numberOfAnimals++;
    }

    // Methods
    public void makeSound() {
        System.out.println(SOUND);
    }

    public void eat() {
        System.out.println("The animal is eating.");
    }

    // Overloaded methods
    public void sleep() {
        System.out.println("The animal is sleeping.");
    }

    public void sleep(int hours) {
        System.out.println("The animal is sleeping for " + hours + " hours.");
    }

    // Getters and Setters
    public String getSpecies() {
        return species;
    }

    public void setSpecies(String species) {
        this.species = species;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static int getNumberOfAnimals() {
        return numberOfAnimals;
    }

    // Overriding toString() method from Object class
    @Override
    public String toString() {
        return "Animal [species=" + species + ", age=" + age + "]";
    }

    // Example of static method
    public static void printSound() {
        System.out.println("Every animal makes a sound.");
    }

    public static void main(String[] args) {
        // 创建Animal类的对象
        Animal lion = new Animal("Lion", 5);
        Animal elephant = new Animal("Elephant", 10);

        // 访问对象的属性
        System.out.println("Lion: " + lion.getSpecies() + ", Age: " + lion.getAge());
        System.out.println("Elephant: " + elephant.getSpecies() + ", Age: " + elephant.getAge());

        // 调用对象的方法
        lion.makeSound();
        lion.eat();
        lion.sleep(8);

        elephant.makeSound();
        elephant.eat();
        elephant.sleep();

        // 访问静态变量
        System.out.println("Number of animals created: " + Animal.getNumberOfAnimals());

        // 调用静态方法
        Animal.printSound();
    }
}

