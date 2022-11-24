/*
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
 

Example 1:

Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.



Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() 
which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 ≤ length of array ≤ 1000
1 ≤ arr[i] ≤ 1000000
*/


class Solution{

    

    pair<vector<int>, vector<int>> LIS(vector<int> nums){

        int n = nums.size();

        vector<int> dpLeft(n, -1);

        vector<int> dpRight(n, -1);

        

        for(int i = 0;i < n; i++){

            int count = 1;

            int j = i - 1;

            while(j >= 0){

                if(nums[j] < nums[i]){

                    count = max(count, dpLeft[j] + 1);

                }

                j--;

            }

            dpLeft[i] = count;

        }

        for(int i = n - 1;i >= 0; i--){

            int count = 1;

            int j = i + 1;

            while(j < n){

                if(nums[j] < nums[i]){

                    count = max(count , dpRight[j] + 1);

                }

                j++;

            }

            dpRight[i] = count;

            

        }

        

        return {dpLeft, dpRight};

    }

    

    

 public:

 int LongestBitonicSequence(vector<int>nums)

 {

     // code here

     pair<vector<int>, vector<int>> p = LIS(nums); 

     int Max = 0;

     int n = nums.size();

     for(int i = 0; i < n; i++){

         Max = max(Max, p.first[i] + p.second[i] - 1);

     }

     

     return Max;

 }

};
