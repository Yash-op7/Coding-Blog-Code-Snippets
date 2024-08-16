#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    int first = *nums.begin();
    int last = *(--(nums.end()));
    
    first = *(--(nums.rend()));
    last = *nums.rbegin();
    
    cout << first << ' ' << last << '\n';
    
    int second = *(++(nums.begin()));
    int secondLast = *(++(nums.rbegin()));
    
    cout << second << ' ' << secondLast << '\n';
    
    for(auto it=nums.rbegin();it != nums.rend(); ++it) {
        cout << *it << ' ';
    }

    set<int> set1 = {1, 3, 5, 7, 9};
    set<int> set2 = {2, 4, 6, 8, 10, 5};

    // Merge set2 into set1, emptying set2 into set1
    set1.merge(set2);
    cout << "\nset1 is: ";
    for(const auto x:set1) {
        cout << x << ' ';
    }
    cout << "\nset2 is: ";
    for(const auto x:set2) {
        cout << x << ' ';
    }
}