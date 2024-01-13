#include <iostream>

int binarySearch(int* p, int* q, int value) {

    int start = 0;
    int end = q - p;
    int mid = 0;

    while (start <= end) {

        mid = (start + end) / 2;

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
}
