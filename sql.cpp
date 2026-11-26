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

void sql(int a, int b, User* p, Good* pg) {
	char s[300] = { "\0" };
	char pi[20] = { "\0" };
	int i = 0, j = 0, n = 1;
	Order* head2 = ogoujian(), * p4 = head2;
	Good* p1 = (Good *)malloc(sizeof(Good));
	Good* head = ggoujian(), * p0 = head;
	Order* p2 = (Order*)malloc(sizeof(Order));
	User* head1 = ugoujian(), * p3 = NULL;
	time_t timep;
	time(&timep);
	struct tm* pt = localtime(&timep);
	switch (a) {
	case(1):if (b == 1) {
		strcpy(s, "INSERT INTO user VALUES(");
		for (i = 24; i < 28; ++i) {
			s[i] = p->u_id[i - 24];
		}
		s[i] = ',';
		for (i = 29; i < 29 + strlen(p->u_name); ++i) {
			s[i] = p->u_name[i - 29];
		}
		s[i] = ','; ++i;
		j = i;
		for (; i < j + strlen(p->u_key); ++i) {
			s[i] = p->u_key[i - j];
		}
		s[i] = ','; ++i;
		j = i;
		for (; i < j + strlen(p->u_phone); ++i) {
			s[i] = p->u_phone[i - j];
		}
		s[i] = ','; ++i;
		for (j = i; i < j + strlen(p->u_address); ++i) {
			s[i] = p->u_address[i - j];
		}
		s[i] = ',';
		s[++i] = '0'; s[++i] = '.'; s[++i] = '0'; s[++i] = ','; s[++i] = '1'; s[++i] = ')'; s[++i] = '\0';
	}
		   else if (b == 2) {
		strcpy(s, "INSERT INTO commodity VALUES(");
		p1->next = NULL; p1->g_state = 1; strcpy(p1->seller_id, p->u_id);
		p1->g_time[0] = (1900 + pt->tm_year) / 1000 + '0';
		p1->g_time[1] = (1900 + pt->tm_year) / 100 % 10 + '0';
		p1->g_time[2] = (1900 + pt->tm_year) % 100 / 10 + '0';
		p1->g_time[3] = (1900 + pt->tm_year) % 10 + '0';
		p1->g_time[4] = '-';
		p1->g_time[5] = (1 + pt->tm_mon) / 10 + '0';
		p1->g_time[6] = (1 + pt->tm_mon) % 10 + '0';
		p1->g_time[7] = '-';
		p1->g_time[8] = (pt->tm_mday) / 10 + '0';
		p1->g_time[9] = (pt->tm_mday) % 10 + '0';
		p1->g_time[10] = '\0';
		while (p0) {
			p0 = p0->next;
			++n;
		}
		p1->g_id[0] = 'M';
		p1->g_id[1] = n / 100 + '0';
		p1->g_id[2] = n / 10 % 10 + '0';
		p1->g_id[3] = n % 10 + '0';
		cout << endl << "请输入你想上架的商品名称：";
		cin >> p1->g_name;
		cout << endl << "请输入单价：";
		cin >> p1->g_price;
		cout << endl << "请输入数量：";
		cin >> p1->g_num;
		cout << endl << "请输入描述：";
		cin >> p1->g_des;
		for (i = 29; i < 33; ++i) {
			s[i] = p1->g_id[i - 29];
		}
		s[i] = ','; ++i;
		j = i;
		for (; i < j + strlen(p1->g_name); ++i) {
			s[i] = p1->g_name[i - j];
		}
		s[i] = ','; ++i;
		memset(pi, 0, sizeof(pi));
		sprintf(pi, "%.1lf", p1->g_price);
		for (j = i; i < j + strlen(pi); ++i) {
			s[i] = pi[i - j];
		}
		s[i] = ','; ++i;
		memset(pi, 0, sizeof(pi));
		sprintf(pi, "%d", p1->g_num);
		for (j = i; i < j + strlen(pi); ++i) {
			s[i] = pi[i - j];
		}
		s[i] = ','; ++i;
		for (j = i; i < j + strlen(p1->g_des); ++i) {
			s[i] = p1->g_des[i - j];
		}
		s[i] = ','; ++i;
		for (j = i; i < j + strlen(p1->seller_id); ++i) {
			s[i] = p1->seller_id[i - j];
		}
		s[i] = ','; ++i;
		for (j = i; i < j + strlen(p1->g_time); ++i) {
			s[i] = p1->g_time[i - j];
		}
		s[i] = ','; ++i;
		s[i++] = '1';
		s[i++] = ')'; s[i] = '\0';
		cout<<endl<<"发布成功！"<<endl;
	}
		   else if (b == 3) {
		cout << endl<<"请输入你想购买的商品id；";
		cin >>pi;
		p1 = idsousuo(head, pi);
		if(!p1||!strcmp(p1->seller_id,p->u_id)){
			cout<<endl<<"商品不存在！或请不要购买自己的商品！"<<endl;
			buyer(p);
		}
		cout << endl << "请输入数量：";
		cin >> n;
		if (p1->g_state == 0 || p1->g_num < n || p->u_money < (n * p1->g_price)) {
			cout << endl<<"商品已下架！或您的购买意愿超过负担！" << endl; buyer(p);
		}
		else {
			p2->next = NULL; strcpy(p2->buyer_id, p->u_id); strcpy(p2->g_id, s); p2->o_num = n; p2->o_price = p1->g_price; strcpy(p2->seller_id, p1->seller_id);
			i = 1;
			while (p4) {
				p4 = p4->next;
				++i;
			}
			p2->o_id[0] = 'T';
			p2->o_id[1] = i / 100 + '0';
			p2->o_id[2] = i / 10 % 10 + '0';
			p2->o_id[3] = i % 10 + '0';
			p2->o_time[0] = (1900 + pt->tm_year) / 1000 + '0';
			p2->o_time[1] = (1900 + pt->tm_year) / 100 % 10 + '0';
			p2->o_time[2] = (1900 + pt->tm_year) % 100 / 10 + '0';
			p2->o_time[3] = (1900 + pt->tm_year) % 10 + '0';
			p2->o_time[4] = '-';
			p2->o_time[5] = (1 + pt->tm_mon) / 10 + '0';
			p2->o_time[6] = (1 + pt->tm_mon) % 10 + '0';
			p2->o_time[7] = '-';
			p2->o_time[8] = (pt->tm_mday) / 10 + '0';
			p2->o_time[9] = (pt->tm_mday) % 10 + '0';
			p2->o_time[10] = '\0';
			p1->g_num -= n;
			if (!p1->g_num){
				 p1->g_state = 0;
			}
			p->u_money -= n * p1->g_price;
			p3 = idusousuo(head1, p1->seller_id);
			p3->u_money += n * p1->g_price;
			cout << "+++++++++++++++++++++++++++++" << endl;
			cout << "交易提醒！" << endl;
			cout << "交易时间：" << p2->o_time << endl;
			cout << "交易单价：" << p2->o_price << endl;
			cout << "交易数量：" << p2->o_num << endl;
			cout << "您的余额：" << p->u_money << endl;
			cout << "+++++++++++++++++++++++++++++" << endl;
			sql(2, 1, p, p1); sql(2, 1, p3, p1); sql(2, 2, p, p1);
			strcpy(s, "INSERT INTO order VALUES(");
			for (i = 25; i < 29; ++i) {
				s[i] = p2->o_id[i - 29];
			}
			s[i] = ','; ++i;
			j = i;
			for (; i < j + strlen(p2->g_id); ++i) {
				s[i] = p1->g_name[i - j];
			}
			s[i] = ','; ++i;
			memset(pi, 0, sizeof(pi));
			sprintf(pi, "%.1lf", p2->o_price);
			for (j = i; i < j + strlen(pi); ++i) {
				s[i] = pi[i - j];
			}
			s[i] = ','; ++i;
			memset(pi, 0, sizeof(pi));
			sprintf(pi, "%d", p2->o_num);
			for (j = i; i < j + strlen(pi); ++i) {
				s[i] = pi[i - j];
			}
			s[i] = ','; ++i;
			for (j = i; i < j + strlen(p2->o_time); ++i) {
				s[i] = p1->g_time[i - j];
			}
			s[i] = ','; ++i;
			for (j = i; i < j + strlen(p2->seller_id); ++i) {
				s[i] = p2->seller_id[i - j];
			}
			s[i] = ','; ++i;
			for (j = i; i < j + strlen(p2->buyer_id); ++i) {
				s[i] = p2->buyer_id[i - j];
			}
			s[i++] = ')'; s[i] = '\0';
		}
	}break;
	case(2):if (b == 1) {
		strcpy(s, "UPDATE user SET name=");
		for (i = 21; i < 21 + strlen(p->u_name); ++i) {
			s[i] = p->u_name[i - 21];
		}
		strcat(s, ", key="); i += 6;
		j = i;
		for (; i < j + strlen(p->u_key); ++i) {
			s[i] = p->u_key[i - j];
		}
		strcat(s, ", phone="); i += 8;
		j = i;
		for (; i < j + strlen(p->u_phone); ++i) {
			s[i] = p->u_phone[i - j];
		}
		strcat(s, ", address="); i += 10;
		for (j = i; i < j + strlen(p->u_address); ++i) {
			s[i] = p->u_address[i - j];
		}
		strcat(s, ", money="); i += 8;
		memset(pi, 0, sizeof(pi));
		sprintf(pi, "%.1lf", p->u_money);
		for (j = i; i < j + strlen(pi); ++i) {
			s[i] = pi[i - j];
		}
		strcat(s, ", state="); i += 8;
		s[i++] = (int)p->u_state + '0'; s[i] = ' ';
		strcat(s, "WHERE ID CONTAINS ");
		strcat(s, p->u_id);
	}
		   else if (b == 2) {
		strcpy(s, "UPDATE commodity SET prcie=");
		memset(pi, 0, sizeof(pi));
		sprintf(pi, "%.1lf", pg->g_price);
		for (i = 27; i < 27 + strlen(pi); ++i) {
			s[i] = pi[i - 27];
		}
		strcat(s, ", num="); i += 6;
		j = i;
		memset(pi, 0, sizeof(pi));
		sprintf(pi, "%d", pg->g_num);
		for (; i < j + strlen(pi); ++i) {
			s[i] = pi[i - j];
		}
		strcat(s, ", des="); i += 6;
		j = i;
		for (; i < j + strlen(pg->g_des); ++i) {
			s[i] = pg->g_des[i - j];
		}
		strcat(s, ", state="); i += 8;
		s[i++] = (int)pg->g_state + '0'; s[i] = ' ';
		strcat(s, "WHERE ID CONTAINS ");
		strcat(s, pg->g_id);
	}break;
	case(3):if (b == 0) {
		strcpy(s, "SELECT*FROM commodity WHERE state CONTAINS 1");
	}
		   else if (b == 1) {
		strcpy(s, "SELECT*FROM commodity WHERE sellerid CONTAINS ");
		i = 46;
		for (; i < 46 + strlen(p->u_id); ++i) {
			s[i] = p->u_id[i - 46];
		}
		s[i] = '\0';
	}
		   else if (b == 2) {
		strcpy(s, "SELECT*FROM order WHERE buyerid CONTAINS ");
		i = 41;
		for (; i < 41 + strlen(p->u_id); ++i) {
			s[i] = p->u_id[i - 41];
		}
		s[i] = '\0';
	}
		   if (b == 3) {
			   strcpy(s, "SELECT*FROM order WHERE sellerid CONTAINS ");
			   i = 42;
			   for (; i < 42 + strlen(p->u_id); ++i) {
				   s[i] = p->u_id[i - 42];
			   }
			   s[i] = '\0';
		   }break;
	case(4):if (b == 1) {
		strcpy(s, "SELECT*FROM user");
	}
		   else if (b == 2) {
		strcpy(s, "SELECT*FROM commodity");
	}
		   else if (b == 3) {
		strcpy(s, "SELECT*FROM order");
	}break;
	default:cout << "error!" << endl; break;
	}
		   FILE* fp = fopen("C:\\Users\\陈怡然\\Desktop\\Commands.txt", "a");
		   fprintf(fp, "%d-%02d-%02d %02d:%02d:%02d:%s\n", pt->tm_year+1900,pt->tm_mon+1,pt->tm_mday,pt->tm_hour,pt->tm_min,pt->tm_sec, s);
		   fclose(fp);
		   sqlcl(s);
	}
