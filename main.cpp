#include<iostream>
#include <string>
using namespace std;
#include "G.h"
int main(){
cout<<"Enter your message\r\n>";
string mess = GetStr();
int m_len=GetLen(mess);
cout<<"Enter your key:\r\n>";
string key = GetStr();
int ind  = 0;
while(m_len>GetLen(key)){
    key+=key[ind];
    ind++;
}
string encrypted;
for(int i = 0;i<m_len;i++){
    char ch = mess[i];
    ch-=97;
    ch+=key[i]-'0';
    ch%=26;
    ch+=97;
    encrypted+=ch;
}
cout<<encrypted<<endl;
//Decryption
string decrypted;
for(int i = 0;i<m_len;i++){
    char ch = encrypted[i];
    ch-=97;
    ch-=key[i]-'0';
    while(ch<0){
        ch+=25;
    }
    ch+=97;
    decrypted+=ch;
}
cout<<decrypted;
return 0;
}
