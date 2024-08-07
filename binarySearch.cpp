#include <vector>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            std::cout << "startOfLoop" << "| Left: " << left << " | Mid: " << mid << " | Right: " << right << " |" << std::endl;

            if (nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            } else if(nums[mid] > target){
                right = mid - 1;
            }
            std::cout << "endOfLoop  " << "| Left: " << left << " | Mid: " << mid << " | Right: " << right << " |" << std::endl;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    std::vector<int> v1 = {-1,0,2,4,5,6,7,13,61,111,231,432,1000,2000,2500};
    int target = 432;
    int answer = sol.search(v1,target);
    std::cout <<"Output: "<< answer << std::endl;
}