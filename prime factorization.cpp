#include<iostream>
using namespace std;
void primeFactorization(int n)
{
     while(n%2==0)
     {
        cout<<2<<" ";
        n/=2;
     }
     for(int i=3;i*i<=n;i+=2)
     {
        if(n%i==0)
        {
            while(n%i==0)
            {
                cout<<i<<" ";
                n/=i;
            }
        }
     }
     if(n>1) cout<<n<<"\n";
}
int main()
{
    int n;
    cin>>n;
    primeFactorization(n);
    return 0;
}