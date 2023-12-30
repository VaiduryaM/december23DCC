//Day 30 - 1897. Redistribute Characters to Make All Strings Equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {

        /*
        //brute force
        int n = words.size();
        if(n==1) return true;
        unordered_map<char,int> freq;
        for(string s:words){
            for(int i=0;i<s.length();i++){
                if(freq.find(s[i]) == freq.end()) freq[s[i]] = 1;
                else freq[s[i]]++;
            }
        }

        for (auto x : freq) 
        {
            if(x.second%n != 0) return false;
        }
        return true;
        */

        //optimized
        int n= words.size();
        vector<int> freq(26,0);
        for(string c:words){
            for(char ch:c){
                freq[ch-'a']++;
            }
        }

        for(int i:freq){
            if(i%n != 0) return false;
        }
        return true;
    }
};