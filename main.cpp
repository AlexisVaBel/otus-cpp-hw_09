#include <cassert>
#include <algorithm>
#include <cstdarg>
#include <iostream>


#include "io/ip_io.h"
#include "ip_filter.h"

#include <range/v3/all.hpp>


// @brief functions for filtering elements - predicates for apply_if and for_each_print
auto first_is_one       = [](IntIpVectorT vct) -> bool { return *vct.begin() == 1; };
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

int main(int argc , char const *argv[] ){
    try{
        
         IntIpVectorsT vct_vct = load_IntIpVectorT_stdin();

//        IntIpVectorsT vct_vct{{1,1,2,3,4,5},{2,7,65,4},{1,9,65,4},{8,9,65,4},{46,70,65,4},{46,9,70,4}};
        std::sort(vct_vct.begin(), vct_vct.end(), std::greater<IntIpVectorT> () );
        // @brief using ranges::view
        // @brief removing not in filter
        auto vct_first_ones = vct_vct | ranges::view::remove_if(
                                 not_first_is_one);
        // @brief stayed just in filter
        auto vct_first_46_70 = vct_vct | ranges::view::filter(
                                 first46_second70);
        auto vct_any_46 = vct_vct | ranges::view::filter(
                                 any_is_46);

        printVector(vct_vct);
        printVector(vct_first_ones);
        printVector(vct_first_46_70);
        printVector(vct_any_46);


    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

