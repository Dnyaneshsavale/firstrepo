#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	cout<<"Enter The String"<<endl;
	cin>>str;
	
	int n=str.length();
	for(int i=0;i<n/2;i++){
		swap(str[i],str[n-1-i]);
	}
	cout<<"Reversed String:"<<str<<endl;
	return 0;
}
