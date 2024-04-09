class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int openCount=0;
        int closeCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                ans.push_back(s[i]);
            }
             else if(s[i]=='('){
                openCount++;
                ans.push_back(s[i]);
            }
            else if(s[i]==')' && openCount>0){
                openCount--;
                ans.push_back(s[i]);
            }
        }
        string answer="";
            for(int i=ans.length()-1;i>=0;i--){
                if(ans[i]>='a' && ans[i]<='z'){
                    answer.push_back(ans[i]);
                }
                else if(ans[i]==')'){
                    closeCount++;
                    answer.push_back(ans[i]);
                }
                else if(ans[i]=='(' && closeCount>0){
                      closeCount--;  
                      answer.push_back(ans[i]);
                }
            }
        reverse(answer.begin(),answer.end());    
        return answer;
    }
};