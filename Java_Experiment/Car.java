package Java_Experiment;

public class Car {
    private static int totalCars=0;
    private String brand;
    private String model;

    public Car(String brand,String model){
        this.brand=brand;
        this.model=model;
        totalCars++;
    }

    public static int getTotalCars(){
        return totalCars;
    }

    public String getCarInfo(){
        return "Brand: "+brand+", Model: "+model;
    }

    public static void main(String[] args) {
        Car car1=new Car("Toyota", "Camry");
        Car car2=new Car("Honda", "Civic");
        Car car3=new Car("Ford", "Focus");

        System.out.println("Total Cars: "+Car.getTotalCars());
        System.out.println(car1.getCarInfo());
        System.out.println(car2.getCarInfo());
        System.out.println(car3.getCarInfo());
        
    }
}
