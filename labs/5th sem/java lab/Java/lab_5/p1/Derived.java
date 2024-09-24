package lab_5.p1;

public class Derived extends Protection {

    public int stuff = 23421;

    public void print() {
        System.out.println("I am a function of Derived class");
    }

    public void printProtected() {
        System.out.println("I can access the protected variable of Protection class. Its value is: " + stringVariable);
    }

    
}
