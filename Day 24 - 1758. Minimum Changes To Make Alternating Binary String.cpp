//Day 24 - 1758. Minimum Changes To Make Alternating Binary String


class Solution {
public:
    int minOperations(string s) {
        bool startBit = true;
        map<bool,char> bits = {{true,'1'}, {false,'0'}};
        int startOne = 0, startZero = 0;
        for(char i: s){
            if(i != bits[startBit]) startOne++;

            if(i != bits[!startBit]) startZero++;

            startBit = !startBit;
        }

        return min(startOne, startZero);
    }
};