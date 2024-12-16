// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        // if(n == 0 or n == 1) return n;

        int i = 0, j = 0;
        unordered_map<int, int> mp;
        int max_cnt = INT_MIN;
        int types_of_fruits = 2;

        while(j < n) {
            mp[fruits[j]]++;

            if(mp.size() < types_of_fruits) j++;
            else if(mp.size() == types_of_fruits) {
                max_cnt = max(max_cnt, j-i+1);
                j++;
            }
            else if(mp.size() > types_of_fruits) {
                while(mp.size() > types_of_fruits) {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        if(mp.size() < types_of_fruits) return mp[fruits[0]];
        return max_cnt;
    }
};