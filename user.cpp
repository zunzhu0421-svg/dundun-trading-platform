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

void shengcheng(User* p, int n,char* s) {
	chong* head = cgoujian(), * p0 = head;
	Order* head1 = ogoujian(), * p1 = head1;
	char pi[10] = { "\0" };
	char pj[10] = { "\0" };
	switch (n) {
	case(1):cout<<endl<<"请输入表达式：";cin >> s;break;
	case(2):
		memset(s, 0, sizeof(s)); memset(pi, 0, sizeof(pi));
		while (p0 != NULL) {
			if (!strcmp(p0->u_id, p->u_id)) {
				sprintf(pi, "%1lf", p0->n);
				if (!s[0]) {
					strcat(s, pi);
				}
				else {
					strcat(s, "+");
					strcat(s, pi);
				}
				memset(pi, 0, sizeof(pi));
			}
			p0 = p0->next;
		}
		free(p0); free(head);
		memset(pj, 0, sizeof(pj));
		while (p1 != NULL) {
			if (!strcmp(p->u_id, p1->seller_id)) {
				sprintf(pi, "%d", p1->o_num);
				sprintf(pj, "%1lf", p1->o_price);
				if(s[0]) strcat(s,"+");
				strcat(s, pi);
				strcat(s, "*");
				strcat(s, pj);
				memset(pi, 0, sizeof(pi));
				memset(pj, 0, sizeof(pj));
			}
			if (!strcmp(p->u_id, p1->buyer_id)) {
				sprintf(pi, "%d", p1->o_num);
				sprintf(pj, "%1lf", p1->o_price);
				strcat(s, "-");
				strcat(s, pi);
				strcat(s, "*");
				strcat(s, pj);
				memset(pi, 0, sizeof(pi));
				memset(pj, 0, sizeof(pj));
			}
			p1=p1->next;
        }
		free(p0);free(head1);break;
	default:cout << endl<<"输入错误！请重新输入！" << endl; user(p);break;
	}
}

void user(User* p) {
	cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "1.卖家界面 2.买家界面 3.个人信息管理 4.留言 5.注销登录" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl<<"输入你的选择：";
	char c[10]={"\0"};
	char s[100] = { "\0" };
	cin >> c;
	if(strlen(c)>1){
		cout << endl<<"输入错误！请重新输入！" << endl; user(p);
	}
	Good* p1 = NULL;
	double n1;
	switch (c[0]) {
	case('1'):seller(p); break;
	case('2'):buyer(p); break;
	case('3'):cout <<endl<<"++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "1.查看信息 2.修改信息 3.充值 4.返回用户主界面" << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << endl<<"请输入操作：";
		cin >> c;
		if(strlen(c)>1){
			cout <<endl<< "输入错误！" << endl;
			user(p);
		}
		if (c[0] == '1') {
			cout << endl<<"请选择你的余额计算的方式：1.用户输入算式（不用输入等号）2.自动计算"<<endl;
			cin >> c;
			if (strlen(c)>1||(c[0]!='1'&&c[0]!='2')) {
				cout << "输入错误！" << endl;
				user(p);
			}
			shengcheng(p, c[0]-'0',s);
			calculate(s, c[0]-'0');
			cout<<endl<<"++++++++++++++++++++++++++"<<endl;
			cout << "你的用户名：" << p->u_name << endl;
			cout << "你的地址：" << p->u_address << endl;
			cout << "你的联系方式：" << p->u_phone << endl;
			cout << "你的钱包余额：" << s << endl;
			cout << "你的用户状态：" ;
			if(p->u_state){
				cout<<"正常"<<endl;
			}
			else{
				cout<<"封禁状态"<<endl;
			}
			cout<<"++++++++++++++++++++++++++"<<endl;
			user(p);
		}
		else if (c[0] == '2') {
			cout << endl<<"请输入你要修改的信息：1.用户名 2.联系方式 3.地址" << endl;
			cin >> c;
			if(strlen(c)>1){
				cout <<endl<< "输入错误！" << endl;
				user(p);
			}
			if (c[0] == '1') {
				cout << endl<<"请输入你想修改的用户名：";
				cin >> s;
				strcpy(p->u_name, s);
				sql(2, 1, p, p1);
				user(p);
			}
			else if (c[0] == '2') {
				cout << endl<<"请输入你想修改的联系方式：";
				cin >> s;
				strcpy(p->u_phone, s);
				sql(2, 1, p, p1);
				user(p);
			}
			else if (c[0] == '3') {
				cout << endl<<"请输入你想修改的地址：";
				cin >> s;
				strcpy(p->u_address, s);
				sql(2, 1, p, p1);
				user(p);
			}
			else {
				cout <<endl<< "输入错误！" << endl;
				user(p);
			}
			cout<<endl<<"修改成功！"<<endl;
		}
		else if (c[0] == '3') {
			cout << endl<<"请输入充值金额：";
			scanf("%1lf", &n1);
			p->u_money += n1;
			cout << endl << "充值成功！当前余额：" << p->u_money << endl;
			sql(2, 1, p, p1);
			FILE* fp = fopen("C:\\Users\\陈怡然\\Desktop\\chong.txt", "a");
			fprintf(fp, "%s,%lf\n", p->u_id, n1);
			fclose(fp);
			user(p);
		}
		else if (c[0] == '4') {
			user(p);
		}
		else {
			cout <<endl<< "输入错误！" << endl;
			user(p);
		}break;
	case('4'):chatting(p);
	case('5'):free(p); system("cls");main(); break;
	default:cout << endl<<"输入错误！请重新输入！" << endl; user(p); break;
	}
}

