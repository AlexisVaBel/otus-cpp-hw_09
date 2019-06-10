#include <cassert>
#include <algorithm>
#include <cstdarg>
#include <iostream>


#include "io/ip_io.h"
//#include "ip_filter.h"

#include <range/v3/all.hpp>

// @brief vector elements printing function
auto print = [](IntIpVectorT vct) {
    auto it = vct.begin();
    while (it != vct.end()) {
        if(it != vct.cbegin()) std::cout << ".";
        std::cout << *it++;
    }
    std::cout << std::endl;
};

// @brief apply predicate and if it is true then print
auto for_each_print = [](IntIpVectorT vct,std::function<bool (IntIpVectorT)> predicate){
    if(predicate(vct)){
        print(vct);
    }
};

// @brief function for use in main programm
auto apply_if = [] (IntIpVectorsT vct, std::function<bool(IntIpVectorT)> predicate){
    auto it = vct.begin();
    while (it != vct.end()){
        for_each_print((*it),predicate);
        ++it;
    }
};


// @brief functions for filtering elements - predicates for apply_if and for_each_print
auto all                = [](IntIpVectorT vct) -> bool { return true; };
auto first_is_one       = [](IntIpVectorT vct) -> bool { return *vct.begin() == 1; };
auto first46_second70   = [](IntIpVectorT vct) -> bool {
    auto it = vct.begin();
    return *it == 46 && *(++it) == 70;
};
auto any_is_46_or_70    = [](std::vector<int> vct) -> bool {
    return ranges::any_of(vct,[](int i){return i == 46 || i == 70;});
};

//@brief functions for view::remove_if TODO
auto first_is_not_one   = [](IntIpVectorT vct) -> bool { return *vct.begin() != 1; };



int main(int argc , char const *argv[] ){
    try{
        
//         IntIpVectorsT vct_vct = load_IntIpVectorT_stdin();

        IntIpVectorsT vct_vct{{1,1,3,4,5},{2,7,65,4},{1,9,65,4},{8,9,65,4},{46,70,65,4},{46,9,70,4}};
        std::sort(vct_vct.begin(), vct_vct.end(), std::greater<IntIpVectorT> () );


        apply_if(vct_vct,all);
        apply_if(vct_vct,first_is_one);
        apply_if(vct_vct,first46_second70);
        apply_if(vct_vct,any_is_46_or_70);

        // @brief using ranges::view unused, need to proceed '.' printing on end of the view
//        auto rng = vct_vct | ranges::view::remove_if(
//                                 first_is_not_one);

//        auto it = rng.begin();
//        while (it != rng.end()){
//            ranges::for_each((*it),[](auto t){
//                std::cout<<(t)<< ".";
//            });
//            std::cout<< std::endl;
//            ++it;
//        }
        // @brief using ranges::view

    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

