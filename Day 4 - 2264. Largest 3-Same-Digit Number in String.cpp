//Day 4 - 2264. Largest 3-Same-Digit Number in String


class Solution {
public:
    string largestGoodInteger(string num) {
       
        //should return highest     
        string ret="";
        int g = -1;
        for(int i=0; i < num.length()-2; i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                g = max(g,stoi(string(1, num[i])));
            }            
        }
        if(g!=-1){
            ret=to_string(g)+to_string(g)+to_string(g);
            
        }         
        return ret;
        
    }
};