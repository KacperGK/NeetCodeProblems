#include <stack>
#include <string>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        if(s.length() % 2 != 0){
            return false;
        }
        std::stack<char> stack;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                stack.push(c);
        } else if(c == ')' || c == '}' || c == ']'){
            if(stack.empty()){
                return false;
            }
            char topStack = stack.top();
            stack.pop();

            if ((c == ')' && topStack != '(') ||
                    (c == '}' && topStack != '{') ||
                    (c == ']' && topStack != '[')) {
                    return false;
            }
        }
    }
    return stack.empty();
    }
};

int main(){
    std::string s = "({[]})";
    Solution Sol;
    std::cout << Sol.isValid(s) << std::endl;
}