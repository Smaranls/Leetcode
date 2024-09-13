class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int val;
        for(int i=0;i<queries.size();i++){
            int val =0 ;
            int j = queries[i][0];
            int k =queries[i][1];

            if(k==j)
            {
                val = arr[k];
            }

            else{
            while(j<=k){
                val = val ^ arr[j];
                j++;
            }
            }

            ans.push_back(val);
        }

        
    return ans;
    }
};