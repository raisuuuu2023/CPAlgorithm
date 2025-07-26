#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>preday(3);
    cin>>preday[0]>>preday[1]>>preday[2];
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vector<int>day(3);
        day[0]=a+max(preday[1],preday[2]);
        day[1]=b+max(preday[0],preday[2]);
        day[2]=c+max(preday[0],preday[1]);
        preday=day;
    }
    cout<<max({preday[0],preday[1],preday[2]});
    return 0;
}