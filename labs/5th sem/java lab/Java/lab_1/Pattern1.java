
import java.util.Scanner;
public class Pattern1 {
	public static void printBox(int n)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1 || i==n)
			{
				for(int j=1;j<=n;j++)
					System.out.print("*");
			}
			else
			{
				System.out.print("*");
				for(int j=1;j<=n-2;j++)
					System.out.print(" ");
				System.out.print("*");
			}
			System.out.println();
		}
	}
	public static void printOval(int n)
	{
		int t=(n-3)/4;
		for(int i=1;i<=n;i++)
		{
			if(i==1 || i==n)
			{
				for(int j=1;j<=t+1;j++)
					System.out.print(" ");
				for(int j=1;j<=2*t+1;j++)
					System.out.print("*");
			}
			else if(i>1 && i<=t+1)
			{
				for(int j=1;j<=t-i+2;j++)
					System.out.print(" ");
				System.out.print("*");
				for(int j=1;j<=2*t+1+2*(i-2);j++)
					System.out.print(" ");
				System.out.print("*");
			}
			else if(i>t+1 && i<(3*t+3))
			{
				System.out.print("*");
				for(int j=1;j<=4*t+1;j++)
					System.out.print(" ");
				System.out.print("*");
			}
			else
			{
				int k=n-i+1;
				for(int j=1;j<=t-k+2;j++)
					System.out.print(" ");
				System.out.print("*");
				for(int j=1;j<=2*t+1+2*(k-2);j++)
					System.out.print(" ");
				System.out.print("*");
			}
			System.out.println();
		}
	}
	public static void printArrow(int n)
	{
		for(int i=0;i<n/2+1;i++)
        {
            for(int j=0;j<n/2-i;j++)
            {
                System.out.print(" ");
            }
            
            for(int j=0;j<2*i+1;j++)
            {
                 System.out.print("*");
            }
            
            System.out.print("\n");
        }
        
        for(int i=0;i<n/2+2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                System.out.print(" ");
            }
            System.out.print("*\n");
        }
	}
	static void printDiamond(int n)
    {
        for(int i=0;i<n/2+1;i++)
        {
            for(int j=0;j<n/2-i;j++)
            {
                System.out.print(" ");
            }
            
            System.out.print("*");
            
            for(int j=0;j<2*i-1;j++)
            {
                System.out.print(" ");
            }
            
            if(i>0)
            System.out.print("*");
            
            System.out.print("\n");
        }
        
        for(int i=n/2-1;i>=0;i--)
        {
            
            for(int j=0;j<n/2-i;j++)
            {
                System.out.print(" ");
            }
            
            System.out.print("*");
            
            for(int j=0;j<2*i-1;j++)
            {
                System.out.print(" ");
            }
            
            if(i>0)
            
            System.out.print("*");
            System.out.print("\n");
        }
    }
	public static void main(String args[])
	{
		System.out.println("1.print a box");
		System.out.println("2.print a oval");
		System.out.println("3.print a arrow");
		System.out.println("4.print a diamond");
		System.out.println("5.exit");
		int t=1;
		while(t==1)
		{
			System.out.print("enter your choice");
			Scanner in = new Scanner(System.in);
			int ch=in.nextInt();
			switch(ch)
			{
			case 1:
				System.out.print("enter no .of rows");
				int n=in.nextInt();
				printBox(n);
				break;
			case 2:
				System.out.print("enter no .of rows in 4n+3");
				int m=in.nextInt();
				printOval(m);
				break;
			case 3:
				System.out.print("enter no .of rows in 2n+1");
				int r=in.nextInt();
				printArrow(r);
				break;
			case 4:
				System.out.print("enter no .of rows in 2n+1");
				int d=in.nextInt();
				printDiamond(d);
				break;
			case 5:
				t=0;
				break;
			}
		}
	}
}
