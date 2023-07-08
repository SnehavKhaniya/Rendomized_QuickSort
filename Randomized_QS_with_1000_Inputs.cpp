#include <bits/stdc++.h>
using namespace std;


int Partition(int arr[], int p, int r, int &count){
    int x = arr[r];
    int i = p - 1;
    int j;

    for(j = p; j <= r - 1; ++j){
        count++;                                    //to see how many times it running.
        if(arr[j] <= x){
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}



int Randomized_Partition(int arr[], int p, int r, int &count){
    srand(time(NULL));
    int i = p + rand() % (r - p + 1);
    cout << "Random no.: " << i << endl;

    swap(arr[i], arr[r]);

    return Partition(arr, p, r, count);

}

void QS(int arr[], int p, int r, int &count){
    
    if(p < r){
        int q = Randomized_Partition(arr, p, r, count);
        QS(arr, p, q - 1, count);
        QS(arr, q + 1, r, count);
    }
}

int main(){

    int n = 1000;

    int arr[n];
    
    for(int i = 0; i < n; ++i){             //already sorted array
        arr[i] = i;
    }

    int count = 0;

    QS(arr, 0, n - 1, count);

    cout << "Sorted array: ";

    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << "\n" << "Count: " << count;


    return 0;
}
