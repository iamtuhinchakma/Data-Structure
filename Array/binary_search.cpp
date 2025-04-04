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
    for(int i = 0; i < n; i++)  cout << arr[i] << ' ';
    cout << endl;
    int item;
    cin >> item;
    int left = 0, right = n - 1;
    bool found = false;
    while(left <= right){
        int middle = left + (right - left) / 2;
        if(arr[middle] == item){
            cout << "Item found on index: " << middle << endl;
            found = true;
            break;
        } else if(arr[middle] < item){
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    if(!found) cout << "Item not found\n";
    return 0;
}