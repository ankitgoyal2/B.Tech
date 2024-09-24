package lab_4.p1;

import java.util.*;

class mainClass {

	public static void main(String[] args) {

		System.out.println("\nAccessing the problem1b(which extends the problem1) variables and functions.");
		problem1b p1b = new problem1b();
		System.out.println("\nWow! I can access my public members here: " + p1b.stuff);
		System.out.println("\nAlso, I can use my parents function : ");
		p1b.CallMe();
	}
}