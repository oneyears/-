//
//  main.cpp
//  Leetcode20ValidParentheses
//
//  Created by Neworigin on 18/5/20.
//  Copyright © 2018年 Neworigin. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;
//==========================
//leetcode 函数
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '('||s[i]=='{'||s[i]=='[')
                stack.push(s[i]);
            else{
                if(stack.size() == 0)
                    return false;
                char c = stack.top();
                stack.pop();
                char match;
                if(s[i] == ')')
                    match = '(';
                else if (s[i] == ']')
                    match = '[';
                else{
                    assert(s[i] == '}');
                    match = '{';
                }
                if(c != match)
                    return false;
            }
        }
        if(stack.size()!= 0)
            return false;
        return true;
    }
};
int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    return 0;
}
