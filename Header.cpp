#include"Header.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int mainmenu()//Main Menu
{
	int p = 0;
	system("cls");
	cout << "\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t\t  PLEASE SELECT YOUR DESIRED OPERATION:\n\n";
	SetConsoleTextAttribute(h, 0x7);
	cout << "\t\t" << setfill('ß') << setw(59) << "\n\n";
	cout << "[1] =====> Admin MODE.\n";
	cout << "[2] =====> WareHouse MODE.\n";
	cout << "[3] =====> About Programmer.\n";
	cout << "[4] =====> Exit.\n\n";
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t\t\t\tMAIN MENU\n\n";
	SetConsoleTextAttribute(h, 0x7);
	cout << "\t\t" << setfill('ß') << setw(59) << "\n\n";
	cout << "Select:";
	cin >> p;
	return p;
}

int MenuOfManager()//MENU OF Manager's Works
{
	int n = 0;
	system("cls");
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
	cout << "\t\t\t  PLEASE SELECT YOUR DESIRED OPERATION:\n\n";
	cout << "\t\t" << setfill('ß') << setw(58) << "\n";
	cout << "\t\t\t\t     Manager's Menu\n\n";
	cout << "\t\t" << setfill('ß') << setw(59) << "\n\n";
	SetConsoleTextAttribute(h, 0x7);
	cout << "[1] =====> ADD WareHouseMan:\n";
	cout << "[2] =====> View List Of Products Decending:\n";
	cout << "[3] =====> View List of products with less than 5 inventory:\n";
	cout << "[4] =====> Warehouse specifications that have entered the most product into the system:\n";
	cout << "[5] =====> Exit System.\n\n" << endl;
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t" << setfill('ß') << setw(59) << "\n";
	SetConsoleTextAttribute(h, 0x7);
	cout << "Select:";
	cin >> n;
	return n;
}


int menu_of_wareHouses(int& Wareid)//Menu of WareHouseMans works
{
	int a = 0;
	system("cls");
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
	cout << "\t\t\t  PLEASE SELECT YOUR DESIRED OPERATION:\n\n";
	cout << "\t\t" << setfill('ß') << setw(58) << "\n";
	cout << "\t\t\t\t  WarehouseMan'S Menu\n\n";
	cout << "\t\t" << setfill('ß') << setw(59) << "\n\n";
	SetConsoleTextAttribute(h, 0x7);
	cout << "[1] =====> ADD Product:\n";
	cout << "[2] =====> Delete Product:\n";
	cout << "[3] =====> Update Product's Information:\n";
	cout << "[4] =====> View List Of Products Decending:\n";
	cout << "[5] =====> Exit System.\n\n";
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t\t\t      UserID:" << Wareid << "\n\n";
	cout << "\t\t" << setfill('ß') << setw(59) << "\n";
	SetConsoleTextAttribute(h, 0x7);
	cout << "Select:";
	cin >> a;
	return a;
}

void writingwarehouses(WareHouses list[MAX], int& cur_warehouses_num)//Write WareHouse's information to WareHouseMans.txt
{
	system("cls");
	string warehousefile = "WareHouseMans.txt";
	ofstream fout(warehousefile);
	if (!fout)
	{
		cerr << "File Does Not Exist.\a\n";
		exit(1);
	}
	else
	{
		for (int i = 0; i < cur_warehouses_num; i++)
		{
			fout << list[i].PersonalCode << " ";
			fout << list[i].age << " ";
			fout << list[i].income << " ";
			fout << list[i].WareHousePass << endl;
		}
	}
	fout.close();
}

void writingproducts(Products list2[MAX], int& cur_product_num)//Write Product's information to Products.txt
{
	system("cls");
	string Productsfile = "Products.txt";
	ofstream fout(Productsfile);
	if (!fout)
	{
		SetConsoleTextAttribute(h, 0x4);
		cerr << "File Does Not Exist.\a\n";
		SetConsoleTextAttribute(h, 0x7);
		exit(1);
	}
	else
	{
		for (int i = 0; i < cur_product_num; i++)
		{
			fout << list2[i].barcode << " ";
			fout << list2[i].productname << " ";
			fout << list2[i].price << " ";
			fout << list2[i].in_stock << " ";
			fout << list2[i].PersonalCode << endl;
		}
	}
	fout.close();
}

