



class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int s = rectangles.size();
        vector<vector<int>> ver, hor;

        // Store vertical and horizontal segment ranges
        for (auto i : rectangles) {
            ver.push_back({i[0], i[2]});  // (x1, x2) for vertical cuts
            hor.push_back({i[1], i[3]});  // (y1, y2) for horizontal cuts
        }

        // Sort vertical segments by start coordinate (x1)
        sort(ver.begin(), ver.end());
        int cnt = 1, mx = ver[0][1];  // Initialize cut count and max end point

        // Check for vertical cuts
        for (int i = 1; i < s; i++) {
            if (ver[i][0] < mx) // Overlapping segment, extend max end
                mx = max(mx, ver[i][1]);
            else {  // New non-overlapping cut
                cnt++;
                mx = ver[i][1];
            }
            if (cnt >= 3) return true;  // Found at least 3 valid cuts
        }

        // Sort horizontal segments by start coordinate (y1)
        sort(hor.begin(), hor.end());
        cnt = 1, mx = hor[0][1];

        // Check for horizontal cuts
        for (int i = 1; i < s; i++) {
            if (hor[i][0] < mx) // Overlapping segment, extend max end
                mx = max(mx, hor[i][1]);
            else {  // New non-overlapping cut
                cnt++;
                mx = hor[i][1];
            }
            if (cnt >= 3) return true;  // Found at least 3 valid cuts
        }

        return false; // Not enough valid cuts in either direction
    }
};
