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
	while(cin >> k >> v){ //Doc gia tri vao k va v cho den khi khong hop le hoac gap so am  
		if(k <0 || v < 0) break; 
		T tmp; //bien cau truc tam thoi kieu T 
		tmp.key = k;
		tmp.value = v;
		list.push_back(tmp); //Day vao vector list  
	} 
	sort(list.begin(), list.end(), [](T a, T b){
		if(a.value > b.value ) return true; //Sap xep theo value giam dan  
		else if(a.value < b.value ) return false;
		else return a.key >= b.key; 
	});
	for(unsigned int i=0; i < list.size(); i++){
		cout << list[i].key << " " << list[i].value << endl; 
	} 
	return 0; 
}

