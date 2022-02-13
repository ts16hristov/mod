#include "modLab.hpp"
#include "userio.hpp"
#include <iostream>
#include <cmath>


int allocateDarr(int** darr,int n){
    for(int i=0;i<2;i++){
        darr[i]=new int[n-1];
    }
    return 0;
}


int dellocateArr(int *arr){
    if(arr!=nullptr){
        delete[] arr;
        arr=nullptr;
    }
    return 0;
}


int dellocateDarr(int** darr,int n){
    if(darr!=nullptr){
        for(int i=0;i<2;i++){
            delete[] darr[i];
        }
        darr=nullptr;
    }
    return 0;
}

int printArray(int *z,int n){
    for(int i=0;i<n;i++){
        std::cout<<z[i]<<' ';
    }
    std::cout<<'\n';
    return 0;
}

int enteringOneNum(int v,int n){
    bool l1=true;
    do
    {
        l1=true;
        std::cout<<"Enter remainder from Zn:\n";
        std::cin>>v;
        if(v<0 || v>n-1){
            l1=false;
            std::cout<<"This remainder is out of range! Try again!\n";
        }
    } while(l1 == false );
    return v;
}


int fillZn(int *z,int n){
    //Task1
    for(int i=0;i<n;i++){
        z[i]=i;
    }
    return 0;
}

int sumRemainders(int n,int z1,int z2){
    //Task2
    return (z1+z2)%n;
}

int substractRemainders(int n,int z1,int z2){
    //Task3
    if(z1-z2>=0){
        return (z1-z2)%n;
    } else {
        return n+((z1-z2)%n);
    }
    
}

int multiplyRemainders(int n,int z1,int z2){
    //Task4
    return (z1*z2)%n;
}

int checkForReciprocal(int** z,int a,int end){
    //Task 6 and helping function in Task 5
    for(int i=1;i<end;i++){
        if(a==z[1][i]){
            return z[0][i];
            break;
        }
    }
    return -1;
}

int reciprocalRemainder(int** z,int n){
    //Task 5
    z[0][0]=1;
    z[1][0]=1;
    int couple=1;
    int ch;
    for(int i=2;i<n;i++){
        ch=checkForReciprocal(z,i,couple);
        if(ch!=-1){
            z[0][couple]=i;
            z[1][couple]=ch;
            couple++;
        }else{
            int r=0;
            bool l=false;
            for(int j=0;j<n;j++){
                if((i*j)%n==1){
                    r=j;
                    l=true;
                    break;
                }
            }
            if(l){
                z[0][couple]=i;
                z[1][couple]=r;
                 couple++;
            }
        }
        
    }
    return couple;
}

int basicEuclideanAlgorithm(int a,int b){
    //Helping function for task 7
    if(a==0){
        return b;
    } else {
        return basicEuclideanAlgorithm(b%a,a);
    }
}

int reciprocalRemainderByIndentityOfBesuAndBEA(int a,int n){
    //Task 7
    if(basicEuclideanAlgorithm(a,n)==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j*a-i*n==1){
                    return j;
                }
            }
        }
    } else {
        return -1;
    }
    return 0;
}

int divisionOfRemainders(int a,int b,int n){
    //Task 8
    int r=reciprocalRemainderByIndentityOfBesuAndBEA(b, n);
    if(r!=-1){
        return multiplyRemainders(n, a, r);
    } else {
        return -1;
    }
    return 0;
}

int gradationOfRing(int* z,int n,int a){
    //recursive function which fill our array of gradation of the basis with degrees(elements of the ring)
    static int i=1;
    if(i==n){
        i=0;
        return 0;
    }
    
    z[i]=a*z[i-1]%n;
    i++;
        return gradationOfRing(z, n, a);
}


int grading(int n,int a,int m){
    //Task9
    int k=0;
    int* remaindersOfRing=new int[n];
    remaindersOfRing[0]=1;
    gradationOfRing(remaindersOfRing, n, a);
    if(remaindersOfRing[1]==1){
            return 1;
        } else {
            for(int i=2;i<n;i++){
                if(remaindersOfRing[i]==1){
                    k=i;
                    break;
                }
            }
            return remaindersOfRing[m%k];
        }
    
}

int binaryGrading(int *b,int n,int sz){
    static int i=1;
    int pows;
    if(i==sz){
        i=0;
        return 0;
    }
    pows=pow(b[i-1],2);
    b[i]=pows%n;
    i++;
    return binaryGrading(b, n, sz);
    
}

int gradationBinaryMethod(int n,int a,int m){
    //Task 10
    int decimalM=m;
    int resultOfGradation=1;
    int sz=0;
    int *gradingBinarry=new int[32];
    int *binarry=new int[32];
    while(decimalM>0){
        binarry[sz]=decimalM%2;
        decimalM/=2;
        sz++;
    }
    gradingBinarry[0]=a%n;
    binaryGrading(gradingBinarry,n,sz);
    for(int i=0;i<sz;i++){
        if(binarry[i]!=0){
            resultOfGradation*=gradingBinarry[i];
        }
    }
    std::cout<<resultOfGradation<<std::endl;
    return resultOfGradation%n;
}

bool checkForPrimitiveRoot(int a,int n){
    //Task 11
    int remainders[n];
    int pows;
    remainders[0]=a;
    for(int i=1;i<n-1;i++){
        pows=pow(a,i+1);
        remainders[i]=pows%n;
        for(int j=i-1;j>=0;j--){
            if(remainders[i]==remainders[j]){
                return 0;
            }
        }
    }
    return 1;
}

int primitiveRoots(int n){
    //Task 12
    bool* z=new bool[n]{0};
    bool l=true;
    for(int i=0;i<n;i++){
        if(checkForPrimitiveRoot(i, n)){
            z[i]=1;
            l=false;
        }
    }
    if(l){
        std::cout<<"There are not primitive roots of "<<n<<std::endl;
    } else {
        std::cout<<"Primitive roots of "<<n<<" are:\n";
        for(int i=0;i<n;i++){
            if(z[i]!=0){
                std::cout<<i<<' ';
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}

bool isItResidualField(int n){
    //Task 13
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int* enteringTwoNum(int* v,int n){
    bool l1=true;
    bool l2=true;
    do
    {
        l1=true;
        l2=true;
        std::cout<<"Enter two remainders from Zn:\n";
        std::cin>>v[0]>>v[1];
        if(v[0]<0 || v[0]>n-1){
            l1=false;
            std::cout<<"First remainder is out of range! Try again!\n";
        }
        if(v[1]<0 || v[1]>n-1){
            l2=false;
            std::cout<<"Second remainder is out of range! Try again!\n";
        }
    } while(l1 == false || l2==false);
    return v;
}

