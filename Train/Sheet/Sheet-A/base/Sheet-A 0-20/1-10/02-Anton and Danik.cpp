#include <iostream>
using namespace std;
int main(){
	int n , an=0, dn=0;
	char inp;
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>inp;
		if(inp=='A')
			an++;
		else if (inp == 'D')
			dn++;
	}
	if(an > dn)
		cout<<"Anton"<<endl;
	else if(dn > an)
		cout<<"Danik"<<endl;
	else
		cout<<"Friendship"<<endl;
    return 0;
}
