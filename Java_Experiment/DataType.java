package Java_Experiment;

public class DataType {
    public static void main(String[] args) {

        // 定义各种基本类型
        int intValue=10;
        double doubleValue=3.14;
        char charValue='A';
        boolean booleanValue=true;

        System.out.println(intValue);
        System.out.println(doubleValue);
        System.out.println(charValue);
        System.out.println(booleanValue);

        // 输出各种类型的占用内存大小
        System.out.println("int占用内存大小: " + Integer.BYTES + " bytes");
        System.out.println("double占用内存大小: " + Double.BYTES + " bytes");
        System.out.println("char占用内存大小: " + Character.BYTES + " bytes");
        System.out.println("boolean占用内存大小: " + Byte.BYTES + " bytes");

        // 输出数值型数据的最大、最小值
        System.out.println("int的最大值: " + Integer.MAX_VALUE);
        System.out.println("int的最小值: " + Integer.MIN_VALUE);
        System.out.println("double的最大值: " + Double.MAX_VALUE);
        System.out.println("double的最小值: " + Double.MIN_VALUE);

        // 分别定义一个基本类型的数组
        int[] intArray = {1, 2, 3, 4, 5};

        // 定义一个对象类型的数组
        String[] stringArray = {"Apple", "Banana", "Orange"};

        // 对数组元素进行初始化
        for (int i = 0; i < intArray.length; i++) {
            System.out.println("intArray[" + i + "] = " + intArray[i]);
        }

        for (int i = 0; i < stringArray.length; i++) {
            System.out.println("stringArray[" + i + "] = " + stringArray[i]);
        }

        // 数组元素存取
        intArray[2] = 99;
        System.out.println("修改后的intArray[2] = " + intArray[2]);

        // 输出满足一定条件的数组元素
        System.out.println("大于3的元素: ");
        for (int i = 0; i < intArray.length; i++) {
            if (intArray[i] > 3) {
                System.out.println("intArray[" + i + "] = " + intArray[i]);
            }
        }

    }
}
