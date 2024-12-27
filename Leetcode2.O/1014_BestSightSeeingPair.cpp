/***1014. Best Sightseeing Pair
Solved
Medium
Topics
Companies
Hint

You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11

Example 2:

Input: values = [1,2]
Output: 2

 

Constraints:

    2 <= values.length <= 5 * 104
    1 <= values[i] <= 1000

 */


/*************Approach 1 */


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int res=0;
        int max_Till_Now=values[0] +0;   // which is like val[i] +i one part of eqn


        for(int j=1;j<n;j++){
            int a=values[j] -j;
            int b= max_Till_Now;
            res= max(res,a+b);
            max_Till_Now=max(max_Till_Now,values[j]+j);
        }

        return res;




    } 
};



/*******************
 *                      Approach 2
 */


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> vec(n,0); // this initialse the vector with n size and all values to 0
        vec[0]=values[0] + 0; // which is values[i]+ i we assume here vec[i] this is maximum untill we get next max one 

        for(int i=1;i<n;i++){
            vec[i]=max(values[i]+i,vec[i-1]);  // so here values[i] +i is just part of eqn if you just remember here we are storing the max upto index i

        }

        int res=0;

        for(int j=1;j<n;j++){
            int a= values[j] - j;
            int b =vec[j-1]; // this gives max value upto index j just before it 
            // now to find the max value and need to return 
            res=max(res,a+b);
        }
        return res;



    } 
};
