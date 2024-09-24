package lab_9;
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="KeyEvents" width=300 height=100>
</applet>
*/

public class KeyEvents extends Applet implements KeyListener {
	
		String msg = "";
		int X = 10, Y = 20;
		
		public void init() {
			addKeyListener(this);
		}
		
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
		
		public void paint(Graphics g) {
			g.drawString(msg, X, Y);
		}

}
