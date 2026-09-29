class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows == 1 || numRows >= s.size()) return s;
        vector<string>rows(numRows);
        int direction = 1;
        int row = 0;
        for(auto i : s){
            rows[row] += i;
            if(row == 0){
                direction = 1;
            }
            if(row == numRows-1){
                direction = -1;
            }
            row += direction;
        }
        string ans;
        for(auto i:rows){
            ans += i;
        }
        return ans;
    }
};