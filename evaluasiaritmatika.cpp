// Nama Anggota Kelompok :
// Nur Setiowati - 2017051013
// Dwi Kurniawan - 2017051013
// Satria Sapta Nugraha - 2017051022

#include <iostream>
#include <vector>
#define elif else if
#define maks 100
#define cnum 48
using namespace std;

string dt_ch = "abcdefghijklmnopqrstuvwxyz";
int index = 0;

void inToPost(string str, int len);
int isOpr(char ch);
bool isNum(char ch);
void postEval(string str, int len);
int hitung(int a, int b, char opr);

int main(){
  
  //enter code here
}

void inToPost(string str, int len) {
	struct stack stk;
	stk.index = 0; // intial index stack
	stk.ch[stk.index] = '#';
	stk.index++;
	string postfix = "";
	int jml=0, num, postLen;
	
	for(int i=0; i<len; i++) {
		if(isNum(str[i])) {
			num = str[i] - cnum;
			if(isNum(str[i+1])) {
				jml = (jml * 10) + (num * 10);
			}
			else {
				jml += num;
				edt[index].ch = dt_ch[index];
				edt[index].num = jml;
				postfix += edt[index].ch;
//				cout << edt[index].ch <<  edt[index].num << endl;
				index++;
				jml = 0;
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
					stk.index--;
				}
				stk.index--;
			}
			else {
				if(str[i]!=' ') {
					if(!(isNum(str[i-1])) && str[i]=='-' && isNum(str[i+1])) {
						edt[index].ch = dt_ch[index];
						edt[index].num = jml;
						postfix += edt[index].ch;
						index++;
					}
					else {
						while(stk.ch[stk.index-1]!='#' && isOpr(str[i]) <= isOpr(stk.ch[stk.index-1])) {
							postfix += stk.ch[stk.index-1];
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
		stk.index--;
	}
	
	cout << postfix;
	postLen = postfix.size();
	postEval(postfix, postLen);
	delete &stk;
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
