package lab_8;
import java.awt.*;
import java.applet.*;
import java.net.*;

/*
<applet code="Bases" width=300 height=50>
</applet>
*/
public class URlshowing extends Applet {
	
	public void paint(Graphics g) {
		String msg;
		
		
		URL url = getCodeBase();
		msg = "Code base is: " + url.toString();
		g.drawString(msg, 10, 20);
		
		
		url = getDocumentBase(); 
		msg = "Document base is: " + url.toString();
		g.drawString(msg, 10, 40);
	}
}

