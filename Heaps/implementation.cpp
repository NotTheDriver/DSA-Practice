#include<iostream>
using namespace std;
class heap{
    public:
        int arr[100];
        int size;
        heap(){
            arr[0]=-1;
            size=0;
        }
        void insert(int val){
            size=size+1;
            int index=size;
            arr[index]=val;
            while(index>1){
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

    void deleteFromHeap(){
        if(size==0){
            cout<<"empty heap, nothing to delete"<<endl;
            return; 
        }
        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size){
            int left=2*i;
            int right=2*i+1;
            if(left<size && arr[left]>arr[i]){
                swap(arr[i],arr[left]);
                i=left;
            }
            else if(right<size && arr[right]>arr[i]){
                swap(arr[i],arr[right]);
                i=right;
            }
            else{
                return;
            }
        }
    }};

void heapify(int arr[], int n, int i){
        int largest=i;
        int left=2*i;
        int right=2*1+1;
        if(left<=n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }

    }    
void heap_sort(int arr[],int n){
            int size=n;
            while(size>1){
                swap(arr[size],arr[1]);
                size--;
                heapify(arr,size,1);
            }
        }
int main(){
   
    int arr[6]={-1,4,10,3,6,2};
    int n=5;
    cout<<"Array before sorting"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }
    heap_sort(arr,5);
    cout<<endl;
    cout<<"Array after sorting"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}