#include <iostream>

using namespace std;

class t1
{
	void show() {}
};

class t2
{
	virtual void show() {}
};

struct s1
{
	void show() {}
};

struct s2
{
	virtual void show() {}
};

enum e
{
	//gcc compiler don't allow empty enum
};

int main(void)
{
	t1 obj1;
	t2 obj2;
	struct s1 st1;
	struct s2 st2;

	enum e e1;
	
	cout << "empty class without virtual:\t" << sizeof(obj1) << endl;
	cout << "empty class with virtual:\t" << sizeof(obj2) << endl;
	cout << "empty struct without virutal:\t" << sizeof(st1) << endl;
	cout << "empty struct with virutal\t" << sizeof(st2) << endl;

	cout << "empty enum:\t" << sizeof(e1) << endl;

	return 0;
}

