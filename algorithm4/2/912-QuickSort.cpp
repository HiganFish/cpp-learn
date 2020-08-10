class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void QuickSort(vector<int>& nums, int low, int high)
    {
        if (high <= low)
        {
            return;
        }
        int div = partition(nums, low, high);
        QuickSort(nums, low, div - 1);
        QuickSort(nums, div + 1, high);
    }

    int partition(vector<int>& nums, int low, int high)
    {
        int i = low;
        int j = high + 1;

        while (true)
        {
            while ((nums[++i] < nums[low]) && (i != high))
            {
            }
            while ((nums[--j] > nums[low]) && (j != low))
            {
            }
            if (i >= j)
            {
                break;
            }
            swap(nums[i], nums[j]);
        }

        swap(nums[low], nums[j]);
        return j;
    }
};