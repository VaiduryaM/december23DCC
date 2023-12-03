//Day 1 - 1662. Check If Two String Arrays are Equivalent


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1, str2;
        for(auto i : word1) str1+=i;

        for(auto i: word2) str2+=i;
        if(strcmp(str1.c_str(), str2.c_str())==0) return true;
        else return false;
        

    }
};