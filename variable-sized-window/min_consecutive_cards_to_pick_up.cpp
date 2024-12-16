// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int i = 0, j = 0;
        int n = cards.size();
        unordered_map<int, int> mp;
        int min_cnt = INT_MAX;

        while(j < n) {
            mp[cards[j]]++;

            if(mp.size() == j-i+1) j++;

            // that means you have encountered a duplicate element
            else if(j-i+1 > mp.size()) {
                while(j-i+1 > mp.size()) {
                    min_cnt = min(j-i+1, min_cnt);
                    
                    mp[cards[i]]--;
                    if(mp[cards[i]] == 0) mp.erase(cards[i]);
                    i++;
                }
                j++;
            }
        }

        return min_cnt == INT_MAX ? -1 : min_cnt;
    }
};