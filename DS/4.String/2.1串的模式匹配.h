//
// Created by 渠继旺 on 2022/10/14.
//
#define Maxsize 255

typedef struct {
    char str[Maxsize];
    int len;
} SString;

// 匹配 T 在 S 中的位置
int Index(SString S, SString T) {
    int i, j;
    i = j = 0;
    while (i < S.len && j < T.len) {
        if (S.str[i] == T.str[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.len)
        return i - j;//这里的i因为匹配，指向串尾，所以要减去 j 让 i 指向串头
    return -1;
}