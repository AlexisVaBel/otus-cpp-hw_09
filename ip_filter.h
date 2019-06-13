#ifndef IP_FILTER_H
#define IP_FILTER_H

#include <iostream>
#include <range/v3/all.hpp>
#include "commontypes.h"

//// @brief vector elements printing function
void printVector(IntIpVectorsT vct){
    ranges::for_each(vct,[](IntIpVectorT lclvct){
        int first[1];
        first[0] = 0;
        ranges::for_each(lclvct,[&first](int ival){
            if(first[0] == 1) std::cout<<".";
            *first = 1;
            std::cout<<ival;
        });
        std::cout<<std::endl;
    });
}

auto first_is_one       = [](IntIpVectorT vct) -> bool { return *vct.begin() == 1; };

// @brief functions for filtering elements - predicates for apply_if and for_each_print

auto first46_second70   = [](IntIpVectorT vct) -> bool {
    auto it = vct.begin();
    return *it == 46 && *(++it) == 70;
};
auto any_is_46    = [](std::vector<int> vct) -> bool {
    return ranges::any_of(vct,[](int i){return i == 46;});
};

//@brief functions for view::remove_if TODO
auto not_first_is_one   = [](IntIpVectorT vct) -> bool { return *vct.begin() != 1; };
auto not_first46_second70   = [](IntIpVectorT vct) -> bool {
    auto it = vct.begin();
    return *it != 46 && *(++it) != 70;
};

#endif // IP_FILTER_H
