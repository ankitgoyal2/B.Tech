
class Sync extends Thread 
{ 
	Sync()
	{
		System.out.println("Object created\n");
	}
	public synchronized void run(String s)
	{  
		for(int i = 0 ; i< 3 ; i++)
		{
		System.out.println("Sending "+ s);
		try {
			Thread.sleep(600);
		}
		catch (InterruptedException e) {
				System.out.println("Thread interrupted");
			} 
		System.out.println("\n\n"+ s + " sent");			
		
		}
	}
	public void finalise()
	{
		System.out.println("Object is to be destroyed");
	}
}
class Test extends Thread
{
	private String s;
	Sync sy ;
	Test(String a , Sync b)
	{
		s = a;
		sy = b;
	}
	public void run()
	{
		System.out.println("Before running the finalise method");
		sy.run(s);
		sy.finalise();
		System.out.println("calling the Garbage collector");
		System.gc();
	}
}

public class SynchronisedThread
{ 
	public static void main(String[] args) 
	{
        Sync a ;
        a = new Sync();
        Test b = new Test("HI" , a);
        b.run();
			
	}
	
}
