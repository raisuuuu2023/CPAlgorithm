#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        vector<int>arr(n),brr(n),pos(n+1);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            cin>>brr[i];
            pos[brr[i]]=i;
        }
        vector<int>mapped(n);
        for(int i=0;i<n;i++)
        {
            mapped[i]=pos[arr[i]];
        }
        vector<int>lis;
        for(int x:mapped)
        {
            auto it=lower_bound(lis.begin(),lis.end(),x);
            if(it==lis.end()) lis.push_back(x);
            else *it=x;
        }
        int lcs=lis.size();
        int op=2*(n-lcs);
        cout<<"Case "<<i<<": "<<op<<"\n";
    }
    return 0;
} 