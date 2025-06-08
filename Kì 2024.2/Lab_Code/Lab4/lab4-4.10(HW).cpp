#include<bits/stdc++.h>
using namespace std;

// Bien toan cuc
int n_07, q_07;
vector<vector<string>> doc_07; // Luu tru danh sach tai lieu
vector<vector<string>> word_07; // Luu tru danh sach tu can tim kiem
vector<int> f_max_07; // Luu tru tan so tu lon nhat trong tung tai lieu
map<string, int> df_07; // Luu tru so tai lieu chua tu khoa
map<pair<string, int>, int> fe_07; // Luu tru tan so xuat hien cua tu trong tai lieu

// Ham tach chuoi thanh cac tu
vector<string> split_string(string str);

// Ham xu ly tien xu ly du lieu
void pre();

//Ho va ten: Nguyen Viet Anh
//MSSV: 20215307

// Ham nhap du lieu
void input() {
    vector<string> doc_raw; // Luu tam thoi cac tai lieu
    vector<string> word_raw; // Luu tam thoi cac tu can tim

    cin >> n_07; // Nhap so luong tai lieu
    string tmp;
    getline(cin, tmp); // Doc bo dong trong

    for(int i = 0; i < n_07; i++) {
        string tmp;
        getline(cin, tmp); // Doc tung tai lieu
        doc_raw.push_back(tmp);
    }

    cin >> q_07; // Nhap so luong tu can tim
    getline(cin, tmp); // Doc bo dong trong
    for(int i = 0; i < q_07; i++) {
        string tmp;
        getline(cin, tmp); // Doc tung tu can tim
        word_raw.push_back(tmp);
    }

    // Tach chuoi tai lieu va tu can tim thanh cac tu don
    for(string d : doc_raw) {
        doc_07.push_back(split_string(d));
    }
    for(string w : word_raw) {
        word_07.push_back(split_string(w));
    }
}

// Ham tach chuoi thanh cac tu don
vector<string> split_string(string str) {
    vector<string> split_stringg;

    while (!str.empty()) {
        string tmp = str.substr(0, str.find(',')); // Tach chuoi den dau phay
        int pos = str.find(' '); // Tim vi tri dau cach
        int position = str.find(',');
        if(pos > tmp.size())
            split_stringg.push_back(tmp); // Them tu vao vector
        else {
            while(pos <= tmp.size()) {
                tmp.erase(pos, 1); // Xoa dau cach
                pos = tmp.find(" ");
            }
        }
        if(position > str.size()) {
            break;
        } else {
            str.erase(0, position + 1); // Xoa phan da tach khoi chuoi goc
        }
    }

    return split_stringg;
}

// Ham tinh tan so xuat hien cua tu trong tai lieu
int fre(string word_s, int i) {
    if(fe_07.find({word_s, i}) != fe_07.end()) {
        return fe_07[{word_s, i}];
    }

    int index = 0;
    vector<string> str_tmp = doc_07[i];

    for(string v : str_tmp) {
        if(word_s == v) index++;
    }

    fe_07.insert({{word_s, i}, index});
    return index;
}

// Ham dem so luong tai lieu chua tu
int count(string word_use) { 
    if(df_07.find(word_use) != df_07.end()) {
        return df_07[word_use];
    }
    int index = 0;
    for(vector<string> str_tmp : doc_07) {
        vector<string>::iterator ite = find(str_tmp.begin(), str_tmp.end(), word_use);
        if(ite != str_tmp.end()) {
            index++;
        }
    }

    df_07.insert({word_use, index});
    return index;
}

// Ham tien xu ly du lieu
void pre() {
    for(vector<string> word_str : doc_07) {
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
        f_max_07.push_back(max_f); // Them tan so lon nhat vao vector
    }
}

// Ham tim kiem tai lieu phu hop nhat voi danh sach tu can tim
int search_engine(vector<string> list_word) {
    double score_max = -1000;
    int predict_label = -1;
    for(int i = 0; i < n_07; i++) {
        vector<string> list_word_train_doc = doc_07[i];
        double score = 0;
        for(string word_tmp : list_word) {
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word_tmp) == list_word_train_doc.end()) {
                continue;
            } else {
                int ftd = fre(word_tmp, i);
                int dft = count(word_tmp);
                int maxfd = f_max_07[i];
                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n_07 / dft);
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
    input(); // Nhap du lieu
    pre(); // Tien xu ly du lieu
    int i = 0;
    while(i < q_07) {
        cout << search_engine(word_07[i]) << endl; // In ket qua tim kiem cho tung tu
        i++;
    }
    return 0;
}
