#include <bits/stdc++.h>
using namespace std;
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}
bool in(int &x) {
//	return scanf("%lf", &x);		// double
	return scanf("%d", &x);			// int
//	return scanf("%lld", &x);			// long long int
}
void ot(int x) {
	printf("%d ", x);
//	printf("%lld ", x);		//  	long long int
//	printf("%.3lf ", x);
}
#define all(v) ((v).begin(),(v).end())
#define sz(v) ((int)((v).size()))
#define cl(v,d) memset(v,d,sizeof(v))
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
const int N = 1e3 + 5;
typedef long long int lli;
typedef vector<lli> vi;
typedef pair<int, int> ii;

int ar[] { 1, 2, 3, 1 }, n;
lli mem[5][1001];
lli slv(int ii, int sm) {
	if (sm == n) {
		return 1;
	}
	if (mem[ii][sm] != -1)
		return mem[ii][sm];
	lli ret = 0;
	for (int i = 0; i < 4; ++i)
		if (sm + ar[i] <= n)
			ret += slv(i, sm + ar[i]);
	return mem[ii][sm] = ret;
}

int main() {
	file();

	lli dp[1001] { 0 };
	dp[0] = 1, dp[1] = 2, dp[2] = 5, dp[3] = 13;
	for (int i = 4; i < 1001; ++i)
		dp[i] = 2 * dp[i - 1] + dp[i - 2] + dp[i - 3];
	while (cin >> n)
		mem(mem, -1), cout << slv(0, 0) << "\n";
//		cout << dp[n] << "\n";
	/*
	 *
	 * java
	 import java.math.BigInteger;
	 import java.util.Arrays;
	 import java.util.Scanner;

	 public class Main {

	 public static void main(String[] args) {
	 // TODO Auto-generated method stub
	 Scanner input = new Scanner (System.in);
	 BigInteger dp [] = new BigInteger [1000 + 10];

	 Arrays.fill(dp, BigInteger.ZERO);

	 dp [0] = BigInteger.valueOf(1);
	 dp [1] = BigInteger.valueOf(2);
	 dp [2] = BigInteger.valueOf(5);
	 dp [3] = BigInteger.valueOf(13);

	 for ( int i = 4; i <= 1000; i++ ) {
	 dp [i] = dp [i].add(dp [i - 1]);
	 dp [i] = dp [i].add(dp [i - 2]);
	 dp [i] = dp [i].add(dp [i - 3]);
	 dp [i] = dp [i].add(dp [i - 1]);
	 }

	 int n;

	 while ( input.hasNextInt() ) {
	 n = input.nextInt();
	 System.out.println (dp [n]);
	 }
	 }
	 }
	 *
	 */
	return 0;
}
