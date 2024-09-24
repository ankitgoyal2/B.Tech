package oslab;
class basic11
{
	int t=0;
	boolean k=false,p1=true,p2=true;
	boolean p1using=false, p2using=false;
	
	
	public synchronized void critical(int i)
	{
		t++;
		System.out.println("Inside critical section "+i+" : "+t);
		System.out.println("Exiting the section "+i);
		
	}

}


class process11 implements Runnable
{
	basic11 b;
	Thread t;
	process11(basic11 b)
	{
		this.b=b;
		t=new Thread(this,"Process1");
		System.out.println("Process 1 Created");
		t.setPriority(9);
		t.start();
		
	}
	
	public void run()
	{  System.out.println("RUN 1");

		while(b.p1)
	{
		b.p1using=true;
		while(b.p2using)
		{
			//System.out.println("Process 1 in Waiting state");
			
		}
		
		b.critical(1);
		b.p1using=false;
	
		
		

		System.out.println("Process 1 in the normal section");
		
	}
	}
	public void stopi()
	{System.out.println("Stop Process 1");
		b.p1=false;
	}
	
}

class process22 implements Runnable
{
	basic11 b;
	Thread t;
	process22(basic11 b)
	{
		this.b=b;
		t=new Thread(this, "Process2");
		System.out.println("Process 2 created ");
		t.setPriority(10);
		t.start();
	}
	public void run()
	{ System.out.println("RUN 2");
	
		
		
		while(b.p2)
		{
			b.p2using=true;
			while(b.p1using)
			{
				//System.out.println("Process 2 in Waiting State");
			}

			
			b.critical(2);
			b.p2using=false;
			

			System.out.println("Process 2 in the normal section");
			
			
		}
		}
	public void stopi()
	{  System.out.println("Stop Process 2");
		b.p2=false;
	}
}

public class algo3 {

	public static void main(String[] args){
		
		basic11 b=new basic11();
		process11 p=new process11(b);
		process22 k=new process22(b);

		//p.t.start();
		//k.t.start();
		
try{
		Thread.sleep(10000);
   }
catch(Exception e)
{
	System.out.println("Exception caught 3 "+e);
}

System.out.println("Calling to stop the execution of Threads");
p.stopi();
k.stopi();

try {
	
	p.t.join();
	k.t.join();
	
}
catch(Exception e)
{
	System.out.println("Exception Caught");
}

System.out.println("Main Thread Exiting");
}


}
