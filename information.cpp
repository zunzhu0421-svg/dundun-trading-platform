#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cfloat>
#include"trade.h"
#pragma warning(disable : 4996)
using namespace std;

User* ugoujian() {
	User* head = NULL, * p1 = head, * p2 = head;
	char s[100] = { "\0" };
	FILE* fp = fopen("C:\\Users\\³ÂâùÈ»\\Desktop\\user.txt", "r");
	rewind(fp);
	fscanf(fp, "%s", s);
	p1 = (User*)malloc(sizeof(User)); p1->next = NULL;
	fscanf(fp, "%s", s);
	int i = 0, j = 0;
	while (s[i] != ',') {
		p1->u_id[j++] = s[i++];
	}
	p1->u_id[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->u_name[j++] = s[i++];
	}
	p1->u_name[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->u_key[j++] = s[i];
		++i;
	}
	p1->u_key[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->u_phone[j++] = s[i++];
	}
	p1->u_phone[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->u_address[j++] = s[i++];
	}
	p1->u_address[j] = '\0';
	j = 0; ++i;
	char tmp[10] = { "\0" };
	while (s[i] != ',') {
		tmp[j++] = s[i++];
	}
	tmp[j] = '\0';
	p1->u_money = atof(tmp);
	++i; p1->u_state = s[i] - '0';
	head = p2 = p1;
	while (!feof(fp)) {
		p2->next = p1;
		p2 = p1;
		p1 = (User*)malloc(sizeof(User)); p1->next = NULL;
		fscanf(fp, "%s", s);
		i = 0; j = 0;
		while (s[i] != ',') {
			p1->u_id[j++] = s[i++];
		}
		p1->u_id[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->u_name[j++] = s[i++];
		}
		p1->u_name[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->u_key[j++] = s[i];
			++i;
		}
		p1->u_key[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->u_phone[j++] = s[i++];
		}
		p1->u_phone[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->u_address[j++] = s[i++];
		}
		p1->u_address[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			tmp[j++] = s[i++];
		}
		tmp[j] = '\0';
		p1->u_money = atof(tmp);
		++i; p1->u_state = s[i] - '0';
	}
	fclose(fp);
	return head;
}


Good* ggoujian() {
	Good* head = NULL, * p1 = head, * p2 = head;
	FILE* fp = fopen("C:\\Users\\³ÂâùÈ»\\Desktop\\commodity.txt", "r");
	char s[100] = { "\0" };
	rewind(fp);
	fscanf(fp, "%s", s);
	p1 = (Good *)malloc(sizeof(Good)); p1->next = NULL;
	fscanf(fp, "%s", s);
	int i = 0, j = 0;
	while (s[i] != ',') {
		p1->g_id[j++] = s[i++];
	}
	p1->g_id[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->g_name[j++] = s[i++];
	}
	p1->g_name[j] = '\0';
	j = 0; ++i;
	char tmp[10] = { "\0" };
	while (s[i] != ',') {
		tmp[j++] = s[i++];
	}
	tmp[j] = '\0';
	p1->g_price = atof(tmp);
	j = 0; ++i;
	while (s[i] != ',') {
		tmp[j++] = s[i];
		++i;
	}
	tmp[j] = '\0';
	p1->g_num = atoi(tmp);
	j = 0; ++i;
	while (s[i] != ',') {
		p1->g_des[j++] = s[i++];
	}
	p1->g_des[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->seller_id[j++] = s[i++];
	}
	p1->seller_id[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->g_time[j++] = s[i++];
	}
	p1->g_time[j] = '\0';
	j = 0; ++i;
	p1->g_state = s[i] - '0';
	head = p2 = p1;
	while (!feof(fp)) {
		p2->next = p1;
		p2 = p1;
		p1 = (Good*)malloc(sizeof(Good)); p1->next = NULL;
		fscanf(fp, "%s", s);
		i = 0; j = 0;
		while (s[i] != ',') {
			p1->g_id[j++] = s[i++];
		}
		p1->g_id[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->g_name[j++] = s[i++];
		}
		p1->g_name[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			tmp[j++] = s[i++];
		}
		tmp[j] = '\0';
		p1->g_price = atof(tmp);
		j = 0; ++i;
		while (s[i] != ',') {
			tmp[j++] = s[i];
			++i;
		}
		tmp[j] = '\0';
		p1->g_num = atoi(tmp);
		j = 0; ++i;
		while (s[i] != ',') {
			p1->g_des[j++] = s[i++];
		}
		p1->g_des[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->seller_id[j++] = s[i++];
		}
		p1->seller_id[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->g_time[j++] = s[i++];
		}
		p1->g_time[j] = '\0';
		j = 0; ++i;
		p1->g_state = s[i] - '0';
	}
	fclose(fp);
	return head;
}

