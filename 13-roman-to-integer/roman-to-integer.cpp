class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.size();
        int ans = 0;

        map<char, int>m;
        m['I'] = 1;
        m['X'] = 10;
        m['V'] = 5;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        ans = m[s[n-1]];
        for(int i = n-2; i >= 0; i--){

            if(m[s[i]] >= m[s[i+1]]) ans += m[s[i]];

            else ans-= m[s[i]];
        }
        
        return ans;
    }
};