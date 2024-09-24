package lab_8;
//import java.util.*;
import java.applet.Applet; 
import java.awt.Graphics; 
public class Pattern extends Applet
{
	public void paint(Graphics g) 
	{ 
		String s = "****";
		g.drawString(s,0 ,  10);
		g.drawString(s, 5, 20);
		g.drawString(s, 0, 30);
		g.drawString(s, 5, 40); 
		System.out.println("hello");
	} 
	
}
