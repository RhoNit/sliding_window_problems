// https://leetcode.com/problems/find-the-longest-semi-repetitive-substring

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i = 0, j = 1;
        int max_len = 1;
        int last_pair_found_at = -1;
        int n = s.size();

        while(j < n) {
            // if you haven't encountered any adjacent pair of same digit,
            // the window is valid in that case, so we would keep increasing the window length
            if(s[j] != s[j-1]) {
                max_len = max(max_len, j-i+1);
                j++;
            }

            // if you have found an adjacent pair of same digit,
            // increase the 'i' and keep checking the condition while shrinking the window
            if(s[j] == s[j-1]) {
                // since the value of `j` is altered from -1,
                // this is the not the first time you've found out any pair
                if(last_pair_found_at != -1) {
                    // bring `i` at the index of last encountered pair
                    i = last_pair_found_at;
                }

                // update the index of the recently found pair
                last_pair_found_at = j;

                max_len = max(max_len, j-i+1);
                j++;
            }
        }

        return max_len;
    }
};