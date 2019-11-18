#include"cater.h"

/*******************已实现****************/


List_Food *initList_Food (){
	
	List_Food *list = (List_Food *)malloc(sizeof(List_Food));
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;

	return list;
}//链表初始化

NodeFood *Find_Food_number(List_Food *list,int number){
	NodeFood *tmp = list->head;
	while(tmp != NULL && tmp->data->number != number){
		tmp = tmp->next;
	}
	return tmp;
}//通过number查找节点并返回

NodeFood *Find_Food_name(List_Food *list,char name[]){
	NodeFood *tmp = list->head;
	while(tmp != NULL && strcmp(tmp->data->name,name)){
		tmp = tmp->next;
	}
	return tmp;
}//通过name查找节点并返回

NodeFood *PromptFind_Food_number(List_Food *list){
	int number;
	NodeFood *food;
	printf("\n请输入您要查找的菜号\n");
	scanf("%d",&number);
	food = Find_Food_number(list,number);
	
	return food;
}//提醒用户输入要查找的菜号

void delNode_Food(List_Food *list){
	NodeFood *node = PromptFind_Food_number(list);
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
}//删除链表中的节点

void PromptFoodInput_Type(Food *food){
	int flat;
	printf("请选择类型\n");
	printf("1主食\t2汤\t3肉\t4蔬菜\t5水果\t6饮料\n");
	scanf("%d",&flat);
	switch(flat){
			case 1: strcpy(food->type,"主食");
					break;
			case 2:	strcpy(food->type,"汤");
					break;
			case 3:	strcpy(food->type,"肉");
					break;
			case 4:	strcpy(food->type,"蔬菜");
					break;
			case 5:	strcpy(food->type,"水果");
					break;
			case 6:	strcpy(food->type,"饮料");
					break;
			default:printf("未找到命令 ！\n");
	}
	return;
}//作为PromptFoodInput_Data的内部函数提醒用户选择菜类型


int Judge_FoodNumber(List_Food *list){
	int number;
	printf("请输入菜号\n");
	scanf("%d",&number);
	if(Find_Food_number(list,number) == NULL){
		return number;
	}else{
		printf("数据已存在请重新输入 ！\n");
		return 0;
	}
	
}//判断菜号是否重复

int Judge_FoodName(List_Food *list,char name[]){

	if(Find_Food_name(list,name) == NULL){
		return 0;
	}else{
		printf("数据已存在请重新输入 ！\n");
		return 1;
	}
	
}//判断菜名称是否重复

Food *PromptFoodInput_Data(List_Food *list){
	Food *food = (Food *)malloc(sizeof(Food));
	int number;
	char name[20];
	while(!( number = Judge_FoodNumber(list)) );	//菜号的输入
	food->number = number;
	
	printf("请输入菜名\n");							//菜名的输入
	scanf("%s",name);
	while(Judge_FoodName(list,name)){
				printf("请输入菜名\n");
				scanf("%s",name);
	}
	strcpy(food->name,name);

	printf("请输入价格\n");							//价格的输入
	scanf("%f",&(food->price));

	PromptFoodInput_Type(food);						//类型的选择

	return food;

}//提醒用户输入菜信息

void addTail_Food(List_Food *list){
	
	NodeFood *node = (NodeFood *)malloc(sizeof(NodeFood));
	node->data = PromptFoodInput_Data(list);
	node->next = NULL;

	if(list->head == NULL){
		list->head = node;
	}else{
		list->tail->next = node;
	}
	list->tail = node;

	return;
}//头插法构建链表


void displayList_Food(List_Food *list){
	NodeFood *tmp =list->head;
	while( tmp != NULL ){
		if(tmp->data->price == 0) break;
		printf("%-5d",tmp->data->number);
		printf("%-15s",tmp->data->name);
		printf("%.2f￥\t",tmp->data->price );
		printf("%s\n",tmp->data->type );

		tmp = tmp->next;
	}
	return;
}//输出菜信息


