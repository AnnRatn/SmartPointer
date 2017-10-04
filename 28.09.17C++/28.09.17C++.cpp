// 28.09.17C++.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Cfoocpp.cpp"

void foo(const Cfoo& obj) {

}

std::ostream& operator<<(std::ostream& stream, const Cfoo& obj) {
	stream << "a = " << obj.a << " b = " << obj.b << std::endl;
	return stream;
}

int main()
{
	Cfoo a;
	Cfoo b(a);
	foo(a);
	b = a;

	Cfoo *f = new Cfoo();

	CfooNew<Cfoo> ff(f);
	ff->SomeFunction();
	
	system("pause");
    return 0;
}

