package Java_Experiment;

public class MemoryAllocation {
    // 栈内存溢出
    private static void stackOverflow(){
        stackOverflow(); // 递归调用，导致栈内存溢出
    }

    //堆内存溢出
    private static void heapOverflow(){
        // 创建大量对象，导致堆内存溢出
        while (true) {
            new Object();
        }
    }

    public static void main(String[] args) {
        // 栈内存溢出示例
        try{
            stackOverflow();
        }catch(StackOverflowError e){
            System.out.println("栈内存溢出异常："+e.getMessage());
        }

        // 堆内存溢出示例
        try{
            heapOverflow();
        }catch(OutOfMemoryError e){
            System.out.println("堆内存溢出异常："+e.getMessage());
        }

        //内存监控
        Runtime runtime=Runtime.getRuntime();
        long totalMemory=runtime.totalMemory();
        long freeMemory=runtime.freeMemory();
        long usedMemory=totalMemory-freeMemory;

        System.out.println("总内存：" + totalMemory + " bytes");
        System.out.println("已分配内存：" + usedMemory + " bytes");
        System.out.println("剩余内存：" + freeMemory + " bytes");
    }
}
