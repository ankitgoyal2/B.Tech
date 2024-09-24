
import java.util.*;

class NewThread4 implements Runnable {

String name;
Thread t;
long  click=0;
private volatile boolean running=true;
 NewThread4(String threadname,int p){

     name=threadname;
     t=new Thread(this,name);
     System.out.println("New thread: "+t);
     t.setPriority(p);
     t.start();
 }

 public void run()
 {
     while(running)
        click++;
 }

 public void stop()
 {
     running=false;
 }


 public void frequency()
 {
     System.out.println("no. of clicks "+name+" "+click);
 }

 }

public class MultiThreadWithPrioirty{

 public static void main(String args[]){
         NewThread4 one= new NewThread4("One",Thread.MIN_PRIORITY);
         NewThread4 two= new NewThread4("Two",Thread.NORM_PRIORITY);
         NewThread4 three= new NewThread4("Three",Thread.MAX_PRIORITY);



          try{
              Thread.sleep(100);
          }
          catch(InterruptedException e)
          {

          }

          one.stop();
          two.stop();
          three.stop();

          one.frequency();
          two.frequency();
          three.frequency();

          System.out.println("main thread exiting");      }

           }


