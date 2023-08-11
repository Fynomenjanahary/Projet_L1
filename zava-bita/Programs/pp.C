#include <iostream>
using namespace std;
void reference(int& value);
int main(int argc, char* argv[])
{
	cout << "Hello world\n";
	int a=1;
	cout << "Value = " << a << "\n";
	reference(a);
	cout << "Value = " << a << "\n";
	
	return 0;
	
}
void reference(int& value){
	value = 2;
}
