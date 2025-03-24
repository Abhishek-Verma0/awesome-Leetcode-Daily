/***
 *
 * T.C ->  O( n(log(n)))
 * S.C -> O(n);
 */

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Step 1: Sort meetings by start time to process in order
        sort(meetings.begin(), meetings.end());
        
        int free = 0;  // Stores the count of free days
        int new_end = 0; // Tracks the last occupied day by any meeting

        // Step 2: Iterate over all meetings
        for (auto& i : meetings) {
            int st = i[0]; // Start day of current meeting
            int ed = i[1]; // End day of current meeting

            // Step 3: Count free days before this meeting if there's a gap
            if (st > new_end + 1) {  
                free += st - (new_end + 1);  // Gap between meetings
            }
            
            // Step 4: Extend occupied days range
            new_end = max(new_end, ed);
        }

        // Step 5: Add remaining free days after the last meeting (if any)
        free += days - new_end;
        
        return free;
    }
};
