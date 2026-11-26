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

void seller(User* p) {
	cout << endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "1.发布商品 2.查看商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl<<"请输入操作：";
	char c[10]={"\0"};
	cin>>c;
	Good* p1 = NULL;
	Good* head = ggoujian();
	char s[100] = { "\0" };
	double pr;
	switch (c[0]) {
	case('1'): if(!p->u_state){
		cout<<endl<<"你处于封禁状态！"<<endl;
		seller(p);
	}
	sql(1, 2, p, p1);seller(p); break;
	case('2'): sql(3, 1, p, p1); seller(p);break;
	case('3'):if(!p->u_state){
		cout<<endl<<"你处于封禁状态！"<<endl;
		seller(p);
	}
	cout <<endl<< "请输入你想修改的商品id：";
		cin >> s;
		p1 = idsousuo(head, s);
		if (!p1) {
			cout << endl<<"你输入的商品不存在！" << endl;
			seller(p); break;
		}
		else {
			cout << endl<<"请输入被修改的商品属性：1.价格2.描述：";
			cin >> c;
			if(strlen(c)>1){
				cout <<endl<< "修改失败！" << endl;
				seller(p);
			}
			if (c[0] == '1') {
				cout << endl<<"请输入修改的价格：";
				cin >> pr;
				cout << endl<<"确认修改？（y/n)：";
				cin >> c;
				if(strlen(c)>1){
					cout<<endl<<"输入错误！"<<endl;
					seller(p);
				}
				if (c[0] == 'y') {
					p1->g_price = pr;
					cout <<endl<< "修改成功！" << endl;
				}
				else {
					cout <<endl<< "取消修改操作成功！" << endl;
					seller(p);
				}
			}
			else if (c[0] == '2') {
				cout << endl<<"请输入修改的描述：";
				cin >> s;
				cout <<endl<< "确认修改？（y/n)：";
				cin >> c;
				if(strlen(c)>1){
					cout<<endl<<"输入错误！"<<endl;
					seller(p);
				}
				if (c[0] == 'y') {
					strcpy(p1->g_des, s);
					cout << endl<<"修改成功！" << endl;
				}
				else {
					cout <<endl<< "取消修改操作成功！" << endl;
					seller(p);
				}
			}
			else {
				cout << endl<<"输入错误！" << endl; seller(p);
			}
		}sql(2, 2, p, p1); seller(p);break;
	case('4'):if(!p->u_state){
		cout<<endl<<"你处于封禁状态！"<<endl;
		seller(p);
	}
	cout << endl<<"请输入你想下架的商品id：";
		cin >> s;
		p1 = idsousuo(head, s);
		if (!p1) {
			cout <<endl<< "输入错误！" << endl;
			seller(p); break;
		}
		else {
			cout << endl<<"请确认你要下架该商品吗？请选择（y/n):";
			cin >> c;
			if(strlen(c)>1){
				cout<<endl<<"输入错误！"<<endl;
				seller(p);
			}
			if (c[0] == 'y') {
				p1->g_state = 0; sql(2, 2, p, p1); cout << "下架成功！" << endl;
			}
			else cout << endl<<"取消下架操作成功！" << endl;
		}
		seller(p); break;
	case('5'):sql(3, 3, p, p1); seller(p);break;
	case('6'):user(p); break;
	default:cout << endl<<"输入错误!请重新输入！" << endl; seller(p); break;
	}
}
