int findDuplicate(int* nums, int numsSize){
	int fast, slow;

	slow = 0;
	fast = 0;

	do {
		slow = nums[slow];
		fast = nums[nums[fast]];
		//printf("%d, %d, ", slow, fast);
	} while (slow != fast);

	fast = 0;
	do {
		slow = nums[slow];
		fast = nums[fast];
	} while (slow != fast);

	return slow;

}

