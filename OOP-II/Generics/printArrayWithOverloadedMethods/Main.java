import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) 
	{
	    Integer[] integerArray = {1,2,3,4,5,6};
	    Double[] doubleArray = {1.1,2.2,3.3,4.4,5.5,6.6};
	    Character[] characterArray = {'H','E','L','L','O'};
		OverLoadedMethods olm= new OverLoadedMethods();
		olm.printArray(integerArray);
		olm.printArray(doubleArray);
		olm.printArray(characterArray);
	}
}