int reverse(int passnumber)
{
	int rever = 0;
	while (passnumber > 0)
	{
		rever = rever * 10 + passnumber % 10;
		passnumber = passnumber / 10;
	}
	return rever;
}

void Read_WareHouses_Information(WareHouses list[MAX], int& cur_warehouse_num)
{
	system("cls");
	string warehousefile = "WareHouseMans.txt";
	ifstream fin(warehousefile);
	if (!fin)
	{
		cerr << "File Does Not Exist.\a\n";
		exit(1);
	}
	if (fin)
	{
		SetConsoleTextAttribute(h, 0xA);
		cout << "File Opened Successfully, Loading Information From File.\n";
		SetConsoleTextAttribute(h, 0x7);
		system("Pause");
		int i = 0;
		while (fin >> list[i].PersonalCode)
		{
			fin >> list[i].age >> list[i].income >> list[i].WareHousePass;
			cur_warehouse_num++;
			i++;
		}
	}
	fin.close();
}


void ADD_WAREHOUSE(WareHouses list[MAX], int& cur_warehouses_num)
{
	system("cls");
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t" << "__________ Enter the WareHouse's Personal Information __________" << endl;
	SetConsoleTextAttribute(h, 0x7);
	while (true)
	{
		cout << "Personal Code =====> ";
		cin >> list[cur_warehouses_num].PersonalCode;
		int code = list[cur_warehouses_num].PersonalCode;
		if (code <= 99 && code >= 10)
		{
			break;
		}
		else
		{
			SetConsoleTextAttribute(h, 0x4);
			cout << "!...INVALID PLEASE TRY AGAIN...! \nPersonal Code Must Be A Positive Two_Digit Number\a\n";
			SetConsoleTextAttribute(h, 0x7);
		}
	}
	while (true)
	{
		cout << "Age =====> ";
		cin >> list[cur_warehouses_num].age;
		int age = list[cur_warehouses_num].age;
		if (age <= 50 && age>=25)
		{
			break;
		}
		else
		{
			SetConsoleTextAttribute(h, 0x4);
			cout << "!...INVALID PLEASE TRY AGAIN...! \n WareHouseMans Must Have An Age Beetween 25 upto 50\a\n";
			SetConsoleTextAttribute(h, 0x7);
		}
	}
	cout << "income =====> ";
	cin >> list[cur_warehouses_num].income;
	while(true)
	{
		cout << "Enter Password =====>";
		cin >> list[cur_warehouses_num].WareHousePass;
		int passnumber = list[cur_warehouses_num].WareHousePass;
		if(passnumber != reverse(passnumber))
		{
			break;
		}
		else
		{
			SetConsoleTextAttribute(h, 0x4);
			cout << "!...INVALID PLEASE TRY AGAIN...! \nDefined Password Must not be equal to it's reverse!\a\n";
			SetConsoleTextAttribute(h, 0x7);
		}
	}
	cur_warehouses_num++;
	writingwarehouses(list, cur_warehouses_num);//Add entered information to WareHouseMans.txt
}

void Read_Products_Information(Products list2[MAX], int& cur_product_num)
{
	system("cls");
	string Productsfile = "Products.txt";
	ifstream fin(Productsfile);
	if (!fin)
	{
		SetConsoleTextAttribute(h, 0x4);
		cerr << "File Does Not Exist.\a\n";
		SetConsoleTextAttribute(h, 0x7);
		exit(1);
	}
	if (fin)
	{
		SetConsoleTextAttribute(h, 0xA);
		cout << "File Opened Successfully.\n";
		SetConsoleTextAttribute(h, 0x7);
		int i = 0;
		while (fin >> list2[i].barcode)
		{
			fin >> list2[i].productname >> list2[i].price >> list2[i].in_stock >> list2[i].PersonalCode;
			cur_product_num++;
			i++;
		}
	}
	fin.close();
}

bool Contains(int produceid, int inp)
{

	if (produceid == inp)
	{
		return true;
	}
	return false;
}


