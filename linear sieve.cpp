#include<iostream>
#include<vector>
using namespace std;
vector<int>linearSieve(int n)
{
    vector<int>primes;
    vector<int>lp(n+1,0);
    for(int i=2;i<=n;i++)
    {
        if(lp[i]==0)
        {
            lp[i]=i;
            primes.push_back(i);
        }
        for(int p:primes)
        {
            if(lp[i]<p || i*1LL*p>n) break;
            lp[i*p]=p;
        }
    }
    return primes;
}
int main()
{
    int n;
    cin>>n;
    vector<int>primes=linearSieve(n);
    for(int p:primes)
    {
        cout<<p<<"\n";
    }
    return 0;
}