void FoodToFile(List_Food *list){
	
	NodeFood *tmp = list->head;
	FILE *fp;
	fp = fopen("fooddata.txt","a");
	if (fp != NULL)
	{
		while(tmp != NULL){
			fprintf(fp, "%-12d", tmp->data->number);
			fprintf(fp, "%-12s", tmp->data->name);
			fprintf(fp, "%-12.2f", tmp->data->price);
			fprintf(fp, "%s\n", tmp->data->type);
			tmp = tmp->next;
		}
		fclose(fp);
	}else{
		printf("文件保存失败 ！\n");
	}
}//向fooddata文本文件中保存菜信息

void FoodFromFile(List_Food *list){
	FILE *fp;
	fp = fopen("fooddata.txt", "r");
	if (fp != NULL)
	{
		while(!feof(fp)){
			Food *food = (Food *)malloc(sizeof(Food));
			fscanf(fp,"%d",&(food->number));
			fscanf(fp,"%s",food->name);
			fscanf(fp,"%f",&(food->price));
			fscanf(fp,"%s",food->type);

			addTail_FoodFile(list,food);
		}

		fclose(fp);

	}else{
		printf("文件打开失败 ！\n");
	}
	return;
}//从fooddata文件中获取菜信息

void addTail_FoodFile(List_Food *list,Food *data){
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
}//作为FoodFromFile的内部函数实现链表构建

void Free_Foodlist(List_Food *list){

	NodeFood *tmp = list->head;
	NodeFood *tmp1 = list->head->next;
	while(tmp != NULL){
		free(tmp);
		tmp = tmp1;
		tmp1 = tmp1->next;
		tmp = tmp->next;
	}
	return;
}//释放链表


Food *Min_FoodNumber(List_Food *list){
	int min;
	NodeFood *tmp = list->head;
	NodeFood *tmpmin = tmp;
	min = tmp->data->number;
	while(tmp != NULL){
		if (min > tmp->next->data->number){
			tmp = tmp->next;
			min = tmp->data->number;
			tmpmin = tmp;
		}else{
			tmp = tmp->next;
		}
	}
	Food *data = (Food *)malloc(sizeof(Food));
	data = tmpmin->data;
	return data;
}//找出链表中最小number

List_Food *Sort_FoodNumber(List_Food *list){
	NodeFood *tmp = list->head;
	//NodeFood *tmp1 = list->head;
	List_Food *Slist;
	Slist = initList_Food();
	while(tmp != NULL){

		Food *data = (Food *)malloc(sizeof(Food));
		data = Min_FoodNumber(list);
		addTail_FoodFile(Slist,data);
		tmp = tmp->next;
		//free(tmp1);
		//tmp1 = tmp;

	}
	return Slist;
}
/*
List_Food *SortList(List_Food *list){
		List_Food *r = list;
		List_Food *SL = NULL;
		while (r != NULL){
			List_Food *t = r->next;
			List_Food * cp = SL;
			List_Food * ap = NULL;
			while (cp != NULL){

				if(r->num < cp->num){
					break;
				}else{
					ap = cp;
					cp=cp->next;
				}
			}
			if (ap == NULL){

				r->next = SL;
				SL = r;

			}else{
				r->next = cp;
				ap->next = r;
			}
			r = t;
		}
		return SL;
}


*/


/******************************已实现*******************************/




/**************************二叉树************************/

BiTNode *initate_Food(){
	BiTNode *bt;
	bt = (BiTNode *)malloc(sizeof(BiTNode));

	bt->lchild = NULL;
	bt->rchild = NULL;
	return bt;
}

BiTNode *Create_Food(BiTNode *bt,int n,int length){
	BiTNode *tmp = (BiTNode *)malloc(sizeof(BiTNode));
	Food *food = (Food *)malloc(sizeof(Food));
	tmp->data = food;
	if (length > 1)
	{	
		tmp->data->number = length;
		tmp->lchild = NULL;
		tmp->rchild = NULL;
		if(n == 0) bt = tmp;
		if(n == 1) bt->lchild = tmp;
		if(n == 2) bt->rchild = tmp;
		Create_Food(tmp,1,--length);
		Create_Food(tmp,2,--length);
	}
	return bt;
}

void InOrder(BiTNode *bt){
	if(bt == NULL) return;

	InOrder(bt->lchild);
	printf("%d\n",bt->data->number );
	InOrder(bt->rchild);
}

/**************************二叉树************************/
