/*
Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.
Note: The elements greater than N in the array can be ignored for counting and do modify the array in-place.


Example 1:

Input:
N = 5
arr[] = {2, 3, 2, 3, 5}
P = 5
Output:
0 2 2 0 1
Explanation: 
Counting frequencies of each array element
We have:
1 occurring 0 times.
2 occurring 2 times.
3 occurring 2 times.
4 occurring 0 times.
5 occurring 1 time.
Example 2:

Input:
N = 4
arr[] = {3,3,3,3}
P = 3
Output:
0 0 4 0
Explanation: 
Counting frequencies of each array element
We have:
1 occurring 0 times.
2 occurring 0 times.
3 occurring 4 times.
4 occurring 0 times.

Your Task:
You don't need to read input or print anything. Complete the function frequencycount() that takes the array and n as input parameters and modify the array itself in place to denote the frequency count of each element from 1 to N. i,e element at index 0 should represent the frequency of 1, and so on.


Can you solve this problem without using extra space (O(1) Space)?


Constraints:
1 ≤ N ≤ 105
1 ≤ P ≤ 4*10^4 
1 <= A[i] <= P
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{//Using unordered map properties
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        unordered_map<int, int> mp;
        for(int i=0; i<N; i++){
            mp[arr[i]]++;
        }
        for(int i=0; i<N; i++){
            if(mp.find(i+1)!=mp.end()){
                arr[i] = mp[i+1];
            }
            else{
                arr[i]=0;
            }
        }
        
};


class Solution{//Using an extra array for counting
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int x = max(N+1, P+1);
        int a[x] = {0};
        for (int i = 0; i < N; i++){
            a[arr[i]] += 1;
	    }
        for (int i = 0; i < N; i++){
            arr[i] = a[i + 1];
        }
    }
};

	
class Solution{//Optimised solution
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        int i = 0;
        while (i<N)
        {
            // If this element is already processed,
            // then nothing to do
            if (arr[i] <= 0 || arr[i]>N || arr[i]>P)
            {
                i++;
                continue;
            }
     
            // Find index corresponding to this element
            // For example, index for 5 is 4
            int elementIndex = arr[i]-1;
     
            // If the elementIndex has an element that is not
            // processed yet, then first store that element
            // to arr[i] so that we don't lose anything.
            if (arr[elementIndex] > 0)
            {
                arr[i] = arr[elementIndex];
     
                // After storing arr[elementIndex], change it
                // to store initial count of 'arr[i]'
                arr[elementIndex] = -1;
            }
            else
            {
                // If this is NOT first occurrence of arr[i],
                // then decrement its count.
                arr[elementIndex]--;
     
                // And initialize arr[i] as 0 means the element
                // 'i+1' is not seen so far
                arr[i] = 0;
                i++;
            }
        }
        for(int i=0;i<N;i++) {
            if(arr[i] < 0) arr[i] = -arr[i];
            else arr[i]=0;
        }
    }
};

//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}





// } Driver Code Ends
