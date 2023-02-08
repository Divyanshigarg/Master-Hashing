// First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/
/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Input: s = "leetcode"
Output: 0
Input: s = "loveleetcode"
Output: 2
Example 3:
Input: s = "aabb"
Output: -1
*/


#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    // return the index
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (mpp[s[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string s ;
    cin>>s;
    int answer = firstUniqChar(s);
    cout << "The answer is " << answer << endl;
    return 0;
}
// TC: O(n)
// SC: O(1)