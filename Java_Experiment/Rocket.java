package Java_Experiment;
import java.nio.CharBuffer;

public class Rocket {
    protected String name;

    public Rocket(String name){
        this.name=name;
    }

    public void launch(){
        System.out.println(name+" is launching into space!");
    }

    public String getName(){
        return name;
    }
}

class Falcon9 extends Rocket{
    private int payloadCapacity;

    public Falcon9(String name,int payloadCapacity){
        super(name);
        this.payloadCapacity=payloadCapacity;
    }

    @Override
    public void launch(){
        System.out.println(name+" is launching with a payload capacity of "+payloadCapacity+" kg");
    }

    public int getPayloadCapacity(){
        return payloadCapacity;
    }
}

interface Reusable {
    void land();
}

interface Readable {
    int read(CharBuffer cb);
}

class FalconHeavy extends Falcon9 implements Readable, Reusable {
    private static final String HEAVY_TYPE = "Heavy-lift";

    public FalconHeavy(String name, int payloadCapacity) {
        super(name, payloadCapacity);
    }

    @Override
    public void land() {
        System.out.println(getName() + " is landing back on Earth after launch");
    }

    @Override
    public void launch() {
        System.out.println(getName() + " is launching with USSF-52(OTV-7) Mission");
    }

    @Override
    public int read(CharBuffer cb) {
        return 0;
    }

    public static String getHeavyType() {
        return HEAVY_TYPE;
    }
}

class Out{
    public static void main(String[] args) {
        Rocket myRocket=new Rocket("LFNL Rocket");
        myRocket.launch();
        System.out.println("Rocket Name: "+myRocket.getName());
        Falcon9 myFalcon9=new Falcon9("LFNL Falcon9", 22000);
        myFalcon9.launch();
        System.out.println("Falcon 9 Payload Capacity: "+myFalcon9.getPayloadCapacity());

        FalconHeavy myFalconHeavy=new FalconHeavy("LFnl Falcon Heavy", 64000);
        myFalconHeavy.launch();
        myFalconHeavy.land();
        System.out.println("Falcon Heavy Payload Capacity: "+myFalconHeavy.getPayloadCapacity());
        System.out.println("Falcon Heavy Type: "+FalconHeavy.getHeavyType());
    }
}