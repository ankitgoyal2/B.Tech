
import java.util.*;
public class circle {

	static final  double pi = 3.14;
	public static void main(String[] args) 
	{
		double r;
		System.out.print("enter radius of circle");
		Scanner in =  new Scanner(System.in);
		r = in.nextFloat();
		in.close();
		System.out.println("The diameter of the circle is "+ (2*r));
		System.out.println("The circumference of the circle is " + (2*pi*r));
		System.out.println("The Area of the circle is" + (pi * r* r ));
		
	}
		
}

