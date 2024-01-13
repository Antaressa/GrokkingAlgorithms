#include <iostream>

int binarySearch(int* p, int* q, int value) {

    // start and end define the search segment in array
    int start = 0;
    int end = q - p;

    // mid is the position number of the middle element from the current segment
    int mid = 0;

    // run a loop until the searched segment is reduced to one value
    while (start <= end) {

        // calculate middle item position
        mid = (start + end) / 2;

        // compare middle item with the searched value
        if ( *(p + mid) == value ) {
            return mid + 1;
        }

        else if (*(p + mid) <= value) {
            start = mid;
        }
        else {
            end = mid;
        }
    }

    // item does not exist in array
    return -1;
}

int main()
{
    int mass[6] = { 1, 3, 5, 7, 9, 11 };
    int* p = mass;
    int* q = &mass[5];
    int value = 0;

    std::cout << "Enter your value: ";
    std::cin >> value;

    int result_pos = binarySearch(p, q, value);

    if (result_pos == -1) {
        std::cout << "Entered item does not exist in the array." << std::endl;
    }
    else {
        std::cout << "Item position: " << result_pos << std::endl;
    }

    return 0;
}
