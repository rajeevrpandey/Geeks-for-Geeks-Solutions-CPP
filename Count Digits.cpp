/*
Given a number N. Count the number of digits in N which evenly divides N.

Note :- Evenly divides means whether N is divisible by a digit i.e. leaves a remainder 0 when divided.
 

Example 1:

Input:
N = 12
Output:
2
Explanation:
1, 2 both divide 12 evenly
Example 2:

Input:
N = 23
Output
0
Explanation:
2 and 3, none of them
divide 23 evenly

Your Task:
You don't need to read input or print anything. Your task is to complete the function evenlyDivides() which takes an integer N as input parameters and returns an integer, total number factor of digits N which divides N evenly.


Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)
 

Constraints:
1<=N<=105
*/

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        //code here
        int count = 0;
        int dig, num = N;
        while(num){
            dig = num % 10;
            num = num / 10;
            if(dig>0 && N % dig == 0){
                count++;
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
