/*leetcode 1248 统计【优美子数组】
给你一个整数数组 nums 和一个整数 k。
如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
请返回这个数组中「优美子数组」的数目
*/
/*双指针，当维护的区间中的奇数个数cntcnt达到kk时，
保存此位置为k\_cnt\_right\_begink_cnt_right_begin，
然后再将右端点rr往右移直到指针到数组边界或右边的数字是个奇数（会导致cntcnt加11）。
此时移动左端点ll，每次移动对答案的贡献是r - k\_cnt\_right\_begin + 1r−k_cnt_right_begin+1，
即左端点为ll，右端点落在[k\_cnt\_right\_begin, r][k_cnt_right_begin,r]的区间。
移动ll并更新cntcnt直到cnt < kcnt<k。此时再移动右指针。
重复以上步骤直到遍历完数组即可。
时间复杂度 O(N)O(N) ，空间复杂度 O(1)O(1) 。
*/

int numberOfSubarrays(vector<int>& nums, int k) {
	int n = nums.size();

	int l = 0, r = -1, cnt = 0;
	int ans = 0;
	while (r + 1 < n) {
		// 在 cnt < k 时继续拓展右端点
		while (r + 1 < n && cnt < k) cnt += nums[++r] & 1;
		if (r >= n) break;
		int k_cnt_right_begin = r;

		// 在维持 cnt == k 的前提下，再尽量移动右端点
		while (r + 1 < n && !(nums[r + 1] & 1)) ++r;

		// 则满足 cnt == k 的区间的左端点为 l
		// 右端点为 [k_cnt_right_begin, r] 之一
		while (l <= r && cnt == k) {
			ans += r - k_cnt_right_begin + 1;
			cnt -= nums[l++] & 1;
		}
	}

	return ans;
}