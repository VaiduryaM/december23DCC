//Day 19 - 2706. Buy Two Chocolates


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int m = money;
        m = m - prices[0];
        if(m > 0){
            m = m - prices[1];
                  
        if(m >= 0) return m;        
        }
        return money;           
    }
};