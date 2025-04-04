#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << "Before Swapping: ";
    for(int i = 0; i < n; i++)  cout << arr[i] << ' ';
    cout << endl;

    for(int i = 0; i < n; i++){
        int temp;
        for(int j = i + 1; j < n - 1; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "After swapping: ";
    for(int i = 0; i < n; i++)  cout << arr[i] << ' ';
    cout << endl;    
    return 0;
}