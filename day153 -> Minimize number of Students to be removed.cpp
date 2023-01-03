/*
N Students of different heights are attending an assembly. The heights of the students are represented by an array H[].
The problem is that if a student has less or equal height than the student standing in front of him, then he/she cannot see the assembly.
Find the minimum number of students to be removed such that maximum possible number of students can see the assembly.
 

Example 1:
Input:
N = 6
H[] = {9, 1, 2, 3, 1, 5}
Output:
2
Explanation:
We can remove the students at 0 and 4th index.
which will leave the students with heights
1,2,3, and 5.


Example 2:
Input:
N = 3
H[] = {1, 2, 3} 
Output :
0
Explanation:
All of the students are able to see the
assembly without removing anyone.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function removeStudents() which takes an integer N 
and an array H[ ] of size N as input parameters and
returns the minimum number of students required to be removed to enable maximum number of studentsto see the assembly.


Expected Time Complexity: O(N logN)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 105
1 ≤ H[i] ≤ 105
*/


class Solution {
  public:

    //objective is to find a series that is sorted in ascending order rom the entire given array
    // in order to find ascending order we can neglate the larger elements in between

    int possibleStudent(vector<int> &v){
        
        //create  vector for  possible students
        vector<int> vec;
        
        //push the first student
        vec.push_back(v[0]);
        
        for(int i=1;i<v.size();i++){
            //check if previous is smaller then next then push next in possible students vector
            if(v[i] > vec.back())
               vec.push_back(v[i]);
            
            //otherwise find proper position for next student in the possible student vector
            else{
                int index = lower_bound(vec.begin(),vec.end(),v[i]) - vec.begin();
                vec[index] = v[i];
            }
        }
        
        return vec.size();
    }
   
    int removeStudents(int H[], int N) {
       
       //push the array data into a temporary vector 
        vector<int> v;
        for(int i=0;i<N;i++){
            v.push_back(H[i]);
        }
        
        //find possible number of student in assembly line
        int n = possibleStudent(v);
        
        //return actual length - possible student length
        return N-n;
    }
};

