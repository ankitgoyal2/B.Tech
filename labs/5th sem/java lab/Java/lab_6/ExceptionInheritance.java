

import java.util.Scanner;


class ExceptionA extends Exception
{
	public String toString() 
	{
		return "Exception A";
	}
	
}
class ExceptionB extends ExceptionA
{
	public String toString() 
	{
		return "Exception B";
	}
}

class ExceptionC extends ExceptionB
{
	public String toString() 
	{
		return "Exception C";
	}
}

public class ExceptionInheritance {
	
	static int val;
	public static void main(String args[])
	{
		System.out.println("Enter 1 to throw ExceptionA, 2 for ExcpetionB, 3 for ExceptionC");
		Scanner in = new Scanner(System.in);
		
		val = in.nextInt();
		
		
		
		try
		{
			switch(val)
			{
			case 1:
				throw new ExceptionA();
			
			case 2:
				throw new ExceptionB();
			
			case 3:
				throw new ExceptionC();
		
				
			}
		}
		catch(ExceptionA e)
		{
			System.out.println("Caught Exception is "+ e);
		}
	}
	

}
