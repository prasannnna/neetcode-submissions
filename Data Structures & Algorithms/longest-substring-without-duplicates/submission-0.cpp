class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0, l = 0;
        unordered_map<int, int>mp;
        for(int i = 0; i < s.size(); i++) {
            while(mp[s[i]] == 1) {
                mp[s[l]]--;
                l++;
            }
            longest = max(i - l + 1, longest);
            mp[s[i]]++;
        }
        return longest;
    }
};
