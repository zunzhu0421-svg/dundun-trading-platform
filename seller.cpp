#include<iostream>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cfloat>
#include"trade.h"
#pragma warning(disable : 4996)
using namespace std;

void buyer(User* p) {
	cout << endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl<<"请输入选择的操作：" ;
	char c[10]={"\0"};
	cin >> c;
	if(strlen(c)>1){
		cout << endl<<"输入错误！请重新输入！" << endl; buyer(p); 
	}
	Good* head = ggoujian();
	Good* p1 = NULL;
	char s[100] = { "\0" };
	switch (c[0]) {
	case('1'): sql(3, 0, p, p1);buyer(p); break;
	case('2'):if(!p->u_state){
		cout<<endl<<"你处于封禁状态！"<<endl;
		buyer(p);
	}
		sql(1, 3, p, p1);
		buyer(p); break;
	case('3'):cout << endl<<"请输入你想搜索的商品名称：";
		cin >> s;
		p1 = sousuo(head, s);
		if (!p1) {
			cout << endl<<"你输入的商品名称不存在！" << endl; buyer(p); break;
		}
		else {
			cout << endl<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "商品id 商品名称     商品单价   上架时间      卖家id" << endl;
			cout << " "<<p1->g_id << setw(10) << p1->g_name << " " << setw(10) << p1->g_price << setw(15)<< p1->g_time <<setw(10)<< p1->seller_id << endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		buyer(p); break;
	case('4'):(3, 2, p, p1);buyer(p); break;
	case('5'):cout << endl<<"请输入你想要查看的商品id：";
		cin >> s;
		p1 = idsousuo(head, s);
		if (!p1) {
			cout << endl<<"你输入的商品id不存在！" << endl; buyer(p); break;
		}
		else {
			cout << endl<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "商品id   商品名称    商品单价   上架时间      卖家id    商品描述"  << endl;
			cout << " "<<p1->g_id << setw(10) << p1->g_name << " " << setw(10) << p1->g_price << setw(15)<< p1->g_time <<setw(10)<< p1->seller_id <<"   "<<p1->g_des<< endl;
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		buyer(p); break;
	case('6'):user(p); break;
	default:cout << endl<<"输入错误！请重新输入！" << endl; buyer(p); break;
	}
}
