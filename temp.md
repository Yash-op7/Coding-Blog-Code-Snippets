This is a post I will regularly update with the nuances and tricks that I discover while solving complex DSA questions in C++.

### Accessing set elements via iterators:
Let's say you have a `set<int> nums;`, then:
#### 1. To get the edge elements you can do:
```
int first = *nums.begin();
int last = *(--(nums.end()));
// OR    
first = *(--(nums.rend()));
last = *nums.rbegin();
```

⭐️ so basically try to not use end() and rend() as they are a bit tricky and there are simpler alternatives:

❗️ Note that rbegin() and rend() are reverse iterators so to get the second last element using rbegin() what do you think we will do?

-> The answer is: `int secondLast = *(++(nums.rbegin()));`

❗️ Also remember that rend() and end() don't give iterators pointing to elements, rather they return the pointer of one past the first or the last, i.e, nums.end() will give iterator pointing to the address after the last element which is not dereference-able similarly nums.rend() will give the iterator of the location one before the first element so be careful of how you use them otherwise it will result in memory segmentation errors.

Also one final note about edge operators:
You can also use constant operators if your functionality requires, to write more predictable and debuggable code:
```
auto FIRST_ITR = nums.cbegin();
auto LAST_ITR = nums.cend();
auto FIRST_REV_ITR = nums.crbegin();
auto LAST_REV_ITR = nums.crend();
```

#### 2. Different ways to erase elements:
There are 3 methods:
- `nums.erase(iterator)`


⭐️ If you want to remove the 4th element in the set you **cannot** do:
`nums.erase(((nums.begin())+4));`
because while sets are ordered containers they don't allow random access like vectors so you must iterate with the iterator one at a time like so:
```
auto it = nums.begin();
int x = 4;
while(x--) it++;
nums.erase(it);
```
- `nums.erase(value)` - straightforward, just removes the value from the set if present.
- `nums.erase(iterator1, iterator2)` - useful, removes elements in the range [iterator1, iterator2) ❗️ note the closed-open interval

#### 3. Trivial but useful functions:
- `find()`
- `lower_bound(x)` - Returns an iterator pointing to the first element not less than the given value.
- `upper_bound(x)` - Returns an iterator pointing to the first element greater than the given value.
- `equal_range(x)` - Basically returns a pair of iterators equivalent to `make_pair(nums.lower_bound(x), nums.upper_bound(x))`

- `empty()`
- `size()`

#### 4. Hidden but awesome functions:
- `swap()` - Exchanges the contents of two sets. This is a fast operation because it swaps pointers and size metadata rather than copying the elements.

- `merge(anotherSet)` - Transfers all elements from anotherSet into the set which are not present in destination set, removing duplicates.

```
    std::set<int> set1 = {1, 3, 5, 7, 9};
    std::set<int> set2 = {2, 4, 6, 8, 10, 5};

    // Merge set2 into set1
    set1.merge(set2);

    // Now set2 has one element 5 and set1 contains the union of both.

```
- comparison operators - surprisingly you can compare sets in C++ accordign to their lexicographical order, for example:
```
    set<int> set1 = {1, 3, 5};
    set<int> set2 = {1, 3, 5};
    set<int> set3 = {1, 2, 6};
    set<int> set4 = {1, 3, 4, 7};

    // Compare set1 and set2
    if (set1 == set2) {
        cout << "set1 is equal to set2" << endl;
    }

    // Compare set1 and set3
    if (set1 < set3) {
        cout << "set1 is less than set3" << endl;
    }

    // Compare set1 and set4
    if (set1 < set4) {
        cout << "set1 is less than set4" << endl;
    }

    // output: set1 is equal to set2
```
- Custom set - When constructing a set, you can provide a custom comparator to change the default ordering of the elements.
```
struct ReverseComparator {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs; // Reverse order
    }
};

std::set<int, ReverseComparator> mySet;

```

### Lambda functions
`[capture list](parameters) -> return type { body }`
