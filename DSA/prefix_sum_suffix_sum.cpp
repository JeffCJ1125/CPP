#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    vector<int> arr;
    for(int i = 0; i < 4; i++){
        arr.push_back(i);
    }

    int n = arr.size();

    vector<int> prefix_sum(n,0);
    prefix_sum[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix_sum[i] = arr[i] + prefix_sum[i-1];
    }

    vector<int> suffix_sum(n,0);
    suffix_sum[n-1] = arr.back();
    for(int i = n-2; i >= 0; i--){
        suffix_sum[i] = suffix_sum[i+1] + arr[i];
    }
    cout << "arr : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "prefix_sum : ";
    for(int i = 0; i < n; i++){
        cout << prefix_sum[i] << " ";
    }
    cout << endl;
    cout << "suffix_sum : ";
    for(int i = 0; i < n; i++){
        cout << suffix_sum[i] << " ";
    }
    cout << endl;
}