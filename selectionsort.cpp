#include<bits/stdc++.h>
using namespace std;
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        swap(arr[minIdx],arr[i]);
    }
}
int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    //taking input 
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i<<"  element"<<endl;
        cin>>arr[i];
    }

    cout<<"Before Sorting"<<endl;
    display(arr,n);
    cout<<endl;
    cout<<"After Sorting"<<endl;
    selectionSort(arr,n);
    display(arr,n);



}