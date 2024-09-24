package lab_5.area;

public class Rectangle {
	double length, breadth;
	public void putsides(double length, double breadth){
		this.length=length;
		this.breadth=breadth;
	}
	public double get_area()
	{
		return length*breadth;
	}

}
