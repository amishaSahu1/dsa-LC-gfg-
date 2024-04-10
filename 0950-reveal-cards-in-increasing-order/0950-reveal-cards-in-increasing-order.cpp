class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        sort(deck.begin(),deck.end());
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        vector<int>ans(deck.size(),0);
        int count=0;
        while(!q.empty()){
            int front=q.front();
            ans[front]=deck[count];
            q.pop();
            int curr=q.front();
            q.pop();
            q.push(curr);
            count++;   
        }
        return ans;
    }
};