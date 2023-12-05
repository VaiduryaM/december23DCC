// Day 5 - 1688. Count of Matches in Tournament


class Solution {
public:
    int numberOfMatches(int n) {
        
        return n-1;
        /*
        //solution 1
        int matches = 0;
        while(n != 1){
            int q = n/2;
            n = q + n%2;
            matches += q;
        }

        return matches;
        */

    }
};