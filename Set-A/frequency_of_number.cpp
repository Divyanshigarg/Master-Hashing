// given an integer array, process Q queries. Each query will contain element X, output the freq of X in array
// Note: All element in array and element X will be in range of 1 to N
// Size of hashmap will never exceed number of unique elements in the array
// In C++, we have unordered_map and map

//using frequency map
#include <bits/stdc++.h>
using namespace std;
int main()
{

      int n;
      cin >> n;

      int *arr = new int[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      // preprocessing the array
      unordered_map<int,int > frequency;
      for (int i = 0; i < n; i++)
      {
            frequency[arr[i]]++;
      }

      int queries;
      cin >> queries;

      while (queries--)
      {

            int q;
            cin >> q;

            cout << frequency[q] << endl;
      }

      delete[] arr;
}

//both the codes are correct
//using frequency array

#include <bits/stdc++.h>
using namespace std;
int main()
{

      int n;
      cin >> n;

      int *arr = new int[n];
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }
      // preprocessing the array
      vector<int> frequency(n + 1, 0);
      for (int i = 0; i < n; i++)
      {
            frequency[arr[i]]++;
      }

      int queries;
      cin >> queries;

      while (queries--)
      {

            int q;
            cin >> q;

            cout << frequency[q] << endl;
      }

      delete[] arr;
}

//output
// Enter the size of an array: 6
//Enter the array elements:
// 5 4 3 4 3 2
// Enter the query4
// The frequency of 4 is 2


//t.c=O(N+Q)
//s.c=O(N)
