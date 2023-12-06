//Day 6 - 1716. Calculate Money in Leetcode Bank


class Solution {
public:
    int totalMoney(int n) {
      //cool solution from editorial
        int k = n / 7;
        int F = 28;
        int L = 28 + (k - 1) * 7;
        int arithmeticSum = k * (F + L) / 2;
        
        int monday = 1 + k;
        int finalWeek = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeek += monday + day;
        }
        
        return arithmeticSum + finalWeek;
      
      /*
      //my sol
        int total=0;
        int mon =1;
        int rest = 1;
        int i =1;
        while(i<=n){
            int k = 0;
            if(i%7 == 1) k = mon++;                        
            else  k = rest+1;

            rest = k;
            total +=k;
            i++;
        }

        return total;

      */
    }
};