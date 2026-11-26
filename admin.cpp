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

void admin() {
	cout << endl<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl << "请输入选择的操作：";
	char c[10]={"\0"};
	cin >> c;
	if(strlen(c)>1){
		cout << "输入错误！请重新输入！" << endl; admin();
	}
	User* p = NULL;
	Good* p1 = NULL;
	char s[20] = { "0" };
	Good* head = ggoujian();
	User* head1 = ugoujian();
	switch (c[0]) {
	case('1'):sql(4, 2, p, p1); admin(); break;
	case('2'):cout << endl << "请输入你想搜索的商品名称：";
		cin >> s;
		p1 = sousuo(head, s);
		if (!p1) {
			cout << endl<<"你输入的商品不存在！" << endl;
			admin(); break;
		}
		cout << endl<<"+++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout<<"商品id    商品名称 商品价格 出售用户 商品状态"<<endl;
		cout << p1->g_id << "   " << setw(10)<<p1->g_name << "  "<<setw(5) << p1->g_price << setw(10) << p1->seller_id << "     ";
		if(p1->g_state){
			cout<<"在售"<<endl;
		}
		else{
			cout<<"下架"<<endl;
		}
		cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
		admin(); break;
	case('3'):cout << endl << "请输入你想下架的商品id：";
		cin >> s;
		p1 = idsousuo(head, s);
		if (!p1||p1->g_state==0) {
			cout << "你输入的商品不存在！或已下架！" << endl;
			admin(); break;
		}
		cout << "请确认你要下架该商品吗？请选择（y/n):";
		cin >> c;
		if(strlen(c)>1){
			cout<<endl<<"输入错误！"<<endl;
			admin();
		}
		if (c[0] == 'y') {
			p1->g_state = 0; sql(2, 2, p, p1); cout << "下架成功！" << endl;
		}
		else cout << "取消下架操作成功！" << endl;
		admin(); break;
	case('4'): sql(4, 3, p, p1); admin(); break;
	case('5'): sql(4, 1, p, p1); admin(); break;
	case('6'):cout <<endl<< "请输入你想封禁的用户id：";
		cin >> s;
		p = idusousuo(head1, s);
		if (p != NULL && p->u_state == 1) {
			p->u_state = 0;
			sql(2, 1, p, p1);
			cout << endl << "封禁成功！" << endl;
		}
		else cout << endl<<"未查找到此用户！或此用户已经为封禁状态！" << endl;
		admin(); break;
	case('7'):system("cls"); main(); break;
	default:cout << "输入错误！请重新输入！" << endl; admin(); break;
	}
}
