package lab_9;

import java.applet.*;
import java.awt.Graphics;
import java.awt.event.*;
/*
<applet code="InnerClassKeyEvents" width=200 height=100>
</applet>
*/
public class InnerClassKeyEvents extends Applet {
	
	String msg = "";
	int X = 10, Y = 20;
	
	public void init() {
		addKeyListener(new MyKeyAdapter());
	}
	class MyKeyAdapter extends KeyAdapter {
		
		
		
		public void keyPressed(KeyEvent ke) {
			showStatus("Key Pressed");
		}
		
		public void keyReleased(KeyEvent ke) {
			showStatus("Key Released");
		}
		
		public void keyTyped(KeyEvent ke) {
			msg += ke.getKeyChar();
			showStatus("Key typed");
			repaint();
		}
		
	}
	public void paint(Graphics g) {
		g.drawString(msg, X, Y);
	}
}
