class Solution {
    private:
     vector<int> nextSmallerElement(vector<int>& arr,int n){
        stack<int> stack;
    vector<int> ans(n);
    stack.push(-1);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(stack.top()!=-1 && arr[stack.top()]>=curr){
            stack.pop();
        }
        //ans is stack top , smaller element found
        ans[i]=stack.top();
        stack.push(i);
    }
    return ans;
    }
    vector<int> prevSmallerElement(vector<int>& arr,int n){
      stack<int> stack;
    vector<int> ans(n);
    stack.push(-1);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(stack.top()!=-1 && arr[stack.top()]>=curr){
            stack.pop();
        }
        //ans is stack top , smaller element found
        ans[i]=stack.top();
        stack.push(i);
    }
    return ans;  
    }
    int largestRectangleArea(vector<int>& heights,int n) {
       // int n=heights.size();
        vector<int> next(n);
        next= nextSmallerElement(heights,n); //n-p-1 ish formula k n nikalna h

        vector<int> prev(n);
        prev= prevSmallerElement(heights,n); // n-p-1 ish formula ka p nikalna
        
        int area=INT_MIN;
        for(int i=n-1;i>=0;i--){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b= next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(newArea,area);
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> temp(m,0);
        int a=INT_MIN;
         int area=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(matrix[i][j]=='1'){
                 temp[j]++;
                }
                else{
                    temp[j]=0;
                }
            }
            area=max(area,largestRectangleArea(temp,m));
        }
        return area;
    }
};