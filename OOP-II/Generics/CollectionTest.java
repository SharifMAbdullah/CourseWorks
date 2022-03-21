package Chapter16;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

// Collection interface demonstrated via an ArrayList object
public class CollectionTest {
	public static void main(String[] args) {
		String[] colors = {"MAGENTA", "RED", "WHITE", "BLUE", "CYAN"};
		List<String> list = new ArrayList<String>();
		
		for(String color : colors) {
			list.add(color); // adds color to end of list
		}
		
		// add elements in removeColors array to remove List
		String[] removeColors = {"RED", "WHITE", "BLUE"};
		List<String> removeList = new ArrayList<String>();
		
		for(String color : removeColors) {
			removeList.add(color);
		}
		
		// output list contents
		System.out.println("ArrayList: ");
		
		for(int i=0; i<list.size(); i++) {
			System.out.printf("%s ", list.get(i));
		}
		
		// remove from list the colors contained in removeList
		removeColors(list, removeList);
		
		// output list contents 
		System.out.printf("%n%nArrayList after calling removeColors:%n");
		
		for(String color : list) {
			System.out.printf("%s ", color);
		}
		
	}
	
	private static void removeColors(Collection<String> collection1,
		Collection<String> collection2) {
		// get iterator
		Iterator<String> iterator = collection1.iterator();
		
		// loop while collection has items
		while(iterator.hasNext()) {
			if(collection2.contains(iterator.next())) {
				iterator.remove();  // remove current element
			}
		}
		
	}

}
