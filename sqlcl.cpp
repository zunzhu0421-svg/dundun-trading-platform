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

void sqlcl(char* s) {
	if (s[0] == 'I') {
		if (s[12] == 'u') {
			FILE* fp = fopen("C:\\Users\\陈怡然\\Desktop\\user.txt", "a");
			fseek(fp, 0, SEEK_END);
			int i = 24;
			for (; s[i] != ')'; ++i) {
				fprintf(fp, "%c", s[i]);
			}
			fprintf(fp, "\n");
			fclose(fp);
		}
		else if (s[12] == 'c') {
			FILE* fp = fopen("C:\\Users\\陈怡然\\Desktop\\commodity.txt", "a");
			fseek(fp, 0, SEEK_END);
			int i = 29;
			for (; s[i] != ')'; ++i) {
				fprintf(fp, "%c", s[i]);
			}
			fprintf(fp, "\n");
			fclose(fp);
		}
		else if (s[12] == 'o') {
			FILE* fp = fopen("C:\\Users\\陈怡然\\Desktop\\order.txt", "a");
			fseek(fp, 0, SEEK_END);
			int i = 25;
			for (; s[i] != ')'; ++i) {
				fprintf(fp, "%c", s[i]);
			}
			fprintf(fp, "\n");
			fclose(fp);
		}
	}
	else if (s[0] == 'U') {
		if (s[7] == 'u') {
			char id[5];
			int i = 0;
			for (; i < 4; ++i) {
				id[i] = s[strlen(s) - 4 + i];
			}
			id[4]='\0';
			User* head = ugoujian(), * p = head;
			FILE* fp = fopen("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "w");
			fprintf(fp,"id,名称，密码，联系方式，地址，余额，状态\n");
			while (p != NULL) {
				if (!strcmp(p->u_id, id)) {
					for (i = 21; s[i] != ','; ++i) {
						p->u_name[i - 21] = s[i];
					}
					p->u_name[i - 21] = '\0';
					i += 6; int j = i;
					for (; s[i] != ','; ++i) {
						p->u_key[i - j] = s[i];
					}
					p->u_key[i - j] = '\0';
					i += 8;
					j = i;
					for (; s[i] != ','; ++i) {
						p->u_phone[i - j] = s[i];
					}
					p->u_phone[i - j] = '\0';
					i += 10;
					for (j = i; s[i] != ','; ++i) {
						p->u_address[i - j] = s[i];
					}
					p->u_address[i - j] = '\0';
					i += 8;
					char tmp[100] = { "\0" };
					for (j = i; s[i] != ','; ++i) {
						tmp[i - j] = s[i];
					}
					tmp[i - j] = '\0';
					p->u_money = atof(tmp);
					i += 8;
					p->u_state = s[i] - '0';
				}
				fprintf(fp, "%s,%s,%s,%s,%s,%.1lf,%d\n", p->u_id, p->u_name, p->u_key, p->u_phone, p->u_address, p->u_money, p->u_state);
				p = p->next;
			}
			fclose(fp);
			remove("C:\\Users\\陈怡然\\Desktop\\user.txt");
			rename("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "C:\\Users\\陈怡然\\Desktop\\user.txt");
		}
		else if (s[7] == 'c') {
			char id[5];
			int i = 0;
			for (; i < 4; ++i) {
				id[i] = s[strlen(s) - 4 + i];
			}
			id[4]='\0';
			Good* head = ggoujian(), * p = head;
			FILE* fp = fopen("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "w");
			fprintf(fp,"id，名称，价格，库存，描述，卖家，上架时间，状态\n");
			while (p != NULL) {
				if (!strcmp(p->g_id, id)) {
					char tmp[20] = { "\0" };
					for (i = 27; s[i] != ','; ++i) {
						tmp[i - 27] = s[i];
					}
					tmp[i - 27] = '\0';
					p->g_price = atof(tmp);
					memset(tmp, 0, sizeof(tmp));
					i += 6;
					int j = i;
					for (; s[i] != ','; ++i) {
						tmp[i - j] = s[i];
					}
					tmp[i - j] = '\0';
					p->g_num = atoi(tmp); i += 6;
					j = i;
					for (; s[i] != ','; ++i) {
						p->g_des[i - j] = s[i];
					}
					p->g_des[i - j] = '\0';
					i += 8;
					p->g_state = s[i] - '0';
				}
				fprintf(fp, "%s,%s,%.1lf,%d,%s,%s,%s,%d\n", p->g_id, p->g_name, p->g_price, p->g_num, p->g_des, p->seller_id, p->g_time, p->g_state);
				p = p->next;
			}
			fclose(fp);
			remove("C:\\Users\\陈怡然\\Desktop\\commodity.txt");
			rename("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "C:\\Users\\陈怡然\\Desktop\\commodity.txt");
		}
	}
	else if (s[0] == 'S') {
		if (strlen(s) <= 21) {
			if (s[12] == 'u') {
				cout <<endl<< "++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "用户id       用户名      联系方式          地址       钱包余额 用户状态" << endl;
				User* head = ugoujian(), * p = head;
				while (p != NULL) {
					cout << " "<<p->u_id << setw(15)<< p->u_name << "     " << p->u_phone << setw(20) << p->u_address << setw(7) << p->u_money << "    " ;
					if(p->u_state){
						cout<<"正常"<<endl;
					}
					else{
						cout<<"封禁"<<endl;
					}
					p = p->next;
				}
				cout << "++++++++++++++++++++++++++++++++++++++++++" << endl;
			}
			else if (s[12] == 'c') {
				cout <<endl<< "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "商品id       商品名称 商品单价  上架时间 卖家id" << endl;
				Good* head = ggoujian(), * p = head;
				while (p != NULL) {
					cout <<" "<< p->g_id <<  setw(15) << p->g_name << setw(7) << p->g_price << "    " << p->g_time << " " << p->seller_id << endl;
					p = p->next;
				}
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			}
			else if (s[12] == 'o') {
				cout <<endl<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				cout << "订单id 商品id 交易单价 数量 交易时间 卖家id 买家id" << endl;
				Order* head=ogoujian(), * p = head;
				while (p != NULL) {
					cout << " "<<p->o_id << "   " << p->g_id << "     " << p->o_price << "    " << p->o_num << "  " << p->o_time << " " << p->seller_id << "   " << p->buyer_id << endl;
					p = p->next;
				}
				cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			}
		}
		else {
			if (s[12] == 'c') {
				if (s[29] == 't') {
					cout << endl<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "商品id       商品名称 商品单价  上架时间 卖家id"  << endl;
					Good* head = ggoujian(), * p = head;
					while (p != NULL) {
						if (p->g_state) {
							cout <<" "<< p->g_id <<  setw(15) << p->g_name << setw(7) << p->g_price << "    " << p->g_time << " " << p->seller_id << endl;
					    }
						p = p->next;
					}
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				}
				else if (s[29] == 'e') {
					int i = 46;
					char id[4];
					for (; i < 50; ++i) {
						id[i - 46] = s[i];
					}
					cout << endl<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "商品id       商品名称 商品单价  上架时间 卖家id" << endl;
					Good* head = ggoujian(), * p = head;
					while (p != NULL) {
						if (!strcmp(id, p->seller_id)) {
							cout <<" "<< p->g_id <<  setw(15) << p->g_name << setw(7) << p->g_price << "    " << p->g_time << " " << p->seller_id << endl;
					    }
						p = p->next;
					}
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				}
			}
			else if (s[12] == 'o') {
				if (s[24] == 'b') {
					int i = 41;
					char id[4];
					for (; i < 45; ++i) {
						id[i - 41] = s[i];
					}
					cout <<endl<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "订单id 商品id 交易单价 数量 交易时间 卖家id 买家id" << endl;
					Order* head=ogoujian(), * p = head;
					while (p != NULL) {
						if (!strcmp(id, p->buyer_id)) {
							cout << " "<<p->o_id << "    " << p->g_id << "    " << p->o_price << "    " << p->o_num << "    " << p->o_time << "    " << p->seller_id << "    " << p->buyer_id << endl;
						}
						p = p->next;
					}
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				}
				else if (s[24] == 's') {
					int i = 41;
					char id[4];
					for (; i < 45; ++i) {
						id[i - 41] = s[i];
					}
					cout << endl<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					cout << "订单id 商品id 交易单价 数量 交易时间 卖家id 买家id" << endl;
					Order* head=ogoujian(), * p = head;
					while (p != NULL) {
						if (!strcmp(id, p->seller_id)) {
							cout << " "<<p->o_id << "    " << p->g_id << "    " << p->o_price << "    " << p->o_num << "    " << p->o_time << "    " << p->seller_id << "    " << p->buyer_id << endl;
						}
						p = p->next;
					}
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
				}
			}
		}
	}
}
