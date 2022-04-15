#include <iostream>
#include <chrono>

struct ArrInfo
{
    int value = 0;
    int index = 0;
};

void stats(int arr[], int size)
{
    using namespace std;

    // the program outputs numeric values of the array's indexes in order
    int indexCounter = 0;

    cout << "Array's numbers and their indexes are: \n";
    for (int aaa = 0; aaa < 10; ++aaa)
    {  
        //random seeded values given to all of the array elements in order. the range is from 1 to 100
        arr[aaa] = rand()%100+1;
        cout << " |" << arr[aaa] << "| " << "and its index is " << "|" << indexCounter++ << "|" << endl;
    }

}
ArrInfo biggestNumber(int arr[], int size)
{
    ArrInfo biggest;

    for (int iii = 1; iii < size; iii++)
    {
        if (biggest.value < arr[iii])
        {
            biggest.value = arr[iii];
            biggest.index = iii;
        }
    }

    return biggest;
}

ArrInfo smallestNumber(int arr[], int size)
{
    ArrInfo smallest;

    // to figure out the smallest value we need to compare the array elemets with the highest value possible which is 100.
    smallest.value = 100;

    for (int iii = 1; iii < size; iii++)
    {
        if (smallest.value > arr[iii])
        {
            smallest.value = arr[iii];
            smallest.index = iii;
        }
    }
    
    return smallest;
}
int main()
{
    using namespace std;

    // pseudo-random seeding
    srand(static_cast<int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));

    int arr[10];
    int size = sizeof(arr) / sizeof(arr[0]);

    // outputs the random seeded array values with its values' indexes
    stats(arr, size);
    cout << " \n" << endl;

    ArrInfo biggest = biggestNumber(arr, size);
    ArrInfo smallest = smallestNumber(arr, size);

    cout << "The biggest number is " << biggest.value << " and its index is " << biggest.index << endl;
    cout << "The smallest number is " << smallest.value << " and its index is " << smallest.index << endl;
  
    return 0;
}
