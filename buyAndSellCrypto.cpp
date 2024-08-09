#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }

        bool isDecreasing = true;
        for(size_t i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i-1]){
                isDecreasing = false;
                break;
            }
        }

        if(isDecreasing) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for(size_t i = 1; i < prices.size(); ++i){
            minPrice = std::min(minPrice,prices[i]);
            int currentProfit = prices[i] - minPrice;
            maxProfit = std::max(maxProfit,currentProfit);
        }
        return maxProfit;
    }
};

int main(){
    Solution sol;
    std::vector<int> v1 = {10,1,5,6,7,1};
    std::cout << "Output: " << sol.maxProfit(v1) << std::endl;
}