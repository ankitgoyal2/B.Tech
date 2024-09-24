
import java.util.Scanner;
public class PascalTriangle {
	public static int fact(int n)
	{
		if(n==0)
			return 1;
		else
			return n*fact(n-1);
	}
	public static int ncr(int n, int r)
	{
		int res;
		res=fact(n)/(fact(r)*fact(n-r));
		return res;
	}
	public static void main(String args[])
	{
		System.out.print("enter no. of rows: ");
		Scanner in=new Scanner(System.in);
		int row=in.nextInt();
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<row-i-1;j++)
				System.out.print(" ");
			for(int j=0;j<=i;j++)
			{
				System.out.print(ncr(i,j)+ " ");
			}
			System.out.println();
		}
	}
}
