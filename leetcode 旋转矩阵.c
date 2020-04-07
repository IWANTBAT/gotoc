/*leetcode 26
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include<stdio.h>
#include<windows.h>

int removeDuplicates(int * nums, int numsSize){
	int idx = 0;
	int i = 0;
	int j = 1;
	while (j < numsSize){
		nums[idx++] = nums[i];
		if (nums[i] != nums[j]){
			i++;
			j++;
		}
		else{
			//找第一个不相同的位置
			while (j < numsSize && nums[i] == nums[j]){
				j++;
			}
			i = j;
			j++;
		}
	}
	if (i < numsSize){//保存最后一个值
		nums[idx++] = nums[i];
	}
	return idx;
}

/*leetcode 88 合并两个有序数组
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/

#include<stdio.h>
#include<windows.h>

/*第一种：从前往后先合并小的元素（需要开辟的动态空间）
1：申请一个m+n的数组空间 ret
2：分别遍历两个数组，按照顺序将数组元素放入ret中
3：将未遍历完的数组直接拼接到ret中
4：释放开辟的空间

第二种：从后往前先合并大的元素（不需要开辟空间）
1：确定最后一个元素的位置：pos = m+n-1
2：便利两个数组，将大的元素先放入nums1[pos]中
3：如果第二个数组未遍历完，将其元素放在第一个数组的前面*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

}

/*leetcode 989  数组形式整数加法 
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
*/

/**
* Note: The returned array must be malloced, assume caller calls free().//返回数组必须是动态开辟的，最大位长度
*/

//思路1:将整数K逐步与数组的每一位相加，每次需要丢弃K的个位，然后与数组的下一位相加，最后将结果数组反转输出。
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){

}

/*给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
不占用额外内存空间能否做到？
给定 matrix =
[
[1,2,3],
[4,5,6],
[7,8,9]
],

原地旋转输入矩阵，使其变为:
[
[7,4,1],
[8,5,2],
[9,6,3]
]

*/

void rotate(int** matrix, int matrixSize, int* matrixColSize){
	int k, step, index, temp;
	for (step = matrixSize - 1, index = 0; step>0; step -= 2, index++){
		for (k = 0; k<step; k++){
			temp = matrix[index][index + k];
			matrix[index][index + k] = matrix[index + step - k][index];
			matrix[index + step - k][index] = matrix[index + step][index + step - k];
			matrix[index + step][index + step - k] = matrix[index + k][index + step];
			matrix[index + k][index + step] = temp;
		}
	}
}

