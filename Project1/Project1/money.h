#ifndef __MONEY_H
#define __MONEY_H
#include <iostream>
#include <stdio.h>
using namespace std;

class money
{
private:
	int cash;
	char* name;
public:
	money(int a,char* s);
	//money operator+(const money m);
	money() { cash = 0; name = 0; }
	~money() {
		cout << name << "  end:" << cash << endl;
	}
	//money(const money& a);
	void pri();
	friend void change_name(money& a);
	friend money operator+(const money& a, const money& b);
	friend ostream& operator<<(ostream &os,const money& a);
	money& operator=(const money& a);

};


#endif 



