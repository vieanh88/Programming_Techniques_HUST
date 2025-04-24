#include <iostream> 
using namespace std;

struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;  // Khởi tạo giá trị data của node
        next = NULL;  // Khởi tạo next là NULL
    }
};

// Thêm một phần tử mới vào đầu danh sách
Node* prepend(Node* head, int data) {
    Node* q = new Node(data);  // Tạo một node mới với giá trị data
    if(head == NULL) return q;
    q->next = head;  // Liên kết node mới với head hiện tại
    head = q;
    return head;
}

// In nội dung của danh sách trên một dòng
void print(Node* head) {
    Node* p = head;
    if(head == NULL) return;  // Nếu danh sách rỗng, thoát khỏi hàm
    while(p != NULL) {
        cout << p->data << ' ';  // In giá trị của node hiện tại
        p = p->next;  // Di chuyển tới node tiếp theo
    }
    return;
}

// Trả về head mới của danh sách đã đảo ngược
Node* reverse(Node* head) {
    if(head == NULL) return NULL;  // Nếu danh sách rỗng, trả về NULL
    if(head->next == NULL) return head;  // Nếu danh sách chỉ có một phần tử, trả về head
    Node* p1 = head;  // Khởi tạo p1 là head
    Node* p2 = head->next;  // Khởi tạo p2 là node thứ hai
    p1->next = NULL;  // Ngắt liên kết của node đầu tiên
    while(p2 != NULL) {
        Node* tmp = p2->next;  // Lưu trữ node tiếp theo
        p2->next = p1;  // Đảo ngược liên kết
        p1 = p2;
        p2 = tmp;
    }
    head = p1;  // Cập nhật head mới
    return head;  // Trả về head mới
}

// Họ và tên: Nguyễn Việtt Anh
// MSSV: 20215307

int main() {
    cout << "Ho va ten: Nguyen Viet Anh\n";
    cout << "MSSV: 20215307\n";
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> u; 
        head = prepend(head, u);  // Thêm phần tử vào đầu danh sách
    } 
    
    cout << "Original list: ";
    print(head);  // In danh sách ban đầu

    head = reverse(head);  // Đảo ngược danh sách
    cout << endl;
    cout << "Reversed list: ";
    print(head);  // In danh sách đã đảo ngược

    return 0; 
}
