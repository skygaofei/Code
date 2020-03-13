#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack<char> ans;
string line;

void output(int l,int r){
    int i=r;
    while((line[i]=='0')&&(i>=l)) i--;
    int j=l;
    while((line[j]=='0')&&(j<=r))j++;
    if(i==l-1) {
        printf("0");
        return;
    }
    for(;i>=j;i--) printf("%c",line[i]);
    return;
}

int main(){
    char ch;
    int type=1,pos=0;
    cin>>line;
    if(line[line.length()-1]=='%') type=4;
    else {
        for(int i=0;i<line.length();i++){
            if(line[i]=='.') {
                type=2;
                pos=i;
                break;    
            }
            else if(line[i]=='/'){
                type=3;
                pos=i;
                break;
            }
        }
    }
    switch(type){
        case 1:{
            output(0,line.length()-1);
            break;
        }
        case 2:{
            output(0,pos-1);
            printf(".");
            output(pos+1,line.length()-1);
            break;
        }
        case 3:{
            output(0,pos-1);
            printf("/");
            output(pos+1,line.length()-1);
            break;
        }    
        case 4:{
            output(0,line.length()-2);
            printf("%c",line[line.length()-1]);
            break;
        }    
    }
    return 0;
}