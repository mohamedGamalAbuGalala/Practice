import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger n ;
		while(sc.hasNext())
		{
			n = new BigInteger(sc.next());
			if(n.equals(BigInteger.ZERO))
				System.out.println(1);
			else
				System.out.println(n.multiply(n.subtract(BigInteger.ONE)).add(BigInteger.valueOf(2)));
		}
	}
}
