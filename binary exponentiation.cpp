#include<iostream>
using namespace std;
long long binaryExponentiation(long long a,long long b,long long m)
{
     if(b==0) return 1;
     long long res=binaryExponentiation(a,b/2,m);
     if(b&1){
        return (a*((res*res)%m))%m;
     }
     else{
        return (res*res)%m;
     }

}
int main()
{
    long long a,b,m;
    cin>>a>>b>>m;
    cout<<binaryExponentiation(a,b,m)<<"\n";
    return 0;
}