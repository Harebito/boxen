#include <iostream>

using namespace std;

void* func(void** arr, int n, int size, int x, int y){
    void* ptr= nullptr;
    if (x>=0 && x<n-y && y>=0 && y<n){
        ptr=(char*)arr[y]+x*size;
    }
    return ptr;
}

int main() {
    int n=5;
    int size=sizeof(int);

    int** arr= new int*[n];
    for (int i=0; i<n;i++){
    arr[i]=new int[n];
    }
    int it=0;
    for (int i=0; i<n;i++){
        for (int j=0; j<n-i; j++){
            arr[i][j]=it;
            it++;
        }
    }


    void* a = func((void**)arr, n, size, 2,1);
    if (a!= nullptr){
        cout<<*(int*)a<<endl;
    }
    else{
        cout<<"nullptr"<<endl;
    }
    for (int i=0; i<n;i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
