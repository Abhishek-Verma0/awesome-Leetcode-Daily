/**884. Uncommon Words from Two Sentences
Solved
Easy
Topics
Companies

A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

    1 <= s1.length, s2.length <= 200
    s1 and s2 consist of lowercase English letters and spaces.
    s1 and s2 do not have leading or trailing spaces.
    All the words in s1 and s2 are separated by a single space.

 */

    /**
     * We will use split() function to make two arrays of both strings then we will use concat() 
     *  to  concatenate both arrays into one after all this we will check for the element which occured
     * only once if yes then we will push that into a resultant array then we will return the resultant array 
     */


    /**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
   let arr=s1.split(" ");
   let arr1=s2.split(" ");
    let arr2=arr.concat(arr1);
    let res=[]
    for(let i=0;i<arr2.length;i++){
        let count=0;
        for(let j=0;j<arr2.length;j++){
            if(arr2[i]==arr2[j]){
                count++
            }
        }
        if(count==1){
            res.push(arr2[i]);
        }
    }
    return res;
};