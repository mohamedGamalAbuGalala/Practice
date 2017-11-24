import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		BigInteger m = BigInteger.valueOf(17);
		Scanner sc = new Scanner(System.in);
		while (true) {
			String n = sc.next();
			if (n.equals("0"))
				break;
			System.out.println((new BigInteger(n).mod(m).compareTo(BigInteger.ZERO) == 0) ? 1 : 0);
		}
	}
}
