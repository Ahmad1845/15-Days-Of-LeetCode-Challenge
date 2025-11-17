class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int p : prices) {
            // update minimum price seen so far
            if (p < minPrice)
                minPrice = p;

            // calculate profit if selling today
            int profit = p - minPrice;
            if (profit > maxProfit)
                maxProfit = profit;
        }

        return maxProfit;
    }
};
