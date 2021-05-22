#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str[] = {
        "hello",
        "world",
        "cpp"};

    cout << sizeof(str) / sizeof(string) << endl;
}