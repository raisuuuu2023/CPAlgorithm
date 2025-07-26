#include<iostream>
#include<vector>
using namespace std;
int knapsack(int w,vector<int>& profit,vector<int>& weight,int idx,vector<vector<int>>& memo)
{
    if(idx<0) return 0;
    if(memo[w][idx]!=-1) return memo[w][idx];
    if(weight[idx]>w) memo[w][idx]=knapsack(w,profit,weight,idx-1,memo);
    else {
          memo[w][idx]=max(profit[idx]+knapsack(w-weight[idx],profit,weight,idx-1,memo),knapsack(w,profit,weight,idx-1,memo));
    }
    return memo[w][idx];
}
int main()
{
    int w=50;
    vector<int>profit={300,100,200};
    vector<int>weight={30,10,20};
    int n=weight.size();
    vector<vector<int>>memo(w+1,vector<int>(n,-1));
    cout<<knapsack(w,profit,weight,n-1,memo)<<"\n";
    return 0;
}