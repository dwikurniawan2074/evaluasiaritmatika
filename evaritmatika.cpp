// Nama anggota kelompok :
// Nur Setiowati 2017051013
// Dwi Kurniawan 2017051074
// Satria Sapta Nugraha 2017051022

#include <bits/stdc++.h>
using namespace std;

bool isOperator(char x){
    if(x == '+' || x == '-' ||      
       x == '*' || x == '/' ||
       x == '%'){
        return true;
    }else{
        return false;
    }
}

int putFirst(string x){
    if(x == "+" || x == "-"){
        return 1;
    }
    if(x == "*" || x == "/" || 
       x == "%"){
        return 2;
    }
    return 0;
}
