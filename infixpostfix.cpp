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
    int num1, num2;
    num1 = prioritet(r); num2 = prioritet(s);
    
    return num1 <= num2;
}

vector <string> infix; vector <string> postfix; string temp; vector <string>::iterator remake; vector <string>::iterator ident;

void MasukkanData(){
    string masuk;
    char kar;
    
    while(cin.get(kar)){
        if(kar == '\n'){
            break;
        }
        if(kar != ' '){
            masuk.push_back(kar);
        }
    }
    int length = masuk.length();

    for(int i = 0; i < length; i++){
        if(masuk[i] == '(' ||
           masuk[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(masuk.substr(i, 1));
        }
        if(isdigit(masuk[i]) ||
           (masuk[i] == '-' &&
            i == 0 &&
            isdigit(masuk[i+1]))){
            
            temp.push_back(masuk[i]);
            continue;
        }
        if(oibreoir(masuk[i])){
            if(temp.length() != 0){
                
                infix.push_back(temp);
                temp.clear();
            }
            if((masuk[i] == '-' &&
                oibreoir(masuk[i-1])) ||
               (masuk[i] == '-' &&
                i == 0 && masuk[i+1] == '(') ||
               (masuk[i] == '-' &&
                masuk[i-1] == '(')){
                
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(masuk.substr(i, 1));
            }
        }
    }
    if(temp.length() != 0){
        infix.push_back(temp);
        temp.clear();
    }
}

void InfixtoPostfix(){
    stack <string> temp2;
    int i = 0;
    for(remake = infix.begin(); remake != infix.end() ; remake++, i++){
        if(isdigit(infix[i].back())){
            postfix.push_back(infix[i]);
            continue;
        }
        if(infix[i] == "("){
            
            temp2.push(infix[i]);
            continue;
        }
        if(infix[i] == ")"){
            while(!temp2.empty() &&
                  (temp2.top() != "(")){
                
                string toPush = temp2.top();
                postfix.push_back(toPush);
                temp2.pop();
            }
            temp2.pop();
            continue;
        }
        if(oibreoir(infix[i][0])){
            if(temp2.empty() ||
               temp2.top() == "("){
               temp2.push(infix[i]);
            }
            else{
                while(!temp2.empty() &&
                     (temp2.top() != "(") &&
                      grande(infix[i], temp2.top())){
                    
                    string toPush = temp2.top();
                    postfix.push_back(toPush);
                    temp2.pop();
                }
                temp2.push(infix[i] );
            }
            continue;
        }
    }
    while(!temp2.empty()){
        string toPush = temp2.top();
        postfix.push_back(toPush);
        temp2.pop();
    }
}


        }
        if(infix[i] == "("){
            
            temp2.push(infix[i]);
            continue;
        }
        if(infix[i] == ")"){
            while(!temp2.empty() &&
                  (temp2.top() != "(")){
                
                string toPush = temp2.top();
                postfix.push_back(toPush);
                temp2.pop();
            }
            temp2.pop();
            continue;
        }
        if(oibreoir(infix[i][0])){
            if(temp2.empty() ||
               temp2.top() == "("){
               temp2.push(infix[i]);
            }
            else{
                while(!temp2.empty() &&
                     (temp2.top() != "(") &&
                      grande(infix[i], temp2.top())){
                    
                    string toPush = temp2.top();
                    postfix.push_back(toPush);
                    temp2.pop();
                }
                temp2.push(infix[i] );
            }
            continue;
        }
    }
    while(!temp2.empty()){
        string toPush = temp2.top();
        postfix.push_back(toPush);
        temp2.pop();
    }
}

int main(){
    MasukkanData();
    InfixtoPostfix();
    cout << "Print : ";
    for(ident = postfix.begin(); ident != postfix.end() ; ident++){
        cout << *ident << " ";
    }
}
