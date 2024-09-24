

import java.io.IOException;
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

public class ExceptionClass {
	
	static int val;
	public static void main(String args[])
	{
		System.out.println("Enter 1 to throw ExceptionA, 2 for ExcpetionB, 3 for NullPointerException, 4 for IOException");
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
				throw new NullPointerException();
				
			case 4:
				throw new IOException();
					
			}
		}
		catch(Exception e)
		{
			System.out.println("Caught Exception is "+ e);
		}
	}

}
