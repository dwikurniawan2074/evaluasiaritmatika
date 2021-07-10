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

int main(){
  
  //enter code here
  
  return 0;
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
