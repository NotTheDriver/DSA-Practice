#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *sec=new int[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        sec[i]=arr[k++];
    }
    //merging
    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2<len2){
        if(first[index1]>sec[index2]){
            arr[k++]=sec[index2++];
        }
        else{
            arr[k++]=first[index1++];
        }
    }
    while(index1<len1){
        arr[k++]=first[index1++];
    }
    while(index2<len2){
        arr[k++]=sec[index2++];
    }
    delete []first;
    delete []sec;
}

void mergeSort(int *arr,int s, int e){
    if(s>=e) return;
    int mid=s+(e-s)/2;
    //left side sort
    mergeSort(arr,s,mid);
    //right side
    mergeSort(arr,mid+1,e);
    //merging the 2 sorted arrays
    merge(arr,s,e);
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}