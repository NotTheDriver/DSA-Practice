#include<iostream>
using namespace std;
bool is_Sorted(int *arr,int size){
    if(size==0||size==1){
        return 1;
    }
    else{
        if(arr[0]>arr[1]){
            return 0;
        }
        return is_Sorted(arr+1,size-1);
    }
}
int getSum(int *arr, int size){
    if(size==0){
        return 0;
    }
    int sum=arr[0]+getSum(arr+1,size-1);
    return sum;
}
bool linearSearch(int arr[],int size,int element){
    if(size==0){
        return false;
    }
    if(arr[0]==element){
        return true;
    }
    else{
        return linearSearch(arr+1,size-1,element);
    }
}
bool binarySearch(int arr[],int s,int e,int key){
    if(s>e){
        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    else{
        if(arr[mid]>key){
            return(binarySearch(arr,s,mid-1,key));
        }
        if(arr[mid]<key){
            return(binarySearch(arr,mid+1,e,key));
        }
    }

}
int main(){
    int n=5;
    cin>>n;
    int *arr=new int[n]; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"enter the element";
    cin>>k;
    // cout<<linearSearch(arr,n,k);
    cout<<binarySearch(arr,0,n,k);
    



    // int sum=getSum(arr,n);
    // cout<<"sum is "<<sum;
    // cout<<"The Array is "<<is_Sorted(arr,n)<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<endl;
    // }
    return 0;
}