

class newThread implements Runnable {
	String name;
	Thread t;
	
	newThread(String nameOfThread)
	{
		name = nameOfThread;
		t = new Thread(this, name);
		System.out.println("New Thread: " + t);
		t.start();
	}
	public void run()
	{
		try {
			for(int i = 1; i < 10; i++) {
			System.out.println(name + ": " + i);
			Thread.sleep(500);
			}
			} catch (InterruptedException e) {
			System.out.println(name + "Interrupted");
			}
			System.out.println(name + " exiting.");
	}
}
public class MultiTreadUsingRunnable {

	public static void main(String[] args) {
		new newThread("one");
		new newThread("two");
		new newThread("three");
		try {
			Thread.sleep(5000);
		}catch(InterruptedException e) {
			System.out.println("main interrupted");
		}
		System.out.println("main exiting");
	}

}
