/*
 * File: stats.h
 * Declaration of statistical funcions for an char array
 *
 * Header file with declarations and descriptions of the functions used for statistical analyses of an array of unsigned char elements.
 *
 * Author: Jakub Mihalik
 * Created on: 23.6.2021
 * Last update: 23.6.2021
 */

#ifndef _STATS_H_
#define _STATS_H_

void print_statistics(unsigned char* arr,int length);
/* Prints out the statistics of an array
 * 
 * <unsigned char* arr> - poiter to the char array storing values
 */

void print_array(unsigned char* arr,int length);
/* Given an array and length of the array, prints the array
 *
 * <unsigned char* arr> - poiter to the char array storing values
 * <int length> - length of the array
 * */

unsigned char find_median(unsigned char* arr,int length);
/* Given an array and length of the array, returns median value
 *
 * <unsigned char* arr> - poiter to the char array storing values
 * <int length> - length of the array
 */

unsigned char find_mean(unsigned char* arr,int length);
/* Given an array and length of the array, returns mean value
 * 
 * <unsigned char* arr> - poiter to the char array storing values
 * <int length> - length of the array
 * */

unsigned char find_max(unsigned char* arr,int length);
/* Given an array and length of the array, returns maximal value
 * 
 * <unsigned char* arr> - poiter to the char array storing values
 * <int length> - length of the array
 * */

unsigned char find_min(unsigned char* arr,int length);
/* Given an array and length of the array, returns minimal value
 * 
 * <unsigned char* arr> - poiter to the char array storing values
 * <int length> - length of the array
 * */

void sort_array(unsigned char* arr,int length);
/* Given an array of a given length sorts in the way defined by a compare function 
 *  
 * <unsigned char* arr> - poiter to the char array storing values
 * <int length> - length of the array
 * */

int compare(const void* a,const void* b);
/* Compares two elements of the array we want to sort out in the descending order
 * return<0 --> a<b
 * return=0 --> a=b
 * return>0 --> a>b
 *
 * <const void* a> - elements of the array we compare
 * */


#endif
