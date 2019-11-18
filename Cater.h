#ifndef cater_h
#define cater_h
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED_COLOR        "\e[31m\e[1m%s\e[0m"
#define GREEN_COLOR      "\e[32m\e[1m%s\e[0m"
#define YELLOW_COLOR     "\e[33m\e[1m%s\e[0m"


/********************************类结构体模块********************************/

//客户结构体声明
typedef struct _Guest
{
	int number; //桌号
	char note[200];//备注
	void *selected; //已选菜
	double consume; //消费
	
}Guest;
//出生日期声明
typedef struct _age{
	int year;
	int month;
	int day;
}Age;
//员工结构体声明
typedef struct _Staff
{
	int number; //工号
	char name[10]; //姓名
	char sex[10]; //性别
	Age birthday; //出生日期
	int telnumber[20]; //联系方式
	double salary; //工资
}Staff;
//店长结构体声明
typedef struct _Boos
{
	int number; //姓名
	char sex[10]; //性别
}Boos;
//菜类别声明
typedef struct _Type
{
	bool rice; //主食
	bool soup; //汤
	bool meat; //肉
	bool green; //蔬菜
	bool fruit; //水果
	bool drink; //饮料

}Type;
typedef struct _Formula
{
	
}Formula;
//菜结构体声明
typedef struct _Food
{
	int number; //菜号
	Type type; //类别
	char name[20]; //菜名
	float price; //价格
	Formula formula; //配方
}Food;



/*****************************节点结构体模块************************************/

typedef struct _nodeguest
{
	Guest  *data;
	struct _nodeguest *next;
}NodeGuest;

typedef struct _nodestaff
{
	Staff  *data;
	struct _nodestaff *next;
}NodeStaff;

typedef struct _nodeboos
{
	Boos  *data;
	struct _nodeboos *next;
}NodeBoos;

typedef struct _nodefood
{
	Food  *data;
	struct _nodefood *next;
}NodeFood;



typedef struct _linkedListGuest
{
	NodeGuest *head;
	NodeGuest *tail;
	NodeGuest *current;
}List_Guest;

typedef struct _linkedListStaff
{
	NodeStaff *head;
	NodeStaff *tail;
	NodeStaff *current;
}List_Staff;

typedef struct _linkedListBoos
{
	NodeBoos *head;
	NodeBoos *tail;
	NodeBoos *current;
}List_Boos;

typedef struct _linkedListFood
{
	NodeFood *head;
	NodeFood *tail;
	NodeFood *current;
}List_Food;
/*****************************节点处理模块**************************************/

/**************客户结点处理******************/

/*void initList_Guest(List_Guest *);
{
	//DOWN
}

void addTail_Guest(List_Guest *, Guest );
{
	//DOWN
}

void delNode_Guest(List_Guest *, Guest);
{
	//DOWN
}

void displayList_Guest(List_Guest *);
{
	//TODO
}*/

/****************员工结点处理****************/

//void initList_Staff(List_Staff *);
//void addTail_Staff(List_Staff *, Staff );
//void delNode_Staff(List_Staff *, Staff);
//void displayList_Staff(List_Staff *);

/****************店长结点处理****************/

//void initList_Boos(List_Boos *);
//void addTail_Boos(List_Boos *, Boos );
//void delNode_Boos(List_Boos *, Boos);
//void displayList_Boos(List_Boos *);

/****************菜结点处理****************/

void initList_Food(List_Food *list);//END
void addTail_Food(List_Food *, Food );//END
//void delNode_Food(List_Food *, Food);
void displayList_Food(List_Food *);//ENF

/*****************************查找模块************************************/








/*****************************输入模块************************************/

Guest PromptGuestInput_Data();
Food PromptFoodInput_Data();
Food InputFood();







/*****************************输出模块************************************/









/*****************************界面函数模块*********************************/


//用户登入
//用于调用员工、店长登入
void User_Login();
//员工登入
void Staff_Login();
//店长登入
void Boss_Login();
//客户登入
void Guest_Login();

//客户函数
//点单函数
void Order();
//反馈函数
void Feedback();

//员工函数
//查看点单
void ViewOrder();
//工资查询
void ViewSalary();

//店长函数
//营业额
double Turnover();
//员工查看
void ViewStaff();
//采购
void Buy();

/*******************************主菜单*********************************/

int mainMenu();










#endif
