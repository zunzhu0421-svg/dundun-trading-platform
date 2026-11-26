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

void shanchu(char* s, int i) {
	int j = 0, n = 0;
	for (; j < strlen(s); ++j) {
		if (s[j] == '*') ++n;
		if (n == i) {
			n = j;
			j = strlen(s);
		}
	}
	int cnt = 1;
	for (j = n - 1; j >= 0; --j, ++cnt) {
		if (!isdigit(s[j])&&s[j]!='.') {
			j = -1;
		}
	}
	for (j = n + 1; j < strlen(s); ++j, ++cnt) {
		if (!isdigit(s[j])&&s[j]!='.') {
			n = j;
			j = strlen(s);
			--cnt;
		}
	}
	for (; n <= strlen(s); ++n) {
		s[n - cnt] = s[n];
	}
}

void jiakuohao(char* s) {
	double b[100][2] = { 0 };
	char c[100] = { "\0" };
	int i = 0, n = 0, j = 0, k = 0, a = 0, d = 0;
	char temp[100] = { "\0" };
	for (; i < strlen(s) - 1; ++i) {
		if (s[i] == '*') {
			j = i + 1;
			for (k = 0; j < strlen(s); ++j, ++k) {
				if (!isdigit(s[j])&&s[j]!='.') break;
				temp[k] = s[j];
			}
			temp[k] = '\0';
			a = j;
			if (a < strlen(s) && (s[a] == '*' || s[a] == '/')) continue;
			b[n][1] = atof(temp);
			for (k = 0, j = i - 1; j >= 0; --j, ++k) {
				if (!isdigit(s[j])&&s[j]!='.') break;
				temp[k] = s[j];
			}
			temp[k] = '\0';
			d = j;
			if (s[d] == '*' || s[d] == '/') continue;
			if (s[d] == '+' || d == -1) c[n] = '+';
			else c[n] = '-';
			revr(temp);
			b[n][0] = atof(temp);
			++n;
		}
	}
	if (n == 0 || n == 1);
	else {
		int* flag = new int[n];
		for (i = 0; i < n; ++i) {
			flag[i] = 0;
		}
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				if (b[i][0] == b[j][0] && !flag[i] && !flag[j]) {
					flag[i] = 1; flag[j] = 1;
					char pi[10] = { "\0" };
					sprintf(pi, "%.1lf", b[i][0]);
					if (c[i] == '+') {
						char tmp[30] = { "+" };
						strcat(tmp, pi);
						strcat(tmp, "*(\0");
						memset(pi, 0, sizeof(pi));
						sprintf(pi, "%.1lf", b[i][1]);
						strcat(tmp, pi);
						if (c[j] == '+') {
							strcat(tmp, "+\0");
						}
						else {
							strcat(tmp, "-\0");
						}
						memset(pi, 0, sizeof(pi));
						sprintf(pi, "%.1lf", b[j][1]);
						strcat(tmp, pi);
						strcat(tmp, ")\0");
						strcat(s, tmp);
					}
					else {
						char tmp[30] = { "-" };
						strcat(tmp, pi);
						strcat(tmp, "*(\0");
						memset(pi, 0, sizeof(pi));
						sprintf(pi, "%.1lf", b[i][1]);
						strcat(tmp, pi);
						if (c[j] == '+') {
							strcat(tmp, "-\0");
						}
						else {
							strcat(tmp, "+]0");
						}
						memset(pi, 0, sizeof(pi));
						sprintf(pi, "%.1lf", b[j][1]);
						strcat(tmp, pi);
						strcat(tmp, ")\0");
						strcat(s, tmp);
					}
				}
			}
		}
		for (i = 0, j = 0; i < n; ++i) {
			if (flag[i]) {
				shanchu(s, i + 1 - j);
				++j;
			}
		}
	}
}
