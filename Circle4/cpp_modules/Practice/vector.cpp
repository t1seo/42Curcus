#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

int main()
{
    std::vector<int> v;              // vector
    std::vector<int>::iterator iter; // iterator

    int arr[] = {3, 2, 1, 4, 7};
    v.assign(arr, arr + 5);

    sort(v.begin(), v.end());

    for (iter = v.begin(); iter != v.end(); iter++)
        std::cout << *iter << std::endl;

    int max = *std::max_element(v.begin(), v.end());
    int min = *std::min_element(v.begin(), v.end());

    std::cout << max << " " << min << std::endl;

    std::vector<int> vec(v.size());

    int ar[] = {1, 2, 5, 10, 15, 12, 20};
    std::adjacent_difference(v.begin(), v.end(), back_inserter(vec));

    for (iter = vec.begin(); iter != vec.end(); iter++)
        std::cout << *iter << std::endl;

    return 0;
}
