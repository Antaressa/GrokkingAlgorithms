#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, float> fruits_book;

    fruits_book["Apple"] = 4.59;
    fruits_book["Mango"] = 9.99;
    fruits_book["Orange"] = 7.36;
    fruits_book["Pear"] = 5.67;

    for (auto item : fruits_book) {
        std::cout << item.first << ": " << item.second << std::endl;
    }
}
