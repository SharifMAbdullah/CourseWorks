package Chapter16.Sets;

import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class SetTest {

	public static void main(String[] args) {
		// create and display a List<String>
		String[] colors = {"red", "white", "blue", "green", "grey", "orange", "tan",
				"white", "cyan", "peach", "gray", "orange"};
		List<String> list = Arrays.asList(colors);
		System.out.printf("List(%d): %s%n", list.size(), list);
		
		// eliminate duplicates then print the unique values
		printNoDuplicates(list);
	}
	
	// create a Set from a Collection to eliminate duplicates
	private static void printNoDuplicates(Collection<String> values) {
		// create a HasShet
		Set<String> set = new HashSet<>(values);
		
		System.out.printf("%nNonduplicates are(%d): ", set.size());
		
		for(String value : set) {
			System.out.printf("%s ", value);
		}
		
		System.out.println();
	}
}

