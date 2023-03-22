/*
Geek is very fond of patterns. Once, his teacher gave him a square pattern to solve. He gave Geek an integer n and asked him to build a pattern.

Help Geek to build the pattern.

 

Example 1:

Input: 4

Output:
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

Your Task:

You don't need to input anything. Complete the function printSquare() which takes  an integer n  as the input parameter and print the pattern.

Constraints:

1<= N <= 20
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        for(int i=0; i<2*n - 1; i++){
            for(int j=0; j<2*n - 1; j++){
                int top = i;
                int left  = j;
                int right = 2*n - 2 - j;
                int bottom = 2*n - 2 - i;
                cout << n - min(min(top, left), min(right, bottom)) << " ";
            }
            cout << endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends
