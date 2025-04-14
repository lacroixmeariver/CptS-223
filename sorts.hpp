//
// Created by Ingrid Llorente on 4/12/25.
//

#ifndef SORTS_HPP
#define SORTS_HPP
#include "arrayContainer.hpp"
/* Hash map has an array of node pointers
 * TODO:
 *  - external comparator for the insertion sort
 * 	- need to be able to compare prices for Product class
 * 	- need to change selling price type to int in product class and subsequently in the app class
 *
 * */
template <class T>
class Sort
{
  public:

   // accepts pointer to an array, swaps the indexes based on price
   T* insertionSort(T* array)
   {
     for (int i = 1; i < array->getSize() - 1; i++)
      {
       		int j = i;
       		while (j > 0 && array[j - 1] < array[j])
         	{
         		swap(j, j-1, array);
         	}
      }
     return array;
   }

   void swap(int x, int y, T* array)
   {
      T temp = array[x];
      array[x] = array[y];
      array[y] = temp;
   }


};

#endif //SORTS_HPP
