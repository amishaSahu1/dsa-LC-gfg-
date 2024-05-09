class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long sum=0;
        int i=0;
        int count=0;
        while(i<happiness.size() && k>0){
            sum+=max(happiness[i]-count,0);
            count++;
            i++;
            k--;
        }
        return sum;
    }
};