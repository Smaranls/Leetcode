class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occ;

        for (int i=0;i<arr.size();i++){
            occ[arr[i]]++;
        }

        for(auto c:occ){
            for(auto d:occ)
            {
                if(c.first!= d.first && c.second == d.second){
                    return false;
                }
            }
        }

        return true;
    }
};