//Day 11 - 1287. Element Appearing More Than 25% In Sorted Array


class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        /*
        //what i wrote
     int app = arr.size()/4;
     unordered_map<int,int> freq;
     
     for(int i=0;i<arr.size();i++)
        {
            if(freq.find(arr[i]) != freq.end())
                freq[arr[i]]++;
            
            else freq[arr[i]] = 1;

            if(freq[arr[i]]>app) return arr[i];
        }
        return -1;
        */
        //editorial - binary search
        int n = arr.size();
        vector<int> ele = {arr[n/4], arr[n/2], arr[3*n/4]};

        int t = n/4;

        for(int e: ele){
            int l = lower_bound(arr.begin(), arr.end(), e) - arr.begin();
            int r = upper_bound(arr.begin(), arr.end(), e) - arr.begin() - 1;

            if(r-l+1 > t) return e;
        }

        return -1;
    }
};