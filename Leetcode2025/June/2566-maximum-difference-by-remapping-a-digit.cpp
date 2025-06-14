class Solution {
public:
    int minMaxDifference(int num) {
        // convert  input number to  string for easy manipulation
        string str = to_string(num);

        // creating a copy of the original string to use for the "min" number
        string str1 = str;

        // find  first digit in the number that is not '9' to maximaise number
        int idx = str.find_first_not_of('9');

        // If  a digit is found ( number is not all 9s)
        if (idx != string::npos) {
            // get  first digit that is not 9
            char ch = str[idx];

            // replace all occurrences of that digit with '9' in str
            // this gives us the maximum number possible by changing one digit
            replace(begin(str), end(str), ch, '9');
        }

        // Get the first digit of the original number to minimise
        char ch = str1[0];  // as given that leading digits of the numbner is non zero

        // replace all occurrences of that digit with '0' in str1
        // this gives us the minimum number possible by changing one digit
        replace(begin(str1), end(str1), ch, '0');

        // converting both modified strings back to integers and return their difference
        return stoi(str) - stoi(str1);
    }
};
