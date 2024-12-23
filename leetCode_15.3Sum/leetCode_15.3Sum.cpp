#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 

        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                res.push_back({ nums[i], nums[j], nums[k] });
                std::cout << nums[i] << " " << nums[j] << " " << nums[k] << std::endl;
                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;
                j++;
                k--;
            }
            else if (sum < 0) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    return res;
}



int main()
{
    std::vector<int> test = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
    std::vector<std::vector<int>> res = threeSum(test);
}
