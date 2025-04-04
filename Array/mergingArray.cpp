#include <bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    int arr[n + m];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    for(int i = 0; i < m; i++)  
        cin >> arr2[i];

    for(int i = 0; i < n; i++)  cout << arr1[i] << ' ';
    cout << endl;
    for(int i = 0; i < m; i++)  cout << arr2[i] << ' ';
    cout << endl;

    for(int i = 0; i < n; i++)
        arr[i] = arr1[i];
    
    int j = 0;
    for(int i = n; i < n + m; i++){
        arr[i] = arr2[j];
        j++;
    }
    for(int i = 0; i < n + m; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}