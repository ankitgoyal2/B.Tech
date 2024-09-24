
import java.util.Scanner;

class Employee
{
	public int  whour;
	public int salary;
	Employee()
	{
		this.whour =0;
		this.salary =0;
	}
}
public class Grosspay {

	public static void main(String[] args) {
		Employee[] arr  = new Employee[3];
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the salary per hour  and working hours for the three employees");
		for(int i=0;i<3;i++)
		{
			arr[i] = new Employee();
			arr[i].salary = in.nextInt();
			arr[i].whour = in.nextInt();
		}
		System.out.println("The amount paid to each employee at the end of the month is ");
		for(int i=0; i<3;i++)
		{
			if(arr[i].whour>40)
			{
				System.out.println("the amount paid to  "+ i + "th employee is " +( (40*arr[i].salary)  +( (arr[i].whour - 40 )* ( arr[i].salary / 2))) );
			}
			else
				System.out.println("the amount paid to "+ i + "th employee is " + arr[i].whour *arr[i].salary);
		}
			in.close();
	}

}
