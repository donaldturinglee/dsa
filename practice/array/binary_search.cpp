// Iterative Implementation
int binary_search(int nums[], int target, int length)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        // Finding the mid using floor division
        int mid = left + ((right - left) / 2);
        // Target value is present at the middle of the array
        if (nums[mid] == target)
            return mid;
        // Target value is present in the right subarray
        else if (nums[mid] < target)
            left = mid + 1;
        // Target value is present in the left subarray
        else if (nums[mid] > target)
            right = mid - 1;
    }
    // Target value is not present in the array
    return -1;
}

// Recursive Implementation
int binary_search_recursive(int nums[], int target, int left, int right)
{
    if (left > right)
        return -1;
    
    // Finding the mid using floor division
    int mid = left + ((right - left) / 2);

    // Target value is present at the middle of the array
    if (nums[mid] == target)
        return mid;
    // Target value is present in the high subarray
    else if (nums[mid] < target)
        return binary_search_recursive(nums, target, mid + 1, right);
    // Target value is present in the low subarray
    else
        return binary_search_recursive(nums, target, left, mid - 1);
}

int binary_search(int nums[], int target, int length)
{
    return binary_search_recursive(nums, target, 0, length - 1);
}