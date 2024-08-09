#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
       std::unordered_map<int,int> map;

       for(int i = 0; i < nums.size(); ++i){
            int complement = target - nums[i];

            if(map.find(complement) != map.end()){
                return {map[complement],i};
            }
            map[nums[i]] = i;
       }
       return {};
    }

    void printSolution(const std::vector<int>& vec)const{
        std::cout << "[";
        for(size_t i = 0; i < vec.size(); ++i){
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
        }
};

int main(){
    Solution s;

    std::vector<int> v1 = {2,3,4};
    int target = 6;

    std::vector<int> result = s.twoSum(v1, target);

    std::cout << "Output: ";
    s.printSolution(result);
}