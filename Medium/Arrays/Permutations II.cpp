class Solution {
public:
        vector<vector<int>> ans;
        set <vector<int>> s;  //set used to remove duplicates
    void helper(vector<int> &vec,vector<int>& nums,vector<int> &present,int j)
    {
        if(j>=nums.size())
        {
            s.insert(vec);
        }
        if(nums.size()<j)
            return;
        for(int i=0;i<nums.size();i++)
        { 
             if(present[i]==0)
        {
            vec.push_back(nums[i]);
            present[i]=1;
            helper(vec,nums,present,j+1);
            vec.pop_back();
            present[i]=0;
        }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<int> vec;
        vector<int> present;
       sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            present.push_back(0);
        }
        helper(vec,nums,present,0);  
        for(auto it:s){
            ans.push_back(it);      
        }
        return ans;
    }
};
