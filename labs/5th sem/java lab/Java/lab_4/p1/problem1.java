package lab_4.p1;

public class problem1 {

	public int variable1 = 1234;	// accessible to other classes and other packages also

	protected String variable2 = " Java is Beautiful";	// only accessible to the base classes of class Problem1

	private float variable3 = 2.345f;	// not accessible outside this class

	static public int variable4 = 4321;

	void CallMe() {
		System.out.println("Calling a function of the problem1 class\n");
		System.out.println("We have called you. And you answered, so nice of you! I think you are default or public(may be protected if  I am your child:)");
	}
	// this function acts as public within this package and private outside.
}