
import java.util.Scanner;

public class larger{
	public static void main(String[] args)  {
		System.out.println("enter two numbers: ");
		Scanner in = new Scanner(System.in);
		int num1 = in.nextInt();
		int num2 = in.nextInt();
		if(num1>num2)
			System.out.println(num1 + " is larger");
		else if(num2>num1)
			System.out.println(num2 + " is larger");
		else
			System.out.println("These numbers are equal");
	}
}
		