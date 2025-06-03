#include <iterator>
#include <functional> 
#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

template <class It, class Compare>
void i(It first, It middle, It last, Compare cmp) {
    It i = first;
    It j = middle;
    
    while (i != j && j != last) {
        if (cmp(*j, *i)) {
            It old_j = j;
            ++j;
            rotate(i, old_j, j);
            middle = old_j;
        }
        ++i;
    }
}

template <class It, class Compare = less<>>
void inplace_merge_sort(It first, It last, Compare cmp = Compare{}) {
    auto size = distance(first, last);
    if (size <= 1) return;
    
    It middle = first;
    advance(middle, size / 2);
    
    inplace_merge_sort(first, middle, cmp);
    inplace_merge_sort(middle, last, cmp);
    
    i(first, middle, last, cmp);
}

int main() {
    vector<int> v = {5, 2, 9, 1, 5, 6};
    
    inplace_merge_sort(v.begin(), v.end());
    
    for (int x : v) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
