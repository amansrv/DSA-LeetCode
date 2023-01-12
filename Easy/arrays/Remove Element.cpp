class Solution {
public:
    int removeElement(vector<int>& nums, int val)
{
	auto it = remove_if(nums.begin(), nums.end(), [&](int i){return i==val;});
	return distance(nums.begin(), it);
}
};
