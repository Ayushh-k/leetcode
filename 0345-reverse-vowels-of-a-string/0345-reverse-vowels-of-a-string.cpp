class Solution {
public:
    string reverseVowels(string s) {
        std::unordered_set<char> vwlLst={'a','e','i','o','u','A','E','I','O','U'};
        int i=0,j=s.length()-1;
        while(i<=j){
            if(vwlLst.contains(s[i])&&vwlLst.contains(s[j])){
                char t=s[i];
                s[i]=s[j];
                s[j]=t;
                j--;i++;
            }
            else{
            if(!vwlLst.contains(s[i])){
                i++;
            }
            if(!vwlLst.contains(s[j])){
                j--;
            }
            }
        }
        return s;
    }
};