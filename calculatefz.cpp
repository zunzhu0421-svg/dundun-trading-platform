#include<iostream>
#include<iomanip>
#include<math.h>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include"trade.h"
#pragma warning(disable : 4996)
using namespace std;

int judge(char* s) {
	int n = 0, i = 0, flag = 0;
	for (i = 0; i < strlen(s); ++i) {
		if (isdigit(s[i])||s[i]=='.') flag = 1;
		else {
			if (s[i] == '(') ++n;
			else if (s[i] == ')') {
				--n;
				if (n < 0) return 1;
			}
			else if ((s[i] != '+') && (s[i] != '-') && (s[i] != '*') && (s[i] != '/')) return 2;
			else if (flag == 0)
				return 3;
			else
				flag = 0;
			if ((s[i] == '/') && (s[i + 1] == '0')) return 4;
		}
	}
	if ((i == strlen(s)) && (n == 0)) return 0;
	else return 5;
}

void revr(char* s) {
	int i = 0;
	char a;
	for (; i < strlen(s) / 2; ++i) {
		a = s[i];
		s[i] = s[strlen(s) - i - 1];
		s[strlen(s) - i - 1] = a;
	}
}

double jiandan(char* s) {
	int i = 0, j = 0, flag = 0;
	double ans=0;
	char temp[100];
	for (; i < strlen(s); ++i) {
		if (isdigit(s[i])||s[i]=='.') {
			temp[j] = s[i]; ++j;
		}
		else {
			if (s[i] != '+' && s[i] != '-') {
				continue;
			}
			temp[j] = '\0'; j = 0;
			if (!flag) ans += atof(temp);
			else ans -= atof(temp);
			if (s[i] == '+') flag = 0;
			else flag = 1;
		}
	}
	temp[j] = '\0'; j = 0;
	if (!flag) ans += atof(temp);
	else ans -= atof(temp);
	return ans;
}

void zhijiesuan(char* s, char* s1) {
	double an = 0;
	int i = 0, n = 0, m = 0;
	for (; i < strlen(s); ++i) {
		if (s[i] == '*' || s[i] == '/') {
			n = i;
			i = strlen(s);
		}
	}
	if (n == 0) {
		an = jiandan(s);
		sprintf(s1,"%.1f",an);
	}
	else {
		int j = 0, n1 = n;
		double a;
		char temp[100] = { "\0" };
		for (i = n + 1; i < strlen(s); ++i, ++j) {
			if (!isdigit(s[i])&&s[i]!='.') break;
			temp[j] = s[i];
		}
		temp[j] = '\0';
		n = i - 1;
		an = atof(temp);
		for (j = 0, i = n1 - 1; i >= 0; --i, ++j) {
			if (!isdigit(s[i])&&s[i]!='.') break;
			temp[j] = s[i];
		}
		temp[j] = '\0';
		m = i + 1;
		revr(temp);
		a=atof(temp);
		if (s[n1] == '*')
			an=an*a;
		else an = a / an;
		sprintf(temp,"%.1f",an);
		for (i = m, j = 0; j < strlen(temp); ++i, ++j) {
			s[i] = temp[j];
		}
		for (j = n + 1; j < strlen(s); ++i, ++j) {
			s[i] = s[j];
		}
		s[i] = '\0';
		zhijiesuan(s, s1);
	}
}

