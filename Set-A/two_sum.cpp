//1. Two Sum
//Easy

/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]  */


#include<bits/stdc++.h>
using namespace std;

//brute force approach having O(n*n) complexity
 vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                ans.push_back(j);
                break;
                }
            }
        }
        return ans;
}

//using hashwap with O(n) tc ans O(n) sc
int main()
{
    int n;
	cin >> n;

	vector<int> nums;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}

	int target;
	cin >> target;

	vector<int> result;
	unordered_map<int, int> indexElements;
	for (int i = 0; i < n; ++i)
	{
		int ans = target - nums[i];
		if (indexElements.count(ans) > 0) {
			result.push_back(indexElements[ans]);
			result.push_back(i);
			break;
		}
		else
			indexElements[nums[i]] = i;
	}

	for (int i = 0; i < 2; ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;

}

// Just another way [ shortening the code]
vector<int> twoSum(vector<int>& nums, int target) {

	unordered_map<int, int> indexMap;
	int n = nums.size();
	for (int i = 0; i < n; ++i)
	{
		int remaining = target - nums[i];
		if (indexMap.find(remaining) != indexMap.end()) {
			return {indexMap[remaining], i};
		}
		indexMap[nums[i]] = i;
	}

	return { -1, -1};
}
