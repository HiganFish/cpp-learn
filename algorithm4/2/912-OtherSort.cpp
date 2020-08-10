class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        DownTopMergeSort(nums, 0, nums.size());
        return nums;
    }

    // 自底向上排序
    void DownTopMergeSort(vector<int>&nums, int low, int high)
    {
        int array_size = nums.size();

        for (int child_array_size = 1; child_array_size < array_size; child_array_size *= 2)
        {
            for (int array_sub = 0; array_sub < array_size - child_array_size; array_sub += 2 * child_array_size)
            {
                AbstractInPlaceMergeSort(nums, array_sub, array_sub + child_array_size,
                        std::min(array_sub + child_array_size * 2, array_size));
            }
        }
    }

    // 自顶向下排序
    void TopDownMergeSort(vector<int>& nums, int low, int high)
    {
        if (high - low <= 1)
        {
            return;
        }

        int mid = low + (high - low) / 2;
        TopDownMergeSort(nums, low, mid);
        TopDownMergeSort(nums, mid, high);

        AbstractInPlaceMergeSort(nums, low, (high - low) / 2, high);
    }
    vector<int> AbstractInPlaceMergeSort(vector<int>& nums, int low, int mid, int high)
    {
        int left = 0;
        int right = mid - low;

        vector<int> nums_copy(nums.begin() + low, nums.begin() + high);

        for (int i = low; i < high; ++i)
        {
            if (left >= mid - low)
            {
                nums[i] = nums_copy[right++];
            }
            else if (right >= high - low)
            {
                nums[i] = nums_copy[left++];
            }
            else if (nums_copy[left] < nums_copy[right])
            {
                nums[i] = nums_copy[left++];
            }
            else
            {
                nums[i] = nums_copy[right++];
            }
        }
        return nums;
    }

    // 原地归并排序
    vector<int> AbstractInPlaceMergeSort(vector<int>& nums)
    {
        int nums_size = nums.size();
        int left = 0;
        int right = nums_size / 2;
        int mid = right;

        sort(nums.begin(), nums.begin() + mid);
        sort(nums.begin() + mid, nums.end());

        vector<int> nums_copy(nums);

        for (int i = 0; i < nums_size; ++i)
        {
            if (left == mid)
            {
                nums[i] = nums_copy[right++];
            }
            else if (right == nums_size)
            {
                nums[i] = nums_copy[left++];
            }
            else if (nums_copy[left] < nums_copy[right])
            {
                nums[i] = nums_copy[left++];
            }
            else
            {
                nums[i] = nums_copy[right++];
            }
        }
        return nums;
    }

    // 希尔排序
    vector<int> ShellSort(vector<int>& nums)
    {
        int nums_size = nums.size();
        int gap = nums_size;

        while ((gap /= 2) != 0)
        {
            for (int i = gap; i < nums_size; i += 1)
            {
                int j = i;       
                for (; j >= gap && nums[j] < nums[j - gap]; j-= gap)
                {
                    swap(nums[j], nums[j - gap]);
                }
            }
        }
        return nums;
    }

    // 插入排序
    vector<int> InsertSort(vector<int>& nums)
    {
        int nums_size = nums.size();

        for (int i = 1; i < nums_size; ++i)
        {
            int j = i;
            for (; j >= 1 && nums[j] < nums[j - 1]; j--)
            {
                swap(nums[j], nums[j - 1]);
            }
        }
        return nums;
    }

    // 选择排序
    vector<int> SelectionSort(vector<int>& nums)
    {
        int nums_size = nums.size();

        for (int i = nums_size - 1; i > 0; --i)
        {
            int big_num_sub = i;
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] > nums[big_num_sub])
                {
                    big_num_sub = j;
                }
            }

            swap(nums[big_num_sub], nums[i]);
        }
        return nums;
    }
};