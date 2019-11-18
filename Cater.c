#include"cater.h"

/*********************************************客户模块**************************************/

/********************客户结点处理*********************/

/*void initList_Guest(List_Guest *list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;

	return;
}
Guest PromptGuestInput_Data(){
	Guest *guest;
	printf("请输入桌号\n");
	scanf("%d",&(guest->number));
	printf("有什么要备注的吗？\n");
	scanf("%s",guest->note);

}

void addTail_Guest(List_Guest *list, Guest data);
{
	NodeGuest *node = (NodeGuest *)malloc(sizeof(NodeGuest));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
}

void delNode_Guest(List_Guest *list, NodeGuest node);
{
	if(node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}else{
			list->head = list->head->next;
		}
	}else{
		NodeGuest *tmp = list->head;
		while(tmp != NULL && tmp->next != node){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			tmp->next = node->next;
		}
	}

	free(node);

	return;
}*/
/*************************客户输出************************/
/*void displayList_Guest(List_Guest *);
{
	NodeGuest *tmp =list->head;
	while( tmp != NULL )
	{

	}
}*/

/**********************************************菜模块**********************************************/

/***************************菜结点处理*************************/
void initList_Food (List_Food *list){
	
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;

	return;
}//END
Food *PromptFoodInput_Data(){
	Food *food = (Food *)malloc(sizeof(Food));
	printf("请输入菜号\n");
	scanf("%d",&(food->number));
	printf("请输入菜名\n");
	scanf("%s",food->name);
	printf("请输入价格\n");
	scanf("%f",&(food->price));

	return food;

}//END
void addTail_Food(List_Food *list, Food *data){

	NodeFood *node = (NodeFood *)malloc(sizeof(NodeFood));
	node->data = data;
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
}//END


void displayList_Food(List_Food *list){
	NodeFood *tmp =list->head;
	while( tmp != NULL )
	{
		printf("%d\t",tmp->data->number);
		printf("%s\t",tmp->data->name);
		printf("%.2f￥\n",tmp->data->price );
		tmp = tmp->next;
	}
	return;
}//END
/*void delNode_Food(List_Food *list, NodeFood node)
{
	if(node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}else{
			list->head = list->head->next;
		}
	}else{
		NodeFood *tmp = list->head;
		while(tmp != NULL && tmp->next != node){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			tmp->next = node->next;
		}
	}

	free(node);

	return;
}*/


/************************菜查找*************************/


/************************菜输入*************************/


/************************菜输出*************************/
