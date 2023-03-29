#include <vector>
#include <iostream>
#include "string"
#include "stack"

using namespace std;

class Solution{
public:
    float evalRPN(vector<string>& tokens){
        stack<float> stk;
        // 用于从栈中取出两个数
        float tmp_a, tmp_b;
        // 遍历传进来的数组
        for (auto token:tokens) {
            // 这里只考虑字符串为数字或者运算符
            // 如果不是运算符就一定是数字，数字直接入栈
            if(!(token=="+"||token=="-"||token=="*"||token=="/")){
                stk.push((float) atoi(token.c_str()));
            }else{
                // 这里让tmp_a先等于栈顶元素，所以运算的时候tmp_a要放在运算符的后面
                // 例：输入 123 45 -
                //    这里123会先入栈，45后入栈，所以先给tmp_a赋值的话tmp_a=45
                //    所以在下面运算时要用tmp_b - tmp_a
                tmp_a = stk.top();
                stk.pop();
                tmp_b = stk.top();
                stk.pop();
                // string用switch会报错，所以这里用了多个if来判断
                if (token=="+") stk.push(tmp_b + tmp_a);
                if (token=="-") stk.push(tmp_b - tmp_a);
                if (token=="*") stk.push(tmp_b * tmp_a);
                if (token=="/") stk.push(tmp_b / tmp_a);
            }
        }
        // 上边每次读到运算符会把运算后的结果再次放入栈中，所以要返回栈顶元素
        return stk.top();
    }
};

void TestModule(){
    vector<string> tokens;
    string tokens_str;
    getline(cin,tokens_str);
    string temp_word;
    for(char s:tokens_str){
        switch (s) {
            case '$':
            case ' ':
                if (temp_word.length()>0) tokens.push_back(temp_word);
                temp_word = "";
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                if (temp_word.length()>0) tokens.push_back(temp_word);
                temp_word = "";
                temp_word.push_back(s);
                tokens.push_back(temp_word);
                temp_word = "";
                break;
            default:
                temp_word+=s;
        }
    }
    auto solution = new Solution();
    float res = solution->evalRPN(tokens);
    cout << "结果为：";
    cout << res << endl;
}