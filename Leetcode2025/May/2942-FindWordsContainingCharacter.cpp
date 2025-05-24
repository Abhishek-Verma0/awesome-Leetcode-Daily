class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        // Result vector to store indices of words that contain the character x
        vector<int> res;

        // Loop through each word in the list
        for(int i = 0; i < words.size(); i++) {
            // Loop through each character of the current word
            for(int j = 0; j < words[i].size(); j++) {
                // If the current character matches the target character x
                if(words[i][j] == x) {
                    // Store the index of the word in the result
                    res.push_back(i);
                    // Break the inner loop as we've already found x in this word
                    break;
                }
            }
        } 
        

        // Return the list of indices where x was found in the word
        return res;
    }
};
