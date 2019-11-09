#include"Cater.c"

int main(int argc, char **argv)
{
	List_Food *list;
	initList_Food(list);
	addTail_Food(list, PromptFoodInput_Data());
	displayList_Food(list);
	return 0;
}
