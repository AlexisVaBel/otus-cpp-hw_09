#include <cassert>
#include <algorithm>
#include <cstdarg>
#include <iostream>


#include "io/ip_io.h"
#include "rangeflt/ip_filter.h"






int main(int argc , char const *argv[] ){
    try{
        
//         IntIpVectorsT vct_vct = load_IntIpVectorT_stdin();
//         std::sort(vct_vct.begin(), vct_vct.end(), std::greater<IntIpVectorT> () );


        IntIpVectorsT vct_vct{{1,1,3,4,5},{2,7,65,4},{1,9,65,4},{8,9,65,4},{46,70,65,4},{46,9,70,4}};

        apply_if(vct_vct,first_is_one);
        apply_if(vct_vct,first46_second70);
        apply_if(vct_vct,any_is_46_or_70);

        // @brief using ranges::view
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

