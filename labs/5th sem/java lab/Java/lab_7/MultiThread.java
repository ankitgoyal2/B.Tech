

class newThread1 extends Thread {
	newThread1()
	{
		start();
	}
	public void run() {
		try {
		for(int i = 1; i < 10; i++) {
		System.out.println("Child Thread 1: " + i);
		Thread.sleep(500);
		}
		} catch (InterruptedException e) {
		System.out.println("Child Thread 1 interrupted.");
		}
		System.out.println("Exiting child thread 1.");
		}
}
class newThread2 extends Thread {
	newThread2()
	{
		start();
	}
	public void run() {
		try {
		for(int i = 1; i < 10; i++) {
		System.out.println("Child Thread 2: " + i);
		Thread.sleep(500);
		}
		} catch (InterruptedException e) {
		System.out.println("Child Thread 2 interrupted.");
		}
		System.out.println("Exiting child thread 2.");
		}
}
class newThread3 extends Thread {
	newThread3()
	{
		start();
	}
	public void run() {
		try {
		for(int i = 1; i < 10; i++) {
		System.out.println("Child Thread 3: " + i);
		Thread.sleep(500);
		}
		} catch (InterruptedException e) {
		System.out.println("Child Thread 3 interrupted.");
		}
		System.out.println("Exiting child thread 3.");
		}
}

public class MultiThread {

	public static void main(String[] args) {
		
		new newThread1();
		new newThread2();
		new newThread3();
	}

}
