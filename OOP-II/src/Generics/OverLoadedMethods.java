package Generics;

public class OverLoadedMethods
{
    public static void printArray(Integer[] inputArray)
    {
        for(Integer element : inputArray)
            System.out.printf("%s ",element);
    
    System.out.println();    
    }
    
    public static void printArray(Double[] inputArray)
    {
        for(Double element : inputArray)
            System.out.printf("%s ",element);
    
    System.out.println();    
    }
    
    public static void printArray(Character[] inputArray)
    {
        for(Character element : inputArray)
            System.out.printf("%s ",element);
    
    System.out.println();    
    }
    
}

