class Solution {
public:
   vector<int> genarate_rows(int n){
    vector<int>row;
    row.push_back(1);
    int val =1;
    for(int i=1;i<n;i++){
        val *= (n-i);
        val /=i;
        row.push_back(val);
    }
    return row;
   }
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>triangle;
        for(int i=1;i<=numRows;i++){
           triangle.push_back(genarate_rows(i));
        }
        return triangle;
    }
};