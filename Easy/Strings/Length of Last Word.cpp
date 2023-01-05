class Solution {
public:
    int lengthOfLastWord(string s) {
        int j= s.size()-1;
        while (j>=0 &&s[j]==' ')j--;
        int ans=0;
        while (j>=0 && s[j]!=' '){
            j--;
            ans++;
        }
        return ans;
    }
};
