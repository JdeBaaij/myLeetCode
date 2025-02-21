#include <iostream>
#include <string>

/*

Initial thought: create a substring and use string.find() to see if the character already exists elsewhere

optimization: string operations are slow( so continuously adding characters to a substring is meh)
first optimization was using a character vec with reserved space

Second optimization: using the vector to check against all ascii characters(128) if the character is already present

 */

class Solution
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		std::vector<bool> seen(128, false);
		int maxLength = 0;
		int start = 0;

		for (int i = 0; i < s.length(); ++i)
		{
			while (seen[s[i]])
			{
				seen[s[start]] = false;
				start++;
			}
			seen[s[i]] = true;
			int currentLength = i - start + 1;
			if (currentLength > maxLength)
			{
				maxLength = currentLength;
			}
		}
		return maxLength;
	}
};

int main(void)
{
	std::string test1 = "abcabcbb";
	std::string test2 = "bbbbb";
	std::string test3 = "abc";

	Solution sol;

	std::cout << "test1: " << sol.lengthOfLongestSubstring(test1) << "\ntest2: " << sol.lengthOfLongestSubstring(test2) << "\ntest3: " << sol.lengthOfLongestSubstring(test3) << std::endl;
}