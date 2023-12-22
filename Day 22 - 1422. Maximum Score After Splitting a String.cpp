//Day 22 - 1422. Maximum Score After Splitting a String


class Solution {
public:
    int maxScore(string s) {

        /*
        //my sol
        int l = s.length();
        int totOnes = 0;
        for(auto i: s){
            if (i == '1') totOnes++;
        }

        int score = INT_MIN;

        for(int i=0; i<s.length()-1;i++){
            string left = s.substr(0,i+1);
            int zero = 0, ones = 0;
            for(auto j: left){
                if (j == '0') zero++;
                else ones++;
            }
            score = max(score, (zero+(totOnes-ones)));
        }


        return score;
        */

        /*
        //two pass
        int ones = count(s.begin(), s.end(), '1');
        int score = 0, zeros = 0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='1') ones--;
            else zeros++;
            score = max(score, zeros+ones);
        }

        return score;
        */

        //one pass - mathy
        int ones = 0, zeros = 0, score = INT_MIN;

        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '0') zeros++;
            else ones++;

            score = max(score, zeros-ones);
        }

        if(s[s.size()-1]=='1') ones++;

        return score+ones;

    }
};