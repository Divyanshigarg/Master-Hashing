//problem link: https://practice.geeksforgeeks.org/problems/key-pair5616/1
//Key Pair
//Easy

/*Given an array Arr of N positive integers and another number X. 
Determine whether or not there exist two elements in Arr whose sum is exactly X.

Example 1:
Input:
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16

Example 2:
Input:
N = 5, X = 10
Arr[] = {1, 2, 4, 3, 6}
Output: Yes
Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
*/

// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    //using unordered_map
	   unordered_map<int,int>mpp;
	    for(int i=0;i<n;i++)
	    {
	       if(mpp.find(x-arr[i])!=mpp.end())
	       {
	           return true;
	       }
	       mpp[arr[i]]++;;
	    }
	    return false;
	}