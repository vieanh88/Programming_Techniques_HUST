#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    printf("Ho Va Ten: Nguyen Viet Anh\n");
    printf("MSSV:20215307\n");
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    //# sap xep các vector trong a theo tung các phan tu giam dan
    sort(a.begin(), a.end(), [](vector<int> x, vector<int> y){
            int sum1 = 0;
            for(unsigned int i=0; i<x.size(); i++)
                sum1 += x[i];

            int sum2 = 0;
            for(unsigned int i=0; i<y.size(); i++)
                sum2 += y[i];

            return sum1 > sum2;
         });
//Ho va ten: Nguyen Viet Anh
//MSSV 20215307
    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