void DeleteProduct()
{
	string ProductsFile = "Products.txt";
	string TempFileName = "Temp.txt";
	ifstream fin(ProductsFile);
	ofstream fout(TempFileName);
	int produceid = 0;
	system("cls");
	cout << "Please Enter The Produce ID to Delete it's information: ";
	cin >> produceid;
	if (fin && fout)
	{
		bool found = false;
		Products TempList;
		while (fin >> TempList.barcode)
		{
			fin >> TempList.productname >> TempList.price >> TempList.in_stock >> TempList.PersonalCode;
			if (Contains(produceid, TempList.barcode))
			{
				found = true;
			}
			else {
				fout << TempList.barcode << " " << TempList.productname << " " << TempList.price << " " << TempList.in_stock << " " << TempList.PersonalCode << endl;
			}
		}
		fin.close();
		fout.close();
		if (found)
		{
			remove(ProductsFile.c_str());
			rename(TempFileName.c_str(), ProductsFile.c_str());
			SetConsoleTextAttribute(h, 0xA);
			cout << "The Desired Product's information Deleted Successfully.\n\a";
			SetConsoleTextAttribute(h, 0x7);
			system("pause");
			return;
		}
		else
		{
			SetConsoleTextAttribute(h, 0x4);
			cerr << "Produce Not Found...!\n\a";
			SetConsoleTextAttribute(h, 0x7);
			remove(TempFileName.c_str());
			system("pause");
			return;
		}
	}
	else
	{
		SetConsoleTextAttribute(h, 0x4);
		cout << "An Error While Opening File...\n\a";
		SetConsoleTextAttribute(h, 0x7);
		exit(1);
	}
}

void Update()
{
	string ProductsFile = "Products.txt";
	string infoFileName = "info.txt";
	ifstream fin(ProductsFile);
	ofstream fout(infoFileName);
	int produceid = 0;
	system("cls");
	cout << "Please Enter The Produce ID to Update it's information: ";
	cin >> produceid;
	if (fin && fout)
	{
		bool found = false;
		Products TempList;
		while (fin >> TempList.barcode >> TempList.productname >> TempList.price >> TempList.in_stock >> TempList.PersonalCode)
		{
			if (Contains(produceid, TempList.barcode))
			{
				found = true;
				while (true)
				{
					cout << "Barcode ======> ";
					cin >> TempList.barcode;
					if (TempList.barcode <= 999 && TempList.barcode >= 100)
					{
						break;
					}
					else
					{
						SetConsoleTextAttribute(h, 0x4);
						cout << "!...INVALID PLEASE TRY AGAIN...!\n Product ID or Barcode Must Be A Positive & Three_Digit Number.\n\a";
						SetConsoleTextAttribute(h, 0x7);
					}
				}
				while (true) 
				{
					cout << "Product Name =====> ";
					cin.ignore();
					getline(cin, TempList.productname);
					string s = TempList.productname;
					if (s.size() != 0)
					{
						break;
					}
					else
					{
						SetConsoleTextAttribute(h, 0x4);
						cout << "!...INVALID PLEASE TRY AGAIN...!\n Product Name Must Not Be Empty\n\a";
						SetConsoleTextAttribute(h, 0x7);
					}
				}
				while (true)
				{
					cout << "Price ======> ";
					cin >> TempList.price;
					int price = TempList.price;
					if (price > 0)
					{
						break;
					}
					else 
					{
						SetConsoleTextAttribute(h, 0x4);
						cout << "!...INVALID PLEASE TRY AGAIN...!\n Insert A Positive Number\n\a";
						SetConsoleTextAttribute(h, 0x7);
					}
				}
				while (true) 
				{
					cout << "Number Of Products in Stock =====> ";
					cin >> TempList.in_stock;
					int stock = TempList.in_stock;
					if (stock > 0)
					{
						break;
					}
					else
					{
						SetConsoleTextAttribute(h, 0x4);
						cout << "!...INVALID PLEASE TRY AGAIN...!\n Insert A Positive Number\n\a";
						SetConsoleTextAttribute(h, 0x7);
					}
				}
			}
			fout << TempList.barcode << " " << TempList.productname << " " << TempList.price << " " << TempList.in_stock << " " << TempList.PersonalCode << endl;
		}
		fin.close();
		fout.close();
		if (found)
		{
			remove(ProductsFile.c_str());
			rename(infoFileName.c_str(), ProductsFile.c_str());
			SetConsoleTextAttribute(h, 0xA);
			cout << "The Desired Product's information Updated Successfully.\n\a";
			SetConsoleTextAttribute(h, 0x7);
			system("pause");
			return;
		}
		else
		{
			remove(infoFileName.c_str());
			SetConsoleTextAttribute(h, 0x4);
			cerr << "Produce Not Found...!\n\a";
			SetConsoleTextAttribute(h, 0x7);
			system("pause");
			return;
		}
	}
	else
	{
		SetConsoleTextAttribute(h, 0x4);
		cout << "An Error While Opening File...\n\a";
		SetConsoleTextAttribute(h, 0x7);
		exit(1);
	}
}

