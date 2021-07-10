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
