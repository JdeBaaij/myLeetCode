#include <vector>
#include <unordered_map>
#include <cstddef>
#include <iostream>

class Solution
{
private:
	std::unordered_map<int, int> _numMap; // number + index

public:
	std::vector<int> twoSum(std::vector<int> &nums, int target)
	{
		// add the first number to the map
		_numMap[nums[0]] = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			// int second_num = target - nums[i];
			auto it = _numMap.find(target - nums[i]);
			if (it != _numMap.end()) // found match
			{
				return (std::vector<int>{i, it->second});
			}
			_numMap[nums[i]] = i;

			// debugging.
			// std::cout << "-----------\n";
			// for (const auto &pair : _numMap)
			// {
			// 	std::cout << "Number: " << pair.first << ", Index: " << pair.second << std::endl;
			// }
		}
		return (std::vector<int>{}); // returning empty vec if no match is found
	}
};

int main(void)
{
	std::vector<int> nums = {2, 5, 11, 15, 0, 1, 4};
	int target = 9;
	Solution sol;
	std::vector<int> output = sol.twoSum(nums, target);
	if (!output.empty())
		std::cout << "[" << output[0] << "," << output[1] << "]" << std::endl;

	return (0);
}

/**
 * Personal goal: get best time complexity possible (O(n))
 * Allocating some memory is okay, using an unordered_map should be the fastest way to store the numbers and indexes
 */