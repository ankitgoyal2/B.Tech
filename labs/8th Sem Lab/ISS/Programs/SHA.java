import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

public class SHA {
	public static String encryptThisString(String input)
	{
		try {
			
			MessageDigest md = MessageDigest.getInstance("SHA-512");

			
			byte[] messageDigest = md.digest(input.getBytes());

			
			BigInteger no = new BigInteger(1, messageDigest);

			
			String hashtext = no.toString(16);

			
			while (hashtext.length() < 32) {
				hashtext = "0" + hashtext;
			}

			
			return hashtext;
		}

		
		catch (NoSuchAlgorithmException e) {
			throw new RuntimeException(e);
		}
	}

	public static void main(String args[]) throws NoSuchAlgorithmException
	{

		System.out.println("Enter string to Encrypt");

        Scanner in = new Scanner(System.in);
        String s = in.nextLine();

		System.out.println("Encrypted string is " + encryptThisString(s));

	}
}
