// Find Common Characters
// https://leetcode.com/problems/find-common-characters/

/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Explanation: e, l, l are present in all 3 words
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
Explanation: c, o, are present in all 3 words

*/
 /*Approach
 For each word in the array we will store the frequency of each character occuring in a word
 then, we will take the minimum frequency of that common character from all words
 For example: words: ["ookloo", "ookkl", "ooollk", "oolka"]
 In above example, frequency of ocurence of o are {4,2,3,2} we want common so we take min(4,2,3,2) i.e is 2 so "o", "o"
 Sameway for k and l, output: ["o","o","k","l"]
 We will take two maps, one for frequency and other for minimum frequency
 We will traverse from a to z and store maximum freq for each character in min_freq map
 now we will traverse first word "ookloo" and store freq of each character occuring in it.
 After doing that we will again run a loop for a to z and change the min_freq map ka frequency part according to the frequency map.
The character which is not present in all words will automatically get its minimum value as 0
 Now we move to next word "ookkl" and again update the freq map.
 Now again we go from a to z and check the min_freq map accordingly.
 Now in min_freq map we traverse from a to z and character having frequency > 0 are taken as taken into output vector.
 This way we get the minimum frequency map containing elements common to all with their minimum occurence common to all words. */


#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string> &words)
{
    unordered_map<char, int> min_frequency;
    vector<string> answer;
    // Let us fill the min_freq to maximum (say 1000) first
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        min_frequency[ch] = 1000;
    }
    // Now let us fill freq map for each word in the vector words
    for (auto word : words)
    {
        unordered_map<char, int> frequency;
        // Storing freq for each character of each word
        for (auto ch : word)
        {
            frequency[ch]++;
        }
        // Changing the min_freq map before going to the next word
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            min_frequency[ch] = min(min_frequency[ch], frequency[ch]);
        }
    }
    // storing all characters with freq>0 to output vector
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        while (min_frequency[ch] > 0)
        {
            // our output is of form ["e","l","l"] means each letter is stored as a string inside the vector
            // so we use a constructor string(count,character)
            answer.push_back(string(1, ch));
            // Decrease the frequency after storing in the output
            min_frequency[ch]--;
        }
    }
    return answer;
}

int main()
{
    int n;
    cout<<"Enter the size of array:  ";
    cin>>n;
    vector<string> words ;
    cout<<"Enter the array elements:  ";
    for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		words.push_back(s);
	}
    vector<string> answer = commonChars(words);
    cout<<"The common characters are:  ";
    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i] << " ";
    }
    return 0;
}

// TC: O(n)
// SC: O(2*26) = O(1)
// We can also use vector<int> (26,0) instead of unordered_map it cn be faster
// To store any charcter then we do mp[ch - 'a']++ which means ASCII value of ch - ASCII of a
// Then the value of character will be stored in form of number like 'b' = 98, 'a'=97, b-a = 1
