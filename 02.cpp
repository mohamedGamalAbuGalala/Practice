#include <bits/stdc++.h>
using namespace std;
void fl()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define iln() scanf("\n")          //scan new line
#define sp() printf(" ")           //output single space
#define ln() printf("\n")          //output new line
#define in(n) scanf("%d", &n)      //scan int
#define ot(x) printf("%d", x)      //output int
#define ins(n) scanf("%s", n)      //scan char[]
#define ots(x) printf("%s", x)     //output char[]  ( be careful using it may have some issue )
#define inc(n) scanf("%c", &n)     //scan char
#define otc(x) printf("%c", x)     //output char
#define inf(n) scanf("%lf", &n)    //scan double/float
#define otf(x) printf("%.12lf", x) // output double/float with 0.00
#define inl(n) scanf("%lld", &n)   //scan long long int
#define otl(x) printf("%lld", x)   //output long long int

#define forr(i, j, n) for (int i = j; i < n; i++)
#define frr(i, j, n) for (int i = j; i >= n; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size())) // eg... vector<int> v; sz(v)
#define pb push_back
#define ssz(s) ((int)strlen(s)) // eg... char s[10];  ssz(s)
#define mem(a, b) memset(a, b, sizeof(a))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const int MN = 1e6 + 1e1;
const int OO = 1e9 + 5;
// typedef vector<ii> vii;
typedef vector<int> vi;

#define F first
#define S second
typedef pair<int, int> ii;

bool cmp(ii b, ii a)
{
    return b.F < a.F ? 1 : b.F == a.F ? b.S < a.S : 0;
}

int widestGap(int n, vector<int> start, vector<int> finish)
{
    vector<ii> positions;

    // push the start point
    positions.push_back(ii{0, 0});

    // push car positions into vector<ii>
    for (int i = 0; i < start.size(); i++)
    {
        ii pair;
        pair.F = start[i];
        if (i < finish.size())
            pair.S = finish[i];
        else
            pair.S = n;

        positions.push_back(pair);
    }

    // sort based on F, then the S
    sort(positions.begin(), positions.end(), cmp);

    // push the end point
    positions.push_back(ii{n + 1, n + 1});

    int maxGap = 0;

    for (int i = 0; i < positions.size(); i++)
    {
        int maxEnd = positions[i].S;
        int j = i + 1;
     #include <bits/stdc++.h>
using namespace std;
void fl()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
//	freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}
#define iln() scanf("\n")          //scan new line
#define sp() printf(" ")           //output single space
#define ln() printf("\n")          //output new line
#define in(n) scanf("%d", &n)      //scan int
#define ot(x) printf("%d", x)      //output int
#define ins(n) scanf("%s", n)      //scan char[]
#define ots(x) printf("%s", x)     //output char[]  ( be careful using it may have some issue )
#define inc(n) scanf("%c", &n)     //scan char
#define otc(x) printf("%c", x)     //output char
#define inf(n) scanf("%lf", &n)    //scan double/float
#define otf(x) printf("%.12lf", x) // output double/float with 0.00
#define inl(n) scanf("%lld", &n)   //scan long long int
#define otl(x) printf("%lld", x)   //output long long int

#define forr(i, j, n) for (int i = j; i < n; i++)
#define frr(i, j, n) for (int i = j; i >= n; i--)
#define all(v) v.begin(), v.end()
#define sz(v) ((int)((v).size())) // eg... vector<int> v; sz(v)
#define pb push_back
#define ssz(s) ((int)strlen(s)) // eg... char s[10];  ssz(s)
#define mem(a, b) memset(a, b, sizeof(a))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
const int MN = 1e6 + 1e1;
const int OO = 1e9 + 5;
// typedef vector<ii> vii;
typedef vector<int> vi;

#define F first
#define S second
typedef pair<int, int> ii;

bool cmp(ii b, ii a)
{
    return b.F < a.F ? 1 : b.F == a.F ? b.S < a.S : 0;
}

int widestGap(int n, vector<int> start, vector<int> finish)
{
    vector<ii> positions;

    // push the start point
    positions.push_back(ii{0, 0});

    // push car positions into vector<ii>
    for (int i = 0; i < start.size(); i++)
    {
        ii pair;
        pair.F = start[i];
        if (i < finish.size())
            pair.S = finish[i];
        else
            pair.S = n;

        positions.push_back(pair);
    }

    // sort based on F, then the S
    sort(positions.begin(), positions.end(), cmp);

    // push the end point
    positions.push_back(ii{n + 1, n + 1});

    int maxGap = 0;

    for (int i = 0; i < positions.size(); i++)
    {
        int maxEnd = positions[i].S;
        int j = i + 1;
        // scanning the current covered area
        for (; j < positions.size() && positions[j].F < maxEnd; j++)
            // update the maximum end so far
            if (positions[j].S > maxEnd)
                maxEnd = positions[j].S;

        i = j - 1;
        // caught a gap
        if (i < positions.size() - 1 && maxEnd < positions[i + 1].F)
            // calculate the current gap and take the bigger
            maxGap = max(maxGap, positions[i + 1].F - (maxEnd + 1));
    }
    return maxGap;
}

int main()
{         // dfil
    fl(); //TODO
    int n, m;
    vi start;
    vi finish;
    in(n), iln(), in(m), iln();
    forr(i, 0, m)
    {
        int x;
        in(x), iln();
        start.push_back(x);
    }
    in(m), iln();
    forr(i, 0, m)
    {
        int x;
        in(x), iln();
        finish.push_back(x);
    }
    cout << widestGap(n, start, finish);
    return 0;
}   // scanning the current covered area
        for (; j < positions.size() && positions[j].F < maxEnd; j++)
            // update the maximum end so far
            if (positions[j].S > maxEnd)
                maxEnd = positions[j].S;

        i = j - 1;
        // caught a gap
        if (i < positions.size() - 1 && maxEnd < positions[i + 1].F)
            // calculate the current gap and take the bigger
            maxGap = max(maxGap, positions[i + 1].F - (maxEnd + 1));
    }
    return maxGap;
}

int main()
{         // dfil
    fl(); //TODO
    int n, m;
    vi start;
    vi finish;
    in(n), iln(), in(m), iln();
    forr(i, 0, m)
    {
        int x;
        in(x), iln();
        start.push_back(x);
    }
    in(m), iln();
    forr(i, 0, m)
    {
        int x;
        in(x), iln();
        finish.push_back(x);
    }
    cout << widestGap(n, start, finish);
    return 0;
}