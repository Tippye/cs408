//
// Created by 渠继旺 on 2022/10/14.
//
#define
Maxsize 255

typedef struct {
char str[Maxsize];
int len;
} SString;

// 匹配 T 在 S 中的位置
int Index_KMP(SString S, SString T, int next[]) {
int i, j;
i = j = 1;
while (i <= S.len && j <= T.len) {
if (j == 0 || S.str[i] == T.str[j]) {
++i;
++j;
} else {
j = next[j];
}
}
if (j > T.len)
return i - T.len;
return 0;
}