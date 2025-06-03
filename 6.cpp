#include <iostream>
#include <iterator>
#include <functional>
#include <vector>

using namespace std;

template <class It,class Compare = less<>>
void insort(It first,It last,Compare cmp=Compare{}){
    if(first==last || next(first)==last){//проверка на пустой 
        return; 
    }
    for(It i=next(firts);i!=last;++i){
        auto k=move(*i);
        It j=i;
        while (j!=first && cmp(k,*prev(j))){
            *j=move(*prev(j));
            --j;
        }
        *j=move(k);
    }
}


int main() {
    vector<int> n = {3, 1, 4, 1, 5, 9, 2, 6};
    insort(n.begin(),n.end());
    std::cout << "После  ";
    for (int n : n) std::cout << n << " ";
    std::cout << "\n";
    return 0;
}
