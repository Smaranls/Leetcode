class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);  // Prefix XOR array
        
        // Build the prefix XOR array
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }
        
        vector<int> ans;
        
        // Answer each query in constant time
        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];
            ans.push_back(prefixXOR[right + 1] ^ prefixXOR[left]);
        }
        
        return ans;
    }
};
