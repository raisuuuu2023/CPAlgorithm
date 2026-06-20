#include<iostream>
using namespace std;
const long long MOD=1e9+7;
long long mod_add(long long a,long long b)
{
    a%=MOD;
    b%=MOD;
    long long result=a+b;
    if(result>=MOD) result-=MOD;
    return result;
}
long long mod_substract(long long a,long long b)
{
    a%=MOD;
    b%=MOD;
    long long result=a-b;
    if(result<0) result+=MOD;
    return result;
}
long long mod_mul(long long a,long long b)
{
    return ((a%MOD)*(b%MOD))%MOD;
}
long long binary_ex(long long a,long b)
{
    a%=MOD;
    long long res=1;
    while(b>0)
    {
        if(b&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
long long extended_gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long x1,y1;
    long long g=extended_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}
long long mod_inverse(long long a,long long mod)
{
    return binary_ex(a,mod-2);
}
int main()
{
    long long a,b;
    cin>>a>>b;
    return 0;
}