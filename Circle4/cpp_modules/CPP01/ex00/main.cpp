#include "Pony.hpp"

void ponyOnTheHeap(std::string name)
{
    Pony *pony = new Pony(name);
    pony->Eat();
    pony->Run();
    pony->Sleep();
    delete pony;
}

void ponyOnTheStack(std::string name)
{
    Pony pony(name);
    pony.Eat();
    pony.Run();
    pony.Sleep();
}

int main(void)
{
    ponyOnTheHeap("Heap Pony");
    ponyOnTheStack("Stack Pony");
    return 0;
}