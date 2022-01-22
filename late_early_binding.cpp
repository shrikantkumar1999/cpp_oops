// CPP program to illustrate
// working of Virtual Functions
/*e binding (Runtime) is done in accordance with the content of pointer (i.e. location pointed
//to by pointer) and Early binding (Compile time) is done according to the 
//type of pointer, since print() function is declared with virtual keyword so it will be bound at
//runtime (output is print derived class as pointer is pointing to object of
//derived class) and show() is non-virtual so it will be bound during compile time (output is 
// show base class as pointer is of base type).*/
#include<iostream>
using namespace std;

class base {
public:
	void fun_1() { cout << "base-1\n"; }
	virtual void fun_2() { cout << "base-2\n"; }
	virtual void fun_3() { cout << "base-3\n"; }
	virtual void fun_4() { cout << "base-4\n"; }
};

class derived : public base {
public:
	void fun_1() { cout << "derived-1\n"; }
	void fun_2() { cout << "derived-2\n"; }
	void fun_4(int x) { cout << "derived-4\n"; }
};

int main()
{
	base *p;
	derived obj1;
	p = &obj1;

	// Early binding because fun1() is non-virtual
	// in base
	p->fun_1();

	// Late binding (RTP)
	p->fun_2();

	// Late binding (RTP)
	p->fun_3();

	// Late binding (RTP)
	p->fun_4();
derived o;
  o.fun_4(4);
	// Early binding but this function call is
	// illegal (produces error) because pointer
	// is of base type and function is of
	// derived class
	// p->fun_4(5);

	return 0;
}
