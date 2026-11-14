class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        map<int,int>m;

        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }

        vector<pair<int,int>>v;

        for(auto i : m){
            v.push_back({i.second,i.first});
        }

        sort(v.begin(),v.end(),greater<pair<int,int>>());

        vector<int>ans;
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};