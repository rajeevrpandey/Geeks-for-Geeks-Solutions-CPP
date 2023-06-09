/*
Given two numbers A and B. The task is to find out their LCM and GCD.

 

Example 1:

Input:
A = 5 , B = 10
Output:
10 5
Explanation:
LCM of 5 and 10 is 10, while
thier GCD is 5.
Example 2:

Input:
A = 14 , B = 8
Output:
56 2
Explanation:
LCM of 14 and 8 is 56, while
thier GCD is 2.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function lcmAndGcd() which takes an Integer N as input and returns a List of two Integers, the required LCM and GCD.

 

Expected Time Complexity: O(log(min(A, B))
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= A,B <= 10^18
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {//Unoptimised approach (will give TLE)
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> ans;
        long long minNo = min(A, B);
        long long gcd=1;
        for(int i=2; i<=minNo; i++){
            if(A%i==0 and B%i==0) gcd=i;
        }
        long long lcm = (A * B)/gcd;
        ans.push_back(lcm);
        ans.push_back(gcd);
        return ans;
    }
};

class Solution {//optimised code
  public:
    long long gcd(long long A, long long B){
        if(B==0) return A;
        gcd(B, A%B);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> ans;
        long long g = gcd(A, B);
        long long lcm = (A * B)/g;
        ans.push_back(lcm);
        ans.push_back(g);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends
