package oslab;
class basic
{
	int t=0;
	boolean k=false,p1=true,p2=true;
	
	
	public void critical(int i)
	{
		t++;
		System.out.println("Inside critical section "+i+" : "+t);
		System.out.println("Exiting the section "+i);
		
	}

}


class process1 implements Runnable
{
	basic b;
	Thread t;
	process1(basic b)
	{
		this.b=b;
		t=new Thread(this,"Process1");
		System.out.println("Process 1 Created");
		//t.start();
		
	}
	
	public void run()
	{  while(b.p1)
	{
	
		while(b.k)
		{
			System.out.println("Process 1 in Waiting state");
			
		}
		b.critical(1);
		b.k=true;

		System.out.println("Process 1 in the normal section");
		
	}
	}
	public void stopi()
	{
		b.p1=false;
	}
	
}

class process2 implements Runnable
{
	basic b;
	Thread t;
	process2(basic b)
	{
		this.b=b;
		t=new Thread(this, "Process2");
		System.out.println("Process 2 created ");
		//t.start();
	}
	public void run()
	{
		
		while(b.p2)
		{
		
			while(!b.k)
			{
				System.out.println("Process 2 in Waiting State");
			}

			
			b.critical(2);
			b.k=false;

			System.out.println("Process 2 in the normal section");
			
		}
		}
	public void stopi()
	{
		b.p2=false;
	}
}



public class algo1 {

	public static void main(String[] args){
		
		basic b=new basic();
		process1 p=new process1(b);
		process2 k=new process2(b);
		
		
		p.t.start();
		
		k.t.start();
		
try{
		Thread.sleep(100);
   }
catch(Exception e)
{
	System.out.println("Exception caught 3 "+e);
}

System.out.println("Calling to stop the execution of Threads");
p.stopi();
k.stopi();

System.out.println("Main Thread Exiting");
}


}