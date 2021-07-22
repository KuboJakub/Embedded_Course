/* File: stats.c
 * Main program with definition of the functions for statistical operations
 *
 * Finding max, min, mean, median and sorting an array of unsigned characters.
 *
 *Author: Jakub Mihalik
 * Created on: 24.6.2021
 * Last update: 24.6.2021
 */

#include<stdio.h>
#include<stdlib.h>
#include"stats.h"


/*size of the dataset*/
#define SIZE (40)

int main(){
// array of data
unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

print_statistics(test,SIZE);
/*sort_array(test,SIZE);
        print_array(test,SIZE);
*/




return 0;
}

/*********************************************************************/

/* MEAN OF A DATASET*/
unsigned char find_mean(unsigned char* arr, int length){
	int sum = 0;			// sumation variable
	for(int i=0;i<length;i++){	// sum the array
		sum = (int)*(arr+i)+sum;
	}
return sum/length;			// count and return mean
}

/*FIND MAXIMUM*/
unsigned char find_max(unsigned char* arr,int length){
	unsigned char temp = *arr;	//first value of array as reference
	for(int i=1;i<length;i++){
		if(*(arr+i)>temp){	//comparison for maximum
			temp = *(arr+i);
		}
	}
return temp;
}

/*FIND MINIMUM*/
unsigned char find_min(unsigned char* arr,int length){
	unsigned char temp = *arr;	//first value of array as reference
        for(int i=1;i<length;i++){
                if(*(arr+i)<temp){	//comparison for maximum
                        temp = *(arr+i);
                }
        }
return temp;

}

/*SORT A DATASET*/
void sort_array(unsigned char* arr, int length){
		qsort(arr,length,sizeof(char),compare); //sorting function of stdlib.h
}

/*COMPARE FUNCTION FOR QSORT*/
int compare(const void* a,const void* b){
return (-1)*(int)(*(unsigned char*)a - *(unsigned char*)b); //(-1) for sorting descending
}

/*FIND MEDIAN*/
unsigned char find_median(unsigned char* arr,int length){
	unsigned char temp;
	int* position = (int*)malloc(sizeof(int)); //memory for mosition of the median in an array
	if(length%2==1){	// if odd amount of numbers
		*position = length/2+1;
	}
	else{			// if even amount of numbers
		*position = length/2;
	}
	temp = *(arr+*(position));	//go to median position
        free(position);			//release alocated memory
return temp;
}

/*PRINT ARRAY*/
void print_array(unsigned char* arr,int length){
	int dim = length/8;	//dim rows times 8 columns
	for(int i=0;i<dim;i++){
		for(int j=0;j<8;j++){
			printf("%d\t",*(arr+j+(8*i)));
		}
		printf("\n");
	}
}

/*PRINT STATISTICS*/
void print_statistics(unsigned char* arr,int length){
	printf("Values of the array in the descending order (by rows):\n");
	sort_array(arr,length);
	print_array(arr,length);

	printf("Maximum of the array: %d\n",find_max(arr,length));
	printf("Minimum of the array: %d\n",find_min(arr,length));
	printf("Mean of the array: %d\n",find_mean(arr,length));
	printf("Median of the array: %d\n",find_median(arr,length));
}
