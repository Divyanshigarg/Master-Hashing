// Max distance between same elements
// Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.
/*
Input
n = 12
arr = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}

Output
10

Explanation
arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
Max Distance 10
maximum distance for 2 is 11-1 = 10
maximum distance for 1 is 4-2 = 2
maximum distance for 4 is 10-5 = 5
*/
// Approach
// We will create a Hashmap in which we store <element, firstOccurence>
// we will initialise a variable maxi=0
// We will iterate through the array and store new elements in hashmap but before storing we will check whether the element is already present in the hashmap or not
// if not present simple, input <element,first_occurence_index> in Hashmap
// if present, just find difference of (current_index_for_that_element - first_occurence_index_of_element_from_hashmap) and if its greater than maxi, then we put maxi equal to that value
// then we move ahead, we do not store it in hashmap
// hashmap will only store the first_occurence_index of all elements
// This way we get the maximum distance between the repeated element in the array

#include <bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n)
{
    int maxi = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        // if element is not found
        if (mpp.find(arr[i]) == mpp.end())
        {
            mpp[arr[i]] = i;
        }
        maxi = max(maxi, i - mpp[arr[i]]);
    }
    return maxi;
}

int main()
{
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int answer = maxDistance(arr, n);
    cout << "max distance is " << answer;
    return 0;
}

// TC: O(n), SC: O(n)
