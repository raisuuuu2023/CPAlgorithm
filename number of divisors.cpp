#include<iostream>
using namespace std;
long long numberofDivisors(long long n)
{
    long long ans=1;
    long long count=0;
    while(n%2==0)
    {
        count++;
        n/=2;
    }
    ans*=(count+1);
    for(int i=3;i*i<=n;i+=2)
    {
        count=0;
            while(n%i==0)
            {
                count++;
                n/=i;
            }
            ans*=(count+1);
    }
    if(n>1) ans*=2;
    return ans;
}
int main()
{
    long long n;
    cin>>n;
    cout<<numberofDivisors(n)<<"\n";
    return 0;
}