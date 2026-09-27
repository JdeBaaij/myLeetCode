#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    std::vector<int> combined;
    combined.reserve(nums1.size() + nums2.size());
    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
               std::back_inserter(combined));

    size_t n = combined.size();
    if (n % 2 == 1)
      return combined[n / 2];
    return (combined[n / 2 - 1] + combined[n / 2]) / 2.0;
  }
};

int main(void) {
  std::vector<int> vec1 = {1, 2};
  std::vector<int> vec2 = {3, 4};

  Solution sol;

  std::cout << "test1: \n"
            << sol.findMedianSortedArrays(vec1, vec2) << std::endl;
}