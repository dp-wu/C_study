
/* 1。 多项式加法（5分）（这个题目有点烦，小细节很多，挺简单的一道题我花了挺多时间才通过所有测试集，而且mooc的oj还不给测试集，基本全靠猜。）

题目内容：
一个多项式可以表达为x的各次幂与系数乘积的和，比如：
2x6+3x5+12x3+6x+20
现在，你的程序要读入两个多项式，然后输出这两个多项式的和，也就是把对应的幂上的系数相加然后输出。
程序要处理的幂最大为100。

输入格式:
总共要输入两个多项式，每个多项式的输入格式如下：
每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，所有的系数都是整数。第一行一定是最高幂，最后一行一定是0次幂。
注意第一行和最后一行之间不一定按照幂次降低顺序排列；如果某个幂次的系数为0，就不出现在输入数据中了；0次幂的系数为0时还是会出现在输入数据中。

输出格式：
从最高幂开始依次降到0幂，如：
2x6+3x5+12x3-6x+20
注意其中的x是小写字母x，而且所有的符号之间都没有空格，如果某个幂的系数为0则不需要有那项。

输入样例：
6 2
5 3
3 12
1 6
0 20
6 2
5 3
2 12
1 6
0 20

输出样例：
4x6+6x5+12x3+12x2+12x+40
*/


// 这段代码我没注释因为前前后后删掉重写了好几遍到最后真的没心情注释了。大家凑合看吧。
#include <stdio.h>

void get_input(int *arr) {
    int n1, n2;
    do {
        scanf("%d%d", &n1, &n2);
        arr[n1] = n2;
    } while (n1 != 0);
}

int main() {
    int p1[101] = {0}, p2[101] = {0}, p[101] = {0};

    get_input(p1);
    get_input(p2);
    
    
    
    int start = 0, ind = 0;
    for (int i=100; i>=0; --i) {
        p[i] = p1[i] + p2[i];
        if (start == 0 && p[i] != 0) {
            start = 1;
            ind = i;
            continue;
        }
    }
    
    if (p[ind] > 1 || p[ind] < -1) printf("%dx%d", p[ind], ind);
    else if (p[ind] == 1) printf("x%d", ind);
    else if (p[ind] == -1) printf("-x%d", ind);
    
    if (ind == 0) printf("%d", p[ind]);
    else if (ind == 1) {
        if (p[ind] == 0) {
            if (p[ind-1] == 0) printf("0");
            else printf("%d", p[ind]);
        }
        else {
            if (p[ind-1] == 0) printf("%dx+0", p[ind]);
            else if (p[ind-1] > 0) printf("%dx+%d", p[ind], p[ind-1]);
            else printf("%dx%d", p[ind], p[ind-1]);
        }
    }
    
    if (ind > 1) {
        for (int i=ind-1; i>1; --i) {
            if (p[i] > 1) printf("+%dx%d", p[i], i);
            else if (p[i] == 1) printf("+x%d", i);
            else if (p[i] == -1) printf("-x%d", i);
            else if (p[i] < -1) printf("%dx%d", p[i], i);
        }
        
        if (p[1] > 1) printf("+%dx", p[1]);
        else if (p[1] < -1) printf("%dx", p[1]);
        else if (p[1] == 1) printf("+x");
        else if (p[1] == -1) printf("-x");
        
        if (p[0] >= 0) printf("+%d", p[0]);
        else printf("%d", p[0]);
    }
    

  return 0;
}
