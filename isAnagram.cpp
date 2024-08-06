#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if(s.size() != t.size()){
            return false;
        }


        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());

        return s == t;
    }
};

int main(){
    std::string a = "abc";
    std::string b = "cab";

    Solution sol;

    std::cout << "Output: " << sol.isAnagram(a,b) << std::endl;
}