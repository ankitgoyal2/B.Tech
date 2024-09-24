package lab_8;
import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

public class ColorChangeinApplet extends Applet {
    public void init() {
        // Here we change the default grey color background of an 
        // applet to yellow background.
        setBackground(Color.RED);
    }

    public void paint(Graphics g) {
        g.setColor(Color.BLUE);
        g.drawString("Background is RED and Foreground is BLUE", 0, 50);
    }
}