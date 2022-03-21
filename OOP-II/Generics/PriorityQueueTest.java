package Chapter16;

import java.util.PriorityQueue;

// PriorityQueue test program
public class PriorityQueueTest {
	public static void main(String[] args) {
		// queue of capcaity 11
		PriorityQueue<Double> queue = new PriorityQueue<>();
		
		// insert elements to queue
		queue.offer(3.2);
		queue.offer(9.8);
		queue.offer(5.4);
		
		// see the highest priority element in priorityqueue
		System.out.println("Peek from queue: " + queue.peek());
		
		// remove all elements
		queue.clear();
		System.out.println("Peek from queue after clear: " + queue.peek());
	
		// insert elements to queue
		queue.offer(3.2);
		queue.offer(9.8);
		queue.offer(5.4);
		
		System.out.print("Polling from queue: ");
		
		// display elements in queue
		while(queue.size() > 0) {
			System.out.printf("%.1f ", queue.peek());
			queue.poll();
		}
	}

}
