#ifndef modLab_hpp
#define modLab_hpp

#include <stdio.h>

int createZn(int*,int);

int fillZn(int*,int);

int sumRemainders(int,int,int);

int substractRemainders(int,int,int);

int multiplyRemainders(int,int,int);

int checkForReciprocal(int**,int,int);

int reciprocalRemainder(int**,int);

int basicEuclideanAlgorithm(int,int);

int reciprocalRemainderByIndentityOfBesuAndBEA(int,int);

int divisionOfRemainders(int,int,int);

int gradationOfRing(int*,int,int);

int grading(int,int,int);

int binaryGrading(int*,int,int);

int gradationBinaryMethod(int,int,int);

int* enteringTwoNum(int*,int);

bool checkForPrimitiveRoot(int,int);

int primitiveRoots(int);

bool isItResidualField(int);

int allocateDarr(int**,int);

int dellocateArr(int*);

int dellocateDarr(int**,int);

int printArray(int*,int);

int enteringOneNum(int,int);

#endif /* modLab_hpp */
