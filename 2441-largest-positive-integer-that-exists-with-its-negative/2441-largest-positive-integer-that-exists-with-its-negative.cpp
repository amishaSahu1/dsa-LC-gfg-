class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                mp[nums[i]]++;
            }
        }
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
           if(nums[i]>0 && mp.find(-1*nums[i])!=mp.end() && nums[i]>maxi){
            maxi=nums[i];
           }
        }
        return maxi;
    }
};