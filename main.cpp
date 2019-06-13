#include <cassert>
#include <cstdarg>
#include "io/ip_io.h"
#include "ip_filter.h"


int main(int argc , char const *argv[] ){
    try{
        
        IntIpVectorsT vct_vct = load_IntIpVectorT_stdin();
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

