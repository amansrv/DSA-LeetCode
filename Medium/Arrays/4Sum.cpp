class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end()); 
        set<vector<int>> set;
        vector<vector<int>> v;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newtarget= (long long)target - (long long)nums[i]- (long long)nums[j];
                int start=j+1, end=n-1;
                while(start<end){
                    if(nums[start]+nums[end]<newtarget)
                        start++;
                    else if(nums[start] + nums[end]> newtarget)
                        end--;
                    else{
                        set.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    }
                }
            }
        }
        for(auto i: set){
            v.push_back(i);
        }
        return v;
    }
};
