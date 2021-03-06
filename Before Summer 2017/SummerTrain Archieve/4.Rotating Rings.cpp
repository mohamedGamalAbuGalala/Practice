// 4.Rotating Rings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<algorithm>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
#define pb push_back

int n , t [ 1001 ] [ 1001 ];
vector<int> tt , s;

bool cmp ( ) {
	int ind = -1 , i , a;
	for ( i = 0; i < tt.size ( ); i++ )
		if ( tt [ i ] == s [ 0 ] )
			ind = i;
	if ( ind == -1 )
		return 0;
	i = 1 , a = ind + 1;
	while ( 1 ) {
		i ++ , a ++;
		i %= s.size ( );
		a %= tt.size ( );
		if ( a == ind ) break;
		if ( s [ i ] != tt [ a ] ) return 0;
	}
	return 1;
}

int main ( ) {
	int i , a , st , j , k , c , cnt = 0 , fl = 0 , x , y;
	while ( 1 ) {
		cnt++;
		scanf_s ( "%d" , &n );
		if ( n == 0 ) break;
		for ( i = 0; i < n; i++ )
			for ( a = 0; a < n; a++ )
				scanf_s ( "%d" , &t [ i ] [ a ] );
		a = n / 2;
		if ( n % 2 == 1 )
			a ++;
		fl = 1;
		for ( i = 0; i < a; i++ ) //loop 3ala el rings
		{
			tt.clear ( );
			s.clear ( );
			st = ( ( n - i - 1 ) * n ) + 1 + i;
			x = i , y = i;
			//first segment
			for ( j = st , c = 0; c < n - ( i * 2 ); j -= n ) {
				s.pb ( j ) ;
				tt.pb ( t [ x ] [ y ] );
				c++ ; y++ ;
			}
			y-- , x++ , j += n;
			//second segment
			for ( k = j + 1 , c = 0; c < n - ( i * 2 ) - 1; k++ ) {
				s.pb ( k ) ;
				tt.pb ( t [ x ] [ y ] );
				c++ ; x++;
			}
			x-- , y-- , k--;
			//third segment
			for ( j = k + n , c = 0; c < n - ( i * 2 ) - 1; j += n ) {
				s.pb ( j ) ;
				tt.pb ( t [ x ] [ y ] );
				c++ ; y-- ;
			}
			y++ , x-- , j -= n;
			//forth segment
			for ( k = j - 1 , c = 0; c < n - ( i * 2 ) - 2; k-- ) {
				s.pb ( k ) ;
				tt.pb ( t [ x ] [ y ] );
				x-- ; c++ ;
			}
			if ( !cmp ( ) ) fl = 0; //comparing input ring with the target ring
		}
		if ( fl ) printf ( "%d. YES\n" , cnt );
		else printf ( "%d. NO\n" , cnt );
	}
	return 0;
}
