// Circle_f.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


int main ( ) {
	vector<int> inp;
	vector<int> check;

	string np;
	int n , i , p = -1 , res = 0 , j;
	cin >> n;
	scanf ( "\n" );
	for ( i = 1; i <= n; i++ ) {
		check.push_back ( i );
	}
	check.push_back ( -1 );

	getline ( cin , np );
	stringstream stream(np);
	i = 0;
	while(1) {
		int m;
		stream >> m;
		if(!stream)
			break;
		inp.push_back ( m );
	}
	for (i = 0; i < inp.size(); i++)
	{
		for (  j = 0; j < inp[i]; j++ ) {
			int tmp = p;
			while ( check[tmp+1] == 0 )
				tmp++;
			p = tmp;
			p++;
			if ( p == check.size ( ) - 1 )
				p = 0;
		}
		check [ p ] = 0;
	}
	int tmp = 0;
	while ( check[tmp] == 0 )
		tmp++;
	cout << check [ tmp ] << endl;

	return 0;
}