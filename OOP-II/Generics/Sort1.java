package Chapter16;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Sort1 {
	public static void main(String[] args) {
		String[] suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
		
		// Create and display a list containing the suits array elements
		List<String> list = Arrays.asList(suits);
		System.out.printf("Unsorted array elements: %s%n", list);
		
		Collections.sort(list); // sort ArrayList
		System.out.printf("\nSorted array elements: %s%n", list);
		
		// sort in descending order using a compartor
		Collections.sort(list, Collections.reverseOrder());
		System.out.printf("\nReverse sorted array elements: %s%n", list);
	}

}
