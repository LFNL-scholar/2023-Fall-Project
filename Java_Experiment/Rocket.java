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
