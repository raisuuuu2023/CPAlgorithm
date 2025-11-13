#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct job{
   int id;
   int deadline;
   int profit;
};
bool compare(job a,job b)
{
   return a.profit > b.profit;
}
void jobscheduling(vector<job>&jobs,int n)
{
    sort(jobs.begin(),jobs.end(),compare);
    int maxdeadline=0;
    for(auto& job:jobs)
    {
        maxdeadline=max(maxdeadline,job.deadline);
    }
    vector<int>slot(maxdeadline+1,-1);
    int totalprofit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i].deadline;j>0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=jobs[i].id;
                totalprofit+=jobs[i].profit;
                break;
            }
        }
    }
    for(int i=1;i<=maxdeadline;i++)
    {
        if(slot[i]!=-1)
        cout<<slot[i]<<" ";
    }
    cout<<endl;
    cout<<totalprofit<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<job>jobs(n);
    for(int i=0;i<n;i++)
    {
        jobs[i].id =i+1;
        cin>>jobs[i].deadline>>jobs[i].profit;
    }
    jobscheduling(jobs,n);
    return 0;
}