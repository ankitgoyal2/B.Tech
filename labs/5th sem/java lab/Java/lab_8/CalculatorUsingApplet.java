package lab_8;
import java.util.Scanner;
import java.applet.Applet; 
import java.awt.Graphics; 
import java.awt.*;  
import java.awt.event.*; 
/*class AdapterExample extends WindowAdapter{  
    Frame f;  
    AdapterExample(){  
        f=new Frame();  
        f.addWindowListener(this);  
          
        f.setSize(400,400);  
        f.setLayout(null);  
        f.setVisible(true);  
    }  
public void windowClosing(WindowEvent e) {  
    f.dispose();  
}}  */
public class CalculatorUsingApplet extends Applet
{
	
	public void paint(Graphics g) 
	{ 
		Applet ap = new Applet();
		Scanner in = new Scanner(System.in);
		int a , b;
		System.out.println("enter two integers");
		a = in.nextInt();
		b = in.nextInt();
		g.drawString("Addition  " + (a+b) , 0 , 10); 
		g.drawString("Substraction  " + (a-b) , 0 , 20);
		g.drawString("Multiplicatoin  " + (a*b) ,0 , 30);
		g.drawString("division  " + (a /b)  , 0 , 40);
		//ap.destroy();
		//new AdapterExample();  
	} 
}
/*import java.awt.*;
import java.applet.*;
import java.awt.event.*;


public class CalculatorUsingApplet extends Applet implements ActionListener{

	int n1,n2,ans;

	TextField t1= new TextField(10);
	TextField t2= new TextField(10);
	TextField plus= new TextField(5);
	TextField minus= new TextField(5);
	TextField mult= new TextField(5);
	TextField divide= new TextField(5);


	public void init(){
	
		t2.addActionListener(this);
		add(new Label("First number")); add(t1);
		add(new Label("Second number")); add(t2);
		add(new Label("Sum :")); add(plus);
		add(new Label("Difference :")); add(minus);
		add(new Label("Product :")); add(mult);
		add(new Label("Difference :")); add(divide);
	}

	public void actionPerformed(ActionEvent e){
		double n1= Double.parseDouble(t1.getText(
		double n2= Double.parseDouble(t2.getText(

		double sum= n1+n2;
		double diff= n1-n2;
		double prod= n1*n2;
		double div= n1/n2;
	
		plus.setText(""+sum);
		minus.setText(""+ diff);
		mult.setText(""+prod);
		divide.setText(""+div);
	}

	public void paint(Graphics g){}
}*/

