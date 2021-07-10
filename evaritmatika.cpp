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

bool large(string x, string y){
    int num1, num2;
    num1 = putFirst(x);
    num2 = putFirst(y);
    return num1 <= num2;
}

double run (double x, double y, string n){
    if(n == "+"){
        return x+y;
    }
    else if(n == "-"){
        return x-y;
    }
    else if(n == "*"){
        return x*y;
    }
    else if(n == "/"){
        return x/y;
    }
    else if(n == "%"){
        return (int) x % (int) y;
    }
    return 0;
}

vector <string> infix;
vector <string> postfix;
string temp;
vector <string>::iterator iterator1;
vector <string>::iterator it;
vector <string>::iterator iter;

void input(){
    string str;
    char kar;
    while(cin.get(kar)){
        if(kar == '\n'){
            break;
        }
        if(kar != ' '){
            str.push_back(kar);
        }
    }
    int length = str.length();

    for(int i = 0; i < length; i++){
        if(str[i] == '(' || str[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(str.substr(i, 1));
        }
        if(isdigit(str[i]) || (str[i] == '-' && i == 0 && isdigit(str[i+1]))){
            temp.push_back(str[i]);
            continue;
        }
        if(isOperator(str[i])){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            if((str[i] == '-' && isOperator(str[i-1])) || 
               (str[i] == '-' && i == 0 && str[i+1] == '(') || 
               (str[i] == '-' && str[i-1] == '(')){
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(str.substr(i, 1));
            }
        }
    }
    if(temp.length() != 0){
        infix.push_back(temp);
        temp.clear();
    }
}

void toPostfix(){
    stack <string> stk;
    int i = 0;
    for(iterator1 = infix.begin(); iterator1 != infix.end() ; iterator1++, i++){
        if(isdigit(infix[i].back())){
            postfix.push_back(infix[i]);
            continue;
        }
        if(infix[i] == "("){
            stk.push(infix[i]);
            continue;
        }
        if(infix[i] == ")"){
            while(!stk.empty() && (stk.top() != "(")){
                string toPush = stk.top();
                postfix.push_back(toPush);
                stk.pop();
            }
            stk.pop();
            continue;
        }
        if(isOperator(infix[i][0])){
            if(stk.empty() || stk.top() == "("){
                stk.push(infix[i]);
            }
            else{
                while(!stk.empty() && (stk.top() != "(") && 
                      large(infix[i], stk.top())){
                    string toPush = stk.top();
                    postfix.push_back(toPush);
                    stk.pop();
                }
                stk.push(infix[i] );
            }
            continue;
        }
    }
    while(!stk.empty()){
        string toPush = stk.top();
        postfix.push_back(toPush);
        stk.pop();
    }
}

void result(){
    stack <string> stk;
    int i = 0;
    double res;
    for(iter = postfix.begin(); iter != postfix.end() ; iter++, i++){
        if(isdigit(postfix[i].back())){
            stk.push(postfix[i]);
        }
        else{
            double A = strtod((stk.top()).c_str(), NULL);
            stk.pop();
            double B = strtod((stk.top()).c_str(), NULL);
            stk.pop();
            res = run(B, A, postfix[i]);
            stk.push(to_string(res));
        }
    }
    res = strtod((stk.top()).c_str(), NULL);
    cout << res << endl;
}

int main(){
    input();
    toPostfix();
    result();
}
