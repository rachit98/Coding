//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        return a.first<b.first;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> trains;
    	
    	for(int i=0;i<n;i++)
    	{
    	    trains.push_back(make_pair(arr[i],dep[i]));
    	}
    	sort(trains.begin(),trains.end(),comp);
    	priority_queue <int, vector<int>, greater<int>> pq;
    	for(auto t: trains)
    	{
    	   // cout<<t.first<<" "<<t.second<<endl;
    	    
    	    if(pq.empty())
    	    {
    	        pq.push(t.second);
    	    }
    	    else if(pq.top()<t.first)
    	    {
    	        pq.pop();
    	        pq.push(t.second);
    	    }
    	    else
    	    {
    	        pq.push(t.second);
    	    }
    	   // cout<<pq.size()<<endl;
    	}
    	return pq.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends