class Solution {
public:
    string intToRoman(int num){

        if(num == 0)
            return "";

        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string symbol[] = {
            "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
        };

        for(int i = 0; i < 13; i++) {
            if(num >= value[i]) {
                return symbol[i] + intToRoman(num - value[i]);
            }
        }
        return "";
        
    }
};