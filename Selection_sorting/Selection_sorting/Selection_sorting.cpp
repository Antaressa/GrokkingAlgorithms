#include <iostream>

int findSmallest(int* mass, size_t size) {

    int smallest = mass[0];
    int smallest_element_index = 0;

    for (int i = 1; i < size; i++) {
        if (mass[i] < smallest) {
            smallest = mass[i];
            smallest_element_index = i;
        }
    }

    return smallest_element_index;
}

int main()
{
    int* mass = new int[6] { 3, 8, 4, 1, 85, 24 };
    size_t size = 6;

    std::cout << findSmallest(mass, size) << std::endl;
}
