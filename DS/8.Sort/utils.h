//
// Created by 渠继旺 on 2023/3/2.
//

/**
 * 交换A, B位置
 *
 * @param A
 * @param B
 */
void swap(int &A, int &B) {
    A = A + B;
    B = A - B;
    A = A - B;
}