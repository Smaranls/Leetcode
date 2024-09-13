class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long  zerocounter =0;
        long long  counter =0;
        for (int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zerocounter++;
            }
            else{
                if(zerocounter!=0){
                counter+= (zerocounter)*(zerocounter+1)/2;
                zerocounter =0;}
            }
        }

        if(zerocounter!=0){
            counter+= (zerocounter)*(zerocounter+1)/2;
        }
       return counter ;
        
    }
};