class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto& m : mp) {
            ans.push_back(m.second);
        }
        return ans;
    }
};
