#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	int ar[] = {1, 2, 5, 10, 15, 12, 20};
	std::vector<int> v1(&ar[0], &ar[7]);
	std::vector<int> v2(v1.size());

	// sort v1 and print
	sort(v1.begin(), v1.end());
	std::cout << "v1: ";
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		std::cout << *it << " ";
	}

	// adjacent differnces are saved in v2 vector
	std::adjacent_difference(v1.begin(), v1.end(), v2.begin());
	std::cout << "\n";

	// print v2
	std::cout << "v2: ";
	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	// sort v2 and print
	sort(v2.begin() + 1, v2.end());
	std::cout << "v2: ";
	for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	// shortest span
	std::cout << "Shortest Span: " << v2[1] << std::endl;

	return 0;
}