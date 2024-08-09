#include <vector>
#include <iostream>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }

        int m = matrix.size(); // rows
        int n = matrix[0].size(); // col - each vector is row in matrix


        int left = 0;
        int right = m*n - 1; // flatten to 1D matrix so left=0 and right=elements-1

        while(left <= right){
            int mid = left + (right - left) / 2;

            int midValue = matrix[mid/n][mid%n]; //back to 2d row and column
            if (midValue == target){
                return true;
            }else if(midValue < target){
                left = mid + 1;
            } else if(midValue > target){
                right = mid - 1;
            }
        }
        return false;
    }
};


int main(){
    Solution sol;
    std::vector<std::vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=7;
    std::cout << "Output: " << sol.searchMatrix(matrix, target) << std::endl;
}