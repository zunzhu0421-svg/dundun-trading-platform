#ifndef TRADE_H
#define TRADE_H

struct Good {
	char g_id[5];
	char g_name[21];
	double g_price = 0;
	int g_num = 0;
	char g_des[201];
	char seller_id[5];
	char g_time[11];
	bool g_state = 1;
	Good* next;
};

struct Order {
	char o_id[5];
	char g_id[5];
	double o_price = 0;
	int o_num;
	char o_time[11];
	char seller_id[5];
	char buyer_id[5];
	Order* next;
};

struct User {
	char u_id[5];
	char u_name[11];
	char u_key[21];
	char u_phone[21];
	char u_address[41];
	double u_money = 0;
	bool u_state = 1;
	User* next;
};

struct chong {
	char u_id[5];
	double n;
	chong* next;
};

struct chat {
	char c_id[5];
	char s_uid[5];
	char g_uid[5];
	char cont[100];
	char c_time[21];
	int c_state;
	chat* next;
};

int main();
void user(User* p);
void seller(User* p);
void buyer(User* p);
void admin();

void chatting(User* p);

User* checkuser(User* head, char* s, char* key);
Good* sousuo(Good* head, char* s);
Good* idsousuo(Good* head, char* s);
User* idusousuo(User* head, char* s);

void sql(int a,int b,User* p,Good* pg);
void sqlcl(char* s);

void calculate(char* s, int i);
int judge(char* s);
void revr(char* s);
double jiandan(char* s);
void zhijiesuan(char* s, char* s1);
void qukuohao(char* s);
void shanchu(char* s, int i);
void jiakuohao(char* s);
void shengcheng(User* p,int n,char* s);

chong* cgoujian();
User* ugoujian();
Good* ggoujian();
Order* ogoujian();
chat* chgoujian();
#endif



