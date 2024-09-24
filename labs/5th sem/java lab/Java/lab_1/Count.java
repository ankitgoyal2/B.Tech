public class Count {
	public static void main(String[] args){
		int cnt=args.length;
		System.out.println("no. of arguments is " + cnt + "\n");
		for(int i=0;i<cnt;i++){
			System.out.println(args[i] + " ");
		}
	}
}
