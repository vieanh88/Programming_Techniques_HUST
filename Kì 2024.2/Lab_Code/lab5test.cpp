#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct chibo {
	string TenCB_anhnv_5307;
	string Diachi_anhnv_5307;
	int sodangvien_anhnv_5307;
	string luongtoithieu_anhnv_5307;
	double tongluong_anhnv_5307;
	double tongDangPhithu_anhnv_5307;
	double Chibogiulai_anhnv_5307; //chi bộ giữ lại 30% số tiền đảng phí thu được
	double Nopcaptren_anhnv_5307; //chi bộ nộp cấp trên 70% số tiền đảng phí thu được
};

struct dangvien {
	string sothedv_anhnv_5307;
	string tendangvien_anhnv_5307;
	int namvaodang_anhnv_5307;
	string chucvudang_anhnv_5307;
	double HeSLuong_anhnv_5307;
	double Luong_anhnv_5307; //lương = lương tối thiểu * hệ số lương
	double dangphi_anhnv_5307; //đảng phí = 1% lương
	double tienphucap_anhnv_5307;
    double phaidong_anhnv_5307;
	double tongluong_anhnv_5307;
};


int main() {
	
    //In menu chương trình
    //1. Nhập dữ liệu
    //2. Xuát dữ liệu
    //3. Thoát chương trình

    int n_chibo_anhnv_5307;
    // Nhập số lượng chi bộ
	cin >> n_chibo_anhnv_5307;

    // Khởi tạo mảng chi bộ
	chibo *chibo_anhnv_5307 = new chibo[n_chibo_anhnv_5307];
    for (int i = 0; i < n_chibo_anhnv_5307; i++) {
        cout << "Tên chi bộ: ";
        getline(cin, chibo_anhnv_5307[i].TenCB_anhnv_5307);
        cout << "Địa chỉ: ";
        getline(cin, chibo_anhnv_5307[i].Diachi_anhnv_5307);
        cout << "Số đảng viên: ";
        getline(cin, chibo_anhnv_5307[i].sodangvien_anhnv_5307);
        cout << "Lương tối thiểu: ";
        getline(cin, chibo_anhnv_5307[i].luongtoithieu_anhnv_5307);
        chibo_anhnv_5307[i].tongluong_anhnv_5307 = 0; // Khởi tạo tổng lương
        chibo_anhnv_5307[i].tongDangPhithu_anhnv_5307 = 0; // Khởi tạo tổng đảng phí thu

        int n_dangvien_anhnv_5307 = chibo_anhnv_5307[i].sodangvien_anhnv_5307;
        dangvien *dangvien_anhnv_5307 = new dangvien[n_dangvien_anhnv_5307];
        
        for (int j = 0; j < n_dangvien_anhnv_5307; j++) {
            cout << "Số thẻ đảng viên: ";
            getline(cin, dangvien_anhnv_5307[j].sothedv_anhnv_5307);
            cout << "Tên đảng viên: ";
            getline(cin, dangvien_anhnv_5307[j].tendangvien_anhnv_5307);
            cout << "Năm vào đảng: ";
            getline(cin, dangvien_anhnv_5307[j].namvaodang_anhnv_5307);
            cout << "Chức vụ đảng: ";
            getline(cin, dangvien_anhnv_5307[j].chucvudang_anhnv_5307);
            cout << "Hệ số lương: ";
            getline(cin, dangvien_anhnv_5307[j].HeSLuong_anhnv_5307);
        }
        // Tính lương, đảng phí và tổng lương cho từng đảng viên
        // Lương = lương tối thiểu * hệ số lương
        // Đảng phí = 1% lương
        for (int j = 0; j < n_dangvien_anhnv_5307; j++) {
            dangvien_anhnv_5307[j].Luong_anhnv_5307 = stod(chibo_anhnv_5307[i].luongtoithieu_anhnv_5307) * dangvien_anhnv_5307[j].HeSLuong_anhnv_5307;
            dangvien_anhnv_5307[j].dangphi_anhnv_5307 = 0.01 * dangvien_anhnv_5307[j].Luong_anhnv_5307;
            dangvien_anhnv_5307[j].tongluong_anhnv_5307 = dangvien_anhnv_5307[j].Luong_anhnv_5307 + dangvien_anhnv_5307[j].tienphucap_anhnv_5307;

            // tienphucap - BT: 'BiThu': 0,05 * luong
            // tienphucap - PBT: 'PhoBT': 0,03 * luong
            // tienphucap - DV: 'Dvien': 0
            if (dangvien_anhnv_5307[j].chucvudang_anhnv_5307 == "BiThu") {
                dangvien_anhnv_5307[j].tienphucap_anhnv_5307 = 0.05 * dangvien_anhnv_5307[j].Luong_anhnv_5307;
            } else if (dangvien_anhnv_5307[j].chucvudang_anhnv_5307 == "PhoBT") {
                dangvien_anhnv_5307[j].tienphucap_anhnv_5307 = 0.03 * dangvien_anhnv_5307[j].Luong_anhnv_5307;
            } else {
                dangvien_anhnv_5307[j].tienphucap_anhnv_5307 = 0;
            }
        }
        // Cập nhật tổng lương và tổng đảng phí thu cho chi bộ
        for (int j = 0; j < n_dangvien_anhnv_5307; j++) {
            chibo_anhnv_5307[i].tongluong_anhnv_5307 += dangvien_anhnv_5307[j].tongluong_anhnv_5307;
            chibo_anhnv_5307[i].tongDangPhithu_anhnv_5307 += dangvien_anhnv_5307[j].dangphi_anhnv_5307;
        }
    }
        
    // Hiển thị thông tin chi bộ và đảng viên
    for (int i = 0; i < n_chibo_anhnv_5307; i++) {
        cout << "Tên chi bộ: " << chibo_anhnv_5307[i].TenCB_anhnv_5307 << "\t"
        << "Địa chỉ: " << chibo_anhnv_5307[i].Diachi_anhnv_5307 << "\t"
        << "Số đảng viên: " << chibo_anhnv_5307[i].sodangvien_anhnv_5307 << endl;
        
        cout << "Tổng lương: " << chibo_anhnv_5307[i].tongluong_anhnv_5307 << "\t"
        << "Tổng thu đảng phí(1% Tổng lương): " << chibo_anhnv_5307[i].tongDangPhithu_anhnv_5307 << endl;

        cout << "Trích chi bộ (30% tổng thu ĐP): " << chibo_anhnv_5307[i].Chibogiulai_anhnv_5307 << "\t"
        << "Nộp cấp trên (70% tổng thu ĐP): " << chibo_anhnv_5307[i].Nopcaptren_anhnv_5307 << endl;

        int n_dangvien_anhnv_5307 = chibo_anhnv_5307[i].sodangvien_anhnv_5307;
        dangvien *dangvien_anhnv_5307 = new dangvien[n_dangvien_anhnv_5307];
        
        for (int j = 0; j < n_dangvien_anhnv_5307; j++) {
            cout << "TT: " << j + 1 << "\t"
            << "Mã thẻ đảng: " << dangvien_anhnv_5307[j].sothedv_anhnv_5307 << "\t"
            << "Họ và tên: " << dangvien_anhnv_5307[j].tendangvien_anhnv_5307 << "\t"
            << "Tuổi đảng: " << dangvien_anhnv_5307[j].namvaodang_anhnv_5307 << "\t"
            << "CV đảng: " << dangvien_anhnv_5307[j].chucvudang_anhnv_5307 << "\t"
            << "Hes luong: " << dangvien_anhnv_5307[j].HeSLuong_anhnv_5307 << "\t"
            << "Lương: " << dangvien_anhnv_5307[j].Luong_anhnv_5307 << "\t"
            << "Đảng phí: " << dangvien_anhnv_5307[j].dangphi_anhnv_5307 << "\t"
            << "Phucap: " << dangvien_anhnv_5307[j].tienphucap_anhnv_5307 << "\t"
            << "Tong Luong: " << dangvien_anhnv_5307[j].tongluong_anhnv_5307 << endl;
            // Cập nhật tổng lương và tổng đảng phí thu cho chi bộ
            chibo_anhnv_5307[i].tongluong_anhnv_5307 += dangvien_anhnv_5307[j].tongluong_anhnv_5307;
            chibo_anhnv_5307[i].tongDangPhithu_anhnv_5307 += dangvien_anhnv_5307[j].dangphi_anhnv_5307;
        }
    }
    return 0;
}