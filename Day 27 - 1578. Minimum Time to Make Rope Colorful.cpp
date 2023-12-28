//Day 27 - 1578. Minimum Time to Make Rope Colorful
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        
        //my sol
        int cost = 0;
        //brute force - two pointers
        int left = 0, right = 1;
        bool ll = false;
        int pseudo = 0;
        while(right<colors.length()){

            if(colors[left] == colors[right]){
                //check which is less
                if(neededTime[left] > neededTime[right]){ 
                    cost += neededTime[right];
                    ll = true;
                    pseudo++;
                    
                }else{
                    cost += neededTime[left];
                    left = right;  
                    ll = false;      
                    pseudo = 0;           
                }
                right++;
            }
            else{
                if(ll) {
                    ll = false;
                    left += pseudo;
                    pseudo = 0;
                }
                left++;
                right++;
            }
        }
        return cost;
        
        

        /*

        int time = 0;
        int i=0, j=0;
        int n = neededTime.size();

        while(i<n && j <n){
            int tot=0, maxT=0;

            while(j<n && colors[i] == colors[j]){
                tot += neededTime[j];
                maxT = max(maxT, neededTime[j]);
                j++;
            }

            time += (tot-maxT);
            i=j;
        }
        return time;
        */
    }
};