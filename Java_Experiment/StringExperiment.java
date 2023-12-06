package Java_Experiment;
public class StringExperiment {
    public static void main(String[] args) {
        String word="Hello";
        System.out.println("Initial Word: "+word);
        modifyWord(word);

        System.out.println("After Modification: "+word);
        StringBuilder stringBuilder=new StringBuilder(word);

        for(int i=0;i<5;i++){
            stringBuilder.append("word");
        }

        String resultWithStringBuilder=stringBuilder.toString();
        System.out.println("Using StringBuilder: "+resultWithStringBuilder);

        StringBuffer stringBuffer=new StringBuffer(word);

        for(int i=0;i<5;i++){
            stringBuffer.append("Universe");
        }

        String resultWithStringBuffer=stringBuffer.toString();
        System.out.println("Using StringBuffer: "+resultWithStringBuffer);
    }
    private static void modifyWord(String input){
        input=input+"World";
        System.out.println("Inside Modification Method: "+input);
    }
}
