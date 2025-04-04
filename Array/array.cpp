#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];
    // for(int i = 0; i < n; i++)  cout << arr[i] << endl;
    //Array Traversing start from here
    int max = arr[0], minValue = arr[0];
    //Finding the maximum value
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << "Maximum Value is: " << max << endl;
    //Finding the minimum value
    for(int i = 0; i < n; i++){
        if(arr[i] < minValue){
            minValue = arr[i];
        }
    }
    cout << "Minimum Value is: " << minValue << endl;
    //Findint the average value
    int sum = 0, avg = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    avg = sum/n;
    cout << "Average value is: " << avg << endl;
    cout << "Total Value is: " << sum << endl;
    cout << "Sin Value of Total is: " << sin(sum) << endl;
    //Traversing end here
    
}