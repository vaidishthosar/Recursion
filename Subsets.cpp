/*
Given a set of positive integers, find all its subsets.

Example 1 :

Input : 
array = {1, 2, 3}
Output :
// this space denotes null element. 
1
1 2
1 2 3
1 3
2
2 3
3
Explanation: 
The following are the subsets 
of the array {1, 2, 3}.*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
     void solve(vector<int>& A,vector<vector<int>>& ans, vector<int> output, int i){
        if(i >= A.size()){
            ans.push_back(output);
            return;
        }
        
        // Exclude:
        solve(A,ans,output,i+1);
        
        // Include:
        output.push_back(A[i]);
        solve(A,ans,output,i+1);
            
        
    }
    
    public:
    
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> ans;
        
        vector<int> output;
        
        int index = 0;
        
        solve(A,ans,output,index);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};


int main()
{
	
    int n, x;
    cin >> n;

    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        array.push_back(x);
    }
    
    
    Solution ob;
    vector<vector<int> > res = ob.subsets(array);

    // Print result
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    


	return 0;
}
