class Solution {
public:
    int search(vector<int>& nums, int target) {

int n=nums.size();

// find pivot
  int s = 0;
  int e = n - 1;
  while (s < e) 
  {
    int mid = s + (e - s) / 2;
    if (nums[mid] >= nums[0]) 
    {
      s = mid + 1;
    } 
    else
      e = mid;
  }
  int pivot = e;

  // apply binary search
  int index=-1;
  if (target <= nums[n - 1] && target >= nums[pivot])
  {
    int start = pivot;
    int end = n - 1;
    while (start <= end) 
    {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) 
      {
        index = mid;
        break;
      } 
      else if (nums[mid] > target) 
      {
        end = mid - 1;
      } 
      else if (nums[mid] < target) 
      {
        start = mid + 1;
      }
    }
  }
  else
  {
    int start = 0;
    int end = pivot - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) 
      {
        index = mid;
        break;
      } 
      else if (nums[mid] > target) 
      {
        end = mid - 1;
      } 
      else if (nums[mid] < target) 
      {
        start = mid + 1;
      }
    }
  }
  return index;



    }
};
