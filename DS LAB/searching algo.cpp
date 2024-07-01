#include<iostream>
using namespace std;
int linear_search(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
void binary_search(int arr[],int key,int n,int s,int e){
    if(s>e){
        cout<<"-1";
        return;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        cout<<mid;
    }
    else if(arr[mid]>key){
        binary_search(arr,key,n,s,mid-1);
    }
    else{
        binary_search(arr,key,n,mid+1,e);
    }
}
void bin_search(int arr[],int key,int n){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==key){
            cout<<mid<<endl;
            return;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    cout<<"-1";
}
int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;
    int arr[size];
    int i=0;
    while(i<size){
        cin>>arr[i];
        i++;
    }
    int k;
    cout<<"enter data to be searched: "<<endl;
    cin>>k;
    bin_search(arr,k,size);
    return 0;

}