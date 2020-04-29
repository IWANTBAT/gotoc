﻿//leetcode 字符串转整数

/*
因为不需要读入空格，因此无论左边有多少空格直接无视，直接移动str指针到第一个不是空格的位置上。
然后判断符号位，此时存在三种情况：'+'、'-'和无正负号，因此选择使用switch，当没有符号的时候不需要任何操作，当是-号时使flag = -1。因为无论是'+'还是'-'最后都要使str移动到下一个位置，因此不需要break。
排除完不是数字的情况后，逐个将数字字符转化为整数，同时判断溢出。写在循环内部的判断可以使循环次数限制在int的最大位数内。
*/
int myAtoi(char* str) {
	long ret = 0;
	int flag = 1;//默认正数
	//去除空格及判断符号位
	for (; *str == 32; str++);
	switch (*str) {
	case 45:
		flag = -1;
	case 43:
		str++;
	}
	//排除非数字的情况
	if (*str < 48 || *str>57) return 0;

	while (*str >= 48 && *str <= 57) {
		ret = ret * 10 + (*str - 48);
		//判断溢出
		if ((int)ret != ret) {
			return (flag == 1) ? (INT_MAX) : (INT_MIN);
		}
		str++;
	}
	ret *= flag;
	return (int)ret;
}
