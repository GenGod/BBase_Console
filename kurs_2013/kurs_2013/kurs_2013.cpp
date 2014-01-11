#define _CRT_SECURE_NO_WARNINGS


#include <fstream>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include "Header.h"

template<class T>
void swapt(T &fru, T &fgh)
{
	T rtg;
	fru.set_type(rtg.get_type());
	fru.set_kol(rtg.get_kol());
	fru.set_price(rtg.get_price());
	fru.set_smth(rtg.get_smth());
	fru.set_type(fgh.get_type());
	fru.set_kol(fgh.get_kol());
	fru.set_price(fgh.get_price());
	fru.set_smth(fgh.get_smth());
	fgh.set_type(rtg.get_type());
	fgh.set_kol(rtg.get_kol());
	fgh.set_price(rtg.get_price());
	fgh.set_smth(rtg.get_smth());
}

void print_smth(vector<fruit> fru)
{
	vector<fruit>::iterator ou = fru.begin();
	if (ou == fru.end())
		cout << "BBase is empty.\n";
	else for (ou; ou != fru.end(); ou++)
		cout << *ou;
}

void print_smth(vector<ovos> ovo)
{
	vector<ovos>::iterator ou = ovo.begin();
	if (ou == ovo.end())
		cout << "BBase is empty.\n";
	for (ou; ou != ovo.end(); ou++)
		cout << *ou;
}

vector<fruit>::iterator search_smth(vector<fruit>& ovo, string str)
{
	vector<fruit>::iterator hj=ovo.end();
	vector<fruit>::iterator it = ovo.begin();
	for (it; it != ovo.end(); it++)
	{
		if (it->get_type() == str)
		{
			hj=it;
			break;
		}
	}
	return hj;
}

vector<ovos>::iterator search_smth(vector<ovos>& ovo,string str)
{
	vector<ovos>::iterator it = ovo.begin();
	for (it; it != ovo.end(); it++)
	{
		if (it->get_type() == str)
		{
			return it;
			break;
		}
	}
}

void delete_smth(vector<ovos>& vovos)
{
	int f;
	int b = 0;
	string str;
	while (1)
	{
		cout << "Enter the name of vegetable to delete:\n";
		cin >> str;
		vector<ovos> ::iterator iy = vovos.begin();
		iy = search_smth(vovos, str);
		if (iy != vovos.end())
		{
			int hg = (iy - vovos.begin());
			swapt(vovos[hg], vovos.back());
			vovos.pop_back();
		}
		else cout << "Vegetable not found." << endl;
		cout << "1. Back to menu\n2. Delete more vegetable\n"<<endl;
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  b++;
				  break;
		}
		case 2: break;
		}
		if (b!=0)
		break;
	}
}

void delete_smth(vector<fruit>& vfru)
{
	int f;
	int a = 0;
	string str;
	cout << vfru[0];
	while (1)
	{
		cout << "Enter the name of fruit to delete:\n";
		cin >> str;
		vector<fruit> ::iterator is = vfru.begin();
		is = search_smth(vfru, str);
		if (is != vfru.end())
		{
			int hg = (is - vfru.begin());
			swapt(vfru[hg], vfru.back());
			vfru.pop_back();
		}
		else cout << "Fruit not found." << endl;
		cout << "1. Back to menu\n2. Delete more fruit\n" << endl;
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  a++;
				  break;
		}
		case 2: break;
		}
		if (a!=0)
		break;
	}
}

void trans_sybd(vector<ovos> &vovo, vector<fruit> &vfruit)
{
	string str;
	ovos vovos;
	fruit vfru;
	double doo;
	cout << "Enter the product name to search and transfer:" << endl;
	cin >> str;
	vector<ovos>::iterator uo = search_smth(vovo, str);
	str = uo->get_type();
	vfru.set_type(str);
	doo = uo->get_kol();
	vfru.set_kol(doo);
	doo = uo->get_price();
	vfru.set_price(doo);
	doo = uo->get_shelf_life();
	vfru.set_shelf_life(doo);
	cout << "Specify the country of origin:" << endl;
	cin >> str;
	vfru.set_smth(str);
	vfruit.push_back(vfru);
}

