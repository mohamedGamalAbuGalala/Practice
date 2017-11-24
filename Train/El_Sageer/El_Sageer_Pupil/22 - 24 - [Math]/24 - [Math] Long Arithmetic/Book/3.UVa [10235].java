import java.util.Scanner;
import java.math.BigInteger;

class Main { /* Simply Emirp, 2.788s in Java */
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int N = sc.nextInt();
      BigInteger BN = BigInteger.valueOf(N);
      String R = new StringBuffer(BN.toString()).reverse().toString();
      int RN = Integer.parseInt(R);
      BigInteger BRN = BigInteger.valueOf(RN);
      System.out.printf("%d is ", N);
      if (!BN.isProbablePrime(10)) // certainty 10 is enough for most cases
        System.out.println("not prime.");
      else if (N != RN && BRN.isProbablePrime(10))
        System.out.println("emirp.");
      else
        System.out.println("prime.");
} } }
