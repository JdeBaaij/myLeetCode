from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}  # number + index
        num_map[nums[0]] = 0  # add the first number to the map
        for i in range(1, len(nums)):
            if target - nums[i] in num_map:  # found match
                return [i, num_map[target - nums[i]]]
            num_map[nums[i]] = i

            # debugging
            # print("-----------")
            # for num, index in num_map.items():
            #     print(f"Number: {num}, Index: {index}")

        return []  # returning empty list if no match is found

if __name__ == "__main__":
    nums = [2, 5, 11, 15, 0, 1, 4]
    target = 9
    sol = Solution()
    output = sol.twoSum(nums, target)
    if output:
        print(f"[{output[0]},{output[1]}]")