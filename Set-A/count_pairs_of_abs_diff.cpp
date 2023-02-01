//problem link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/

// 2006. Count Number of Pairs With Absolute Difference K

/*Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.
The value of |x| is defined as:

x if x >= 0.
-x if x < 0.
 
Example 1:
Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1] */

#include <bits/stdc++.h>
using namespace std;
 
//brute force approach 
 int countKDifference(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        int diff=0;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<j;i++)
            {
                diff=nums[i] - nums[j];
                if(diff==k || 0-diff==k)
                count++;
            }
        }
        return count;
    }

//optimal approach
int countKDifference(vector<int>& nums, int k) {
        // TC: O(n), SC: O(n)
        // can be done using 2 pointer or binary serach for that we need to sort it 
        // it will take TC: O(nlogn) then
        unordered_map<int,int> mpp;
        int res = 0;
        for(int j = 0;j<nums.size();j++)
        {
            int num1 = nums[j]-k;
            int num2 = nums[j]+k;
            res += mpp[num1];
            res += mpp[num2];
            mpp[nums[j]]++;
        }
        return res;
}
    
//Time Complexity - Iterating over the array takes O(N) time.
//Space Complexity - Since we are storing the elements in a hashmap, space complexity is O(N).
//Explanation - Upon solving the equation |x - y| = k, we find that y can be either x + k or x - k. 
//If these values are present in the hashmap, we can form a pair. 
//Thus for every x in the array, we add the frequency of x + k and x - k to count, and add the current x to the hashmap.

    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;
        // |x - y| = k => y = x + k or y = x - k

        for(auto x : nums){
            count +=  mp[x + k] + mp[x - k]; // If y1 and/or y2 is present, they can form a pair with x
            mp[x]++;
        }
        return count;
    }
