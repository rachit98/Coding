//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        return a.first>b.first;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;i++)
        {
            jobs.push_back(make_pair(arr[i].profit, arr[i].dead));
        }
        sort(jobs.begin(),jobs.end(),comp);
        
        int max_profit = 0;
        int num_jobs = 0;
        
        int max_dead = jobs[0].second;
        for(auto j:jobs)
            max_dead = max(j.second,max_dead);
        
        vector<int> deadlines (max_dead + 1, -1);
        
        for(auto j:jobs)
        {
            for(int i=j.second;i>0;i--)
            {
                if(deadlines[i]==-1)
                {
                    deadlines[i] = 1;
                    num_jobs++;
                    max_profit += j.first;
                    break;
                }
            }
        }
        return {num_jobs,max_profit};
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends