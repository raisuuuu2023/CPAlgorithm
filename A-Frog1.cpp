#include<iostream>
#include<cmath>
#include<climits>
#include<cstring>
using namespace std;
const int N=1e5+10;
int h[N];
int dp[N];
int frog(int i)
{
    int mincost=INT_MAX;
    if(i==0) return 0;
    if (dp[i]!=-1) return dp[i];
    mincost=min(mincost,frog(i-1)+abs(h[i]-h[i-1]));
    if(i>1)
    mincost=min(mincost,frog(i-2)+abs(h[i]-h[i-2]));
    return dp[i]=mincost;

}
int main()
{
    memset(dp,-1,sizeof(dp));
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>h[i];
    }
    cout<<frog(N-1);
    return 0;
}