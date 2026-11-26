#include<iostream>
#include<string.h>
#include<time.h>
#include<stdio.h>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
#include<cfloat>
#include<conio.h>
#include"trade.h"
#pragma warning(disable : 4996)
using namespace std;
int main() {
	cout << endl<<"        欢迎来到冬奥会纪念品交易平台！" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "1.管理员登录 2.注册用户 3.用户登录 4.退出程序" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl << "请输入你的选择：";
	char c[10]={"\0"};
	cin>>c;
	if(strlen(c)>1){
		cout <<endl<< "输入错误！请重新输入！" << endl; main();
	}
	char s[10] = { "\0" };
	char k[10] = { "\0" };
	User* p = NULL;
	User* head = ugoujian(), * p1 = head;
	int nm = 1;
	Good* p2 = NULL;
	switch (c[0]) {
	case('1'):cout << endl << "请输入管理员姓名：";
		cin >> s;
		cout << endl << "请输入密码：";
		cin >> k;
		if (strcmp(s, "admin") == 0 && !strcmp(k,"123456")) {
			cout << endl<<"-----登录成功-----" << endl; admin();
		}
		else cout << endl << "-----登录失败，返回主菜单-----" << endl; main(); break;
	case('2'):
		p = (User*)malloc(sizeof(User));
		p->next = NULL; p->u_money = 0; p->u_state = 1;
		cout << endl<<"请输入你想要注册的用户名：";
		cin >> p->u_name;
		cout << endl << "请输入你设置的密码：";
		cin >> p->u_key;
		cout << endl << "请输入你的地址：";
		cin >> p->u_address;
		cout << endl<<"请输入你的号码：";
		cin >> p->u_phone;
		while (p1) {
			p1 = p1->next;
			++nm;
		}
		p->u_id[0] = 'U';
		p->u_id[1] = nm / 100 + '0';
		p->u_id[2] = nm / 10 % 10 + '0';
		p->u_id[3] = nm % 10 + '0';
		sql(1, 1, p, p2);
		cout << endl << "恭喜注册成功！请重新登录！" << endl;
		main(); break;
	case('3'):cout << endl << "请输入用户名：";
		cin >> s;
		cout << endl << "请输入密码：";
		cin >> k;
		if (p = checkuser(head, s, k)) {
			cout <<endl<< "-----登录成功-----" << endl; user(p); break;
		}
		else {
			cout << endl<<"-----登录失败，返回主菜单-----" << endl; main(); break;
		}
	case('4'):cout << "你确认要退出系统吗？（y/n):";
		cin >> c;
		if(strlen(c)>1){
			cout<<endl<<"输入错误！"<<endl;
			main();
		}
		if (c[0] == 'y') exit(0);
		else{
			cout<<endl<<"取消退出系统成功！"<<endl;
			main();
		}
	    break;
	default:cout <<endl<< "输入错误！请重新输入！" << endl; main(); break;
	}
}
