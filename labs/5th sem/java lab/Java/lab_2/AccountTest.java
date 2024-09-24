
import java.util.Scanner;

class Account
{
public int balance;
Account(int a)
{
	this.balance = a;
}
}
public class AccountTest {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int amt;
		System.out.print("enter amount: ");
		amt = in.nextInt();
		Account obj = new Account(amt);
		int debit ;
		System.out.print("enter amount u want to debit: ");
		debit = in.nextInt();
		if(debit > obj.balance)
		{
			System.out.println("Debit balance exceeded from the current balance");
			System.out.println("new balance is " + obj.balance);
			
		}
		else
		{
			obj.balance = obj.balance - debit;
			System.out.println("Account debited successfully");
			System.out.println("new balance is "+ obj.balance);
		}
		in.close();
	}

}
