// Nama anggota kelompok :
// Nur Setiowati 2017051013
// Dwi Kurniawan 2017051074
// Satria Sapta Nugraha 2017051022

#include <bits/stdc++.h>
using namespace std;

bool oibreoir(char r){
    if(r == '+' || 
       r == '-' || 
       r == '*' || 
       r == '/' || 
       r == '%'   ){
        return true;
    }
    else{
        return false;
    }
}

int prioritet(string r){
    if(r == "+" ||
       r == "-"   ){
        return 1;
    }
    else if(r == "*" ||
            r == "/" ||
            r == "%"   ){
        return 2;
    }
    return 0;
}

bool grande(string r, string s){
    int Nilai1, Nilai2;
    Nilai1 = prioritet(r); Nilai2 = prioritet(s);
    
    return Nilai1 <= Nilai2;
}

vector <string> infix; vector <string> postfix; string temp; vector <string>::iterator remake; vector <string>::iterator itu;

void MasukkanData(){
    string khayt;
    char harf;
    
    while(cin.get(harf)){
        if(harf == '\n'){
            break;
        }
        if(harf != ' '){
            khayt.push_back(harf);
        }
    }
    int length = khayt.length();

    for(int i = 0; i < length; i++){
        if(khayt[i] == '(' ||
           khayt[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(khayt.substr(i, 1));
        }
        if(isdigit(khayt[i]) ||
           (khayt[i] == '-' &&
            i == 0 &&
            isdigit(khayt[i+1]))){
            
            temp.push_back(khayt[i]);
            continue;
        }
        if(oibreoir(khayt[i])){
            if(temp.length() != 0){
                
                infix.push_back(temp);
                temp.clear();
            }
            if((khayt[i] == '-' &&
                oibreoir(khayt[i-1])) ||
               (khayt[i] == '-' &&
                i == 0 && khayt[i+1] == '(') ||
               (khayt[i] == '-' &&
                khayt[i-1] == '(')){
                
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(khayt.substr(i, 1));
            }
        }
    }
    if(temp.length() != 0){
        infix.push_back(temp);
        temp.clear();
    }
}
