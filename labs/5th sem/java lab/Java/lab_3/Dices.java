

public class Dices {

	public static void main(String[] args) {
		
		int[][] arr = new int[6][6];
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				arr[i][j]=i+j+2;
			}
		}
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<6;j++)
			{
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}

	}

}
