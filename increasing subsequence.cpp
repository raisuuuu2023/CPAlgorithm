#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<long long>lis;
    for(int x:arr)
    {
        auto it=lower_bound(lis.begin(),lis.end(),x);
        if(it==lis.end())
        {
            lis.push_back(x);
        }
        else{
            *it=x;
        }
    }
    cout<<(int)lis.size()<<"\n";
    return 0;
}