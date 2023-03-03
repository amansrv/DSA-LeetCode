class Solution {
public:
    int strStr(string ha, string needle) {
        // if needle doesn't exist in haystack
        if(ha.find(needle) == string :: npos) return -1;
        
        int n = ha.size() , m = needle.size() ;

        for(int i = 0 ; i < n - m + 1 ; i++ )
            // if any substring in haystack with size m == needle 
            if(needle == ha.substr(i,m) )
                return i;
        return -1;
    }
};
