#include <bits/stdc++.h>
using namespace std;

// helpers
void file() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("ot.txt", "w", stdout);
#else
//	freopen("jumping.in", "r", stdin);	// HERE
#endif
}

typedef vector<int> vi;
typedef vector<vi> vvi;

int i, j, k;

#define forr(i, j, n) for (i = j; i < n; i++)
#define frr(i, j, n) for (i = j; i >= n; i--)

// 23280666450650  23280666450650

// Define all 4 adjacent possible cells
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Data holder in the global state instead of
//     passing all of this data in a recursive way
int R;
int C;
vvi grid;

// Using floodfill to find all the adjacent cells in the parking
void floodfill(int r, int c) {
  // if not a parking area return
  if (!grid[r][c])
    return;

  // mark it as visited
  grid[r][c] = 0;

  // loop on the 4 possible adjacent places
  for (int d = 0, rr, cc; d < 4; d++) {
    // new row(rr), column(cc)
    rr = r + dx[d], cc = c + dy[d];
    // check if its valid place before visiting it
    if (rr >= 0 and rr < R and cc >= 0 and cc < C and grid[rr][cc] != 0)
      floodfill(rr, cc);
  }
  return;
}

int numberAmazonTreasureTrucks(int rows, int column,
                               vector<vector<int>> _grid) {
  // set the data on the global state
  grid = _grid;
  R = rows;
  C = column;

  int ret = 0;
  // for on rows
  forr(i, 0, rows)
      // for on columns
      forr(k, 0, column)
      // check if its a parking area
      if (grid[i][k]) ret++,
      floodfill(i, k);

  return ret;
}

int main() {
  file(); // TODO

  cout << numberAmazonTreasureTrucks(
      4, 4, {{1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}});

  return 0;
}
