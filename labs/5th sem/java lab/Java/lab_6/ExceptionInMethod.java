
import java.io.IOException;

public class ExceptionInMethod {
	
	public static void methodB()
	{
		System.out.println("Hello You are in method B");
		
		try
		{
			throw new IOException();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			throw new NullPointerException();
		}
	}
	public static void methodA()
	{
		System.out.println("Hello You are in method A");
		
		try
		{
			methodB();
		}
		catch(Exception e)
		{
			e.printStackTrace();
			throw new ArithmeticException();
		}
	}
	
	public static void main(String args[])
	{
		System.out.println("you are in Main");
		
		try
		{
			methodA();
		}
		catch(Exception e)
		{
			e.printStackTrace();

		}
		
	}
	

}
