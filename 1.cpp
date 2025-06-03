#include <iterator>
#include <functional> 
#include <iostream>
#include <vector>

using namespace std;

template <class It, class Out, class Compare = less<>>
Out merge(It first1, It last1, It first2, It last2, Out out, Compare cmp = Compare{}) {
    while (first1 != last1 && first2 != last2) {//пока оба не будут пустыми 
        if (cmp(*first2, *first1)) {//сравниваем элементы каждого с элементом из другого 
            *out = *first2;//если второго меньше из первого,то копирауем его 
            ++first2;
        } else {
            *out = *first1;
            ++first1;
        }
        ++out; 
    }
    out = copy(first1, last1, out);
    out = copy(first2, last2, out);
    return out;
}
int main() {
    std::vector<int> v1 = {1, 3, 5, 7};
    std::vector<int> v2 = {2, 4, 6, 8};
    std::vector<int> result;
    
    // Слияние с использованием back_inserter для добавления в конец вектора
    merge(v1.begin(), v1.end(), 
          v2.begin(), v2.end(), 
          std::back_inserter(result));
    
    for (int x : result) std::cout << x << " ";
    std::cout << "\n"; 
    return 0;
}
