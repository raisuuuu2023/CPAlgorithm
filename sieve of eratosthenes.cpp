#include<iostream>
#include<vector>
using namespace std;
void sieveofEratosthenes(int n)
{
    vector<bool>isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int p=2;p*p<=n;p++)
    {
        if(isPrime[p]){
        for(int i=p*p;i<=n;i+=p)
        {
            isPrime[i]=false;
        }
    }
    }
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    sieveofEratosthenes(n);
    return 0;
}