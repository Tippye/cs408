#include <cstdio>

//
// Created by 渠继旺 on 2023/4/16.
//
int main() {
    //例1
    // x的补码为		    1110 1111 0001 1111
    short x1 = -4321;
    // 无符号位y的二进制为	1110 1111 0001 1111  真值61215
    unsigned short y1 = (unsigned short) x1;
    printf("x1=%d\ny1=%u\n\n", x1, y1);// %u是按unsigned int输出

    //例2
    // x2               1111 1111 1111 1111
    unsigned short x2 = 65535;
    // y2               1111 1111 1111 1111  真值-1
    short y2 = (short) x2;
    printf("x2=%u\ny2=%d", x2, y2);
    return 0;
}