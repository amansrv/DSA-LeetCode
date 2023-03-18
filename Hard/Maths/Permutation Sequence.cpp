class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        string temp = "";
        for(int i=1;i<=n;i++){
            temp += to_string(i);
        }
        if(k == 1){
            return temp;
        }
        while(next_permutation(temp.begin(), temp.end())){
            k--;
            if(k == 1) {
               ans += temp;
               break;
            }
        }
        return ans;
    }
};
