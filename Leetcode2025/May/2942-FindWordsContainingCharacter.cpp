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


//  Second Approach -- Using lamda capture and any_of() -- STL


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n= words.size();
        vector<int> res;

        //  using lamda capture here syntax [] - for capture it capture var out of it's scope can use refrence or value ,, (params)-- it has parmaeter {body}; - remeber body always end woth semicolon(;)

        auto  hasChar= [x](char c){
            return c==x;
        };
        //  here we use any_of stl which returns true if any_char is matched
        for(int i=0;i<n;i++){
            if(any_of(begin(words[i]),end(words[i]),hasChar)==true){
                res.push_back(i);
            }
        }
return res;
    }
};
