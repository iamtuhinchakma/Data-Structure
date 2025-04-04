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
    for(int i = 0; i < n; i++)  cout << arr[i] << ' ';
    cout << endl;
    int item;
    cin >> item;
    bool found = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == item){
            found = true;
            cout << "Item has found at index: " << i << endl;
            break;
        }
    }
    if(!found) cout << "Item not found\n";
    return 0;
}