//Day 16 - 242. Valid Anagram


class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        vector<int> freq(26,0);

        for(int i=0; i<t.size();i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i: freq){
            if(i != 0) return false;
        }

        return true;


        /*
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        
        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        
        //why is it running for 114 iterations??????? - because key is alpha and you are comparing using int
        for(int i = 0; i < smap.size(); i++){
            if(smap[i] != tmap[i]) return false;
        }
        return true;
        */
    }
};