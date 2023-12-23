//1496. Path Crossing


class Solution {
public:
    bool isPathCrossing(string path) {

        map<char,pair<int,int>> dir;
         dir['N']= {0,1};
         dir['E']={1,0};
         dir['S']={0,-1};
         dir['W']={-1,0};

        vector<int> move = {0,0};
        unordered_set<string> visit;
        visit.insert("0,0");
        int x=0, y=0;
        for(auto i:path){
            pair<int, int> direction = dir[i];
            int dx = direction.first;
            int dy = direction.second;

            x += dx;
            y += dy;

            string newMove = to_string(x)+","+to_string(y);
            if(visit.find(newMove) != visit.end()) return true;
            
                visit.insert(newMove);
            
        }

        return false;
                
    }
};