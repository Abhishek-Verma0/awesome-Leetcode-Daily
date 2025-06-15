class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string st1 = str;

        int idx = str.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = str[idx];
            replace(begin(str), end(str), ch, '9');
        }

        if (st1[0] != '1') {
            replace(begin(st1), end(st1), st1[0], '1');
        }
        else {
            idx = st1.find_first_not_of("01");
            if (idx != string::npos) {
                char ch = st1[idx];  // <-- only access if valid idx
                replace(begin(st1), end(st1), ch, '0');
            }
            // else: do nothing, no replacement possible
        }

        return stoi(str) - stoi(st1);
    }
};
