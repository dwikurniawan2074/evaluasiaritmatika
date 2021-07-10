#include <iostream>
#include <cstring>
using namespace std;

// Anggota Kelompok
// Nur Setiowati 2017051013
// Dwi Kurniawan 2017051074
// Satria Sapta Nugraha 2017051022

int main(){
    string str,str1;
    getline(cin, str);
    int a = str.length();
    
    for(int i=0;i<a;i++){
        if(isdigit(str[i])){
            str1+=str[i];
            if(!(isdigit(str[i+1]))){
                str1+=' ';
            }
        
        }else if (!(isdigit(str[i])) && str[i] != ' ')
        {
            str1 += str[i];
            if (i == 0 && isdigit(str[i + 1]) && str[i] == '-')
            {
                str1 += "";
            }
            else if (str[i] == '-' && str[i + 1] == '(' && isdigit(str[i - 2]))
            {
                str1 += "1 * ";
            }
            else if (str[i] == '-' && isdigit(str[i + 1]) && !(isdigit(str[i - 1])))
            {
                str1 += "1 * ";
            }
            else if (str[i] == '-' && str[i - 2] != ')' && str[i - 1] != ')' && str[i + 1] == '(' && !(isdigit(str[3 - 2])))
            {
                str1 += "1 * ";
            }
            else if (i == ((int)str.length()) - 1)
            {
                str1 += "";
            }
            else
            {
                str1 += " ";
            }
        }
	}
    cout << "Print : " << str1;

}
