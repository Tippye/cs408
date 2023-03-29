#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // str为实际操作的字符串
        string str;
        // 去除str中非字母数字的字符
        for (char s_char: s)
            if (isalnum(s_char))
                str += tolower(s_char);

        // n为字符串长度（仅数字字母）
        int n = str.length();
        stack<char> stk;
        int i;

        // 先循环一半，将每个字符放入到栈中
        for (i = 0; i < n / 2; i++)
            stk.push(str[i]);
        // 上一个for循环执行后i在n/2的位置上，比如"abcde"，循环完时i应该指向b
        // 如果字符长度是奇数个，需要让指针后移一位，偶数个就不需要，奇数个时n%2=1，偶数个时n%2=0，所以直接让i加上n%2就可以实现指针的移动
        for (i += n % 2; i < n; i++) {
            // 如果这里栈顶的元素和指针指向的元素相同就把栈顶元素弹出，i向后移动（这一步在for循环中有写）
            // 如果不相同那就说明这个不是回文串，就可以直接返回false
            if (stk.top() == str[i])
                stk.pop();
            else
                return false;
        }
        // 不用担心栈在循环的时候会空，因为栈内的元素是n/2向下取整，i从n/2或n/2+1处开始循环，i<n停止，所以最多也就循环n/2次
        // 所以如果走到这里就说明每一个前半和后半的字符都一样，字符串是回文串，可以直接返回true
        return true;
    }
};

void TestModule() {
    string test_list[5] = {"ab","abba","a","A man, a plan, a canal: Panama","race a car"};
    auto solution = new Solution();
    for(const auto& s:test_list){
        if (s.length()<1) continue;
        bool r = solution->isPalindrome(s);
        cout << s;
        cout << (r ? "是" : "不是");
        cout << "回文串" << endl;
    }
}