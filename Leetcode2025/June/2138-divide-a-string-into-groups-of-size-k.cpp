class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> str; // this will store the final chunks
        int n = s.size();   // original size of the string

        // if the string length isn't a perfect multiple of k,
        // we need to add some fill characters to make it so
        if (n % k != 0) {
            int rem = n % k; // how many characters are left out
            for (int i = n; i < n + (k - rem); i++) {
                s += fill; // add fill characters one by one
            }
            n += (k - rem); // update string length after padding
        }

        // now we're ready to divide the string into k-sized chunks
        string st = ""; // temporary string to collect k characters
        int cnt = 0;    // counts how many characters we've added to st
        int i = 0;      // index for looping through the string

        // loop over the entire padded string
        while (i < n) {
            if (cnt < k) {
                st += s[i]; // keep adding characters to current chunk
                cnt++;
                i++;
            } else {
                str.push_back(st); // when chunk is full, store it
                cnt = 0;
                st = ""; // reset for next chunk
            }
        }

        // don't forget to add the last chunk if it has exactly k characters
        str.push_back(st);

        return str; // return the list of k-sized string parts
    }
};
