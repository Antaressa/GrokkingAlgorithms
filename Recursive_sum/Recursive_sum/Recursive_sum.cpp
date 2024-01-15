#include <iostream>
#include <vector>

int recursiveSum(std::vector<int> v) {
    
    if (v.size() == 1) {
        return v[0];
    }
    else {
        int last_el = v.back();
        v.pop_back();
        return last_el + recursiveSum(v);
    }
}

int numberOfElements(std::vector<int> v) {

    if (v.size() == 1) {
        return 1;
    }
    else {
        v.pop_back();
        return 1 + numberOfElements(v);
    }
}

int maxNumber(std::vector<int> v) {


}

int main()
{
    std::vector<int> v = {4,8,23,67,5,1,34,762,2};

    std::cout << "Sum: " << recursiveSum(v) << std::endl;
    std::cout << "Number of elements: " << numberOfElements(v);
}
