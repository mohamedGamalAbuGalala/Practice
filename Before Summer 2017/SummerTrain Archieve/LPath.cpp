int max_ = 3;

int arr[3][3];
int Mpath(int i , int j){
	if(i == max_ || j ==max_) return 0;
	if( i == max_-1  && j == max_-1)
		return arr[i][j];
	int p1 = arr[i][j]+ Mpath(i,j+1);
	int p2 = arr[i][j]+ Mpath(i+1,j);
	return max(p1,p2);
}

int main(void){
	cout<<"hello"<<endl;
	for (int i = 0; i < 3; ++i){
		cin>>arr[i][0];
		cin>>arr[i][1];
		cin>>arr[i][2];
	}
	int res = Mpath(0,0);
	cout<<res<<endl;

	return 0;

}