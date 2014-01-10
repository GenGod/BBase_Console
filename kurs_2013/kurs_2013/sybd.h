#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sybd
{
public:
	string type;
	double kol;
	double price;
	sybd(void);
	sybd(string str, double dob, double doo);
	void set_price(double doo);
	void ust_string();
	void ust_double();
	void ust_doub();
	double get_price(void);
	void set_kol(double dob);
	double get_kol(void);
	void set_type(string str);
	string get_type(void);
	virtual void print_msg(void)=0;
	virtual ~sybd(void) = 0;
};