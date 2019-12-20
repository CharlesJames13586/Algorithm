#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool flag = true;
        int l = s.length();
        stack <char> stk;
        char temp = NULL;
        for (int i = 0; i < l; i++) {
            switch (s[i]) {
                //��������ջ
                case '(':
                case '{':
                case '[':
                    stk.push(s[i]);
                    break;
                //������ƥ��
                case ')':
                case '}':
                case ']':
                    //�ȼ��ջ�Ƿ�Ϊ��
                    if (!stk.empty()) {
                        temp = stk.top();
                    }
                    else{
                        flag = false;
                        break;
                    }
                    //ƥ��ʧ�ܵ����
                    if (!(s[i] == ')' && temp == '(' || s[i] == '}' && temp == '{' || s[i] == ']' && temp == '[')) {
                        flag = false;
                    }
                    stk.pop();
                    break;
                //�����������Ĭ��ʧ��
                default:
                    flag = false;
                    break;
            }
            if (flag == false)  //�������ƥ��ʧ�ܣ������˳�ƥ�����
                break;
        }
        if (flag == true) {
            if (!stk.empty()) { //�˳�ƥ����̺󣬼��ջ�Ƿ�Ϊ��
                flag = false;
            }
        }
        return flag;
    }
};

//���Ժ���
/*
int main() {
    string s;
    Solution solution;
    while (s!="#") {
        cin >> s;
        if (solution.isValid(s)) {
            cout << "True" << endl;
        }
        else {
            cout << "False" << endl;
        }
    }
    
}
*/
/*
��Ŀ
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
    Output : true
    Example 2 :

    Input : "()[]{}"
    Output : true
    Example 3 :

    Input : "(]"
    Output : false
    Example 4 :

    Input : "([)]"
    Output : false
    Example 5 :

    Input : "{[]}"
    Output : true
*/
