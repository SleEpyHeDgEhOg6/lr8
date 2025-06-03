#include <iterator>
#include <vector>
#include <functional> 
#include <algorithm> 
#include <iostream>

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

template <class It, class Out, class Compare = std::less<>>
Out merge_sort(It first, It last, Out out, Compare cmp = Compare{}) {
    auto size = distance(first, last);
    
    if (size <= 1) {
        return copy(first, last, out);
    }

    auto middle = first;//середина 
    advance(middle, size / 2);//сдвиг 
    
    using ValueType = typename iterator_traits<It>::value_type;//для временного хранения отсортированной половины 
    vector<ValueType> left_part, right_part;
    
    merge_sort(first, middle, back_inserter(left_part), cmp);
    merge_sort(middle, last, back_inserter(right_part), cmp);
    
    return merge(left_part.begin(), left_part.end(),
                right_part.begin(), right_part.end(),
                out, cmp);
}

int main() {
    std::vector<int> uns = {5, 2, 9, 1, 5, 6};
    std::vector<int> s;

    merge_sort(uns.begin(), uns.end(), std::back_inserter(s));
    for (int x : s) std::cout << x << " ";
    std::cout << "\n"; 
    return 0;
}
