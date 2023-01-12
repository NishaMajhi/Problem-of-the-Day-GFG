/*
You are given N elements, you can remove any two elements from the list, note their sum, and add the sum to the list.
Repeat these steps while there is more than a single element in the list. The task is to minimize the sum of these chosen sums.
 

Example 1:
Input:
N = 4
arr[] = {1, 4, 7, 10}

Output:
39

Explanation:
Choose 1 and 4, Sum = 1 + 4 = 5.
arr[] = {5, 7, 10} 
Choose 5 and 7, Sum = 5 + (5 + 7) = 17.
arr[] = {12, 10} 
Choose 12 and 10, Sum = 17 + (12 + 10) = 39.
arr[] = {22}
 


Example 2:
Input:
N = 5
arr[] = {1, 3, 7, 5, 6}

Output:
48
 

Your Task:
You don't need to read input or print anything. The task is to complete the function minimizeSum() which takes N as size of arr array and a arr array. 
Your task is to minimize the sum of these chosen sums and return it.


Expected Time Complexity: O(N * log(N))
Expected Auxiliary Space: O(N)
 

Constraints:
1 <= N, arr[i] <= 105
*/


class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        
        // we are using priority queue in which the data is sorted in ascending order
        // we push the array data in the priority queue
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<N;i++){
            pq.push(arr[i]);
        }
        
        int sum=0;
        //we will take two elements from the priority queue and find sum and push into the priority queue
        //the added data will be its right position as the priority queue is sorted in ascending order
        // we will do this till the priority queue has only one element left
        while(pq.size()!=1){
            // take top element out
            int x=pq.top(); 
            pq.pop();
            // take next top element out
            int y=pq.top();
            pq.pop();
            // store addition of two in the previous sum
            sum+=(x+y);
            //push the new data(sum of two) in the priority queue
            // it will insert according to the ascending order
            pq.push(x+y);
        }
        // return calculated sum from the begining to the end
        return sum;
        
    }
};
