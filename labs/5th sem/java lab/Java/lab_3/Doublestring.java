
import java.util.Scanner;

public class Doublestring {

	public static void main(String[] args) {
		String a;
		Scanner in = new Scanner(System.in);
		System.out.println("enter a string");
		a = in.nextLine();
		if(a.length()%2 !=0)
		{
			System.out.println("this string is not a double string");
			in.close();
			return ;
		}
		else 
		{
			for(int i=0;i<a.length()/2;i++)
			{
				if(a.charAt(i)!=a.charAt(a.length()-1-i))
				{
					System.out.println("this strng is not a double string ");
					in.close();
					return ;
				}
			}
			System.out.println("this string is double string");
			in.close();
			return ;
		}

	}

}
