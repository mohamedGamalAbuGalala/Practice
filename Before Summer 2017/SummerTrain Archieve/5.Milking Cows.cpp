// 5.Milking Cows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define pb push_back
pair<int , int>r;
vector< pair<int , int> > ranges;

bool cmp ( pair<int , int> b , pair<int , int> a ) {
	if ( b.first < a.first ) return 1;
	if ( b.first == a.first ) return b.second < a.second;
	return 0;
}

int main ( ) {
	int milking = 0 , gap = 0 , n , i , j;
	scanf_s("%d\n", &n);
	for ( i = 0; i < n; i++ ) {
		scanf_s ( "%d %d" , &r.first , &r.second );
		ranges.pb(r);
	}
	sort ( ranges.begin ( ) , ranges.end ( ) , cmp );

	for ( i = 0; i < ranges.size ( ); i++ ) {
		int m = ranges [ i ].second;
		for ( j = i + 1; j < ranges.size ( ) && ranges [ j ].first < ranges [ i ].second; j++ ) {
			if ( ranges [ j ].second > m )
				m = ranges [ j ].second;
		}
		int t = m ;
		t = t - ranges [ i ].first;
		if ( milking < t )
			milking = t;
		if ( i < ranges.size ( ) - 1 ) {
			if ( m < ranges [ i + 1 ].first ) {
				m = ranges [ i + 1 ].first - m;
				if ( m > gap )
					gap = m;
			}
		}
	}
	printf ( "%d %d" , milking , gap );
	return 0;
}

