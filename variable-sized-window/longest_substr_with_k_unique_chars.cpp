// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int max_length = INT_MIN;
        int n = s.size();

        while(j < n) {
            // insert the elem into the map as we move forward
            mp[s[j]]++;

            if(mp.size() < k) j++;
            else if(mp.size() == k) {
                max_length = max(j-i+1, max_length);
                j++;
            }
            else if(mp.size() > k) {
                while(i < j and mp.size() > k) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        
        if(mp.size() < k) return -1;
        
        return max_length;
    }
};