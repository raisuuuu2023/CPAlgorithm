#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int>sieve(int limit)
{
    vector<bool>isPrime(limit+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int p=2;p*p<=limit;p++)
    {
        if(isPrime[p])
        {
        for(int i=p*p;i<=limit;i+=p)
        {
            isPrime[i]=false;
        }
        }
    }
    vector<int>primes;
    for(int p=2;p<=limit;p++)
    {
        if(isPrime[p]) primes.push_back(p);
    }
    return primes;
}
void segmentedSieve(long long L,long long R)
{
    int limit=floor(sqrt(R))+1;
    vector<int>primes=sieve(limit);
    vector<bool>isprime(R-L+1,true);
    for(int p:primes)
    {
        long long start=max((long long)p*p,((L+p-1)/p)*p);
        for(int i=start;i<=R;i+=p)
        isprime[i-L]=false;
    }
    if(L==1) isprime[0]=false;
    for(long long i=0;i<=R-L;i++)
    {
        if(isprime[i])
        cout<<(L+i)<<" ";
    }
    cout<<endl;
}
int main()
{
    long long L,R;
    cin>>L>>R;
    segmentedSieve(L,R);
    return 0;
}