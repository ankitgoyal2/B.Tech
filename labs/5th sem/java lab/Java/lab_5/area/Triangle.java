package lab_5.area;

public class Triangle {
	double base, height;
	public void putdims(double base, double height){
		this.base=base;
		this.height=height;
	}
	public double get_area()
	{
		return 0.5*base*height;
	}

}
