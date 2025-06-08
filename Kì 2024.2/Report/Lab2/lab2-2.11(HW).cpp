#include "iostream"
using namespace std;
//Ho va ten Nguyen Viet Anh
//MSSV: 20215307
int main() {
  int n, m;
	cout << "Ho va ten: Nguyen Viet Anh\n";
	cout << "MSSV: 20215307\n";
	cin >> n; // Nhap bac cua A(x)
	
  int Ax[n + 1]; // Mang luu tru cac he so A(x)
  for (int i = 0; i <= n; i++) {
    cin >> Ax[i]; 
  }
  cin >> m; // Nhap bac da thuc B(x)
  
  int Bx[m + 1]; // Mang luu tru he so da thuc B(x)
  for (int i = 0; i <= m; i++) {
    cin >> Bx[i];
  }

  int res_07[n + m + 1]; // Mang luu tru ket qua khi nhan A(x) va B(x)
  res_07[0] = Ax[0] * Bx[0]; // Tinh toan res[0] = A[0] * B[0]

  int xor_res = res_07[0]; // Bien luu tru XOR cua cac he so C(x)

//Ho va ten Nguyen Viet Anh
//MSSV: 20215307
  for (int i = 1; i <= n + m; i++) {
    res_07[i] = 0; // Tao res[i]
    for (int j = 0; j <= i; j++) {
      if (j <= n && (i - j) <= m) {
        res_07[i] += Ax[j] * Bx[i - j]; // Cong don tïch A[j] * B[i - j] vao res[i]
      }
    }
    xor_res ^= res_07[i]; // Cap nhat XOR sau moi lan tinh toan res[i]
  }
	cout << xor_res << endl; // In ra XOR

  return 0;
}
// BTVN 2.11 - Nguyen Viet Anh - 5307

