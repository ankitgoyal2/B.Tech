package lab_5;

import lab_5.p1.*;
import lab_5.p2.*;

class Problem1 {

    public static void main(String[] args) {
        Protection p = new Protection();
        System.out.println("Public Variable's value : "+ p.publicVariable);
        System.out.println("\n\nThe variables and functions of Protection class are: ");
        // System.out.println("Protected Varible: "  + stringVariable);
        System.out.println("Can't access Private and Protected variables\n\n");

        Derived d = new Derived();
        System.out.println("The variables and functions of Derived class are: ");
        System.out.println("Public variable's value : " + d.stuff);
        d.print();
        d.printProtected();
        System.out.println("\n\n");

        SamePackage s = new SamePackage();
        System.out.println("The variables and functions of SamePackage class are: ");
        System.out.println("The default variable of this class is not visible.");
        System.out.println("The protected variable of this class is not visible.\n\n");

        first f = new first();
        System.out.println("The variables and functions of first class are: ");
        System.out.println("The default variable of the class is not accessible.");
        System.out.println("Public variable's value is : " + f.anyName + "\n\n");

        second sec = new second();
        System.out.println("The default variables of the class are not accessible.");
        System.out.println("But there is a public function. Lets call that : ");
        sec.print();
        System.out.println("\n\n");
    }
}
