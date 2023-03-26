class Solution {
public:
    bool isOverlap(vector<int>& a,vector<int>& b){
        return min(a[1], b[1]) - max(a[0], b[0]) >= 0;
    }

    vector<int> merge(vector<int>& a, vector<int>& b)
    {
        return {min(a[0],b[0]),max(a[1],b[1])};
    }   

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx = upper_bound(intervals.begin(),intervals.end(),newInterval) - intervals.begin();

        if(idx==intervals.size())
            intervals.push_back(newInterval);
        else
            intervals.insert(intervals.begin()+idx,newInterval);
        
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        {
            vector<int> temp{intervals[i][0],intervals[i][1]};
            while(i<intervals.size() && isOverlap(temp,intervals[i]))
                temp = merge(temp,intervals[i++]);
            --i;
            ans.push_back(temp);
        }
        return ans;


    }
};
