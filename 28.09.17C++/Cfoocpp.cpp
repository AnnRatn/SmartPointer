#include "stdafx.h"

class Cfoo {
public:
	Cfoo():b(10), a(20) {
		//не нужно сделать создание объекта, а потом его копирование, достаточно сделать сразу присваивание
		std::cout << "Constructor" << std::endl;
	}
	~Cfoo() {
		std::cout << "Dectructor" << std::endl;
	}

	Cfoo(const Cfoo &obj) {
		std::cout << "Construct from another object" << std::endl;
		a = obj.a;
	}

	//Cfoo& operator=(const Cfoo &first) {
	//	a = first.a;
	//	std::cout << "===" << std::endl;
	//	return *this;
	//}

	void SomeFunction(/*const Cfoo& obj*/) {
		std::cout << "Some function" << std::endl;
		//a = obj.a;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Cfoo& obj);

private:
	int a, b;
};


//переопределить *, &, ->
template< typename Type >
class CfooNew {

private:
	Type* obj;

public:
	CfooNew(Type* f) {
		obj = f;
	}

	Type* operator->() {
		return obj;
	}

	Type& operator* () { 
		return *obj; 
	}

	~CfooNew() {
		delete obj;
	}
};