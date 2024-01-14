#include <iostream>
using namespace std;

int findSmallest(int* mass, size_t size) {

    int smallest = mass[0];
    int smallest_element_index = 0;

    for (int i = 1; i < size; i++) {
        if (mass[i] < smallest && mass[i] != NULL) {
            smallest = mass[i];
            smallest_element_index = i;
        }
    }

    return smallest_element_index;
}


void selectionSorting(int* new_mass, int* mass, size_t size) {

    int i = 0;

    while (i != size) {
        int pos = findSmallest(mass, size);
        new_mass[i] = mass[pos];
        mass[pos] = INT_MAX;
        i++;
    }

    delete[] mass;
}


int main()
{
    size_t size = 6;
    int* mass = new int[size] { 3, 8, 4, 1, 85, 24 };
    int* new_mass = new int[size];

    selectionSorting(new_mass, mass, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << new_mass[i] << " ";
    }

    cout << endl;
}
