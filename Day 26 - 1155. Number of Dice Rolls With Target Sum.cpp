//Day 26 - 1155. Number of Dice Rolls With Target Sum

class Solution {
public:
    const int MOD = 1e9+7;
    /*
    //recursive brute force - exceeds time limit

    int rolls(int dice, int faces, int target, int sum){
        
        //base
        if(dice == 0) return (sum==target?1:0);

        int totRolls = 0;
        for(int i=1; i<=faces; i++){
            totRolls += rolls(dice-1, faces, target, sum+i);
        }

        return totRolls;
        
    }
    */

    int rolls(vector<vector<int>>& memo, int diceIndex, int dices, int sum, int target, int faces){

        //when all the n dices are rolled, target should be reached
        if(diceIndex == dices) return sum == target;

        //using memo
        if(memo[diceIndex][sum] != -1) return memo[diceIndex][sum];

        int totRolls = 0;
        for(int i=1; i<= min(faces, target-sum); i++){
            totRolls = (totRolls+rolls(memo, diceIndex+1, dices, sum+i, target, faces))%MOD;
        }
        //The entire expression is part of a return statement, meaning that the value calculated (in this case, ways) is returned by the function. This value is also simultaneously stored in the memo matrix at the specified indices.
        return memo[diceIndex][sum] = totRolls;
    }

    int numRollsToTarget(int n, int k, int target) {

        //solution 1
        //brute force - recursion - roll n dices, iterate over k values such that at end sum = target
         //return rolls(n,k,target,0); //exceeds time limit


        /*
        //solution 2
         //top down - memoi

        //n+1: The outer vector has a size of n+1. This suggests that there are n+1 rows in the 2D matrix.

        //vector<int>(target+1, 1): Each row is initialized as a vector of integers with a size of target+1. The inner vector is filled with -1 as the initial value.

         vector<vector<int>> memo(n+1, vector<int>(target+1,-1));

         return rolls(memo, 0, n, 0, target, k);
         */

        //solution 3 - bottom up approach
        vector<vector<int>> memo(n+1, vector<int>(target+1, 0));
        memo[n][target] = 1;

        for(int diceIndex=n-1; diceIndex >= 0; diceIndex--){
            for(int sum=0; sum<=target; sum++){
                int totRolls = 0;

                for(int i=1;i<=min(k,target-sum);i++)
                totRolls = (totRolls + memo[diceIndex+1][sum+i]) % MOD;

                memo[diceIndex][sum] = totRolls;
            }
        }

        return memo[0][0];
    }

};