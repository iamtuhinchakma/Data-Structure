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
    for(int i = 0; i < n; i++)  cout << arr[i] << " ";
    cout << endl;
    int data;
    cin >> data;
    //Inserting 54 to a sorted array
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > data){
            pos = i;
            break;
        }
        if(i == n - 1) pos = n;
    }
    // cout << pos << endl;
    for(int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = data;
    n++;
    for(int i = 0; i < n; i++)  cout << arr[i] << " ";
    cout << endl;
    //inserting at sorted array ended here
    //inserting 99 to position 5
    pos = 5;
    for(int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = 99;
    n++;
    for(int i = 0; i < n; i++) cout << arr[i] << " ";


}