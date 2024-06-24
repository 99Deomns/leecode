#include "money.h"

money::money(int a,char* s) {
	this->cash = a;
	this->name = s;
}
/*
money money::operator+(const money m) {
	money sum(0);
	sum.cash = this->cash + m.cash;
	return sum;
}*/


void money::pri() {
	cout << this->cash << endl;
	cout << this->name << endl;
	printf("%p    %p     %p\n", &(this->cash), this->name, &(this->name));
	cout << (void*)this->name << "   " << &(this->name) << endl;
}

money& money::operator=(const money& a)
{
	delete[] name;
	this->name = new char[4];
	strcpy(name, a.name);
	cash = a.cash;
	return *this;
}

void change_name(money& a)
{
	char b[] = "copy";
	a.name = b;
	cout << b << endl;
}

money operator+(const money& a, const money& b)
{
	char str[] = "str";
	money sum(0,str);
	sum.cash = a.cash + b.cash;
	return sum;
}

ostream& operator<<(ostream& os, const money& a)
{
	os << a.cash;
	return os;
}


