//Day 2 - 1160. Find Words That Can Be Formed by Characters


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        unordered_map<char, int> counts;
        for (char c : chars) {
            counts[c]++;
        }
        
        int ans = 0;
        for (string word : words) {
            unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }
            
            bool good = true;
            for (auto& [c, freq] : wordCount) {
                if (counts[c] < freq) {
                    good = false;
                    break;
                }
            }
            
            if (good) {
                ans += word.size();
            }
        }
        
        return ans;

        /*
        //My sol
        map<char,int> freq;
        for(auto i:chars){
            if(freq.find(i)!=freq.end()) freq[i]++;
            else freq[i] =1;
        }
        
        int result = 0;

        // Check if words can be formed
        for (auto word : words) {
            map<char, int> tempFreq = freq;  // Create a copy of freq for each word
            bool canFormWord = true;

            for (auto ch : word) {
                if (tempFreq.find(ch) != tempFreq.end() && tempFreq[ch] > 0) {
                    tempFreq[ch]--;
                } else {
                    canFormWord = false;
                    break;
                }
            }

            if (canFormWord) {
                result += word.length();
            }
        }

        return result;
        */
        
    }
};