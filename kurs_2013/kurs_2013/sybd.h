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
	double shelf_life;
	sybd(void);
	sybd(string str, double dob, double doo, double shelf_lif);
	void set_price(double doo);
	void ust_string(void);
	void ust_double(void);
	void ust_doub(void);
	void ust_dooo(void);
	double get_price(void);
	void set_kol(double dob);
	double get_kol(void);
	void set_type(string str);
	string get_type(void);
	void set_shelf_life(double shelf_lif);
	double get_shelf_life(void);
	virtual void print_msg(void)=0;
	virtual ~sybd(void) = 0;
};