class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll>mp;
        mp[0]=1; //past m i have seen cum_xor=0
        int cum_xor=0;
        ll result=0;
        for(char &ch:word){
            int shift=ch-'a';
            //1<<shift
            cum_xor^= (1<<shift);
            result+= mp[cum_xor]; //all chars are even in count
            for(char chh='a';chh<='j';chh++){
                shift=chh-'a';
                ll checkxor= (cum_xor ^(1<<shift));
                result+= mp[checkxor];
            }
            mp[cum_xor]++;
        }
        return result;
    }
};