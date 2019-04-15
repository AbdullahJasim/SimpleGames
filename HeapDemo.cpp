#include <iostream>
#include <string>

using namespace std;

class Critter {
public:
	Critter(const string& name = "", int age = 0);
	~Critter();
	Critter(const Critter& c);
	Critter& operator=(const Critter& c);
	void Greet() const;

private:
	string* m_pName;
	int m_Age;
};

Critter::Critter(const string& name, int age) {
	cout << "Creating critter...\n";
	m_pName = new string(name);
	m_Age = age;
}

Critter::~Critter() {
	cout << "Deleting critter...\n";
	delete m_pName;
}

Critter::Critter(const Critter& c) {
	cout << "Copying critter...\n";
	m_pName = new string(*(c.m_pName));
	m_Age = c.m_Age;
}

Critter& Critter::operator=(const Critter& c) {
	cout << "Copying critter via operator...\n";

	if (&c != this) {
		delete m_pName;
		m_pName = new string(*(c.m_pName));
		m_Age = c.m_Age;
	}

	return *this;
}

void Critter::Greet() const {
	cout << "My name is " << *m_pName << ", and I am " << m_Age << " years old.\n";
	cout << "&m_pName: " << &m_pName << endl;
}

void runHeapDemo();
void testDestructor();
void testCopyConstructor(Critter c);
void testAssignmentOperator();

//int main() {
//	runHeapDemo();
//
//	return 0;
//}

void runHeapDemo() {
	testDestructor();
	cout << endl;

	Critter blanket("Blanket", 5);
	blanket.Greet();

	testCopyConstructor(blanket);
	blanket.Greet();
	cout << endl;

	testAssignmentOperator();
}

void testDestructor() {
	Critter toDestroy("Lamb to the slaughter", 3);
	toDestroy.Greet();
}

void testCopyConstructor(Critter c) {
	c.Greet();
}

void testAssignmentOperator() {
	Critter c1("White Rabbit", 2);
	Critter c2("Red Rabbit", 3);

	c1 = c2;

	c1.Greet();
	c2.Greet();

	cout << endl;

	Critter c3("Blue Rabbit", 6);
	c3 = c3;
	c3.Greet();
}