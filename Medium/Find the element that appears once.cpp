/*
Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

Example 1:

Input:
N = 5
A = {1, 1, 2, 5, 5}
Output: 2
Explanation: 
Since 2 occurs once, while
other numbers occur twice, 
2 is the answer.
Example 2:

Input:
N = 7
A = {2, 2, 5, 5, 20, 30, 30}
Output: 20
Explanation:
Since 20 occurs once, while
other numbers occur twice, 
20 is the answer.
Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes two arguments(array A and integer N) and returns the number occurring only once.

Expected Time Complexity: O(Log(N)).
Expected Auxiliary Space: O(1).

Constraints
0 <   N  <= 10^6
0 <= A[i] <= 10^9
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{// XOR based (O(n) time)
public:	
	int search(int A[], int N){
	    //code
	    int XOR = 0;
        for (int i = 0; i < N; i++) {
            XOR = XOR ^ A[i];
        }
        return XOR;
	    
	}
};

class Solution{// Linear Search based (O(n) time)
public:	
	int search(int A[], int N){
	    //code
	    for(int i=0; i<N; i+=2){
	        if(A[i]!=A[i+1]) return A[i];
	    }
	    
	}
};


class Solution{// A Binary Search based function (O(log n) time)
public:	
	int search(int A[], int N){
	    //code
	    return search(A, 0, N - 1);
	}
	int search(int A[], int low, int high){
	    // Base cases
        if (low > high)
            return -1;
    
        if (low == high) {
            return A[low];
        }
    
        // Find the middle point
        int mid = (low + high) / 2;
    
        // If mid is even and element next to mid is
        // same as mid, then output element lies on
        // right side, else on left side
        if (mid % 2 == 0) {
            if (A[mid] == A[mid + 1])
                search(A, mid + 2, high);
            else
                search(A, low, mid);
        }
    
        // If mid is odd
        else {
            if (A[mid] == A[mid - 1])
                search(A, mid + 1, high);
            else
                search(A, low, mid - 1);
        }
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends
