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
}