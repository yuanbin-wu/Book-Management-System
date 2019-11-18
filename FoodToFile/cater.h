#ifndef cater_h
#define cater_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct _Food
{
	int number; //菜号
	char name[20]; //菜名
	float price; //价格
	char type[20];//类别

}Food;

typedef struct _nodefood
{
	Food  *data;
	struct _nodefood *next;

}NodeFood;

typedef struct _linkedListFood
{
	NodeFood *head;
	NodeFood *tail;
	NodeFood *current;

}List_Food;

typedef struct _bitnode
{
	Food *data;
	struct _bitnode *lchild,*rchild;
}BiTNode;


List_Food *initList_Food ();									//链表初始化

void PromptFoodInput_Type();									//作为PromptFoodInput_Data的内部函数提醒用户选择菜类型
int Judge_FoodNumber(List_Food *list);							//判断菜号是否重复
int Judge_FoodName(List_Food *list,char name[]);				//判断菜名称是否重复
Food *PromptFoodInput_Data(List_Food *list);					//提醒用户输入菜信息

void addTail_Food(List_Food *list);								//头插法构建链表
void displayList_Food(List_Food *list);

NodeFood *PromptFind_Food_number(List_Food *list);				//提醒用户输入要查找的菜号
NodeFood *Find_Food_number(List_Food *list,int number);			//通过number查找节点并返回
NodeFood *Find_Food_name(List_Food *list,char name[]);			//通过name查找节点并返回

void delNode_Food(List_Food *list);								//删除链表中的节点
void FoodToFile(List_Food *list);								//向fooddata文件中保存菜信息
void FoodFromFile(List_Food *list);								//从fooddata文件中获取菜信息
void addTail_FoodFile(List_Food *list,Food *data);				//作为FoodFromFile的内部函数实现链表构建


void Free_Foodlist(List_Food *list);							//释放链表
Food *Min_FoodNumber(List_Food *list);						//找出链表中最小number
List_Food *Sort_FoodNumber(List_Food *list);

BiTNode *initate_Food();										//二叉树初始化
BiTNode *Create_Food(BiTNode *bt,int n,int length);				//创建节点个数为length二叉树
void InOrder(BiTNode *bt);

#endif
