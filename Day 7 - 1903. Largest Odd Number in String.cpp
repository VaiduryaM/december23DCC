//Day 7 - 1903. Largest Odd Number in String


class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        for(int i = num.length()-1; i>=0; i--){
            if((num[i] - '0')%2==1)  {
                index = i;
                break;
            }  
        }

        if(index != -1) return num.substr(0,index+1);
        else return "";

    }
};