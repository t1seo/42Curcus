#include <iostream>

using namespace std;

class Person
{
public:
	Person(std::string name, int age);
	~Person();
	std::string getName() const;
	int getAge() const;
	void setName(std::string newName);

private:
	std::string mName;
	int mAge;
};

Person::Person(std::string name, int age)
    : mName(name), mAge(age)
{
}

Person::~Person()
{
}

std::string Person::getName() const
{
	return mName;
}

int Person::getAge() const
{
	return mAge;
}

void Person::setName(std::string newName)
{
	mName = newName;
}

int main(void)
{
	Person tom("Tom", 21);

	std::cout << tom.getName() << " " << tom.getAge() << std::endl;

	tom.setName("Tommy");

	std::cout << tom.getName() << " " << tom.getAge() << std::endl;

	return 0;
}