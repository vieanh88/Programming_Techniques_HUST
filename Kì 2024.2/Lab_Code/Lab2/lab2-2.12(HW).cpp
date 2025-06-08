#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//Cau truc T gom cap khoa va gia tri  
struct T{
	int key;
	int value; 
}; 
//Ho va ten Nguyen Viet Anh
//MSSV: 20215307
vector<T> list; //Vector list luu tru các phan tu co kieu du lieu la T 
int main(){
	printf("Ho va ten: Nguyen Viet Anh\n");
	printf ("MSSV: 20215307\n");
int k, v; 
	while(cin >> k >> v){
		T tmp; //bien cau truc tam thoi kieu T 
		tmp.key = k;
		tmp.value = v;
		list.push_back(tmp); //Day vao vector list  
	} 
	sort(list.begin(), list.end(), [](T a, T b){
		if(a.value > b.value ) return true; //Sap xep theo value giam dan v lon hon thi dung trc
		else if(a.value < b.value ) return false; //v nho hon thi dung sau
		else return a.key >= b.key; // v bang nhau thi k lon hon dung trc
	});
	for(unsigned int i=0; i < list.size(); i++){
		cout << list[i].key << " " << list[i].value << endl; 
	} 
	return 0; 
}
// BTVN 2.12 - Nguyen Viet Anh - 5307
