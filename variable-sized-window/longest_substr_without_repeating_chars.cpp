// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int max_len = INT_MIN;

        if(n == 0) return 0;

        while(j < n) {
            mp[s[j]]++;

            if(mp.size() == j-i+1) {
                max_len = max(j-i+1, max_len);
                j++;
            }
            else if(j-i+1 > mp.size()) {
                while(j-i+1 > mp.size()) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }

        return max_len;
    }
};