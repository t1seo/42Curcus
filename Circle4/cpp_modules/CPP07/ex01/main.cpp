#include "iter.hpp"

int main(void)
{
    int iArr[5] = {1, 2, 3, 4, 5};
    float fArr[5] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};
    double dArr[5] = {100.0, 200.0, 300.0, 400.0, 500.0};
    std::string sArr[5] = {"A", "B", "C", "D", "E"};

    iter(iArr, sizeof(iArr) / sizeof(int), &printElem);
    std::cout << std::endl;
    iter(iArr, sizeof(iArr) / sizeof(int), &printElemPlus5);
    std::cout << std::endl;
    iter(fArr, sizeof(fArr) / sizeof(float), &printElem);
    std::cout << std::endl;
    iter(dArr, sizeof(dArr) / sizeof(double), &printElem);
    std::cout << std::endl;
    iter(sArr, sizeof(sArr) / sizeof(std::string), &printElem);
    std::cout << std::endl;

    return 0;
}