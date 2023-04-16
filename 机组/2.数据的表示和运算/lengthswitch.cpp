#include <cstdio>

//
// Created by 渠继旺 on 2023/4/16.
//
int main(){
    //例1
    // int 占用32位(4B)
    //x: 0x000286a1
    //u: 0xffff7751
    int x = 165537, u = -34991;
    //y: 0x86a1
    //v: 0x7751
    short y = (short) x, v = (short) u;
    printf("x=%d, y=%d\n", x, y);//x=165537,y=-31071
    printf("u=%d, v=%d\n", u, v);//u=-34991,v=30545

    //例2
    //x1: 0xef1f
    //y1: 0xffffef1f
    short x1 = -4321;
    int y1 = x1;
    //u1: 0xef1f
    //v1: 0x0000ef1f
    unsigned short u1 = (unsigned short)x1;
    unsigned int v1 = u1;
    printf("x=%d, y=%d\n", x1, y1);//x=-4321, y=-4321
    printf("u=%d, v=%d\n", u1, v1);//u=61215, v=61215
    return 0;
}