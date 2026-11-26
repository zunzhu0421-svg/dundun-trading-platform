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

void chatting(User* p) {
	if(!p->u_state){
		cout<<endl<<"你处于封禁状态！"<<endl;
		user(p);
	}
	cout << endl << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "1.查看新留言 2.查看所有留言 3.留言 4.删除留言 5.聊天室 6.返回用户界面" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl << "请输入你的选择：";
	char s[100] = { "\0" };
	char i[30] = { "\0" };
	char c[10] = { "\0" };
	int n = 1;
	bool f = 1;
	FILE* fp = NULL;
	time_t timep;
	time(&timep);
	struct tm* pt = localtime(&timep);
	chat* head1 = chgoujian(), * p1 = head1;
	User* head2 = ugoujian(), * p2 = NULL;
	cin >> c;
	if (strlen(c) > 1) {
		cout << endl << "输入错误！请重新输入！" << endl;
		chatting(p);
	}
	switch (c[0]) {
	case('1'):while (p1) {
		if (!strcmp(p1->g_uid, p->u_id) && p1->c_state == 1) {
			f = 0;
		}
		p1 = p1->next;
	}
			 if (f) {
				 cout << endl << "没有新的留言！" << endl;
				 chatting(p);
			 }
			 fp = fopen("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "w");
			 fprintf(fp, "留言id，发送者，接收者，内容，时间，状态\n");
			 p1 = head1;
			 cout << endl <<  "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  << endl;
			 cout << "留言id 发送者id                                         留言内容      留言时间" << endl;
			 while (p1) {
				 if (!strcmp(p1->g_uid, p->u_id) && p1->c_state == 1) {
					 cout << " " << p1->c_id << "    " << p1->s_uid << setw(50) << p1->cont << " " << p1->c_time << endl;
					 p1->c_state = 0;
				 }
				 fprintf(fp, "%s,%s,%s,%s,%s,%d\n", p1->c_id, p1->s_uid, p1->g_uid, p1->cont, p1->c_time, p1->c_state);
				 p1 = p1->next;
			 }
			 cout <<  "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  << endl;
			 fclose(fp);
			 remove("C:\\Users\\陈怡然\\Desktop\\chat.txt");
			 rename("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "C:\\Users\\陈怡然\\Desktop\\chat.txt");
			 chatting(p);
			 break;
	case('2'):cout << endl << "你发送的留言：" << endl;
		while (p1) {
			if (!strcmp(p1->s_uid, p->u_id)&&p1->c_state!=3) {
				f = 0;
			}
			p1 = p1->next;
		}
		if (f) {
			cout << endl << "无" << endl;
		}
		else {
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "留言id 接收者id                                         留言内容      留言时间       状态" << endl;
			p1 = head1;
			while (p1) {
				if (!strcmp(p1->s_uid, p->u_id)&&p1->c_state!=3) {
					cout << " " << p1->c_id << "    " << p1->g_uid << setw(50) << p1->cont << " " << p1->c_time << " ";
					if (p1->c_state == 1) {
						cout << "未读" << endl;
					}
					else if (p1->c_state == 0) {
						cout << "已读" << endl;
					}
					else {
						cout << "对方已删除此条留言！" << endl;
					}
				}
				p1 = p1->next;
			}
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		}
		cout << endl << "你接收到的留言：" << endl;
		f = 1;
		p1=head1;
		while (p1) {
			if (!strcmp(p1->g_uid, p->u_id)&&p1->c_state!=2&&p1->c_state!=3) {
				f = 0;
			}
			p1 = p1->next;
		}
		if (f) {
			cout << endl << "无" << endl;
		}
		else {
			cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "留言id 发送者id                                         留言内容      留言时间"  << endl;
			p1 = head1;
			fp = fopen("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "w");
			fprintf(fp, "留言id，发送者，接收者，内容，时间，状态\n");
			while (p1) {
				if (!strcmp(p1->g_uid, p->u_id) && p1->c_state != 2&&p1->c_state!=3) {
					cout << " "<<p1->c_id << "    " << p1->g_uid << setw(50) << p1->cont << " " << p1->c_time;
					if (p1->c_state == 1) {
						cout << " " << "（新消息）" << endl;
						p1->c_state = 0;
					}
					else{
						cout<<endl;
					}
				}
				fprintf(fp, "%s,%s,%s,%s,%s,%d\n", p1->c_id, p1->s_uid, p1->g_uid, p1->cont, p1->c_time, p1->c_state);
				p1 = p1->next;
			}
			cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			fclose(fp);
			remove("C:\\Users\\陈怡然\\Desktop\\chat.txt");
			rename("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "C:\\Users\\陈怡然\\Desktop\\chat.txt");
		}
		chatting(p);
		break;
	case('3'):cout << endl << "请输入你想留言的对象id：";
		cin >> i;
		p2 = idusousuo(head2, i);
		if (!p2) {
			cout << endl << "未查找到此人！" << endl;
			chatting(p);
		}
		cout << endl << "请输入你的留言内容(请不要超过50字)：";
		cin >> s;
		while (p1) {
			p1 = p1->next;
			++n;
		}
		fp = fopen("C:\\Users\\陈怡然\\Desktop\\chat.txt", "a");
		fseek(fp, 0, SEEK_END);
		fprintf(fp, "X%03d,%s,%s,%s,%d-%02d-%02d--%02d:%02d:%02d,1\n", n, p->u_id, p2->u_id, s, pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec);
		fclose(fp);
		cout << endl << "留言成功！请等待对方回复！" << endl;
		chatting(p); break;
	case('4'):cout << endl << "请选择删除留言类型：1.自己的留言 2.他人留言" << endl;
		cin >> c;
		if (strlen(c) > 1 || (c[0] != '1' && c[0] != '2')) {
			cout << endl << "输入错误！" << endl;
			chatting(p);
		}
		if (c[0] == '1') {
			cout << endl << "请输入你想删除的留言id：";
			cin >> i;
			while (p1) {
				if (!strcmp(p1->c_id, i) && !strcmp(p1->s_uid, p->u_id)) {
					f = 0;
				}
				p1 = p1->next;
			}
			if (f) {
				cout << endl << "未查找到此留言！留言不存在或无权限删除！" << endl;
				chatting(p);
			}
			cout << endl << "请确认是否删除此留言(y/n):";
			cin >> c;
			if (strlen(c) > 1) {
				cout << endl << "输入错误！" << endl;
				chatting(p);
			}
			if (c[0] == 'y') {
				fp = fopen("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "w");
				fprintf(fp, "留言id，发送者，接收者，内容，时间，状态\n");
				p1 = head1;
				while (p1) {
					if (!strcmp(p1->c_id, i)) {
						p1->c_state=3;
					}
					fprintf(fp, "%s,%s,%s,%s,%s,%d\n", p1->c_id, p1->s_uid, p1->g_uid, p1->cont, p1->c_time, p1->c_state);
					p1 = p1->next;
				}
				fclose(fp);
				remove("C:\\Users\\陈怡然\\Desktop\\chat.txt");
				rename("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "C:\\Users\\陈怡然\\Desktop\\chat.txt");
				cout << endl << "删除留言成功！" << endl;
			}
			else {
				cout << endl << "取消删除操作成功！" << endl;
			}
		}
		else {
			cout << endl << "请输入你想删除的留言id：";
			cin >> i;
			while (p1) {
				if (!strcmp(p1->c_id, i) && !strcmp(p1->g_uid, p->u_id)) {
					f = 0;
				}
				p1 = p1->next;
			}
			if (f) {
				cout << endl << "未查找到此留言！留言不存在或无权限删除！" << endl;
				chatting(p);
			}
			cout << endl << "请确认是否删除此留言(y/n):";
			cin >> c;
			if (strlen(c) > 1) {
				cout << endl << "输入错误！" << endl;
				chatting(p);
			}
			if (c[0] == 'y') {
				fp = fopen("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "w");
				fprintf(fp, "留言id，发送者，接收者，内容，时间，状态\n");
				p1 = head1;
				while (p1) {
					if (!strcmp(p1->c_id, i)) {
						p1->c_state = 2;
					}
					fprintf(fp, "%s,%s,%s,%s,%s,%d\n", p1->c_id, p1->s_uid, p1->g_uid, p1->cont, p1->c_time, p1->c_state);
					p1 = p1->next;
				}
				fclose(fp);
				remove("C:\\Users\\陈怡然\\Desktop\\chat.txt");
				rename("C:\\Users\\陈怡然\\Desktop\\tmp.txt", "C:\\Users\\陈怡然\\Desktop\\chat.txt");
				cout << endl << "删除留言成功！" << endl;
			}
			else {
				cout << endl << "取消删除操作成功！" << endl;
			}
		}
		chatting(p);
		break;
	case('5'):cout << endl << "请输入你想查看的聊天对象id：";
		cin >> i;
		p2 = idusousuo(head2, i);
		if (!p2) {
			cout << endl << "很遗憾对方不存在！" << endl;
			chatting(p);
		}
		while (p1) {
			if ((!strcmp(p1->s_uid, p->u_id) && !strcmp(p1->g_uid, p2->u_id)) || (!strcmp(p1->s_uid, p2->u_id) && !strcmp(p1->g_uid, p->u_id))) {
				f = 0;
			}
			p1 = p1->next;
		}
		if (f) {
			cout << endl << "你与对方没有交流！" << endl;
			chatting(p);
		}
		cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << p2->u_id << "(对方)" << setw(42) << p->u_id << "(你)" << endl;
		p1 = head1;
		while (p1) {
			if (!strcmp(p1->s_uid, p2->u_id) && !strcmp(p1->g_uid, p->u_id)&&p1->c_state!=3&&p1->c_state!=2) {
				cout << endl << p1->c_time << endl;
				cout << p1->cont << endl;
			}
			if (!strcmp(p1->s_uid, p->u_id) && !strcmp(p1->g_uid, p2->u_id)&&p1->c_state!=3) {
				cout << endl << setw(55) << p1->c_time << endl;
				cout << setw(55) << p1->cont << endl;
			}
			p1 = p1->next;
		}
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		chatting(p);
		break;
	case('6'):user(p);break;
	default:cout << endl << "输入错误！请重新输入！" << endl; chatting(p); break;
	}
}

