#ifndef IP_FILTER_H
#define IP_FILTER_H


#include <range/v3/all.hpp>
#include "commontypes.h"

//// @brief vector elements printing function
//auto print = [](IntIpVectorT vct) {
//    auto it = vct.begin();
//    while (it != vct.end()) {
//        if(it != vct.cbegin()) std::cout << ".";
//        std::cout << *it++;
//    }
//    std::cout << std::endl;
//};

//// @brief apply predicate and if it is true then print
//auto for_each_print = [](IntIpVectorT vct,std::function<bool (IntIpVectorT)> predicate){
//    if(predicate(vct)){
//        print(vct);
//    }
//};

//// @brief function for use in main programm
//auto apply_if = [] (IntIpVectorsT vct, std::function<bool(IntIpVectorT)> predicate){
//    auto it = vct.begin();
//    while (it != vct.end()){
//        for_each_print((*it),predicate);
//        ++it;
//    }
//};


//// @brief functions for filtering elements - predicates for apply_if and for_each_print
//auto all                = [](IntIpVectorT vct) -> bool { return true; };
//auto first_is_one       = [](IntIpVectorT vct) -> bool { return *vct.begin() == 1; };
//auto first46_second70   = [](IntIpVectorT vct) -> bool {
//    auto it = vct.begin();
//    return *it == 46 && *(++it) == 70;
//};
//auto any_is_46_or_70    = [](std::vector<int> vct) -> bool {
//    return ranges::any_of(vct,[](int i){return i == 46 || i == 70;});
//};

////@brief functions for view::remove_if TODO
//auto first_is_not_one   = [](IntIpVectorT vct) -> bool { return *vct.begin() != 1; };


#endif // IP_FILTER_H
