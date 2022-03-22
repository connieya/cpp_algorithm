#include "stdio.h"
#include "stdlib.h"

void MergeSort(int dataSet[] , int startIndex , int endIndex);
void Merge(int [] , int ,int ,int);

void MergeSort(int dataSet[] , int startIndex , int endIndex) {
    int middleIndex;
    if (endIndex-startIndex < 1) return;
    middleIndex = (startIndex+endIndex)/2;

    MergeSort(dataSet,startIndex,middleIndex);
    MergeSort(dataSet,middleIndex+1,endIndex);
    Merge(dataSet,startIndex ,middleIndex,endIndex);
}

void Merge(int dataSet[] , int startIndex , int middleIndex , int endIndex) {
    int i;
    int leftIndex = startIndex;
    int rightIndex = middleIndex+1;
    int destIndex = 0;

    int * destination = (int *) malloc(sizeof(int) *(endIndex-startIndex+1));
    while (leftIndex <= middleIndex && rightIndex <= endIndex) {
        if (dataSet[leftIndex] < dataSet[rightIndex]) {
            destination[destIndex] = dataSet[leftIndex];
            leftIndex++;
        }else {
            destination[destIndex] = dataSet[rightIndex];
            rightIndex++;
        }
        destIndex++;
    }
    while (leftIndex <= middleIndex) {
        destination[destIndex++] = dataSet[leftIndex++];
    }
    while (rightIndex <= endIndex) {
        destination[destIndex++] = dataSet[rightIndex++];
    }
    destIndex = 0;
    for (i= startIndex; i<=endIndex; i++){
        dataSet[i] = destination[destIndex++];
    }
    free(destination);
}

int main()
{
    int dataSet[] = {334,6,4,2,3,1,5,117,12,34};
    int len = sizeof(dataSet) / sizeof(dataSet[0]);
    int i = 0;
    MergeSort(dataSet,0,len-1);
    for( i = 0; i < len; ++i) {
        printf("%d " , dataSet[i]);
    }
    printf("\n");

    return 0;
}