void trans_sybd(vector<fruit> &vfruit, vector<ovos> &vovo)
{
	string syr;
	bool boo;
	string str;
	double doo;
	fruit vfru;
	ovos vovos;
	cout << "Enter the product name to search and transfer:" << endl;
	cin >> syr;
	vector<fruit>::iterator uo = search_smth(vfruit,syr);
	str = uo->get_type();
	vovos.set_type(str);
	doo = uo->get_kol();
	vovos.set_kol(doo);
	doo = uo->get_price();
	vovos.set_price(doo);
	doo = uo->get_shelf_life();
	vovos.set_shelf_life(doo);
	cout << "Enter a new presence indicator of GMOs (1 - yes, 0 - no):" << endl;
	cin >> boo;
	vovos.set_smth(boo);
	vovo.push_back(vovos);
}

double profit(vector<ovos> vovos)
{
	double prof, kj, fh;
	vector<ovos>::iterator ip;
	if (ip != vovos.end())
	{
		for (ip = vovos.begin(); ip != vovos.end(); ip++)
		{
			kj = ip->get_price();
			fh = ip->get_kol();
			prof = (kj)*(fh);
		}
		double ght = prof;
		prof = prof - (((prof / 100) + (fmod(ght, 100)) * 16));
		return prof;
	}
	else return 0;
}

double profit(vector<fruit> vfru)
{
	double prof, fd, ds;
	vector<fruit>::iterator ip;
	if (ip != vfru.end())
	{
		for (ip = vfru.begin(); ip != vfru.end(); ip++)
		{
			fd = ip->get_price();
			ds = ip->get_kol();
			prof = (fd)*(ds);
		}
		double ghu = prof;
		prof = prof - (((prof / 100) + (fmod(ghu, 100)) * 16));
		return prof;
	}
	else return 0;
}

void add_smth(vector<ovos>& vovos)
{
	int g=0;
	double dod;
	bool r;
	string str;
	while (1)
	{
		ovos gu;
		gu.print_msg();
		cin >> str;
	    gu.set_type(str);
		cin >> dod;
		gu.set_kol(dod);
		cin >> dod;
		gu.set_price(dod);
		cin >> r;
		gu.set_smth(r);
		cin >> dod;
		gu.set_shelf_life(dod);
		vovos.push_back(gu);
		int f;
		cout << "1. Back to menu\n2.Add more vegetable\n";
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  g++;
				  break;
		}
		case 2: break;
		}
		if (g != 0)
			break;
	}
}

void add_smth(vector<fruit>& vfru)
{
	double dod;
	string str;
	int d = 0;
	while (1)
	{
		fruit fu;
		fu.print_msg();
		cin >> str;
			fu.set_type(str);
			cin >> dod;
			fu.set_kol(dod);
			cin >> dod;
			fu.set_price(dod);
			cin >> str;
			fu.set_smth(str);
			cin >> dod;
			fu.set_shelf_life(dod);
		vfru.push_back(fu);
		int f;
		cout << "1. Back to menu\n2.Add more fruit\n";
		cin >> f;
		switch (f)
		{
		case 1:
		{
				  d++;
				  break;
		}
		case 2: break;
		}
		if (d != 0)
			break;
	}
}

template <class T>
void file_save(vector<T>& vovos, int right, string username)
{
	switch (right)
	{
	case 1:
	{
			  char* ch;
			  wchar_t* wch;
			  string put = "C:\\BBase\\Premium\\";
			  string put2 = put;
			  put += username;
			  string name_p;
			  int hu = put.capacity();
			  vector<T>::iterator uy = vovos.begin();
			  CreateDirectoryW(L"C:\\BBase", NULL);
			  CreateDirectoryW(L"C:\\BBase\\Premium\\", NULL);
			  ch = new char[hu];
			  wch = new wchar_t[hu];
			  strcpy(ch, put.c_str());
			  for (int i = 0; i < hu; i++)
				  MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, &ch[i], 1, &wch[i], 1);
			  CreateDirectoryW(wch, NULL);
			  put += "\\";
			  cout << "Enter filename to save a data (if it does not exist, one will be created):" << endl;
			  cin >> name_p;
			  put += name_p;
			  put += ".dba";
			  ofstream out(put);
			  for (uy; uy != vovos.end(); uy++)
			  {
				  out << uy->get_type();
				  out << " ";
				  out << uy->get_kol();
				  out << " ";
				  out << uy->get_price();
				  out << " ";
				  out << uy->get_smth();
				  out << " ";
				  out << uy->get_shelf_life();
				  out << "\n";
			  }
			  cout << "Data has been successfully saved!\n";
			  out.close();
			  break;
	}
	case 2:
	{
			  cout << "In free version you can't save more than 30 items!\n";
			  vector<T>::iterator uy = vovos.begin();
			  int j = 0;
			  CreateDirectoryW(L"C:\\BBase", NULL);
			  string name_p;
			  string put = "C:\\BBase\\Gewonlich\\";
			  cout << "Enter filename to save a data (if it does not exist, one will be created)" << endl;
			  cin >> name_p;
			  put += name_p;
			  put += ".dba";
			  ofstream out(put);
			  for (uy; uy != vovos.end(); uy++)
			  {
				  out << uy->get_type() << " " << uy->get_kol() << " " << uy->get_price() << " " << uy->get_smth() << " " << uy->get_shelf_life()<< "\n";
				  if (j < 10)
					  j++;
				  else break;
			  }
			  cout << "Data has been successfully saved!\n";
			  out.close();
			  break;
	}
	case 3:
	{
			  cout << "You can't save data to disk in the trial version!";
			  break;
	}
	}
}

