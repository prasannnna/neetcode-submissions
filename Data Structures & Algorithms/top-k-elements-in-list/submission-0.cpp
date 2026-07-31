class Solution {
public:
    bool cmp(const pair<int, int>mp1, const pair<int, int>mp2){
        return mp1.second > mp2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int n : nums) {
            mp[n]++;
        }
        vector<vector<int>>bucket(nums.size() + 1);
        for(auto &m : mp) {
            bucket[m.second].push_back(m.first);
        }
        for(int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for(int x : bucket[i]) {
                ans.push_back(x);
                if(ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
