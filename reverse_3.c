/* 逆序的三位数
题目内容：
程序每次读入一个正三位数，然后输出逆序的数字。注意，当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。
提示：对一个三位数数x，做x%10可以得到它的个位数，做x/100可以得到它的百位数，十位数则通过/和%两个运算的结合可以得到。

输入格式:
你的程序每次读到一个3位的正整数。
输出格式：
输出逆序的数。

输入样例：
163
输出样例：
361*/


#include <stdio.h>

int main() {
    // Initialize
	int input;
	scanf("%d", &input);

	if (input % 100 == 0) {
		printf("%d", input / 100);
	}
	else if (input % 10 == 0) {
		printf("%d%d", input % 100 / 10, input / 100);
	}
	else {
		printf("%d%d%d", input % 10, input % 100 / 10, input / 100);
	}

	return 0;
}
