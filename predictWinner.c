#include<iostream>
#include<vector>
#include <bits/stdc++.h>

class Solution {
public:
    bool PredictTheWinner(std::vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        return helper(nums, 0, nums.size()-1)>=0;
    }
    
    int helper(std::vector<int>& nums, int s, int e){        
        if (s > e) 
            return 0;
        int sum = 0;
        sum += std::max(nums[e] - helper(nums, s, e-1), nums[s] - helper(nums, s+1, e));
        std::cout << "sum = "<<sum <<"\n";
	return sum;
    }
};


int main () {
	Solution s;
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(2);
	/*
	nums.push_back(233);
	nums.push_back(7);
	*/
	std::cout<<s.PredictTheWinner(nums) <<"\n";
}
