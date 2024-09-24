
import java.util.Scanner;

import area.*;

public class FindArea {
	public static void main(String []args){
		System.out.println("You can find the area for ");
		System.out.println("1. square");
		System.out.println("2. rectangle");
		System.out.println("3. circle");
		System.out.println("4. elipse");
		System.out.println("5. triangle");
		while(true){
		System.out.println("enter choice");
		int choice ;
		Scanner in = new Scanner(System.in);
		choice = in.nextInt();
		switch(choice)
		{
		case 1 :
		{
			Square s = new Square();
			System.out.println("enter side");
			double side = in.nextDouble();
			s.putside(side);
			System.out.println("area of square = " + s.get_area());
			break;
		}
		case 2 :
		{
			Rectangle r = new Rectangle();
			System.out.println("enter length and breadth");
			double length = in.nextDouble();
			double breadth = in.nextDouble();
			r.putsides(length,breadth);
			System.out.println("area of rectangle = " + r.get_area());
			break;
		}
		case 3 :
		{
			Circle c = new Circle();
			System.out.println("enter radius");
			double rad = in.nextDouble();
			c.putrad(rad);
			System.out.println("area of circle = " + c.get_area());
		
		break;
		}
		case 4 :
		{
			Elipse e = new Elipse();
			System.out.println("enter major and minor axes");
			double major = in.nextDouble();
			double minor = in.nextDouble();
			e.putaxes(major,minor);
			System.out.println("area of rectangle = " + e.get_area());
			break;
		}
		case 5 :
		{
			Triangle t = new Triangle();
			System.out.println("enter base and height");
			double base = in.nextDouble();
			double height = in.nextDouble();
			t.putdims(base, height);;
			System.out.println("area of rectangle = " + t.get_area());
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
