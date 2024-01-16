#include <iostream>
#include <vector>

void fillGreaterLessVectors(std::vector<int>* p_v_less, std::vector<int>* p_v_greater, std::vector<int> v_initial, int pivot) {

    for (int i = 1; i < v_initial.size(); i++) {
        if (v_initial[i] >= pivot) {
            p_v_greater->push_back(v_initial[i]);
        }
        else {
            p_v_less->push_back(v_initial[i]);
        }
    }
}

std::vector<int> quickSort(std::vector<int> v) {

    if (v.size() < 2) {
        return v;
    }
    else {
        int pivot = v[0];
        std::vector<int> v_less;
        std::vector<int> v_greater;
        std::vector<int>* p_v_less = &v_less;
        std::vector<int>* p_v_greater = &v_greater;

        fillGreaterLessVectors(p_v_less, p_v_greater, v, pivot);

        v = quickSort(v_less);
        v.push_back(pivot);
        quickSort(v_greater);
        for (int i = 0; i < v_greater.size(); i++) {
            v.push_back(v_greater[i]);
        }

        return v;
    }
}

int main()
{
    std::vector<int> v = { 5, 8, 1, 3, 2};

    v = quickSort(v);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
