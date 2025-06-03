#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <class It, class Compare=std::less<>>
void quick_sort(It first, It last, Compare cmp=Compare{}){//алгоритм быстрой сортировки
    if (first == last || next(first) == last) {
        return; 
    }

    auto pivot = *prev(last);//выбираем элемент,который зафиксируем и будем на него дальше ссылаться (тут последний)
    
    // Разделяем элементы на две группы: меньше опорного и больше/равные
    It middle = partition(first, prev(last),  //делим элементыы на две подгруппы, те которые меньше фиксируемого и те которые больше
        [&pivot, &cmp](const auto& item) { 
            return cmp(item, pivot); 
        });
    
    iter_swap(middle, std::prev(last));//передвигаем фиксируемый элемент на его конечную позицию
    
    quick_sort(first, middle, cmp);//делаем рекурсию для двух подгрупп  
    quick_sort(next(middle), last, cmp);
}


 int main(){
    vector<int> n = {3, 1, 4, 1, 5, 9, 2, 6};
    quick_sort(n.begin(),n.end());
    std::cout << "После  ";
    for (int n : n) std::cout << n << " ";
    std::cout << "\n";
    return 0;
 }
