package lab_4.p2;

import lab_4.p1.*;
class anotherClass {

	public String variable = "This is my public Variable";
	void Public() {
		System.out.println("\nThe called function is my public.\n\n");
	}

	void CallingProblem1() {
		System.out.println("\nThis is the public member of the problem1 class of package1 : " + lab_4.p1.problem1.variable4);
	}
}
