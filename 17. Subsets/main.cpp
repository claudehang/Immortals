//
//  main.cpp
//  17. Subsets
//
//  Created by Shuyu on 2018/4/6.
//  Copyright © 2018年 Shuyu. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * @param nums A set of numbers
     * @return: A list of lists
     */
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        std::vector<std::vector<int>> results;
        std::vector<int> subset;
        results.push_back(subset);
        this->calculateSubsets(0, nums, subset, results);
        return results;
    };
private:
    void calculateSubsets(int index,
                          std::vector<int> &nums,
                          std::vector<int> &subset,
                          std::vector<std::vector<int>> &results) {
        
        if (index == nums.size()) {
            return;
        }
        
        subset.push_back(nums[index]);
        
        results.push_back(subset);
        
        this->calculateSubsets(index + 1, nums, subset, results);
        
        subset.pop_back();
        
        this->calculateSubsets(index + 1, nums, subset, results);
        
    };
};

int main(int argc, const char * argv[]) {
    
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    std::vector<std::vector<int>> results;
    
    Solution solve;
    
    results = solve.subsets(nums);
    
    for (int index = 0; index < results.size(); ++index) {
        if (results[index].size() == 0) {
            std::cout << "[]";
        }
        for (int i_index = 0; i_index < results[index].size(); ++i_index) {
            std::cout << "[" << results[index][i_index] << "]";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
