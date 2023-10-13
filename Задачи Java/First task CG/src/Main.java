import com.sun.source.tree.Tree;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class DrawingPanel extends JFrame implements ActionListener {
    private final int BACKGROUND_WIDHT = 800;
    private final int BACKGROUND_HEIGHT = 800;
    private final int TIMER_DELAY = 1000;
    private final Timer timer = new Timer(TIMER_DELAY, this);
    private int ticksFormStart = 0;

    public DrawingPanel() {
        setTitle("Drawing panel");
        setSize(BACKGROUND_WIDHT, BACKGROUND_HEIGHT);
        setVisible(true);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        timer.start();
    }

    public static void roadLine(Graphics2D g2d, int num, int ticksFormStart) {
        g2d.setColor(Color.WHITE);
        g2d.drawRect(-75 + (num * 100) - (ticksFormStart * 20), 662, 50, 25);
        g2d.fillRect(-75 + (num * 100) - (ticksFormStart * 20), 662, 50, 25);
    }

    public static void roadLines(Graphics2D g2d, int ticksFormStart) {
        int num = 1;
        while (num < 10000){
            roadLine(g2d, num, ticksFormStart);
            num++;
        }
    }

    public static void cloude1(Graphics2D g2d, int num, int ticksFormStart) {
        g2d.setColor(Color.GRAY);
        g2d.drawOval(-625 + (num * 575) - (ticksFormStart * 20), 150, 150, 50);
        g2d.fillOval(-625 + (num * 575) - (ticksFormStart * 20), 150, 150, 50);


        g2d.drawOval(-540 + (num * 575) - (ticksFormStart * 20), 175, 100, 50);
        g2d.fillOval(-540 + (num * 575) - (ticksFormStart * 20), 175, 100, 50);
    }
    public static void cloude2 (Graphics2D g2d, int num, int ticksFormStart) {
        g2d.setColor(Color.WHITE);
        g2d.drawOval(-425 + (num * 600) - (ticksFormStart * 20), 100, 200, 100);
        g2d.fillOval(-425 + (num * 600) - (ticksFormStart * 20), 100, 200, 100);


        g2d.drawOval(-275 + (num * 600) - (ticksFormStart * 20), 100, 100, 50);
        g2d.fillOval(-275 + (num * 600) - (ticksFormStart * 20), 100, 100, 50);
    }

    public static void clouds (Graphics2D g2d, int ticksFormStart) {
        int num = 1;
        while (num < 10000){
            cloude1(g2d, num, ticksFormStart);
            cloude2(g2d, num, ticksFormStart);
            num++;
        }
    }

    public static void bigTree (Graphics2D g2d, int num, int ticksFormStart) {
        g2d.setColor(Color.ORANGE);
        g2d.drawRect(-300 + (num * 350) - (ticksFormStart * 20), 300, 50, 250);
        g2d.fillRect(-300 + (num * 350) - (ticksFormStart * 20), 300, 50, 250);
        g2d.setColor(Color.GREEN);
        g2d.drawOval(-320 + (num * 350) - (ticksFormStart * 20), 280,100,100);
        g2d.fillOval(-320 + (num * 350) - (ticksFormStart * 20), 280,100,100);

        g2d.drawOval(-275 + (num * 350) - (ticksFormStart * 20), 330,70,70);
        g2d.fillOval(-275 + (num * 350) - (ticksFormStart * 20), 330,70,70);

        g2d.drawOval(-305 + (num * 350) - (ticksFormStart * 20), 350,70,70);
        g2d.fillOval(-305 + (num * 350) - (ticksFormStart * 20), 350,70,70);

        g2d.drawOval(-335 + (num * 350) - (ticksFormStart * 20), 330,70,70);
        g2d.fillOval(-335 + (num * 350) - (ticksFormStart * 20), 330,70,70);
    }

    public static void smallTree (Graphics2D g2d, int num, int ticksFormStart) {
        g2d.setColor(Color.ORANGE);
        g2d.drawRect(-125 + (num * 350) - (ticksFormStart * 20), 400, 50, 150);
        g2d.fillRect(-125 + (num * 350) - (ticksFormStart * 20), 400, 50, 150);
        g2d.setColor(Color.GREEN);
        g2d.drawOval(-145 + (num * 350) - (ticksFormStart * 20), 380,90,90);
        g2d.fillOval(-145 + (num * 350) - (ticksFormStart * 20), 380,90,90);

        g2d.drawOval(-100 + (num * 350) - (ticksFormStart * 20), 430,60,60);
        g2d.fillOval(-100 + (num * 350) - (ticksFormStart * 20), 430,60,60);

        g2d.drawOval(-130 + (num * 350) - (ticksFormStart * 20), 450,60,60);
        g2d.fillOval(-130 + (num * 350) - (ticksFormStart * 20), 450,60,60);

        g2d.drawOval(-160 + (num * 350) - (ticksFormStart * 20), 430,60,60);
        g2d.fillOval(-160 + (num * 350) - (ticksFormStart * 20), 430,60,60);
    }

    public static void trees(Graphics2D g2d, int ticksFormStart) {
        int num = 1;
        while (num < 10000){
            bigTree(g2d, num, ticksFormStart);
            smallTree(g2d, num, ticksFormStart);
            num++;
        }
    }

    @Override
    public void paint(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;

        g2d.setColor(Color.BLUE);
        g2d.fillRect(0, 0, BACKGROUND_WIDHT, BACKGROUND_HEIGHT);

        g2d.setColor(Color.GRAY);
        g2d.drawRect(0, 550, 800, 250);
        g2d.fillRect(0, 550, 800, 250);

        roadLines(g2d, ticksFormStart);
        trees(g2d, ticksFormStart);
        clouds(g2d, ticksFormStart);




    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == timer) {
            repaint();
            ++ticksFormStart;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        new DrawingPanel();
    }

}