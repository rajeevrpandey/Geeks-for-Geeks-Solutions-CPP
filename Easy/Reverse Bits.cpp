/*
Given a 32 bit number X, reverse its binary form and print the answer in decimal.

Example 1:

Input:
X = 1
Output:
2147483648 
Explanation:
Binary of 1 in 32 bits representation-
00000000000000000000000000000001
Reversing the binary form we get, 
10000000000000000000000000000000,
whose decimal value is 2147483648.
Example 2:

Input:
X = 5
Output:
2684354560 
Explanation:
Binary of 5 in 32 bits representation-
00000000000000000000000000000101
Reversing the binary form we get, 
10100000000000000000000000000000,
whose decimal value is 2684354560.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reversedBits() which takes an Integer X as input and returns the answer.

Expected Time Complexity: O(log(X))
Expected Auxiliary Space: O(1)

Constraints:
0 <= X < 2^32
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {//naive approach (using extra space)
  public:
    long long reversedBits(long long X) {
        // code here
        if(X==0){
            return 0;
        }
        long long base = 1;
        long long dec = 0;
        int binaryNum[32] = {0};
        long long n = X;
        int i = 0;
        while (n > 0) {
 
            // storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        i=31;
        while(i>=0){
            dec += binaryNum[i] * base;
            base *= 2;
            i--;
        }
        return dec;
    }
};


class Solution {//best approach
  public:
    long long reversedBits(long long X) {
        // code here
        unsigned int num = X;//since unsigned int uses 32bit but long long uses 64bit
        unsigned int NO_OF_BITS = sizeof(num) * 8;
        unsigned int reverse_num = 0;
        int i;
        for (i = 0; i < NO_OF_BITS; i++) {//If a bit at ith position is set in the i/p no.
                                            //then set the bit at (NO_OF_BITS-1)-i in o/p
            if ((num & (1 << i)))
                reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
        }
        return reverse_num;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
