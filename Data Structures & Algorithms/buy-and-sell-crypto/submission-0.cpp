class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_price = INT_MIN, min_so_far = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            min_so_far = min(prices[i], min_so_far);
            max_price = max(max_price, prices[i] - min_so_far);
        }
        return max_price;
    }
};
