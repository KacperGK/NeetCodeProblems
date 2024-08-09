#include <string>
#include <cctype>
#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        for(char &c : s){
            c = std::tolower(c);
        }
        std::string normalized;

        for(char c : s){
            if(std::isalnum(c)){
                normalized += c;
            }
        }

        int left = 0;
        int right = normalized.length() - 1;

        while (left < right){
            if(normalized[left] != normalized[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};


int main(){
    Solution sol;
    std::string s = "Was it a car or a cat I saw?";
    std::cout << sol.isPalindrome(s) << std::endl;
}