vector<fruit> load_file(int right)
{
	vector<fruit> vovos;
	string put;
	string str, dfg;
	double dod, dob, goh;
	fruit voso;
	cout << "Enter path to file as: C:\\Folder_Name\\File_Name.dba\n";
	cin >> put;
	ifstream in(put);
	if (!in)
	{
		cout << "File not found!\n";
	}
	else
	{
		switch (right)
		{
		case 1:
		{
				  while (in)
				  {
					  in >> str >> dod >> dob >> dfg >> goh;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(dfg);
					  voso.set_shelf_life(goh);
					  vovos.push_back(voso);
				  }
				  vovos.pop_back();
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 2:
		{
				  cout << "In free version you can't load more than 10 items from the file." << endl;
				  int j = 0;
				  while (in)
				  {
					  in >> str >> dod >> dob >> dfg >> goh;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(dfg);
					  voso.set_shelf_life(goh);
					  vovos.push_back(voso);
					  if (j < 9)
						  j++;
					  else break;
				  }
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 3:
		{
				  cout << "In trial version you can load from the file one item only." << endl;
				  in >> str >> dod >> dob >> dfg >> goh;
				  voso.set_type(str);
				  voso.set_kol(dod);
				  voso.set_price(dob);
				  voso.set_smth(dfg);
				  voso.set_shelf_life(goh);
				  vovos.push_back(voso);
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		}
	}
	in.close();
	return vovos;
}

vector<ovos> load_file(double right2)
{
	vector<ovos> vovos;
	string put;
	int right = int(right2);
	string str;
	double dob, dod, goh;
	bool boo;
	ovos voso;
	cout << "Enter path to file as: C:\\Folder_Name\\File_Name.dba\n";
	cin >> put;
	ifstream in(put);
	if (!in)
	{
		cout << "File not found!\n";
	}
	else
	{
		switch (right)
		{
		case 1:
		{
				  while (in)
				  {
					  in >> str >> dod >> dob >> boo >>goh;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(boo);
					  voso.set_shelf_life(goh);
					  vovos.push_back(voso);
				  }
				  vovos.pop_back();
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 2:
		{
				  cout << "In free version you can't load more than 10 items from the file." << endl;
				  int j = 0;
				  while (in)
				  {
					  in >> str >> dod >> dob >> boo >> goh;
					  voso.set_type(str);
					  voso.set_kol(dod);
					  voso.set_price(dob);
					  voso.set_smth(boo);
					  voso.set_shelf_life(goh);
					  vovos.push_back(voso);
					  if (j < 9)
						  j++;
					  else break;
				  }
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		case 3:
		{
				  cout << "In trial version you can load from the file one item only." << endl;
				  in >> str >> dod >> dob >> boo >> goh;
				  voso.set_type(str);
				  voso.set_kol(dod);
				  voso.set_price(dob);
				  voso.set_smth(boo);
				  voso.set_shelf_life(goh);
				  vovos.push_back(voso);
				  cout << "Data from the file has been successfully added!\n";
				  break;
		}
		}
	}
	in.close();
	return vovos;
}
void menu(vector<ovos>& vovos, vector<fruit>& vfru, int right, string user_name)
{
	int h;
	int d;
	int t = 0;
	int e = 0;
	double right2 = right;
	while (1)
	{
		cout << "What you want to work?\n1. Vegetables\n2. Fruit\n3. Exit program" << endl;
		cin >> d;
		switch (d)
		{
		case 1:
		{
				  while (1)
				  {
					  t = 0;
					  cout << "What you want to do?\n1. Add a new vegetable\n2. Delete an existing vegetable\n3. Find a vegetable in BBase\n4. Save BBase of vegetables to disk\n5. Load BBase of vegetables from the disk\n6. Show BBase of vegetables on the screen\n7. Move product to the category 'Fruit' \n8. Profits from the sale of all vegetable stock including tax equal\n9.Return to previous menu\n" << endl;
					  cin >> h;
					  switch (h)
					  {
					  case 1:
					  {
								add_smth(vovos);
								break;
					  }
					  case 2:
					  {
								delete_smth(vovos);
								break;
					  }
					  case 3:
					  {
								string str;
								int f;
								while (1)
								{
									int z = 0;
									cout << "Enter name of vegetable to search:\n" << endl;
									cin >> str;
									vector<ovos>::iterator ut = search_smth(vovos, str);
									if (ut != vovos.end())
									{
										cout << "Change information about it?\n1.Yes\n2.No\n3.Return to menu\n\n\n";
										cin >> f;
										switch (f)
										{
										case 1:
										{
												  while (1)
												  {
													  int k;
													  cout << "What would you like to change?\n1.The name\n2.The price (1 lb)\n3.GMO\n4.Amount (in lb)\n5. Shelf life (in month)\n6. Return to previous menu\n\n\n";
													  cin >> k;
													  switch (k)
													  {
													  case 1:
													  {
																cout << "Enter new vegetable name: \n";
																ut->ust_string();
																break;
													  }
													  case 2:
													  {
																cout << "Enter new vegetable price:\n";
																ut->ust_double();
																break;
													  }
													  case 3:
													  {
																cout << "Enter a new indicator of presence of GMOs (1 - yes, 0 - no)\n";
																ut->ust_bool();
																break;
													  }
													  case 4:
													  {
																cout << "Enter new vegetable amount (in lb)\n";
																ut->ust_doub();
																break;
													  }
													  case 5:
													  {
																ut->ust_dooo();
																break;
													  }
													  case 6:
													  {
																z++;
																break;
													  }
													  }
													  if (z != 0)
														  break;
												  }
										}
										case 2:
										{
												  z++;
												  break;
										}
										case 3:
										{
												  z++;
												  break;
										}
										}
									}
									if (z != 0)
										break;
								}
								break;
					  }
					  case 4:
					  {
								file_save(vovos, right, user_name);
								break;
					  }
					  case 5:
					  {
								vovos = load_file(right2);
								break;
					  }
					  case 6:
					  {
								print_smth(vovos);
								break;
					  }
					  case 7:
					  {
								trans_sybd(vovos, vfru);
								break;
					  }
					  case 8:
					  {
								double tem = profit(vovos);
								cout << "Profits from the sale of vegetables stock including tax equal is " << tem << endl;
								break;
					  }
					  case 9:
					  {
								t++;
								break;
					  }
					  }
					  if (t != 0)
						  break;
				  }
				  break;
		}
				case 2:
				{
						  while (1)
						  {
							  t = 0;
							  cout << "What you want to do?\n1. Add a new fruit\n2. Delete an existing fruit\n3. Find a fruit in BBase\n4. Save BBase of fruit to disk\n5. Load BBase of fruit from the disk\n6. Show BBase of fruit on the screen\n7. Move product to the category 'Vegetable' \n8. Profits from the sale of all fruit stock including tax equal\n9.Return to previous menu\n" << endl;
							  cin >> h;
							  switch (h)
							  {
							  case 1:
							  {
										add_smth(vfru);
										break;
							  }
							  case 2:
							  {
										delete_smth(vfru);
										break;
							  }
							  case 3:
							  {
										string str;
										int f;
										while (1)
										{
											int z = 0;
											cout << "Enter name of fruit to search:\n" << endl;
											cin >> str;
											vector<fruit>::iterator ut = search_smth(vfru, str);
											if (ut != vfru.end())
											{
												cout << "Change information about it?\n1.Yes\n2.No\n3.Return to menu\n\n\n";
												cin >> f;
												switch (f)
												{
												case 1:
												{
														  while (1)
														  {
															  int k;
															  cout << "What would you like to change?\n1.The name\n2.The price (1 lb)\n3.Origin country\n4.Amount (in lb)\n5. Shelf life (in month)\n6. Return to previous menu\n\n\n";
															  cin >> k;
															  switch (k)
															  {
															  case 1:
															  {
																		cout << "Enter new fruit name: \n";
																		ut->ust_string();
																		break;
															  }
															  case 2:
															  {
																		cout << "Enter new fruit price:\n";
																		ut->ust_double();
																		break;
															  }
															  case 3:
															  {
																		cout << "Enter a new origin country\n";
																		ut->ust_smth();
																		break;
															  }
															  case 4:
															  {
																		cout << "Enter new fruit amount (in lb)\n";
																		ut->ust_doub();
																		break;
															  }
															  case 5:
															  {
																		ut->ust_dooo();
																		break;
															  }
															  case 6:
															  {
																		z++;
																		break;
															  }
															  }
															  if (z != 0)
																  break;
														  }
												}
												case 2:
												{
														  z++;
														  break;
												}
												case 3:
												{
														  z++;
														  break;
												}
												}
											}
											if (z != 0)
												break;
										}
										break;
							  }
							  case 4:
							  {
										file_save(vfru, right, user_name);
										break;
							  }
							  case 5:
							  {
										vfru = load_file(right);
										break;
							  }
							  case 6:
							  {
										print_smth(vfru);
										break;
							  }
							  case 7:
							  {
										trans_sybd(vfru, vovos);
										break;
							  }
							  case 8:
							  {
										double temp = profit(vfru);
										cout << "Profits from the sale of fruit stock including tax equal is " << temp << endl;
										break;
							  }
							  case 9:
							  {
										t++;
										break;
							  }
							  }
							  if (t != 0)
								  break;
						  }
						  break;
				}
		case 3:
		{
				  e++;
				  break;
		}
		}
			if (e != 0)
				break;
	}
}

void reg(vector<password>& vpas)
{
	string sdf, dfg;
	int fgh;
	password gi;
	cout << "New User Registration:\nEnter your username, password and program version(1 - Premium, 2 - Free, 3 - Trial): " << endl;
	cin >> sdf;
	gi.set_name(sdf);
	cin >> dfg;
	gi.set_pass(dfg);
	cin >> fgh;
	gi.set_access(fgh);
	vpas.push_back(gi);
}

int main()
{
	vector<password> vpas;
	vector<password>::iterator bh;
	vector<ovos> vovos;
	vector<fruit> vfru;
	fruit gu;
	ovos gy;
	password gi;
	string sdf,dfg;
	int asd = 0;
	int h;
    int xcv = 0;
	CreateDirectoryW(L"C:\\BBase", NULL);
	CreateDirectoryW(L"C:\\BBase\\Pass", NULL);
	ifstream in("C:\\BBase\\Pass\\key.serd");
	while (in)
	{
		string str1, str2;
		int fgh;
		in >> str1 >> str2 >> fgh;
		gi.set_name(str1);
		gi.set_pass(str2);
		gi.set_access(fgh);
		vpas.push_back(gi);
	}
	if (vpas.capacity())
	{
		vpas.pop_back();
	}
	while (1)
	{
		if (!vpas.capacity())
		{
			reg(vpas);
		}
		else
		{
			vector<password>::iterator hj = vpas.end();
			vector<password>::iterator it = vpas.begin();
			cout << "Authorization:\n1. Register\n2. Log into existing account\n " << endl;
			cin >> h;
			switch (h)
			{
			case 1:
			{
					  reg(vpas);
					  break;
			}
			case 2:
			{
					  while (1)
					  {
						  cout << "Enter username and password: " << endl;
						  cin >> sdf;
						  cin >> dfg;
						  for (it; it != vpas.end(); it++)
						  {
							  if ((it->get_name() == sdf) && (it->get_pas() == dfg))
							  {
								  hj = it;
							  }
						  }
						  if (hj != vpas.end())
						  {
							  menu(vovos, vfru, hj->get_access(), hj->get_name());
							  vector<password>::iterator uy = vpas.begin();
							  ofstream out("C:\\BBase\\Pass\\key.serd");
							  for (uy; uy != vpas.end(); uy++)
							  {
								  out << uy->get_name();
								  out << " ";
								  out << uy->get_pas();
								  out << " ";
								  out << uy->get_access();
								  out << "\n";
							  }
							  asd++;
							  break;
						  }
						  else
						  {
							  cout << "Invalid username and/or password. Try again. Maybe, you want return to main menu?" << endl << "1. Return to main menu\n2. Try again\n";
							  int asg;
							  cin >> asg;
							  if (asg == 1)
								  xcv++;
						  }
						  if (xcv != 0)
							  break;
					  }
					  break;
			}
			}
		}
		if (asd != 0)
		break;
	}
	return 0;
}