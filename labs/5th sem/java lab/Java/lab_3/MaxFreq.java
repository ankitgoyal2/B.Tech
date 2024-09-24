
import java.util.Scanner;

public class MaxFreq {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("enter no. of elements");
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int []v = new int[n];
		for(int i=0;i<n;i++)
		{
			v[i]=in.nextInt();
		}
		int maxcount=0;
		int i=0;
		while(i<n-1)
		{
			int count=1;
			while(i<n-1 && v[i]==v[i+1])
			{
				count++;
				i++;
			}
			if(maxcount<count)
				maxcount=count;
			i++;
		}
		System.out.println("output is "+ maxcount);
	}

}
