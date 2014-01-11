#include "ovos.h"

ovos::ovos()
	{
		type = "Tomato";
		kol = 1;
		gmo = false;
		price = 10;
	}
ovos::ovos(string str, double dob, bool boo, double doo, double shelf_lif)
	{
		type = str;
		kol = dob;
		gmo = boo;
		price = doo;
		shelf_life = shelf_lif;
	}
void ovos::set_smth(bool boo)
	{
		gmo = boo;
	}
bool ovos::get_smth()
	{
		return gmo;
	}
void ovos::ust_bool()
{
	bool boo;
	cin >> boo;
	set_smth(boo);
}
void ovos::print_msg()
{
	cout << "Enter the name of vegetable, the amount in lb, the price for 1 lb of vegetable, GMO (if there is - 1, otherwise - 0) and shelf life of fruit:" << endl << endl;;
}

ovos ovos::operator=(ovos vo)
	{
		vo.set_type(type);
		vo.set_kol(kol);
		vo.set_smth(gmo);
		vo.set_price(price);
		vo.set_shelf_life(shelf_life);
		return vo;
	}
bool ovos::operator==(vector<ovos>::iterator rf)
	{
		if (rf->get_type() == this->get_type())
			return true;
		else return false;
	}
ovos::~ovos(){}