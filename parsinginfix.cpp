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
        
        }else if(str[i]=='-'){
            if(!(isdigit(str[i+1])) && !(isdigit(str[i-1]))){
                str1+="-1 * ";
            }else{
                str1+="- ";
            }
        }
        
        
      
  
    return 0;
}
