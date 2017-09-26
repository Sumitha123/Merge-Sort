//
//  main.cpp
//  MergeSort
//
//  Created by Sumitha on 5/10/17.
//  Copyright © 2017 Sumitha. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define NUM 1000000
int *a = new int[NUM];
void merge(int,int,int);
void merge_sort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low,int mid,int high)
{
    int h,i,j,k;
    int *b = new int[NUM];
    h=low;
    i=low;
    j=mid+1;
    
    while((h<=mid)&&(j<=high))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h;k<=mid;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=low;k<=high;k++) a[k]=b[k];
}
int main()
{
    for(int count = 0;count <1;count++){
    unsigned long start_s=clock();
    int i;
    
    for(i=1;i<=NUM;i++)
    {
        a[i] = rand() % 100;
    }
    merge_sort(1,NUM);
    //cout<<endl;
    //cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;
    //cout<<endl<<endl;
    
   // for(i=1;i<=NUM;i++)
     //   cout<<a[i]<<"	";
    
   // cout<<endl<<endl<<endl<<endl;
        unsigned long stop_s=clock();
        std :: cout  << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << std :: endl;
        
        //return 0;
    }
    
}
