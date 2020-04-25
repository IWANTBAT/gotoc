/*leetcode 全排列*/
void dfs_fill(int *src, int *array, int offset, int num, int *used, int **result, int *resultSize, int *returnColumnSizes)
{
	if (offset == num)
	{
		/*所有位置都填入了数字，得到了一种解法*/
		result[*resultSize] = (int *)calloc(num, sizeof(int));
		memcpy(result[*resultSize], array, sizeof(int)* num);
		returnColumnSizes[*resultSize] = num;
		(*resultSize)++;
		return;
	}

	for (int i = 0; i < num; i++)
	{
		/*找到未使用的数字*/
		if (used[i] == 1)
			continue;

		array[offset] = src[i];
		used[i] = 1;/*标记这个数字为已使用*/
		/*在下一个位置选择数字*/
		dfs_fill(src, array, offset + 1, num, used, result, resultSize, returnColumnSizes);
		used[i] = 0;/*清楚这个数字的使用标记，在当前位置上填入下一个未使用数字*/
	}

}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	*returnSize = 0;
	if (numsSize == 0)
		return NULL;

	int **result = (int **)calloc(1000, sizeof(int *));
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));

	int used[numsSize];
	int array[numsSize];
	memset(used, 0x0, sizeof(int)* numsSize);
	memset(array, 0x0, sizeof(int)* numsSize);
	dfs_fill(nums, array, 0, numsSize, used, result, returnSize, *returnColumnSizes);
	return result;
}
