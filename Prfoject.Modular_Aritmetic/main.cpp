#include <iostream>
#include "userio.hpp"
#include "modLab.hpp"
using namespace std;

int main() {
    int n,t;
    bool l=true;
    reply:
    do{
        cout<<"Enter module:\n";
        cin>>n;
        if(n==0){
            cout<<"There are not modular ring. Try again!";
        }
    }while(n==0);
    do{
        printMenu();
        cin>>t;
        switch(t){
            case 14:
                goto reply;
                break;
            default:
                menu(t,n);
                int e;
                printMenuQuit();
                cin>>e;
                switch(e){
                    case 2:
                        goto reply;
                        break;
                    case 3:
                        l=false;
                        break;
                }
                break;
        }
    }while(l==true);
    return 0;
}
