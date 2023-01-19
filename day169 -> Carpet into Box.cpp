/*
There is a carpet of a size a*b [length * breadth]. You are given a box of size c*d. 
The task is, one has to fit the carpet in the box in a minimum number of moves. 

In one move, you can either decrease the length or the breadth of the carpet by half (floor value of its half).

Note: One can even turn the carpet by 90 degrees any number of times, wont be counted as a move.

 

Example 1:
Input:
A = 8, B = 13
C = 6, D = 10
Output:
Minimum number of moves: 1
Explanation:
Fold the carpet by breadth, 13/2 i.e. 6, 
so now carpet is 6*8 and can fit fine.
 

Example 2:
Input:
A = 4, B = 8
C = 3, D = 10
Output:
Minimum number of moves: 1
Explanation: Fold the carpet by length , 4/2 i.e. 2,
so now carpet is 2*8 and can fit fine.
 

Your Task:
You don't need to read input or print anything. You only need to complete the function carpetBox() that takes an integer A, B, C and D as input 
and returns an integer denoting the minimum numbers of moves required to fit the carpet into the box.

Expected Time Complexity: O( max( log(a), log(b) ) ) .
Expected Auxiliary Space: O(1) .

Constrains:
1<= A,B,C,D <= 109
*/


class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
       
       //to count movement   
        int move=0;
        //priority queue to keep size in descending order so that largest will on top always  
        priority_queue<int> carPet,box;
        // push carpet sizes in carpet priority queue
        carPet.push(A);
        carPet.push(B);
        // push box sizes in box priority queue
        box.push(C);
        box.push(D);
        //run till one of them priority queue is empty
        while(carPet.size() != 0){
            //get large part of carpet
            int temp = carPet.top();
            //if larger side of carpet is lesser or equal to box larger side
            //pop both large side because larger side of carpet can fit into larger side of box
            if(temp<=box.top()){
                carPet.pop();
                box.pop();
            }
            //if larger side of carpet is greater than box larger side
            else{
                //take half of the larger side of carpet and push into the carpet priority queue
                int val = carPet.top()/2;
                //incease the move because when we take half of any side it will consider as 1 move
                move++;
                carPet.pop();
                carPet.push(val);
            }
        }
        //return total performed move 
        return move;
    }
};
