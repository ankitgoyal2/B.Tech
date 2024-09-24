
import java.util.*;

public class Stringimplement {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("You can perform the following operation ");
		System.out.println("1. to convert the string to lower case");
		System.out.println("2. To convert the string to upper case");
		System.out.println("3. To replace a character in entire string");
		System.out.println("4. To check if two strings are equal");
		System.out.println("5. To check the length of string ");
		System.out.println("6. To find a character at given poistion");
		System.out.println("7. To concate two strings");
		System.out.println("8. To return   substring of a string from a specified position");
		while(true){
		int choice ;
		System.out.print("enter your choice: ");
		choice = in.nextInt();
		//System.out.println();
		switch(choice)
		{
		case 1 :
		{
			String a ;
			System.out.println("enter string: ");
			a = in.next();
			a = a.toLowerCase();
			System.out.println("in lower case: "+ a);
			break;
		}
		case 2 :
		{
			String a;
			System.out.print("enter string: ");
			a = in.next();
			a = a.toUpperCase();
			System.out.println("in upper case: " + a);
			break;
		}
		case 3 :
		{
			String a;
			System.out.print("enter string: ");
			a = in.next();
			char b,c;
			System.out.println("enter the character to replace with another  character");
			b = in.next().charAt(0);
			c = in.next().charAt(0);
			a = a.replace(b, c);
			System.out.println("the new string is:  "+ a);
			break;
		}
		case 4 :
		{
			String a , b;
			System.out.print("enter two string: ");
			a = in.next();
			b = in.next();
			if(a.equals(b))
			{
				System.out.println("these strings are equal");
			}
			else System.out.println("these strings are not equal");
			break;
		}
		case 5 :
		{
			String a;
			System.out.print("enter string: ");
			a = in.next();
			System.out.println("the length of the string is "+ a.length());
			break;
		}
		case 6 :
		{
			String a;
			System.out.print("enter string: ");
			a = in.next();
			int b;
			System.out.print("enter a position  to find the character: ");
			b = in.nextInt();
			if(b<0||b>a.length() -1)
			{
				System.out.println("enter  a valid position");
			}
			else System.out.println("the character at the "+ (b+1)+ "th position is "+ a.charAt(b));
			break;
		}
		case 7 :
		{
			System.out.print("enter two string: ");
			String a = in.next();
			String b = in.next();
			System.out.println("the concatenated string is "+ a.concat(b));
			break;
		}
		case 8 :
		{
			int b;
			System.out.print("enter string: ");
			String a = in.next();
			System.out.print("enter a positoin to find the substring: ");
			b = in.nextInt();
			if(b<0 || b> a.length()-1)
			{
				System.out.println("enter a valid positoin");
				
			}
			else
			{
				System.out.println("the required substring is "+ a.substring(b));
			}
			break;
		}
		default :
		{
			System.out.println("enter  a valid choice");
			in.close();
			return ;
		}
		}
			
		}
	}

}
