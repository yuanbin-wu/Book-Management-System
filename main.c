#include"cater.h"

int main(int argc, char **argv)
{
	List_Food *list;
	Food *data;
	initList_Food(list);
	data = PromptFoodInput_Data();
	addTail_Food(list, data);
	displayList_Food(list);
	return 0;
}