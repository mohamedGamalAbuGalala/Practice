// A templating engine.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

map<string , string> m;

int main ( ) {
	int n , m , i , j , k , last;
	bool flag = 1;
	string o = "{{" , c = "}}" , res , inp , tmp , key = "" , val = "" , par , cur ;
	map<string , string> mp ;
	stack<string> s;
	stack<int> las;
	cin >> n >> m;
	scanf ( "\n" );
	for ( i = 0; i < n; i++ ) {
		key = "" , val = "";
		bool f = 1;
		getline ( cin , tmp );
		scanf ( "\n" );
		for ( j = 0; j < tmp.size ( ); j++ ) {
			if ( tmp [ j ] == '=' ) {
				f = 0;
				continue;
			}
			if ( f )
				key += tmp [ j ];
			else val += tmp [ j ];
		}
		mp [ key ] = val;
	}
	for ( i = 0; i < m; i++ ) {
		getline ( cin , inp );
		for ( j = 0; j < inp.size ( ) - 1; j++ ) {
			par = "";
			par += inp [ j ] ; par += + inp [ j + 1 ];
			if ( par == o ) {
				las.push ( j );
				tmp = "" ;
				int d = j + 2;
				while ( inp [ d ] == '{' ) {
					las.push ( d );
					flag = 0;
					d += 2;
				}
				k = d;
				while ( ( inp [ k ] != '{' ) && ( inp [ k ] != '}' ) ) {
					tmp += inp [ k ];
					k++;
				}
				s.push ( tmp );
				j = k - 1;
			} else if ( par == c ) {
				if ( las.size ( ) != 0 )
					last = las.top ( );
				las.pop ( );
				key = s.top ( );
				string s0 = "";
				size_t pos;
				if ( inp.find ( key ) > last ) {
					pos = inp.find ( key ) + key.size ( );
					if ( pos != j ) {
						for ( int l = pos; l < j; l++ )
							s0 += inp [ l ];
					}
				}
				key += s0;
				s.pop ( );
				val = mp [ key ];
				string s1 = inp.substr ( 0 , last );
				string s2 = inp.substr ( j + 2 );
				if (flag )
					j -= ( ( j ) - last - val.size ( ) + 1 );
				else {
					j = las.top ( ) - 1;
				}
				inp = s1; inp += val; inp += s2;
			}
		}
		cout << inp << endl;
	}
	return 0;
}

