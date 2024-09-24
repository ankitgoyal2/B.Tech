
/*class Student {
	int rollNo;
	public void putRollNo(int rollNo){
		this.rollNo = rollNo;
	}
}
class Test extends Student {
	int marks1,marks2;
	public void puttest(int marks1, int marks2){
		this.marks1 = marks1;
		this.marks2 = marks2;
	}
	public int addMarks(){
		return marks1 + marks2;
	}
}
interface Sports {
	final int sportsMarks = 15;
	
}
class Result extends Test implements Sports {
	int total;
	
	public int total()
	{
		total = addMarks() + sportsMarks;
		return total;
	}
}
public class MarksCalculation {
	public static void main (String []args){
		Result r1= new Result();
		r1.putRollNo(17103091);
		r1.puttest(19, 18);
		//r1.putMarks(15);
		int totalMarks = r1.total();
		System.out.print("total marks are "+ totalMarks);
	}
	
}*/

import java.util.*;

class Student {

	int rollNumber;

	void SetRollNumber(int rollNumber) {
		this.rollNumber = rollNumber;
	}

	int GetRollNumber() {
		return this.rollNumber;
	}
}

class Test extends Student {

	int marks1, marks2;
	// int sportsMarks = 0;
	public void setMarks(int marks1, int marks2) {
		this.marks1 = marks1;
		this.marks2 = marks2;
	}

	int AddMarksUp() {
		return this.marks1 + this.marks2;
	}
}

interface Sports {

	public void setSportsMarks(int sM);
	public int putMarks();
}

class Result extends Test implements Sports {

	int sportsMarks;
	
	public void setSportsMarks(int sM) {
		sportsMarks = sM;
	}

	public int putMarks() {
		int totalMarks = sportsMarks + marks1 + marks2;
		return totalMarks;
	}
}



class MarksCalculation {

	public static void main(String[] args) {

		Result R = new Result();

		Test T = new Test();
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the marks in the two tests: ");
		int marks1 = input.nextInt();
		int marks2 = input.nextInt();
		T.setMarks(marks1, marks2);

		System.out.println("Enter the marks in the sports test: ");
		int sportsMarks = input.nextInt();
		R.setSportsMarks(sportsMarks);
		R.marks1 = T.marks1;
		R.marks2 = T.marks2;
		System.out.println("\nThe result is finally out : " + R.putMarks());
	}
}
