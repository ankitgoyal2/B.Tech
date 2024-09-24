
import java.util.*;
public class Phythagoroustriplets {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a , b , c;
		System.out.println("Enter the sides of triangle");
		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();
		a =a*a;
		b =b*b;
		c = c*c;
		if(((a == b+c) || (b == a+c) ) || (c ==a+b) )
			System.out.println("the given numbers are phythagorous triplets");
		else System.out.println("the given numbrs are not phytagorous triplets");

	}

}
