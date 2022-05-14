#include"Header.h"

int main()
{
	WareHouses list[MAX];
	Products list2[MAX];
	int cur_warehouse_num = 0;//counter for current warehouses and number of warehousesman
	int cur_product_num = 0;//counter for current product and number of registered products
	Read_WareHouses_Information(list, cur_warehouse_num);
	Read_Products_Information(list2, cur_product_num);
	int Selector = mainmenu();
	while (Selector != 4)
	{
		mainhandler(list, list2, Selector, cur_warehouse_num, cur_product_num);
		Selector = mainmenu();
	}
	Random_Sentences();
	system("pause");
	return 0;
}