void sort(Products list2[MAX], int& cur_product_num)//This function sorts products information based on inventory in descending order. Bubble Sort
{
	Products temp;

	for (int i = 0; i < cur_product_num - 1; i++)
	{
		for (int j = 0; j < (cur_product_num - 1 - i); j++)
		{
			if (list2[j].in_stock < list2[j + 1].in_stock)
			{
				temp = list2[j];
				list2[j] = list2[j + 1];
				list2[j + 1] = temp;
			}
		}
	}
}

void view_most_registerant_WareHouseMan(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num)
{
	system("cls");
	if (cur_product_num == 0)
	{
		SetConsoleTextAttribute(h, 0x4);
		cout << "No Products Registered Yet...!\n\a";
		SetConsoleTextAttribute(h, 0x7);
		system("pause");
		return;
	}
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t\t" << "__________ Sample WareHouseMan's Information __________\n" << endl;
	SetConsoleTextAttribute(h, 0x7);
	int temp = 0, k = 0;
	for (int i = 0; i < cur_warehouse_num; i++)
	{
		k = 1;
		for (int j = 0; j < cur_product_num; j++)
		{
			if (list2[j].PersonalCode == list[i].PersonalCode)
			{
				list[i].registerant = k++;
			}
		}
	}
	int maximum = 0;
	for (int i = 0; i < cur_warehouse_num; i++)
	{
		if (list[i].registerant > maximum)
		{
			maximum = list[i].registerant;
			temp = i;
		}
	}
	cout << "ID: " << list[temp].PersonalCode << " - Age: " << list[temp].age << " - Income: " << list[temp].income
		<< " - Password: " << list[temp].WareHousePass	<< " - Registrant: " << list[temp].registerant;
	cout << endl;
	system("pause");
	return;
}


void View_Products_Information(WareHouses list[MAX], Products list2[MAX], int cur_product_num)
{
	system("cls");
	if (cur_product_num == 0)
	{
		SetConsoleTextAttribute(h, 0x4);
		cout << "No Products Registered Yet...!\n\a";
		SetConsoleTextAttribute(h, 0x7);
		system("pause");
		return;
	}
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t\t" << "__________ Products's Information __________\n" << endl;
	SetConsoleTextAttribute(h, 0x7);
	for (int i = 0; i < cur_product_num; i++)
	{
		cout << i << ") ID: " << list2[i].barcode << " - Name: " << list2[i].productname << " - Price: " << list2[i].price << " - Stock: "
			<< list2[i].in_stock << " - WarehousemanId: " << list2[i].PersonalCode//Wareid 
			<< "\n\n ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß "<< endl;
	}
	system("pause");
	
}

void View_Products_Information_LessThan5(Products list2[MAX], int cur_product_num)
{
	system("cls");
	if (cur_product_num == 0)
	{
		SetConsoleTextAttribute(h, 0x4);
		cout << "No Products Registered Yet...!\n\a";
		SetConsoleTextAttribute(h, 0x7);
		system("pause");
		return;
	}
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t\t" << "__________ Products's Information __________\n" << endl;
	SetConsoleTextAttribute(h, 0x7);
	for (int i = 0; i < cur_product_num; i++)
	{
		if (list2[i].in_stock < 5)
		{
			cout << i << ") ID: " << list2[i].barcode << " - Name: " << list2[i].productname << " - Price: " << list2[i].price << " - Stock: "
				<< list2[i].in_stock << " - WarehousemanId: " << list2[i].PersonalCode
				<< "\n\n ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß " << endl;
		}
	}
	system("pause");

}

