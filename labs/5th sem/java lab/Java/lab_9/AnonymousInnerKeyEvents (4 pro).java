package lab_9;
import java.applet.*;
import java.awt.Graphics;
import java.awt.event.*;
/*
<applet code="AnonymousInnerKeyEvents" width=200 height=100>
</applet>
*/
	
public class AnonymousInnerKeyEvents extends Applet {
	String msg = "";
	int X = 10, Y = 20;
	public void init() {
		addKeyListener(new KeyAdapter() {
	public void keyPressed(KeyEvent ke) {
	showStatus("key Pressed");
	}
	public void keyReleased(KeyEvent ke) {
		showStatus("Key Released");
	}
	
	public void keyTyped(KeyEvent ke) {
		msg += ke.getKeyChar();
		repaint();
	}
	});
	}
	public void paint(Graphics g) {
		g.drawString(msg, X, Y);
	}
}

