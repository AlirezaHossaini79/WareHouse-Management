#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<Windows.h>
#include<cstdlib>
#include<ctime>

#define MAX 100

using namespace std;

struct WareHouses
{
	int PersonalCode = 0;//Personal Code
	int age = 0;//age
	unsigned long long int income = 0;//income
	unsigned int WareHousePass = 0; //Password of WareHouses
	int registerant = 0;
};

struct Products
{
	int barcode = 0;//number of product
	string productname;//product's name
	int price = 0;//price of the prodct
	int in_stock = 0;//number of products in store
	int PersonalCode = 0;// Pesonal Code Of the WareHouseMan that Registered the product.
};

//            <Summary>

int mainmenu();//Main menu of this programm.
int MenuOfManager();//Menu Of the Managers.
int menu_of_wareHouses(int& Wareid);//Menu OF the WareHouseMans
void writingwarehouses(WareHouses list[MAX], int& cur_warehouses_num);//Write WareHouseMan's information to WareHousMans.txt
void writingproducts(Products list2[MAX], int& cur_product_num);//Write Product's information to Products.txt
int reverse(int passnumber);
void Read_WareHouses_Information(WareHouses list[MAX], int& cur_warehouse_num);//Reading Information From WareHouseMans.txt
void ADD_WAREHOUSE(WareHouses list[MAX], int& cur_warehouses_num);//Adding New WareHouseMan to system by manager.
void Read_Products_Information(Products list2[MAX], int& cur_product_num);//Reading Information From Products.txt
bool Contains(int produceid, int inp);
void DeleteProduct();//Deletes Products information in the file.
void Update();//Updates Products information in the file.
void sort(Products list2[MAX], int& cur_product_num);//This function sorts products information based on inventory in descending order. Bubble Sort.
void view_most_registerant_WareHouseMan(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num);//Show Sample WareHouseman informations
void View_Products_Information(WareHouses list[MAX], Products list2[MAX], int cur_product_num);//View Registered Products Information.
void View_Products_Information_LessThan5(Products list2[MAX], int cur_product_num);//P
void ADD_Product(WareHouses list[MAX], Products list2[MAX], int& cur_product_num, int& Wareid);//Add new product By WareHousesMans.
void WareHouseHandler(WareHouses list[MAX], Products list2[MAX], int& cur_product_num, int& Wareid, int selectwarehhouse);//Handler of WareHouseMans Menu
void WareHouseControl(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num);//Function of WareHouseMans Entery Control.
void ManagerHandler(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num, int selectmanage);//Handler of Manager's Menu.
void AdminControl(WareHouses list[MAX], Products list2[MAX], int& cur_warehouse_num, int& cur_product_num);//FUNCTION OF ADMIN'S ENTERY CONTROL.
void About();//About Programmers.
void Random_Sentences();//Shows Random Sentences In end of programm.
void mainhandler(WareHouses list[MAX], Products list2[MAX], int Selector, int& cur_warehouse_num, int& cur_product_num);//Main Menu Handler.