class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int >row;
        row.push_back(1);
        long long val =1;
        for(int i =1;i <=rowIndex;i++){
            val *=(rowIndex+1-i);
            val /= i;
            row.push_back(val);
        }
        return row;
    }
};