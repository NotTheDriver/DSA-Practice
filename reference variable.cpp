#include <iostream>
using namespace std;
int main(){
    /*int i=6;
    int &j=i;
    i++;
    j++;
    cout<<i<<endl<<j;*/
    int n;
    int m;
    cin>>n;
    cin>>m;
    int **arr= new int*[n];
    for(int i=0;i<m;i++){
        arr[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<endl;
        }
    }

    return 0;
}