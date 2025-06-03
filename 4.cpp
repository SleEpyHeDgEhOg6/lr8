#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

template<class It,class Compare=std::less<>>//4.Реализуйте пирамидальную сортировку. Описание алгоритма ищите в книге Кормена "Алгоритмы. Построение и анализ (3-е издание)", стр 179, глава 6.
void heap_sort(It first,It last,Compare cmp=Compare{}){
    if (first==last){//если пустой 
        return;
    }

    for(auto i=(first+(last-first)/2 -1);i>=first;--i){
        push_heap(first,i+1,cmp);
    }

    for(auto i=last-1;i!=first;--i){
        pop_heap(first,i+1,cmp);
    }
}

int main(){
    vector<int> n = {3, 1, 4, 1, 5, 9, 2, 6};
    heap_sort(n.begin(),n.end());
    std::cout << "После  ";
    for (int n : n) std::cout << n << " ";
    std::cout << "\n";
    return 0;
}
