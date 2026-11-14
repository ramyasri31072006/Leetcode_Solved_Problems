class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp;

        // Basic Roman numeral symbols.
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";

        // Standard Roman numerals lo I, X, C maatrame subtract cheyyadaniki vaadatham.
        // Prathi symbol ni daani value ki 5x leda 10x unna symbol mundu pettachu.
        // I mundu pettagalige symbols V, X.
        mp[4] = "IV";     // 5 - 1
        mp[9] = "IX";     // 10 - 1

        // X mundu pettagalige symbols L, C.
        mp[40] = "XL";    // 50 - 10
        mp[90] = "XC";    // 100 - 10

        // C mundu pettagalige symbols D, M.
        mp[400] = "CD";   // 500 - 100
        mp[900] = "CM";   // 1000 - 100

        // Visit values from largest to smallest.
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string res;

        for (int value : values) {
            // Append the symbol and subtract its value while it fits.
            while (num >= value) {
                res += mp[value];
                num -= value;
            }
        }

        return res;
    }
};