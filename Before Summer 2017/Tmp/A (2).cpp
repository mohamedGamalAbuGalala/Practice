#include <iostream>
using namespace std;



int main() {
	int T, n ,m,tmp1 , tmp2, i;
	cin>>T;
	while(T--){
	    int vis[105]={ 0 };
	    cin>>n>>m;
	    for( i =0; i < m && cin>>tmp1 && cin>>tmp2 ;i++){
	        if(vis[tmp1] || vis[tmp2])
	            break;
	        vis[tmp1] = 1, vis[tmp2] = 1;
	    }
	    if( n&1 || i < m )
	        cout << "no" << endl;
	    else
	        cout << "yes" << endl;
	}
	return 0;
}
