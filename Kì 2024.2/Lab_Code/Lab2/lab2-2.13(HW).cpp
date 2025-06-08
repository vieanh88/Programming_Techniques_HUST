#include <bits/stdc++.h>
using namespace std;

// Cau truc luu so lon co dau va mang ky tu chua chu so
struct bigNum {
    char sign;      // luu dau so: '1' la duong, '0' la am
    char num[101];  // luu chu so, chua toi da 101 chu so
};

// Ham nhap hai so lon tu ban phim
void input(bigNum &num1_07, bigNum &num2_07) {
    string tmp;
    // nhap so thu nhat
    cin >> tmp;
    num1_07.sign = tmp[0];                    // gan dau tu ky tu dau
    int lens1 = tmp.length() - 1;             // do dai phan chu so
    // chuyen cac chu so vao cuoi mang
    for (int i = 0; i < lens1; i++) {
        num1_07.num[100 - lens1 + i + 1] = tmp[i + 1];
    }
    // phan chua chu so con lai gan '0'
    for (int i = 0; i < 100 - lens1 + 1; i++)
        num1_07.num[i] = '0';

    // nhap so thu hai, tuong tu
    cin >> tmp;
    num2_07.sign = tmp[0];
    int lens2 = tmp.length() - 1;
    for (int i = 0; i < lens2; i++) {
        num2_07.num[100 - lens2 + i + 1] = tmp[i + 1];
    }
    for (int i = 0; i < 100 - lens2 + 1; i++)
        num2_07.num[i] = '0';
}

// Ham cong hai mang ky tu chua so
void add(char res[], char *num1, char *num2) {
    int c = 0;  // bien nho cho phep
    for (int i = 100; i >= 0; i--) {
        int tmp = (num1[i] - '0') + (num2[i] - '0') + c;
        c = tmp / 10;
        res[i] = (tmp % 10) + '0';
    }
}

// Ham tru num2 tu num1 (num1 >= num2)
void sub(char res[], char *num1, char *num2) {
    int c = 0;  // bien muon muon
    for (int i = 100; i >= 0; i--) {
        int t1 = num1[i] - '0';
        int t2 = num2[i] - '0';
        if (t1 >= t2 + c) {
            res[i] = (t1 - t2 - c) + '0';
            c = 0;
        } else {
            t1 += 10;
            res[i] = (t1 - t2 - c) + '0';
            c = 1;
        }
    }
}

// Ham nhan hai so lon
void multi(char res[], char *num1, char *num2) {
    // khoi tao ket qua la 0
    for (int i = 0; i < 101; i++) res[i] = '0';

    // nhan tung chu so num1 voi toan bo num2
    for (int i = 100; i >= 0; i--) {
        char tmp[101];
        int k;
        // dua cac so 0 can le phai
        for (k = 0; k < i; k++)
            tmp[100 - k] = '0';

        int c = 0, sum = 0;
        // nhan tung chu so
        for (int j = 100; j >= 0; j--) {
            sum = (num1[i] - '0') * (num2[j] - '0') + c;
            tmp[k] = (sum % 10) + '0';
            c = sum / 10;
            k--;
            if (k < 0) break;
        }
        // cong vao ket qua hien tai
        add(res, tmp, res);
    }
}

// Ham so sanh num1 va num2, tra ve true neu num1 >= num2
bool check(char *num1, char *num2) {
    int i1, i2;
    // tim vi tri chu so khac 0 dau tien
    for (i1 = 0; i1 < 101; i1++) if (num1[i1] != '0') break;
    for (i2 = 0; i2 < 101; i2++) if (num2[i2] != '0') break;

    if (i1 > i2) return false;
    else if (i1 < i2) return true;
    else {
        int i = i1;
        while (i < 101) {
            if (num1[i] < num2[i]) return false;
            else if (num1[i] > num2[i]) return true;
            i++;
        }
    }
    return true;
}

// Nap toan tu cong cho bigNum
bigNum operator+(bigNum num1, bigNum num2) {
    bigNum res;
    if (num1.sign == '1' && num2.sign == '1') {
        res.sign = '1'; add(res.num, num1.num, num2.num);
    } else if (num1.sign == '1' && num2.sign == '0') {
        if (check(num1.num, num2.num)) { res.sign = '1'; sub(res.num, num1.num, num2.num); }
        else { res.sign = '0'; sub(res.num, num2.num, num1.num); }
    } else if (num1.sign == '0' && num2.sign == '1') {
        if (check(num1.num, num2.num)) { res.sign = '0'; sub(res.num, num1.num, num2.num); }
        else { res.sign = '1'; sub(res.num, num2.num, num1.num); }
    } else {
        res.sign = '0'; add(res.num, num1.num, num2.num);
    }
    return res;
}

// Nap toan tu tru cho bigNum
bigNum operator-(bigNum num1, bigNum num2) {
    bigNum res;
    if (num1.sign == '1' && num2.sign == '0') { num2.sign = '1'; res = num1 + num2; }
    else if (num1.sign == '1' && num2.sign == '1') { num2.sign = '0'; res = num1 + num2; }
    else if (num1.sign == '0' && num2.sign == '1') { num2.sign = '0'; res = num1 + num2; }
    else { num2.sign = '1'; res = num1 + num2; }
    return res;
}

// Nap toan tu nhan cho bigNum
bigNum operator*(bigNum num1, bigNum num2) {
    bigNum res;
    // neu dau so giong nhau thi duong, khac thi am
    res.sign = ((num1.sign == num2.sign) ? '1' : '0');
    multi(res.num, num1.num, num2.num);
    return res;
}

// Ham in bigNum ra man hinh
void printBigNumber(bigNum number) {
    cout << number.sign;                // in dau
    int start;
    // tim vi tri chu so dau tien khac 0
    for (start = 0; start < 101; start++)
        if (number.num[start] != '0') break;
    // in cac chu so tu start den cuoi
    for (int i = start; i < 101; i++)
        cout << number.num[i];
}

//Ho va ten Nguyen Viet Anh
//MSSV: 20215307

int main() {
    // thong tin sinh vien
    printf("Ho va ten: Nguyen Viet Anh\n");
    printf("MSSV: 20215307\n");

    // dinh nghia va nhap hai so lon
    bigNum num1_07, num2_07;
    input(num1_07, num2_07);

    // khoi tao so 3 va so 4 de tinh bieu thuc
    bigNum so3_07, so4_07;
    so3_07.sign = '1'; so4_07.sign = '1';
    for (int i = 0; i < 100; i++) {
        so3_07.num[i] = '0';
        so4_07.num[i] = '0';
    }
    so3_07.num[100] = '3';
    so4_07.num[100] = '4';

    // tinh bieu thuc: num1_07 * num2_07 - 3 * num1_07 + 4 * num2_07
    bigNum res_07 = num1_07 * num2_07 - so3_07 * num1_07 + so4_07 * num2_07;

    // in ket qua
    printBigNumber(res_07);
    return 0;
}
// BTVN 2.13 - Nguyen Viet Anh - 5307
