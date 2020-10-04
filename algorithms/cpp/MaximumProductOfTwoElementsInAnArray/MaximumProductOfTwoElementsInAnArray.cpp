//
// Created by 王盟 on 2020/10/4.
//
// Source : https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author : Hao Chen
// Date   : 2020-10-02

/*****************************************************************************************************
 *
 * Given the array of integers nums, you will choose two different indices i and j of that array.
 * Return the maximum value of (nums[i]-1)*(nums[j]-1).
 *
 * Example 1:
 *
 * Input: nums = [3,4,5,2]
 * Output: 12
 * Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum
 * value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
 *
 * Example 2:
 *
 * Input: nums = [1,5,4,5]
 * Output: 16
 * Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of
 * (5-1)*(5-1) = 16.
 *
 * Example 3:
 *
 * Input: nums = [3,7]
 * Output: 12
 *
 * Constraints:
 *
 * 	2 <= nums.length <= 500
 * 	1 <= nums[i] <= 10^3
 ******************************************************************************************************/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=max(nums[0], nums[1]);
        int max2=min(nums[0], nums[1]);

        for (int i=2; i< nums.size(); i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                continue;
            }else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return (max1-1)*(max2-1);
    }
};
44  algorithms/cpp/shuffleTheArray/ShuffleTheArray.cpp
@@ -0,0 +1,44 @@
// Source : https://leetcode.com/problems/shuffle-the-array/
// Author : Hao Chen
// Date   : 2020-10-02

/*****************************************************************************************************
 *
 * Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
 *
 * Return the array in the form [x1,y1,x2,y2,...,xn,yn].
 *
 * Example 1:
 *
 * Input: nums = [2,5,1,3,4,7], n = 3
 * Output: [2,3,5,4,1,7]
 * Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
 *
 * Example 2:
 *
 * Input: nums = [1,2,3,4,4,3,2,1], n = 4
 * Output: [1,4,2,3,3,2,4,1]
 *
 * Example 3:
 *
 * Input: nums = [1,1,2,2], n = 2
 * Output: [1,2,1,2]
 *
 * Constraints:
 *
 * 	1 <= n <= 500
 * 	nums.length == 2n
 * 	1 <= nums[i] <= 10^3
 ******************************************************************************************************/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for (int i=0; i<n; i++) {
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};
