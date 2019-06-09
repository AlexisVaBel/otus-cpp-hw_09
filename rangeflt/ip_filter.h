#ifndef IP_FILTER_H
#define IP_FILTER_H

#include "../commontypes.h"
#include "range/v3/all.hpp"

auto print = [](IntIpVectorT vct) {
    auto it = vct.begin();
    while (it != vct.end()) {
        if(it != vct.cbegin()) std::cout << ".";
        std::cout << *it++;
    }
    std::cout << std::endl;
};

auto for_each_print = [](IntIpVectorT vct,std::function<bool (IntIpVectorT)> predicate){
    if(predicate(vct)){
        print(vct);
    }
};


auto apply_if = [] (IntIpVectorsT vct, std::function<bool(IntIpVectorT)> predicate){
    auto it = vct.begin();
    while (it != vct.end()){
        for_each_print((*it),predicate);
        ++it;
    }
};


// @brief functions for filtering elements
auto first_is_one = [](std::vector<int> vct) -> bool { return *vct.begin() == 1; };
auto first_is_not_one = [](std::vector<int> vct) -> bool { return *vct.begin() != 1; };

auto first46_second70 = [](std::vector<int> vct) -> bool {
    auto it = vct.begin();
    return *it == 46 && *(++it) == 70;
};

auto any_is_46_or_70= [](std::vector<int> vct) -> bool {
    return ranges::any_of(vct,[](int i){return i == 46 || i == 70;});
};

#endif // IP_FILTER_H