Order* ogoujian() {
	Order* head = NULL, * p1 = head, * p2 = head;
	FILE* fp = fopen("C:\\Users\\³ÂâùÈ»\\Desktop\\order.txt", "r");
	rewind(fp);
	char s[100] = { "\0" };
	fscanf(fp, "%s", s);
	p1 = (Order*)malloc(sizeof(Order)); p1->next = NULL;
	fscanf(fp, "%s", s);
	int i = 0, j = 0;
	while (s[i] != ',') {
		p1->o_id[j++] = s[i++];
	}
	p1->o_id[j] = '\0';
	j = 0; ++i;
	while (s[i] != ',') {
		p1->g_id[j++] = s[i++];
	}
	p1->g_id[j] = '\0';
	j = 0; ++i;
	char tmp[10] = { "\0" };
	while (s[i] != ',') {
		tmp[j++] = s[i++];
	}
	tmp[j] = '\0';
	p1->o_price = atof(tmp);
	j = 0; ++i;
	while (s[i] != ',') {
		tmp[j++] = s[i];
		++i;
	}
	tmp[j] = '\0';
	p1->o_num = atoi(tmp);
	j = 0; ++i;
	while (s[i] != ',') {
		p1->o_time[j++] = s[i++];
	}
	p1->o_time[j] = '\0'; j = 0; ++i;
	while (s[i] != ',') {
		p1->seller_id[j++] = s[i++];
	}
	p1->seller_id[j] = '\0';
	j = 0; ++i;
	while (i<strlen(s)) {
		p1->buyer_id[j++] = s[i++];
	}
	p1->buyer_id[j] = '\0';
	head = p2 = p1;
	while (!feof(fp)) {
		p2->next = p1;
		p2 = p1;
		p1 = (Order*)malloc(sizeof(Order)); p1->next = NULL;
		fscanf(fp, "%s", s);
		i = 0; j = 0;
		while (s[i] != ',') {
			p1->o_id[j++] = s[i++];
		}
		p1->o_id[j] = '\0';
		j = 0; ++i;
		while (s[i] != ',') {
			p1->g_id[j++] = s[i++];
		}
		p1->g_id[j] = '\0';
		j = 0; ++i;
		char tmp[10] = { "\0" };
		while (s[i] != ',') {
			tmp[j++] = s[i++];
		}
		tmp[j] = '\0';
		p1->o_price = atof(tmp);
		j = 0; ++i;
		while (s[i] != ',') {
			tmp[j++] = s[i];
			++i;
		}
		tmp[j] = '\0';
		p1->o_num = atoi(tmp);
		j = 0; ++i;
		while (s[i] != ',') {
			p1->o_time[j++] = s[i++];
		}
		p1->o_time[j] = '\0'; j = 0; ++i;
		while (s[i] != ',') {
			p1->seller_id[j++] = s[i++];
		}
		p1->seller_id[j] = '\0';
		j = 0; ++i;
		while (i<strlen(s)) {
			p1->buyer_id[j++] = s[i++];
		}
		p1->buyer_id[j] = '\0';
	}
	fclose(fp);
	return head;
}

