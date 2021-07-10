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
            if(isdigit(str[i+1])){
		    str1+=str[i];
		    if(i!=0)
			    str+=' ';
	    }else if(str[i+1]=='('){
		    if(isdigit(str[i+1])){
			    str1+=str[i];
			    str1+=' ';
		    }else{
			    str1+="-1 * ";
		    }
	    }else{
		    if(str[i+1]!=' ')
			    str1+="-1";
		    else
			    str1+=str[i];
		    str1+=' ';
	    }
		    
        
        }else if(!(isdigit(str[i]))){   // perlu perbaikan
        	if(str[i]!=' '){	
            str1+=str[i];
            str1+=' ';
            }
		}
    }
        
        
    cout << str1;
  
    return 0;
}
