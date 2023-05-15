#include <iostream>
#include <utility>
#include <sstream>
#include <vector>
using namespace std;
 

bool compare(pair<int, int> n1, pair<int, int> n2) {
    // If frequencies of two elements are same
    if (n1.second == n2.second)
        return n2.first > n1.first;
 
    return n1.second > n2.second;
}

void KFrequentNumber(vector<int> arr, int N, int K) {
    // Hashmap
    unordered_map<int, int> mp;

    // Insert values
    for (auto& elem : arr) {
            mp[elem]++;
        }

    vector<pair<int, int> > freq_arr(mp.begin(), mp.end());
 
    // Sort with compare()
    sort(freq_arr.begin(), freq_arr.end(), compare);
 
    // display the K-th most frequent number
    cout << freq_arr[K-1].first << '\n';
}
 

int main() {
    int num;
    vector<int> arr;
 
    cout << "Enter space-seperated integers: ";
    string str;
    getline(cin, str);
    stringstream ss(str);

    while (ss >> num) { 
        arr.push_back(num);
    }

    // int arr[] = {4, 4, 1, 2, 2, 2, 2, 3, 3, 3, 5, 5, 5, 6, 1, 5, 9};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 4;
 
    KFrequentNumber(arr, N, K);
 
    return 0;
}

// Space: O(D) - (due to hashmap)
// Time: O(Dlog(D)) - (due to sorting)
// D = number of distinct ints
