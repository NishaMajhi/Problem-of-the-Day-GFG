/*
Given a matrix of size n x n such that it has only one 0, Find the positive number (greater than zero) to be placed in place of the 0 such that
sum of the numbers in every row, column and two diagonals become equal. If no such number exists, return -1.

Note: Diagonals should be only of the form matrix[i][i] and matrix[i][n-i-1]. n is always greater than 1.
 

Example 1:

Input: matrix = {{5, 5}, {5, 0}}
Output: 5
Explanation: The matrix is
5 5
5 0
Therefore If we place 5 instead of 0, all
the element of matrix will become 5. 
Therefore row 5+5=10, column 5+5=10 and 
diagonal 5+5=10, all are equal.



Example 2:

Input: matrix = {{1, 2, 0}, {3, 1, 2}, 
{2, 3, 1}}
Output: -1
Explanation: It is not possible to insert 
an element in place of 0 so that the 
condition is satisfied.thus result is -1. 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function MissingNo() which takes the matrix as input parameter and
returns the number which should be placed in place of 0 such that the condition gets satisfied. If not possible return -1.


Expected Time Complexity: O(n * n)
Expected Space Complexity: O(2 * n)
 

Constraints:
2 <= n <= 1000
1 <= elements in the matrix <= 10^9
*/



class Solution {
public:
    #define ll long long int
    long long int MissingNo(vector<vector<int> >&v) {
        // Code here
        ll sum =0,sum0=0,x;
        
        for(int i=0; i<v[0].size(); i++)
        {
            sum0+=v[0][i];
        }
        
        for(ll i=0; i<v.size(); i++)
        {
            sum=0;
            for(ll j=0; j<v[i].size(); j++)
            {
                sum+=v[i][j];
            }

            if(sum!=sum0)
            {
                x= abs(sum-sum0);
                break;
            }
        }
        
        ll row=0,col=0,diag1=0,diag2=0;
        set<ll>s;
        
        for(ll i=0; i<v.size(); i++)
        {
            row=0;
            
            for(ll j=0; j<v[i].size(); j++)
            {
                if(v[i][j]==0)
                {
                    row+=x;
                }
                else
                    row+=v[i][j];
            }
            
            s.insert(row);
        }
        
        if(s.size()>1) return -1;
        
        for(ll i=0; i<v.size(); i++)
        {
            col=0;
            
            for(ll j=0; j<v[i].size(); j++)
            {
                if(v[j][i]==0)
                {
                    col+=x;
                }
                else
                    col+=v[j][i];
            }
            
            s.insert(col);
        }
       
        if(s.size()>1) return -1;
        
        for(ll i=0; i<v.size(); i++)
        {
            if(v[i][i]==0)
            {
                diag1+=x;
            }
            else
                diag1+=v[i][i];
                
            if(v[i][v.size()-i-1]==0)
            {
                diag2+=x;
            }
            else
                diag2+=v[i][v.size()-i-1];
        }
        s.insert(diag1);
        s.insert(diag2);
        
        if(s.size()>1) return -1;
        else return x;
    }
    
};

