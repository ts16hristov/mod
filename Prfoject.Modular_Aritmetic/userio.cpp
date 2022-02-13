#include "userio.hpp"
#include "modLab.hpp"
#include <iostream>

int printMenu(){
    std::cout<<"Menu options:\n";
    std::cout<<"1-Task 1: Fill array with remainders of Zn;\n";
    std::cout<<"2-Task 2: Sum of two remainders from Zn;\n";
    std::cout<<"3-Task 3: Substraction of two remainders from Zn;\n";
    std::cout<<"4-Task 4: Multiplication of two remainders from Zn;\n";
    std::cout<<"5-Task 5: Print all couple remainder and their reciprocal;\n";
    std::cout<<"6-Task 6: Check for reciprocal of entered remainder from Zn,\nusing the principle from task 5;\n";
    std::cout<<"7-Task 7:Check for reciprocal of entered remainder from Zn,\nusing the principle of identity of Bezaut and basic Euclidean algorithm;\n";
    std::cout<<"8-Task 8:Division of two ramainders from Zn and\nif it does not possible, it returns like result -1;\n";
    std::cout<<"9-Task 9:Gradation of number using first method:\n finding the smallest raminder of Zn for which the remainder of the graded number is 1;\n";
    std::cout<<"10-Task 10:Gradation of number using second method:\n by representing the degree in a binary number system;\n";
    std::cout<<"11-Task 11:Checks if a remainder from the ring is a primitive root in Zn;\n";
    std::cout<<"12-Task 12:Prints all primitive roots from Zn;\n";
    std::cout<<"13-Task 12:Check is Zn is residual field;\n";
    std::cout<<"14-To enter new module;\n";
    std::cout<<"0-End;\n";
    return 0;
}


int printMenuQuit(){
    std::cout<<"Menu options:\n";
    std::cout<<"1-Continue with the same module;\n";
    std::cout<<"2-Continue with new module;\n";
    std::cout<<"3-End;\n";
    return 0;
}

int menu(int task,int n){
    switch(task){
        case 0:
            break;
        case 1:{
            int* z = new int [n];
            fillZn(z,n);
            printArray(z,n);
            dellocateArr(z);
            break;
        }
        case 2:
        {
            int *num =new int[2];
            num=enteringTwoNum(num,n);
            std::cout<<"The sum of your remainders is:"<<sumRemainders(n,num[0],num[1])<<std::endl;
            dellocateArr(num);
            break;

        }
            
        case 3:
        {
            int *num =new int[2];
            num=enteringTwoNum(num,n);
            std::cout<<"The substraction of your remainders is:"<<substractRemainders(n,num[0],num[1])<<std::endl;
            dellocateArr(num);
            break;
        }
        case 4:
        {
            int *num =new int[2];
            num=enteringTwoNum(num,n);
            std::cout<<"The multiplication of your remainders is:"<<multiplyRemainders(n,num[0],num[1])<<std::endl;
            
            break;
        }
        case 5:
        {
            int**z=new int*[2];
            allocateDarr(z, n);
            int sz = reciprocalRemainder(z,n);
            for(int i=0;i<2;i++){
                for(int j=0;j<sz;j++){
                    std::cout<<z[i][j]<<'\t';
                }
                std::cout<<std::endl;
            }
            dellocateDarr(z, n);
            break;
        }
        case 6:
        {
            int**z=new int*[2];
            allocateDarr(z, n);
            int num = 0;
            enteringOneNum(num, n);
            int v=checkForReciprocal(z, num, reciprocalRemainder(z, n));
            if(v!=-1){
                std::cout<<"The reciprocal of your remainder is: "<<v<<std::endl;
            } else {
                std::cout<<"There are not reciprocal element of this remainder!"<<std::endl;
            }
            dellocateDarr(z, n);
            break;
        }
        case 7:
        {
            int num = 0;
            enteringOneNum(num, n);
            int v=reciprocalRemainderByIndentityOfBesuAndBEA(num, n);
            if(v!=-1){
                std::cout<<"The reciprocal of your remainder is: "<<v<<std::endl;
            } else {
                std::cout<<"There are not reciprocal element of this remainder!"<<std::endl;
            }
            break;
        }
        case 8:
        {
            int *num =new int[2];
            std::cout<<"Enter your two remainders in the way first:second!\n";
            num=enteringTwoNum(num, n);
            std::cout<<divisionOfRemainders(num[0], num[1],n)<<std::endl;
            dellocateArr(num);
            break;
        }
        case 9:
        {
            int a = 0,m;
            std::cout<<"Enter basis from Zn:\n";
            a=enteringOneNum(a, n);
            do{
                std::cout<<"Enter degree:\n";
                std::cin>>m;
            }while(m<0);
            std::cout<<grading(n,a,m)<<std::endl;
            break;
        }
        case 10:
        {
            int a = 0,m;
            std::cout<<"Enter basis from Zn:\n";
            a=enteringOneNum(a, n);
            do{
                std::cout<<"Enter degree:\n";
                std::cin>>m;
            }while(m<0);
            std::cout<<gradationBinaryMethod(n,a,m)<<std::endl;
            break;
        }
        case 11:
        {
            int num=0;
            num=enteringOneNum(num, n);
            if(checkForPrimitiveRoot(num, n)){
                std::cout<<num<<" is primitive root\n";
            } else {
                std::cout<<num<<" is not primitive root\n";
            }
            break;
        }
        case 12:
            primitiveRoots(n);
            break;
        case 13:
            if(isItResidualField(n)){
                std::cout<<"Ring Z"<<n<<" is residual field F"<<n<<"!\n";
            } else {
                std::cout<<"Ring Z"<<n<<" is not residual field!\n";
            }
            break;
        default:
            std::cout<<"There are not option like this!\n";
            break;
    }
    return 0;
}

