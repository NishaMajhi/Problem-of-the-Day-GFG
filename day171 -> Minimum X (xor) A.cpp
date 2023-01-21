/*
Given two integers A and B, the task is to find an integer X such that (X XOR A) is minimum possible and
the count of set bit in X is equal to the count of set bits in B.



Example 1:
Input: 
A = 3, B = 5
Output: 3
Explanation:
Binary(A) = Binary(3) = 011
Binary(B) = Binary(5) = 101
The XOR will be minimum when x = 3
i.e. (3 XOR 3) = 0 and the number
of set bits in 3 is equal
to the number of set bits in 5.



Example 2:
Input: 
A = 7, B = 12
Output: 6
Explanation:
(7)2= 111
(12)2= 1100
The XOR will be minimum when x = 6 
i.e. (6 XOR 7) = 1 and the number 
of set bits in 6 is equal to the 
number of set bits in 12.


Your task :
You don't need to read input or print anything. Your task is to complete the function minVal() that takes integer A and B as input and
returns the value of X according to the question.
 
Expected Time Complexity : O(log MAX(A,B))
Expected Auxiliary Space : O(1)
 
Constraints :
1 <= A, B <= 109
*/


class Solution {
  public:
    // count how many set bits are there in the number
    // set bits means how many 1 are there
    int setBitCount(int n){
        int setBits = 0;
        while(n!=0){
            int digit = n%2;
            if(digit)
               setBits++;
            n = n/2;
        }
        
        return setBits;
    }
  
    int minVal(int a, int b) {
        
        // find setBits of both inputs
        int setBitsA = setBitCount(a);
        int setBitsB = setBitCount(b);
        // find difference between setBits of both input
        int diffSetBits = abs(setBitsA-setBitsB);
        
        //if both input have same number of set Bits
        if(diffSetBits == 0)
            return a;
    
        // we will perform operation on input a only in order to get the integer X such that
        // X XOR A is minimum possible and the count of set bit in X is equal to the count of set bits in B.
       
        //if input a has more number of set bit
        if(setBitsA > setBitsB){
            while(diffSetBits){
              //we will remove least significant bits of input a
                a = a & (a-1);
                diffSetBits--;
            }
        }
        // if input a has less number of set bits
        else{
            while(diffSetBits){
                // we will add bits in input a
                a = a | (a+1);
                diffSetBits--;
            }
        }
        
        // now a become the resultant number that has the same number of setBits that input has
        return a;
        
    }
};
