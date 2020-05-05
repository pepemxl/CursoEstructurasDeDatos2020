#include <iostream>
#include <string>
#include <stdio.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> sol;
        bool found = false;
        for (int i = 0; i < n-1;++i){
            for (int j = i+1; j < n;++j){
                if(nums[i]+nums[j]==target){
                    sol.push_back(i);
                    sol.push_back(j);
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        return sol;
    }
};

int main(){

    return 0;
}