int findMin(int* nums, int numsSize){
	if (numsSize == 1)return nums[0];
	int left = 0, right = numsSize - 1;
	while (right>left){
		int mid = left + (right - left) / 2;
		if (nums[mid]>nums[right]){   
			left = mid + 1;     //右半边找
		}
		else{              //左半边找
			right = mid;    
		}
	}
	return nums[left];
}
