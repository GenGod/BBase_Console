#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class password
{
private:
	string name;
	string pass;
	int access;
public:
	password();
	password(string name1);
	password(string name1, string pas, int fgh);
	password(const password & dfg);
	void set_access(int ghj);
	int get_access();
	void set_name(string name1);
	string get_name();
	void set_pass(string pas);
	string get_pas();
	password operator=(password pas);
	bool password::operator==(vector<password>::iterator rf);
};