/*
 *
 *#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

class Rectangle {
public:
	pair<int, int> lol, lor, ul, ur , center;
	Rectangle(pair<int, int> x, pair<int, int> y) {
		lol.first = x.first, ul.first = x.first, lol.second = x.second, lor.second =
				x.second, ur.first = y.first, lor.first = y.first, ur.second =
				y.second, ul.second = y.second;
	}
	Rectangle() {
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		pair<int, int> t[4];
		for (int i = 0; i < 4; ++i) {
			cin >> t[i].first >> t[i].second;
		}
		Rectangle r1(t[0], t[1]), r2(t[2], t[3]);
	}

	return 0;
}
 *
 *
 */
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <array>
#include <iterator>
#include <set>
#include <cmath>
#include<iomanip>	// Stew(10)		::        12	........ 8 spaces and 2 digits in 10 padding right

#define pb push_back
#define up upper_bound
#define lp lower_bound
#define pr pair<int,int>
#define ll long long int

using namespace std;

int main()
{

    int tc;
    cin >> tc;

    while(tc--) {
        int ax, ay, bx, by, cx, cy, dx, dy;

        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        int ans_LL_x, ans_LL_y, ans_UR_x, ans_UR_y;

        ans_LL_x = max(ax, cx);
        ans_LL_y = max(ay, cy);
        ans_UR_x = min(bx, dx);
        ans_UR_y = min(by, dy);

        if(ans_LL_x >= ans_UR_x || ans_LL_y >= ans_UR_y)
            cout << "No Overlap\n";
        else
            cout << ans_LL_x << ' ' << ans_LL_y << ' ' << ans_UR_x << ' ' << ans_UR_y << '\n';

        if(tc) cout << '\n';
    }
}

