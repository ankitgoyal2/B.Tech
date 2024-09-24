package oslab;
class cp
{
	int buffer[]=new int[100];
	int key=0;
	int dis=-1;
	boolean km=true;
	boolean check=false;
	public synchronized  void get(int a)
	{
		while(check)
		{
			try
			{
				wait();
			}
			catch(Exception e)
			{
				System.out.println("Exception caught");
			}
			
		}
		check=true;
		
		System.out.println("Keyboard working.");
		buffer[key++]=a;
		notify();
		
	}
	
	
	
	public  synchronized void put()
	{
		while(!check)
		{
			try
			{
				wait();
			}
			catch(Exception e)
			{
				System.out.println("Exception Caught ");
				
			}
		}
		check=false;
		dis++;
		
		System.out.println("Display Working: "+buffer[dis]);
	  
		notify();
		
	}


}

class keyboard implements Runnable
{
	cp c;
	Thread t;
	keyboard(cp c)
	{
		this.c=c;
		t=new Thread(this, "Keyboard");
		//t.start();
		
		
	}
	
	public void run()
	{ System.out.println("RUN");
		for( int i=0; i<5;++i)
		{
			c.get(i);
		}
		c.km=false;
	}
	
	
	
}

class display implements Runnable
{
	cp c;
	Thread t;
	
	display(cp c)
	{
		this.c=c;
		t=new Thread(this, "Display");
		//t.start();
	}
	
	
	public void run()
	{
		while(c.km)
		{
			c.put();
			
		}
	}
	
}



public class keyboardDisplay {

	public static void main(String[] args) {
		 cp c=new cp();
		 keyboard k= new keyboard(c);
		 display d= new display(c);
		 
		 k.t.start();
		 d.t.start();
		 
		 System.out.println("Print Ctrl-C to Stop.");
		 
		 
		 
	}

}
