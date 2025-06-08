#include <iostream> 
using namespace std;
struct Node { 
    int data; 
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* q_07 = new Node(data);  // Tạo một node mới với giá trị data
    if(head == NULL) return q_07;
    q_07->next = head;  // Liên kết node mới với head hiện tại
    head = q_07;
    return head;
}
// Ho v� ten: Nguyen Viet Anh
// MSSV: 20215307

// print the list content on a line
void print(Node* head) {
    Node* p_07 = head;
    if(head == NULL) return;  // Nếu danh sách rỗng, thoát khỏi hàm
    while(p_07 != NULL) {
        cout << p_07->data << ' ';  // In giá trị của node hiện tại
        p_07 = p_07->next;  // Di chuyển tới node tiếp theo
    }
    return;
}
// Ho v� ten: Nguyen Viet Anh
// MSSV: 20215307

// return the new head of the reversed list
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
// Ho v� ten: Nguyen Viet Anh
// MSSV: 20215307

int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> u; 
        head = prepend(head, u);
    } 
    
    cout << "Original list: ";
    print(head);

    head = reverse(head);
    cout << endl;
    cout << "Reversed list: ";
    print(head);

    return 0; 
}
