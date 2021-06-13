#include <iostream>

class Person
{
public:
	Person(std::string name, int age);
	~Person();
	Person(const Person &person);
	Person &operator=(const Person &person);

	virtual std::string getName() const;
	int getAge() const;

private:
	int mAge;
	std::string mName;
};

class PeakyBlinders : public Person
{
public:
	PeakyBlinders(std::string name, int age, std::string position);

	std::string getPosition() const;
	std::string getName() const;

private:
	std::string mPosition;
};

Person::Person(std::string name, int age)
    : mName(name), mAge(age)
{
}

Person::~Person()
{
}

Person::Person(const Person &person)
{
	*this = person;
}

Person &Person::operator=(const Person &person)
{
	mName = person.mName;
	mAge = person.mAge;
	return (*this);
}

std::string Person::getName() const
{
	return mName;
}

int Person::getAge() const
{
	return mAge;
}

PeakyBlinders::PeakyBlinders(std::string name, int age, std::string position)
    : Person(name, age), mPosition(position)
{
}

std::string PeakyBlinders::getPosition() const
{
	return mPosition;
}

std::string PeakyBlinders::getName() const
{
	std::string str = (*this).getName();
	return str;
}

int main()
{
	PeakyBlinders tom("Thomas", 21, "boss");

	std::cout << tom.getName() << std::endl;
	std::cout << tom.getAge() << std::endl;
	std::cout << tom.getPosition() << std::endl;
}