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

    int pos;
    cin >> pos;
    for(int i = pos - 1; i < n; i++)
        arr[i] = arr[i + 1];
    n--;
    
    for(int i = 0; i < n; i++)  cout << arr[i] << ' ';
    cout << endl;    
    return 0;
}