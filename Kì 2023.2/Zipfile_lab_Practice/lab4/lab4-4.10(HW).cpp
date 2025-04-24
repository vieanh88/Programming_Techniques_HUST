#include<bits/stdc++.h>
using namespace std;

// Biến toàn cục
int n, q;
vector<vector<string>> doc; // Lưu trữ danh sách tài liệu
vector<vector<string>> word; // Lưu trữ danh sách từ cần tìm kiếm
vector<int> f_max; // Lưu trữ tần số từ lớn nhất trong từng tài liệu
map<string, int> df; // Lưu trữ số tài liệu chứa từ khóa
map<pair<string, int>, int> fe; // Lưu trữ tần số xuất hiện của từ trong tài liệu

// Hàm tách chuỗi thành các từ
vector<string> split_string(string str);

// Hàm xử lý tiền xử lý dữ liệu
void pre();

// Hàm nhập dữ liệu
void input() {
    vector<string> doc_raw; // Lưu trữ tạm thời các tài liệu
    vector<string> word_raw; // Lưu trữ tạm thời các từ cần tìm

    cin >> n; // Nhập số lượng tài liệu
    string tmp;
    getline(cin, tmp); // Đọc bỏ dòng trống

    for(int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp); // Đọc từng tài liệu
        doc_raw.push_back(tmp);
    }

    cin >> q; // Nhập số lượng từ cần tìm
    getline(cin, tmp); // Đọc bỏ dòng trống
    for(int i = 0; i < q; i++) {
        string tmp;
        getline(cin, tmp); // Đọc từng từ cần tìm
        word_raw.push_back(tmp);
    }

    // Tách chuỗi tài liệu và từ cần tìm thành các từ đơn
    for(string d : doc_raw) {
        doc.push_back(split_string(d));
    }
    for(string w : word_raw) {
        word.push_back(split_string(w));
    }
}
//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

// Hàm tách chuỗi thành các từ đơn
vector<string> split_string(string str) {
    vector<string> split_stringg;

    while (!str.empty()) {
        string tmp = str.substr(0, str.find(',')); // Tách chuỗi đến dấu phẩy
        int pos = str.find(' '); // Tìm vị trí dấu cách
        int position = str.find(',');
        if(pos > tmp.size())
            split_stringg.push_back(tmp); // Thêm từ vào vector
        else {
            while(pos <= tmp.size()) {
                tmp.erase(pos, 1); // Xóa dấu cách
                pos = tmp.find(" ");
            }
        }
        if(position > str.size()) {
            break;
        } else {
            str.erase(0, position + 1); // Xóa phần đã tách khỏi chuỗi gốc
        }
    }
    
    return split_stringg;
}

// Hàm tính tần số xuất hiện của từ trong tài liệu
int fre(string word_s, int i) {
    if(fe.find({word_s, i}) != fe.end()) {
        return fe[{word_s, i}];
    }

    int index = 0;
    vector<string> str_tmp = doc[i];

    for(string v : str_tmp) {
        if(word_s == v) index++;
    }

    fe.insert({{word_s, i}, index});
    return index;
}

// Hàm đếm số lượng tài liệu chứa từ
int count(string word_use) { 
    if(df.find(word_use) != df.end()) {
        return df[word_use];
    }
    int index = 0;
    for(vector<string> str_tmp : doc) {
        vector<string>::iterator ite = find(str_tmp.begin(), str_tmp.end(), word_use);
        if(ite != str_tmp.end()) {
            index++;
        }
    }

    df.insert({word_use, index});
    return index;
}

// Hàm tiền xử lý dữ liệu
void pre() {
    for(vector<string> word_str : doc) {
        map<string, int> m;
        int max_f = 0;
        for(string word_tmp : word_str) {
            map<string, int>::iterator ite = m.find(word_tmp);
            if(ite == m.end()) {
                m.insert({word_tmp, 1});
            } else {
                ite->second += 1;
            }
            max_f = max(m[word_tmp], max_f);
        }
        f_max.push_back(max_f); // Thêm tần số lớn nhất vào vector
    }
}

// Hàm tìm kiếm tài liệu phù hợp nhất với danh sách từ cần tìm
int search_engine(vector<string> list_word) {
    double score_max = -1000;
    int predict_label = -1;
    for(int i = 0; i < n; i++) {
        vector<string> list_word_train_doc = doc[i];
        double score = 0;
        for(string word_tmp : list_word) {
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word_tmp) == list_word_train_doc.end()) { // từ này không xuất hiện trong văn bản
                continue;
            } else {
                int ftd = fre(word_tmp, i);
                int dft = count(word_tmp);
                int maxfd = f_max[i];
                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n / dft);
                score += tf_word * idf_word;
            }
        }
        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }
    return predict_label + 1;
}

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    input(); // Nhập dữ liệu
    pre(); // Tiền xử lý dữ liệu
    int i = 0;
    while(i < q) {
        cout << search_engine(word[i]) << endl; // In kết quả tìm kiếm cho từng từ
        i++;
    }
    return 0;
}
