//Day 12 - 1464. Maximum Product of Two Elements in an Array


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int big = 0;
        int sBig = 0;
        for(int e:nums){
            if(e>big){
                
                sBig = big;
                big = e;

            }
            else{
                sBig = max(sBig, e);
            }
        }

        return (big-1)*(sBig-1);

        /*
        //sol 1

        int ret = -1;
        for(int i =0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size();j++){
                ret = max(ret, ((nums[i]-1)*(nums[j]-1)));
            }
        }

        return ret;
        */
        
    }
};