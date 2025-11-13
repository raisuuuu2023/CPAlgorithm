#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int count=0;
    long long ans=1;
    while(n%2==0)
    {
        count++;
        n/=2;
    }
    ans*=(count+1);
    for(int i=3;i*i<=n;i+=2)
    {
        count=0;
        while(n%3==0)
        {
            count++;
            n/=i;
        }
        ans*=(count+1);
    }
    if(n>1) ans*=2;
    cout<<ans<<"\n";
    return 0;
}