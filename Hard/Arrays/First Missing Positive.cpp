class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size(),a=0,temp=1;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(nums[i]>0) v.emplace_back(nums[i]);
            }
        set<int>s;
        for(int i=0;i<v.size();i++){s.insert(v[i]);}
        v.clear();
        for(auto & i:s){v.emplace_back(i);}
        int sz=v.size();
        if(sz>0){
        sort(v.begin(),v.end());
        if(v[0]!=1) return 1;
        else if(v[0]==1 && sz==1) return v[0]+1;
        else{
            for(int i=0;i<sz;i++){
                if(v[i]!=temp){ a=temp;break;
            } 
            else {temp++;}
        }
        if(temp-1==sz) return v[sz-1]+1;
        else return a;
    }
    }
    else return 1;
    }
};
