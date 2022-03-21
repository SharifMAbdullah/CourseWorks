package Chapter16;

import java.util.Arrays;
import java.util.LinkedList;

public class UsingToArray {
	public static void main(String[] args) {
		String[] colors = {"black", "blue", "yellow"};
		LinkedList<String> links = new LinkedList<>(Arrays.asList(colors));
		
		links.addLast("red"); // add as last item
		links.add("pink");  // add to the end
		links.add(3, "green");  // add at 3rd index
		links.addFirst("cyan");  // add as first item
		
		// get linkedList elements as an array
		colors = links.toArray(new String[links.size()]);
		
		System.out.println("colors: [Array]");
		
		for(String color : colors) {
			System.out.println(color);
		}
		
		System.out.println("\ncolors: [link list]");
		for(String color : links) {
			System.out.printf("%s ", color);
		}
	}

}
