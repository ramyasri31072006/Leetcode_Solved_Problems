class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

        int size = 0;

        vector<vector<int>>ans;
        ans.push_back(intervals[0]);

        for(int i = 1; i < n;i++){

            if(ans[size][1] >= intervals[i][0]){
                ans[size][1] = max(ans[size][1],intervals[i][1]);
            }

            else{
                
                ans.push_back(intervals[i]);
                size++;
            }
        }

        return ans;
    }
};