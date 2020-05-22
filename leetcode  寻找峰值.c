int findPeakElement(int* nums, int numsSize){
	int low = 0;
	int high = numsSize - 1;
	int mid = 0;

	while (low + 1 < high)
	{
		mid = low + (high - low) / 2; // 向下取整

		if (nums[mid] < nums[mid + 1])
		{
			low = mid;
		}
		else if (nums[mid] > nums[mid + 1])
		{
			high = mid;
		}
	}

	if (nums[low] < nums[high])
	{
		return high;
	}
	else // (nums[low] > nums[high])
	{
		return low;
	}
}
