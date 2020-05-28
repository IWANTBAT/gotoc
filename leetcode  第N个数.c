class Solution {
public:
	int findNthDigit(int n) {
		n -= 1;
		for (long digits = 1; digits < 11; ++digits){
			int first_num = pow(10, digits - 1);
			if (n < 9 * first_num * digits){
				return int(to_string(first_num + n / digits)[n%digits]) - '0';
			}
			n -= 9 * first_num * digits;
		}
		return 0;
	}
};

