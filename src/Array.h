//
// Created by Zhihang Liu on 3/21/20.
//

#ifndef CPPLODASH_ARRAY_H
#define CPPLODASH_ARRAY_H

#include <cstdlib>
#include <vector>
namespace CppLodash
{
    template <typename T>
    class Array {
    public:
        /**
         *
         * @param array input vector
         * @param size  size of each chunck
         * @return 2d vector with each chunk with specified size
         */
        static std::vector<std::vector<T>> chunk(std::vector<T>& array, size_t size)
        {
            std::vector<std::vector<T>> rst;
            if(array.size() == 0) return rst;
            for(unsigned int i=0; i<array.size();)
            {
                std::vector<T> tmp;
                for(unsigned int j=0; j+i<size; j++)
                {
                    tmp.push_back(array[i+j]);
                }
                i += size;
                rst.push_back(tmp);
            }
            return rst;
        }
        /**
         * Creates an array with all falsey values removed. The values false, null, 0, and "" are falsey.
         * @param array vector<T>
         * @return  vector<T>
         */
        static std::vector<T> compact(std::vector<T>& array)
        {

        }
    };
}



#endif //CPPLODASH_ARRAY_H