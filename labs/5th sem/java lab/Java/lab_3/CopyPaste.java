
/*import java.util.Scanner;

public class CopyPaste {

	public static void main(String[] args) {
		int n , a , b, c, d;
		System.out.println("enter the number of elements in array and the position for copying  (source and destination) and pasting (source and destination");
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();
		d = in.nextInt();
		if( ( a<0 || a>n-1 ) || ( b<0 || b>n-1 ) || ( c<0 || c> n-1 ) || ( d <0 || d>n-1 ) || (b-a + c >n-1) )
		{	System.out.println("enter valid positions");
		in.close();
		return ;
		}
		int arr[] = new int[n];
		System.out.println("enter the elements of array");
		for(int i=0;i<n;i++)
		{
			arr[i] = in.nextInt();
		}
		System.out.println("the given array is");
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]+ " ");
		}
		System.arraycopy(arr, a, arr, c, b-a+1);
		System.out.println("\nthe updated array is");
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i] + " ");
		}
		in.close();
		return ;
	}

}*/

import java.util.*;

class CopyPaste{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size of array: ");
		int size=sc.nextInt();
		int[] arr= new int[size];
		int i,j,length;
		System.out.println("Enter elements of array: ");
		
		for(i=0;i<size;i++){
			arr[i]=sc.nextInt();
		}
		
		int sCopy,eCopy,sPaste;
		int choice=1;
		while(choice==1){
			System.out.println("Enter starting and ending index for copying");
	        sCopy=sc.nextInt();
	        eCopy=sc.nextInt();
	        if(sCopy<0 || eCopy>=size){
	        	System.out.println("Error: Indices out of bound ");
	        } else {
		        length=eCopy-sCopy+1;
		        int[] copiedArray= new int[length];
		    	for(i=sCopy,j=0;i<=eCopy;i++,j++){
		        	copiedArray[j]=arr[i];
		    	}
		   
		        System.out.println("Enter starting index for pasting");
		        sPaste=sc.nextInt();
		        sPaste++;
		        if(sPaste+length<size){
			        for(i=sPaste-1,j=0;i<sPaste+length-1;i++,j++){
			        	arr[i]=copiedArray[j];
			        }
			        for(i=0;i<size;i++){
			            System.out.print(arr[i]+" ");
			        }
    			}
      		}

      		System.out.println("\nDo you want to continue: ");
      		choice = sc.nextInt();
		}
	}
}

