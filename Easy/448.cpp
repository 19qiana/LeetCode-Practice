#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	vector<int> solution;
        // Negate all numbers at index

        for(int i = 0; i < nums.size(); i++)
        {
        	int index = nums[i];
        	if(nums[abs(index) - 1] > 0)
        	{
        		nums[abs(index) -1] = -nums[abs(index) - 1];
        	}
        }
        // Add everything that is not negative
        for(int j = 0; j < nums.size(); j++)
        {
        	if(nums[j] > 0)
        	{
        		solution.push_back(j + 1);
        	}
        }
        
        return solution;
    }
};

// Key points:
// To find missing objects, use nums[i] to mark what is at the nums[i]th index as being used
// Upon iterating through the second time, anything at an index that is not marked negative, is a number
// that is missing from the array.