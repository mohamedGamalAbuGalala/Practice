/*
ID: hosam_s1
TASK: milk3
LANG: C++
*/
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

FILE * in = fopen("milk3.in","r");
FILE * out = fopen("milk3.out","w");

bool vis[21][21][21];
int A , B , C;
int siz[3];

void solve(int a, int b, int c)
{
    if(vis[a][b][c]) return;
    vis[a][b][c] = 1;
    
    int arr[3];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(i != j)
            {
                arr[0] = a; arr[1] = b; arr[2] = c;
                int rem = siz[j] - arr[j];
                
                if(rem >= arr[i])
                {
                    arr[j] += arr[i];
                    arr[i] = 0;
                    solve(arr[0],arr[1],arr[2]);
                }
                else
                {
                    arr[j] = siz[j];
                    arr[i] -= rem;
                    solve(arr[0],arr[1],arr[2]);
                }
            }
    return;
}

int main()
{
    int i , j;
    
    fscanf(in,"%d %d %d",&A,&B,&C);
    siz[0] = A; siz[1] = B; siz[2] = C;
    solve(0,0,C);
    
    set<int> S;
    for(i=0;i<=20;i++)
        for(j=0;j<=20;j++)
            if(vis[0][i][j])
                S.insert(j);
    
    fprintf(out,"%d",*S.begin());
    S.erase(S.begin());
    while(S.size())
    {
        fprintf(out," %d",*S.begin());
        S.erase(S.begin());
    }
    fprintf(out,"\n");
        
    return 0;
}