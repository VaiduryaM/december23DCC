//Day 25 - 91. Decode Ways

class Solution {

public:
    //sol 1 : memoization

    map<int,int> index;
    int memo(int i, string s){

        //if index already present in the map
        if(index.find(i) != index.end()) return index[i];

        //if index has reached end of the string
        if(i == s.length()) return 1;

        //if zero is encountered
        if(s[i] == '0') return 0;

        if(i == s.length()-1) return 1;

    
        //recursive calls
        int decodings = memo(i+1,s);

        //when taking 2 chars at a time
        if(stoi(s.substr(i,2)) <= 26) decodings += memo(i+2,s);

        //save the index
        index[i] = decodings;
        return decodings;


    }
    int numDecodings(string s) {
        //memoization
        return memo(0,s);
    }
};