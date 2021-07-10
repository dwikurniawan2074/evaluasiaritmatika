// Nama Anggota Kelompok :
// Nur Setiowati - 2017051013
// Dwi Kurniawan - 2017051013
// Satria Sapta Nugraha - 2017051022

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define elif else if
#define maks 100
using namespace std;


void inToPost(string str, int len);
int isOpr(char ch);
bool isNum(char ch);

struct stack{
	char ch[maks];
	int index;
};

int main() {
    string infix, str = "";
    int len;
    
    getline(cin, infix);
    
    len = infix.size();
    
    for(int i=0; i<len; i++) {
    	if(isalnum(infix[i])) {
    		str += infix[i];
		}
		else if(infix[i]=='-') {
    		if(isalnum(infix[i+1])) {
    			str += infix[i];
			}
			else if(infix[i+1]=='(') {
				if(isalnum(infix[i-1])) {
					str += infix[i];
				}
				else {
					str += "-1*";
				}
			}
			else {
				if(infix[i+1]!=' ')
					str += "-1";
				else
					str += infix[i];
			}
		}
		else {
			if(infix[i]!=' ') {
				str += infix[i];
			}
		}
	}
	
//	cout << str;
	inToPost(str, str.size());
}

void inToPost(string str, int len) {
	struct stack stk;
	stk.index = 0; // intial index stack
	stk.ch[stk.index] = '#';
	stk.index++;
	string postfix = "";
	
	for(int i=0; i<len; i++) {
		if(isNum(str[i])) {
			if(isNum(str[i+1])) {
				postfix += str[i];
			}
			else {
				postfix += str[i];
				postfix += ' ';
			}
		}
		else {
			if(str[i]=='(') {
				stk.ch[stk.index] = str[i];
				stk.index++;
			}
			elif(str[i]==')') {
				while(stk.ch[stk.index-1]!='#' && stk.ch[stk.index-1]!='(') {
					postfix += stk.ch[stk.index-1];
					postfix += ' ';
					stk.index--;
				}
				stk.index--;
			}
			else {
				if(str[i]!=' ') {
					if(!(isNum(str[i-1])) && str[i]=='-' && isNum(str[i+1])) {
						postfix += str[i];
					}
					else {
						while(stk.ch[stk.index-1]!='#' && isOpr(str[i]) <= isOpr(stk.ch[stk.index-1])) {
							postfix += stk.ch[stk.index-1];
							postfix += ' ';
							stk.index--;
						}
						stk.ch[stk.index] = str[i];
						stk.index++;
					}
				}
			}
		}
	}
	
	while(stk.ch[stk.index-1]!='#') {
		postfix += stk.ch[stk.index-1];
		postfix += ' ';
		stk.index--;
	}
	
	cout << postfix;
}

int isOpr(char ch) {
	if(ch=='+' || ch=='-')
		return 1;
	elif(ch=='*' || ch=='/' || ch=='%')
		return 2;
	else
		return 0;
}

bool isNum(char ch) {
	string idt = "0123456789";
	bool cek = false;
	
	for(int i=0; i<10; i++) {
		if(ch==idt[i]) {
			cek = true;
			break;
		}
	}
	
	return cek;
}
