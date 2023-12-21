//Day 21 - 1637. Widest Vertical Area Between Two Points Containing No Points


class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        
        //my sol
        vector<int> xAxis;
        for (const vector<int>& point : points) {
        xAxis.push_back(point[0]);
        }
        int maxW = INT_MIN;
        sort(xAxis.begin(), xAxis.end());

        for(int i=0; i<xAxis.size()-1;i++){
            maxW = max(maxW, xAxis[i+1] - xAxis[i]);
        }

        return maxW;
        

        /*
        //editorial sol
        sort(points.begin(), points.end());
        
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        
        return ans;
        */
    }
};