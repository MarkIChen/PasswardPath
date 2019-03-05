#include <iostream>
using namespace std;
int number[10];
int length;
int countPath;
bool dis(int s, int des){
    switch(s){
        case 1 :
            if(des==2 || des==4 ||des==5) return true;
            else return false;
            break;
        case 2 :
            if(des==1 || des==3 ||des==4||des==5||des==6) return true;
            else return false;
            break;
        case 3 :
            if(des==2 || des==5 ||des==6) return true;
            else return false;
            break;
        case 4 :
            if(des==1 || des==2 ||des==5||des==7||des==8) return true;
            else return false;
            break;
        case 5 :
            if(des==1 || des==2 ||des==3||des==4||des==8||des==6||des==7||des==9) return true;
            else return false;
            break;
        case 6 :
            if(des==2 || des==3 ||des==5||des==8||des==9) return true;
            else return false;
            break;
        case 7 :
            if(des==4 || des==5 ||des==8) return true;
            else return false;
            break;
        case 8 :
            if(des==4 || des==5 ||des==6||des==7||des==9) return true;
            else return false;
            break;
        case 9 :
            if(des==8 || des==6 ||des==5) return true;
            else return false;
            break;
        defalt:
            cout<<"something wrong";
            return false;

    }
    return false;
}


void findPath(int s){
    if(length == 0){
        countPath++;
        cout<<"Over--> countPath="<<countPath<<endl;
        length++;
        number[s]=1;
        return;
    }
    for(int d=1; d<10;d++){
        if(dis(s, d) && number[d]==1){
            if(length>0) {
                cout<<"I found it s="<<s<<" d="<<d<<"length"<<length<<endl;
                length--;
                number[d] = 0;
                findPath(d);  
                // d=s;
            }
        }
        
    }
    length++;
    number[s]=1;
    return;
}

   

int main(){
    
    countPath = 0;

    for(int i=1; i<=10; i++){
        for(int p=1; p<10;p++) number[p] = 1;
        number[i] = 0;
        length=3;
        cout<<"-------------------------"<<endl;
        findPath(i);
    }


    return 0;
}

