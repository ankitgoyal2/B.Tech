package lab_5.area;

public class Elipse {
	double major, minor;
	public void putaxes(double major, double minor){
		this.major=major;
		this.minor=minor;
	}
	public double get_area()
	{
		return 3.14*major*minor;
	}

}
