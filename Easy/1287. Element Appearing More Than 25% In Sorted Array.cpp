// check n/4
class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
     {
        int times = arr.size() / 4;
        for (int i = 0; i + times < arr.size(); ++i)
            if (arr[i] == arr[i + times])
                return arr[i];

        return -1;
    }
};

// binary search approach
class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
     {
        int n = arr.size();
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        int target = n / 4;
        
        for (int candidate : candidates) 
        {
            int left = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
            /*
                left represents the index of the first occurrence of candidate in the original array.
                right represents the index of the last occurrence of candidate in the original array.
            */
            if (right - left + 1 > target)
             {
                return candidate;
            }
        }
        return -1;
    }
};
