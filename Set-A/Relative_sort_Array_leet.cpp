//problem link: https://leetcode.com/problems/relative-sort-array/
// 1122. Relative Sort Array
// Easy

/*Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

Example 2:
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
*/

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    //    vector<int> ans;
        
    //     map<int, int>mp;
    //     for(auto x: arr1)
    //         mp[x]++;
    //     for(auto temp :  arr2){
    //         if(mp.find(temp)!=mp.end()){
    //             auto x  = mp.find(temp);
    //             int count = x->second;  // 5->2
    //             vector<int>v(count, temp); // v = 5 5 
    //             ans.insert(ans.end(), v.begin(), v.end());
    //             mp.erase(temp);
    //         }
    //     }
        
    //     for(auto x : mp){
    //         int ele = x.first;
    //         int count = x.second;
    //         vector<int>v(count, ele);
    //         ans.insert(ans.end(), v.begin(), v.end());
    //     }
        
    //     return ans;

    //both the solutions are correct


    int size1 = arr1.size();
        int size2 = arr2.size();
        map<int,int>mp;

        for(int i=0;i<size1;i++){
            mp[arr1[i]]++;
        }

        vector<int>ans;
//loop for the elements that are presnt in the array 2 
//counting the occurance of that element in array1 and then pushing it into the vactor ans.
        for(int i=0;i<size2;i++){
            int cnt = mp[arr2[i]];
            for(int j=0;j<cnt;j++){
                ans.push_back(arr2[i]);
            }
            mp[arr2[i]] =0;
        }
//loop for the elemnts left in the array1 
//checking that if they have the frequency greater than 0
        for(auto it:mp){
            if(it.second>0){
                int cnt = it.second;
                for(int j=0;j<cnt;j++){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }