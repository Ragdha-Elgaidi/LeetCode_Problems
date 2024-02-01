class Solution 
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        vector<vector<int>> result;

        // Sort the input array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        // Iterate through the sorted array and group elements
        for (int i = 0; i < n; i += 3) 
        {
            // Check if the current group of 3 elements satisfies the condition
            if (i + 2 < n && nums[i + 2] - nums[i] <= k) 
            {
                result.push_back({nums[i], nums[i + 1], nums[i + 2]});
            } else 
            {
                // If the condition is not satisfied, return an empty array
                return {};
            }
        }
        return result;
    }
};
