package Java_Experiment;
public class Animal {
    private String species;
    private int age;
    private static int numberOfAnimals=0;

    // Constants
    public static final String SOUND="Animal makes a sound";
    
    // Constructors
    public Animal(){
        numberOfAnimals++;
    }

    public Animal(String species,int age){
        this.species=species;
        this.age=age;
        numberOfAnimals++;
    }

    //Methods
    public void makeSound(){
        System.out.println(SOUND);
    }

    public void eat(){
        System.out.println("The animal is eating.");
    }

    //Overloaded methods
    public void sleep(){
        System.out.println("The animal is sleeping.");
    }

    public void sleep(int hours){
        System.out.println("The animal is sleeping for "+hours+" hours.");
    }

    //Getters and Setters
    public String getSpecies(){
        return species;
    }

    public void setSpecies(String species){
        this.species=species;
    }

    public int getAge(){
        return age;
    }

    public void steAge(int age){
        this.age=age;
    }

    public static int getNumberOfAnimals(){
        return numberOfAnimals;
    }

    //Overriding toString() method from Object class
    @Override
    public String toString(){
        return "Animal [species="+species+", age="+age+"]";
    }

    public static void printSound(){
        System.out.println("Every animal makes a sound.");
    }

    public static void main(String[] args) {
        Animal lion=new Animal("Lion",5);
        Animal elephant=new Animal("Elephant",10);

        System.out.println("Lion: "+lion.getSpecies()+", Age: "+lion.getAge());
        System.out.println("Elephant: "+elephant.getSpecies()+", Age: "+elephant.getAge());

        lion.makeSound();
        lion.eat();
        lion.sleep(8);

        elephant.makeSound();
        elephant.eat();
        elephant.sleep();

        System.out.println("NUmber of animals created: "+Animal.getNumberOfAnimals());
        Animal.printSound();
    }
}
