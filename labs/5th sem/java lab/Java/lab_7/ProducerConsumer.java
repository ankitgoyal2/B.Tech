


class Q {
	int n;
	boolean valueSet = false;
	synchronized int get() {
		while(!valueSet)
		try {
			wait();
		} catch(InterruptedException e) {
			System.out.println("InterruptedException caught");
		}
		System.out.println("Got: " + n);
		valueSet = false;
		notify();
		return n;
	}
	synchronized void put(int n) {
		while(valueSet)
		try {
		wait();
		} catch(InterruptedException e) {
		System.out.println("InterruptedException caught");
		}
		this.n = n;
		valueSet = true;
		System.out.println("Put: " + n);
		notify();
	}
}
class Producer implements Runnable {
	Q q;
	Producer(Q q) {
		this.q = q;
		new Thread(this, "Producer").start();
	}
	public void run() {
		int i = 0,j=0;
		while(j<5) {
			
			q.put(i++);
			j++;
		}
	}
}
class Consumer implements Runnable {
	Q q;
	Consumer(Q q) {
		this.q = q;
		new Thread(this, "Consumer").start();
	}
	public void run() {
		int i=0;
		while(i<5) {
			q.get();
			i++;
		}
	}
}

public class ProducerConsumer {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Q q = new Q();
		new Producer(q);
		new Consumer(q);

	}

}
