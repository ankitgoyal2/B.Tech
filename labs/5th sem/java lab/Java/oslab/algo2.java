package oslab;
class basic1
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


class process01 implements Runnable
{
	basic1 b;
	Thread t;
	process01(basic1 b)
	{
		this.b=b;
		t=new Thread(this,"Process1");
		System.out.println("Process 1 Created");
		//t.start();
		
	}
	
	public void run()
	{  System.out.println("RUN 1");
		while(b.p1)
	{
	
		while(b.p2using)
		{
			System.out.println("Process 1 in Waiting state");
			
		}
		b.p1using=true;
		b.critical(1);
		b.p1using=false;
	
		
		

		System.out.println("Process 1 in the normal section");
		
	}
	}
	public void stopi()
	{
		b.p1=false;
	}
	
}

class process02 implements Runnable
{
	basic1 b;
	Thread t;
	process02(basic1 b)
	{
		this.b=b;
		t=new Thread(this, "Process2");
		System.out.println("Process 2 created ");
		//t.start();
	}
	public void run()
	{ System.out.println("RUN 2");
	
		
		while(b.p2)
		{
		
			while(b.p1using)
			{
				System.out.println("Process 2 in Waiting State");
			}

			b.p2using=true;
			b.critical(2);
			b.p2using=false;
			

			System.out.println("Process 2 in the normal section");
			
		}
		}
	public void stopi()
	{
		b.p2=false;
	}
}

public class algo2 {

	public static void main(String[] args){
		
		basic1 b=new basic1();
		process01 p=new process01(b);
		
		process02 k=new process02(b);
		
		
		p.t.start();
		k.t.start();
		
try{
		Thread.sleep(50);
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














