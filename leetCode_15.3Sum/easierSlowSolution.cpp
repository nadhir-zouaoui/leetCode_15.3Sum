#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

bool isNewVec(std::vector<std::vector<int>>& nums, std::vector<int>& newVec) {
    for (std::vector<int>& num : nums) {
        if (std::find(num.begin(), num.end(), newVec[0]) != num.end() &&
            std::find(num.begin(), num.end(), newVec[1]) != num.end() &&
            std::find(num.begin(), num.end(), newVec[2]) != num.end() &&
            std::find(newVec.begin(), newVec.end(), num[0]) != newVec.end() &&
            std::find(newVec.begin(), newVec.end(), num[1]) != newVec.end() &&
            std::find(newVec.begin(), newVec.end(), num[2]) != newVec.end())
            return false;
    }
    return true;
}


std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    int length = nums.size();
    std::vector<std::vector<int>> res;
    for (int i = 0;i < length - 2;i++) {
        for (int j = i + 1;j < length - 1;j++) {
            for (int k = j + 1;k < length;k++) {
                std::vector<int> newVec = { nums[i],nums[j],nums[k] };
                if (nums[i] + nums[j] + nums[k] == 0 && isNewVec(res, newVec)) {
                    res.push_back(newVec);
                    printVector(newVec);
                }
            }
        }
    }
    return res;
}

int main()
{
    std::cout << "slow solution: " << std::endl;
    std::vector<int> test = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
    std::vector<std::vector<int>> res = threeSum(test);
}