void ADD_Product(WareHouses list[MAX], Products list2[MAX], int& cur_product_num, int& Wareid)
{
	system("cls");
	SetConsoleTextAttribute(h, 0xF);
	cout << "\t\t" << "__________ Enter the Products Information __________\n" << endl;
	SetConsoleTextAttribute(h, 0x7);
	while (true)
	{
		cout << "Barcode =====> ";
		cin >> list2[cur_product_num].barcode;
		int bar = list2[cur_product_num].barcode;
		if (bar <= 999 && bar >= 100)
		{
			break;
		}
		else 
		{
			SetConsoleTextAttribute(h, 0x4);
			cout << "!...INVALID PLEASE TRY AGAIN...!\n Product ID or Barcode Must Be A Positive & Three_Digit Number.\n\a";
			SetConsoleTextAttribute(h, 0x7);
		}
	}
	while (true) 
	{
		cout << "Product Name =====> ";
		cin.ignore();
		getline(cin, list2[cur_product_num].productname);
		string s = list2[cur_product_num].productname;
		if (s.size() != 0)
		{
			break;
		}
		else
		{
			SetConsoleTextAttribute(h, 0x4);
			cout << "!...INVALID PLEASE TRY AGAIN...!\n Product Name Must Not Be Empty\n\a";
			SetConsoleTextAttribute(h, 0x7);
		}
	}
	while (true)
	{
		cout << "Price ======> ";
		cin >> list2[cur_product_num].price;
		int price = list2[cur_product_num].price;
		if (price > 0)
		{
			break;
		}
		else 
		{
			SetConsoleTextAttribute(h, 0x4);
			cout << "!...INVALID PLEASE TRY AGAIN...!\n Insert A Positive Number\n\a";
			SetConsoleTextAttribute(h, 0x7);
		}
	}
	while (true){
		cout << "Number Of Products in Stock =====> ";
		cin >> list2[cur_product_num].in_stock;
		int stock = list2[cur_product_num].in_stock;
		if (stock > 0)
		{
			break;
		}
		else
		{
			SetConsoleTextAttribute(h, 0x4);
			cout << "!...INVALID PLEASE TRY AGAIN...!\n Insert A Positive Number\n\a";
			SetConsoleTextAttribute(h, 0x7);
		}
	}
	list2[cur_product_num].PersonalCode = Wareid;//Saving The WareHouseMan PersonalCode Who is Registering A Product.
	cur_product_num++;
	writingproducts(list2, cur_product_num);
}



void WareHouseHandler(WareHouses list[MAX], Products list2[MAX], int& cur_product_num, int& Wareid, int selectwarehhouse)//Handler of WareHouseMans Menu
{
	switch (selectwarehhouse)
	{
	case 1: ADD_Product(list, list2, cur_product_num, Wareid);
		break;
	case 2:DeleteProduct();
		break;
	case 3:Update();
		break;
	case 4:
		sort(list2, cur_product_num);
		View_Products_Information(list, list2, cur_product_num);
		break;
	default:
		cout << "!Wrong Command!\a\n";
		system("pause");
		break;
	}
}

void WareHouseControl(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num)//Function of WareHouseMans Entery Control
{
	system("cls");
	int username = 0, password = 0;
	cout << "Please Enter Your Username: ";
	cin >> username;
	cout << "Please Insert Your Password: ";
	cin >> password;
	system("cls");
	SetConsoleTextAttribute(h, 0x9);
	cout << "Searching ";
	for (int i = 0; i < 3; i++)
	{
		cout << ". ";
		Sleep(500);
	}
	cout << endl;
	SetConsoleTextAttribute(h, 0x7);
	bool found = false;
	for (int i = 0; i < cur_warehouse_num; i++)//Searching Among The information Read From The File For the Correct User & Pass, if Was Correct WareHouseMans Menu Will Open.
	{
		if (list[i].PersonalCode == username && list[i].WareHousePass == password)
		{
			found = true;
			int Wareid = username;//Saveing WareHousesMan's ID & Send it to AddProduct Function.
			system("cls");
			SetConsoleTextAttribute(h, 0xA);
			cout << "Information Confirmed...\n";
			Sleep(1000);
			SetConsoleTextAttribute(h, 0x7);
			int selectwarehouse = menu_of_wareHouses(Wareid);
			while (selectwarehouse != 5)
			{
				WareHouseHandler(list, list2, cur_product_num, Wareid, selectwarehouse);
				selectwarehouse = menu_of_wareHouses(Wareid);
			}
			break;
		}
	}
	if (!found)
	{
		SetConsoleTextAttribute(h, 0x4);
		system("cls");
		cerr << "No WareHouseMan Found By Entered Information...!\n\a";
		Sleep(1200);
		SetConsoleTextAttribute(h, 0x7);
		system("cls");
		cout << "Return to the Main Menu...";
		Sleep(1000);
	}
	return;
}