chong* cgoujian() {
	chong* head = NULL, * p1 = head, * p2 = head;
	FILE* fp = fopen("C:\\Users\\³ÂâùÈ»\\Desktop\\chong.txt", "r");
	char s[100] = { "\0" },tmp[10]={"\0"};
	rewind(fp);
	fscanf(fp, "%s", s);
	p1 = (chong *)malloc(sizeof(chong)); p1->next = NULL;
	fscanf(fp, "%s", s);
	int i = 0, j = 0;
	while (s[i] != ',') {
		p1->u_id[j++] = s[i++];
	}
	p1->u_id[j] = '\0';
	j = 0; ++i;
	while (i<strlen(s)) {
		tmp[j++] = s[i];
		++i;
	}
	tmp[j] = '\0';
	p1->n = atof(tmp);
	head = p2 = p1;
	while (!feof(fp)) {
		p2->next = p1;
		p2 = p1;
		p1 = (chong *)malloc(sizeof(chong)); p1->next = NULL;
		fscanf(fp, "%s", s);
		i = 0, j = 0;
		while (s[i] != ',') {
			p1->u_id[j++] = s[i++];
		}
		p1->u_id[j] = '\0';
		j = 0; ++i;
		while (i<strlen(s)) {
			tmp[j++] = s[i];
			++i;
		}
		tmp[j] = '\0';
		p1->n = atof(tmp);
	}
	fclose(fp);
	return head;
}

chat* chgoujian() {
	chat* head = NULL, * p1 = head, * p2 = head;
	FILE* fp = fopen("C:\\Users\\³ÂâùÈ»\\Desktop\\chat.txt", "r");
	char s[150] = { "\0" };
	rewind(fp);
	fscanf(fp, "%s", s);
	p1 = (chat*)malloc(sizeof(chat)); p1->next = NULL;
	fscanf(fp, "%s", s);
	int i = 0, j = 0;
	while (s[i] != ',') {
		p1->c_id[j++] = s[i++];
	}
	p1->c_id[j] = '\0';
	++i; j = i;
	while (s[i] != ',') {
		p1->s_uid[i - j] = s[i++];
	}
	p1->s_uid[i - j] = '\0';
	++i; j = i;
	while (s[i] != ',') {
		p1->g_uid[i - j] = s[i++];
	}
	p1->g_uid[i - j] = '\0';
	++i; j = i;
	while (s[i] != ',') {
		p1->cont[i - j] = s[i++];
	}
	p1->cont[i - j] = '\0';
	++i; j = i;
	while (s[i] != ',') {
		p1->c_time[i - j] = s[i++];
	}
	p1->c_time[i - j] = '\0';
	++i;
	p1->c_state = s[i] - '0';
	head = p2 = p1;
	while (!feof(fp)) {
		p2->next = p1;
		p2 = p1;
		p1 = (chat*)malloc(sizeof(chat)); p1->next = NULL;
		fscanf(fp, "%s", s);
		int i = 0, j = 0;
		while (s[i] != ',') {
			p1->c_id[j++] = s[i++];
		}
		p1->c_id[j] = '\0';
		++i; j = i;
		while (s[i] != ',') {
			p1->s_uid[i - j] = s[i++];
		}
		p1->s_uid[i - j] = '\0';
		++i; j = i;
		while (s[i] != ',') {
			p1->g_uid[i - j] = s[i++];
		}
		p1->g_uid[i - j] = '\0';
		++i; j = i;
		while (s[i] != ',') {
			p1->cont[i - j] = s[i++];
		}
		p1->cont[i - j] = '\0';
		++i; j = i;
		while (s[i] != ',') {
			p1->c_time[i - j] = s[i++];
		}
		p1->c_time[i - j] = '\0';
		++i;
		p1->c_state = s[i] - '0';
	}
	fclose(fp);
	return head;
}

User* checkuser(User* head,char* s, char* key) {
	User* p = head;
	while (p!=NULL) {
		if (!strcmp(p->u_name, s) && !strcmp(p->u_key, key)) return p;
		p=p->next;
	}
	return p;
}

Good* sousuo(Good* head, char* s) {
	Good* p = head;
	while (p != NULL) {
		if (strcmp(p->g_name, s) == 0) return p;
		p=p->next;
	}
	return p;
}

Good* idsousuo(Good* head, char* s) {
	Good* p = head;
	while (p != NULL) {
		if (strcmp(p->g_id, s) == 0) return p;
		p=p->next;
	}
	return p;
}

User* idusousuo(User* head, char* s) {
	User* p = head;
	while (p != NULL) {
		if (strcmp(p->u_id, s) == 0) return p;
		p=p->next;
	}
	return p;
}
