#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void display(float *array2, int element2)
{
   for (int i = 0; i < element2; i++)
      cout << array2[i] << " ";
   cout << endl;
}
void bucketSort(float *array2, int element2)
{
   vector<float> bucket[element2];
   for (int looper = 0; looper < element2; looper++)
   { //put elements into different buckets
      bucket[int(element2 * array2[looper])].push_back(array2[looper]);
   }
   for (int looper = 0; looper < element2; looper++)
   {
      sort(bucket[looper].begin(), bucket[looper].end()); //sort individual vectors
   }
   int index = 0;
   for (int looper = 0; looper < element2; looper++)
   {
      while (!bucket[looper].empty())
      {
         array2[index++] = *(bucket[looper].begin());
         bucket[looper].erase(bucket[looper].begin());
      }
   }
}
int main()
{
   int element;
   cout << "Enter the number of elements: ";
   cin >> element;
   float array1[element]; //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for (int looper = 0; looper < element; looper++)
   {
      cin >> array1[looper];
   }
   cout << "Array before Sorting: ";
   display(array1, element);
   bucketSort(array1, element);
   cout << "Array after Sorting: ";
   display(array1, element);
}