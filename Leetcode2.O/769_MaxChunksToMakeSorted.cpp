/***769. Max Chunks To Make Sorted
Solved
Medium
Topics
Companies
Hint

You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

 

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.

 

Constraints:

    n == arr.length
    1 <= n <= 10
    0 <= arr[i] < n
    All the elements of arr are unique.

 */




/*** 
 * from description we can say that an array will only contain the elements from 0 to n-1
 * n is size of array
 * Now we have three approach to solve this problem
 * 1- We can use cummalative sum approach means if cummalitve sum of array element upto i index and sum of each indx upto i is same then increase chunk count
 * 2- We can check the max element upto each index if index equals to max element then increase count of chunk
 * 
 * 3- We can use prefix and suffix method which we will explain later below just before problem
 */



/*********************Approach 1  Using Cummalitve and orgSum method */

class Solution {
public:
// we know array will have only elements between (0,n-1) 
//in case of sorted we can check the sum if sum is same for both cummlative and org then we can
// make an chunk and increase count of chunks
    int maxChunksToSorted(vector<int>& arr) {
     int siz= arr.size();
     int cumlSum=0;  // this stores the sum of first n elements of array
     int orgSum=0;   // this one is for index based sum from 0 to n-1 
    int count=0; // this will store the count of max chunk we can make so that we get sorted array
     for(int i=0;i<siz;i++){
        cumlSum+=arr[i];
        orgSum+=i;
        //this will check for the sum whether both are equal or not
        if(cumlSum==orgSum){
            count++;
        }
     }
     return count;
    }
};




/*******************----- Approach 2 Using max element upto i index way */



class Solution {
public:

/*
 In this approach we are aware that array will have elements from 0 to n-1 which means if array is
 sorted then each element will be equal to its index value
  Here we check max elements that occured upto i index if both become equal we can make a new chunk
  so we update count++
*/
    int maxChunksToSorted(vector<int>& arr) {
        int count=0;
        int siz=arr.size();
        int maxTillNow=-1;

        for(int i=0;i<siz;i++){
            maxTillNow=max(maxTillNow,arr[i]);

            if(maxTillNow== i){
                count++;
            }
        }
        return count;
    }
};



/********************************Approach 3 -***********
 * -  Sufix and prefix way most a bit complex than above solutions */



/**
 * here we make two extra array one to store the max element upto index i we say it prefixMax
 * other to store min elements from n-1 to i index we say it suffixMin
 * 
 * now we iterate over both arrays  find max element(maxEl) upto i index from prefix array  and max element upto i index in  suffix array (minEl)
 * if maxEl < minEl then we can make a new chunk and increment count of chunks
 */


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        vector<int> prefixMax(begin(arr),end(arr));
        vector<int> suffixMin(begin(arr),end(arr));
        // this stores the max element upto i-1 index at i`th index
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);
        }
        // this stores the min element upto n-i index at i`th index

        for(int i=n-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i],suffixMin[i+1]);
        }


// this one goes for the calculation of chunk count
        for(int i=0;i<n;i++){
            int maxEl=  i > 0 ? prefixMax[i-1]:-1; //pehle ka max   ,checks if index is greater than 0 then it gives prefix else not
            int minEl= suffixMin[i]; // baad ka min

            if(maxEl< minEl){
                count++;
            }
        }
        return count;
    }
};