class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalZor=0;
        for(int &i:nums){
            totalZor^=i;
        }
        int diff=(totalZor^k);
        return __builtin_popcount(diff);
    }
};