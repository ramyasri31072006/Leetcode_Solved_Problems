class Solution {
public:
    void fun(int ind, vector<vector<int>>&Bvec, vector<int>&Svec , vector<int>&candidates, int tar){
        if(tar == 0){
            Bvec.push_back(Svec);
            return;
        }
        for(int i = ind ; i < candidates.size() ; i++){
            if(i > ind && candidates[i] == candidates[i - 1]) continue;
            if(tar < candidates[i]) break;
            Svec.push_back(candidates[i]);
            fun(i + 1, Bvec, Svec, candidates, tar-candidates[i]);
           // tar += candidates[i];
            Svec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>res;
        fun(0 , result , res , candidates, target);
        return result;
        
    }
};