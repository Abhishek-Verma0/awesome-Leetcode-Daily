/**1813. Sentence Similarity III
Solved
Medium
Topics
Companies
Hint

You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

For example,

    s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
    s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1, it is not separated from "Frog" by a space.

Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar. Otherwise, return false.

 

Example 1:

Input: sentence1 = "My name is Haley", sentence2 = "My Haley"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "name is" between "My" and "Haley".

Example 2:

Input: sentence1 = "of", sentence2 = "A lot of words"

Output: false

Explanation:

No single sentence can be inserted inside one of the sentences to make it equal to the other.

Example 3:

Input: sentence1 = "Eating right now", sentence2 = "Eating"

Output: true

Explanation:

sentence2 can be turned to sentence1 by inserting "right now" at the end of the sentence.

 

Constraints:

    1 <= sentence1.length, sentence2.length <= 100
    sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
    The words in sentence1 and sentence2 are separated by a single space.

 */



/**
 * @param {string} sentence1
 * @param {string} sentence2
 * @return {boolean}
 */
var areSentencesSimilar = function(sentence1, sentence2) {
    // Helper function to split a sentence into words
    const splitWords = (sentence) => sentence.split(" ");

    // Split both sentences into arrays of words
    let words1 = splitWords(sentence1);
    let words2 = splitWords(sentence2);

    // Ensure words1 is the longer sentence
    if (words1.length < words2.length) [words1, words2] = [words2, words1];

    let start = 0, end = 0;
    let n1 = words1.length, n2 = words2.length;

    // Compare from the start
    while (start < n2 && words1[start] === words2[start]) start++;

    // Compare from the end
    while (end < n2 && words1[n1 - end - 1] === words2[n2 - end - 1]) end++;

    // Check if the remaining unmatched part is in the middle
    return start + end >= n2;
};