void ManagerHandler(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num, int selectmanage)//Handler of MANAGER's Menu
{
	switch (selectmanage)
	{
	case 1:
		ADD_WAREHOUSE(list, cur_warehouse_num);
		break;
	case 2:
		sort(list2, cur_product_num);
		View_Products_Information(list, list2, cur_product_num);
		break;
	case 3:
		sort(list2, cur_product_num);
		View_Products_Information_LessThan5(list2, cur_product_num);
		break;
	case 4:view_most_registerant_WareHouseMan(list, list2, cur_warehouse_num, cur_product_num);
		break;
	default:
		cout << "!Wrong Command!\a\n";
		system("pause");
		break;
	}
}


void AdminControl(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num)//FUNCTION OF MANAGER'S ENTRY CONTROL
{
	system("cls");
	string ManagerFile = "Managers.txt";
	ifstream fin(ManagerFile);
	string UserName;
	int Password = 0;
	if (fin)
	{
		cout << "Please Enter Your Username: ";
		cin.ignore();
		getline(cin, UserName);
		cout << "Please Insert Your Password: ";
		cin >> Password;
		string user;
		int pass = 0;
		system("cls");
		SetConsoleTextAttribute(h, 0x9);
		cout << "Searching ";
		for (int i = 0; i < 3; i++)
		{
			cout << ". ";
			Sleep(500);
		}
		cout << endl;
		SetConsoleTextAttribute(h, 0x7);
		bool found = false;
		while (fin >> user)//Searching in The File for The Correct Password if The Password Was Correct Manager Menu will Open.
		{
			fin >> pass;
			if (pass == Password && user == UserName)
			{
				found = true;
				fin.close();
				system("cls");
				SetConsoleTextAttribute(h, 0xA);
				cout << "Information Confirmed...\n";
				Sleep(1000);
				SetConsoleTextAttribute(h, 0x7);
				int selectmanage = MenuOfManager();
				while (selectmanage != 5)
				{
					ManagerHandler(list, list2, cur_warehouse_num, cur_product_num, selectmanage);
					selectmanage = MenuOfManager();
				}
				break;
			}
		}
		if (!found)
		{
			SetConsoleTextAttribute(h, 0x4);
			system("cls");
			cerr << "No Manger Found By This Information...\a\n";
			Sleep(1200);
			SetConsoleTextAttribute(h, 0x7);
			system("cls");
			cout << "Return to the Main Menu...";
			Sleep(1000);
		}
	}
	fin.close();
	return;
}

void About()
{
	system("cls");
	char credit[]= "ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n\n\t\t\t Sayed Alireza Hossaini      \n\t\t     Sadjad University of Technology\n\t\t\t      December 2020\n\n\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
	cout << "Developed By:\n\t\t";
	for (size_t i = 0; i < strlen(credit); i++)
	{
		cout << credit[i];
		Sleep(25);
	}
	system("pause");
	return;
}


void Random_Sentences()
{
	system("cls");
	srand((unsigned int) time(0));
	int x = 1 + rand() % 4;
	switch (x)
	{
	case 1:
		cout << "\n\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		SetConsoleTextAttribute(h, 0xB);
		cout << "\n\t\t    Stay Home Save Lives...\n" << endl;
		SetConsoleTextAttribute(h, 0x7);
		cout << "\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		break;
	case 2:
		cout << "\n\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		SetConsoleTextAttribute(h, 0x9);
		cout << "\n\t\t  Spend More Times Doing The Things You Love...\n" << endl;
		SetConsoleTextAttribute(h, 0x7);
		cout << "\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		break;
	case 3:
		cout << "\n\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		SetConsoleTextAttribute(h, 0xF);
		cout << "\n\t\t\t Clear Your Mind...\n" << endl;
		SetConsoleTextAttribute(h, 0x7);
		cout << "\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		break;
	case 4:
		cout << "\n\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		SetConsoleTextAttribute(h, 0xA);
		cout << "\n\t\t    Stay In The Moment...\n" << endl;
		SetConsoleTextAttribute(h, 0x7);
		cout << "\t\tßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß\n";
		break;
	default:
		break;
	}
}


void mainhandler(WareHouses list[MAX], Products list2[MAX], int Selector, int& cur_warehouse_num, int& cur_product_num)//Handler Of Main Menu
{
	switch (Selector)
	{
	case 1:AdminControl(list, list2, cur_warehouse_num, cur_product_num);
		break;
	case 2:WareHouseControl(list, list2, cur_warehouse_num, cur_product_num);
		break;
	case 3:About();
		break;
	default:
		cout << "!Wrong Command!\a\n";
		system("pause");
		break;
	}
}