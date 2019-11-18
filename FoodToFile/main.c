#include"cater.h"

int main(int argc, char **argv)
{
	List_Food *list;
	List_Food *list1;
	List_Food *list2;

	//BiTNode *bt;
	char flat = 'n';
	list = initList_Food();
	list1 = initList_Food();
	list2 = initList_Food();
	
	while(flat != 'y'){

		addTail_Food(list);
		printf("是否退出y or n\n");
		getchar();
		scanf("%c",&flat);
	}
	
	displayList_Food(list);
	//FoodToFile(list);
	//delNode_Food(list);
	//displayList_Food(list);
	//FoodFromFile(list1);
	//displayList_Food(list1);
	//Free_Foodlist(list1);

	//list2 = Sort_FoodNumber(list);
	//displayList_Food(list2);

	Food *data = (Food *)malloc(sizeof(Food));
	data = Min_FoodNumber(list);
	printf("%d\n",data->number );

	//bt = initate_Food();
	//Create_Food(bt,0,8);
	//InOrder(bt);


	return 0;
}