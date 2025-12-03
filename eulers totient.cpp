#include<iostream>
using namespace std;
long long phi(long long n)
{
    long long res=n;
    if(n%2==0)
    {
        while(n%2==0)
        {
            n/=2;
        }
        res-=res/2;
    }
    for(long long p=3;p*p<=n;p+=2)
    {
        if(n%p==0)
        {
            while(n%p==0)
            {
                n/=p;
            }
            res-=res/p;
        }
    }
    if(n>1) res-=res/n;
    return res;
}
int main()
{
    long long n;
    cin>>n;
    cout<<phi(n)<<"\n";
    return 0;
}