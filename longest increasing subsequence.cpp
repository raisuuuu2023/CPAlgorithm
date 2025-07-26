#include<iostream>
#include<vector>
using namespace std;
int LISatidx(vector<int>& arr,int idx,vector<int>& memo)
{
    if(idx==0) return 1;
    if(memo[idx]!=-1) return memo[idx];
    int len=1;
    for(int i=0;i<idx;i++)
    {
        if(arr[i]<arr[idx])
        len=max(len,LISatidx(arr,i,memo)+1);
    }
    memo[idx]=len;
    return memo[idx];
}
int LIS(vector<int>&arr)
{
    int n=arr.size();
    vector<int>memo(n,-1);
    int len=1;
    for(int i=0;i<n;i++)
    {
        len=max(len,LISatidx(arr,i,memo));
    }
    return len;
}
int main()
{
    vector<int>arr={22,10,9,30,21,50,41,60};
    cout<<LIS(arr)<<"\n";
    return 0;
}