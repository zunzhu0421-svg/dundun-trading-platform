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

void qukuohao(char* s) {
	char temp[50];
	int i = 0, n = -1, m = 0, j = 0;
	for (; i < strlen(s); ++i) {
		if (s[i] == '(') n = i;
	}
	if (n != -1) {
		for (i = n; i < strlen(s); ++i) {
			if (s[i] == ')') {
				m = i; i = strlen(s);
			}
		}
		for (i = n + 1; i < m; ++i) {
			temp[j++] = s[i];
		}
		temp[j] = '\0';
		zhijiesuan(temp, temp);
		for (i = n, j = 0; j < strlen(temp); ++j) {
			s[i++] = temp[j];
		}
		for (j = m + 1; j < strlen(s); ++j) {
			s[i++] = s[j];
		}
		s[i] = '\0';
		qukuohao(s);
	}
}


void calculate(char* s, int i) {
	if (i == 1) {
		if (judge(s) == 1||judge(s)==5) {
			cout << "括号不配对！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		else if (judge(s) == 2) {
			cout << "出现异常符号！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		else if (judge(s) == 3) {
			cout << "符号运用不正确！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		else if (judge(s) == 4) {
			cout << "0不可以作为除数出现！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		qukuohao(s);
		if (judge(s) == 1 || judge(s) == 5) {
			cout << "括号不配对！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		else if (judge(s) == 2) {
			cout << "出现异常符号！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		else if (judge(s) == 3) {
			cout << "符号运用不正确！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		else if (judge(s) == 4) {
			cout << "0不可以作为除数出现！请重新输入！" << endl;
			cin >> s;
			calculate(s, i);
		}
		else {
			zhijiesuan(s, s);
		}
	}
	else {
		jiakuohao(s);
		qukuohao(s);
		zhijiesuan(s, s);
	}
}

