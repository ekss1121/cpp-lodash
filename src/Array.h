//
// Created by Zhihang Liu on 3/21/20.
//

#ifndef CPPLODASH_ARRAY_H
#define CPPLODASH_ARRAY_H

#include <cstdlib>
#include <vector>
#include <typeinfo>
#include <unordered_set>
namespace CppLodash
{
template <typename T>
class Array
{
public:
    /**
         *
         * @param array input vector
         * @param size  size of each chunck
         * @return 2d vector with each chunk with specified size
         */
    static std::vector<std::vector<T>> chunk(std::vector<T> &array, size_t size)
    {
        std::vector<std::vector<T>> rst;
        if (array.size() == 0)
            return rst;
        for (unsigned int i = 0; i < array.size();)
        {
            std::vector<T> tmp;
            for (unsigned int j = 0; j + i < size; j++)
            {
                tmp.push_back(array[i + j]);
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
    static std::vector<T> compact(std::vector<T> &array)
    {
        std::vector<T> rst;
        if (array.size() == 0)
            return rst;
        for (T item : array)
        {
            if (item)
            {
                rst.push_back(item);
            }
        }
        return rst;
    }

    static std::vector<std::string> compact(std::vector<std::string> &array)
    {
        std::vector<std::string> rst;
        if (array.size() == 0)
            return rst;
        for (auto &item : array)
        {
            if (item.size())
            {
                rst.push_back(item);
            }
        }
        return rst;
    }

       static std::vector<T> difference(std::vector<T>& array, std::vector<T>& values)
        {
            std::unordered_set<T> _set;
            _set.insert(values.begin(), values.end());
            std::vector<T> rst;
            for(unsigned int i=0; i<array.size(); i++)
            {
                if(_set.find(array[i]) == _set.end())
                {
                    rst.push_back(array[i]);
                }
            }

            return rst;
        }

        /**
         * @param array The array to inspect
         * @param valuse THe value s to exclude
         * @param [iteratee](function) The iteratee invoked per element
         * 
         */
        static std::vector<T> differenceBy(std::vector<T>& array, std::vector<T>& values, std::function<T>& lambda) {
            std::vector<T> f_values;
            for(T& item : values) {
                f_values.push_back(lambda(item));
            }

            return difference(array, f_values);
        }

    };
} //namespace CppLodash


#endif //CPPLODASH_ARRAY_H
