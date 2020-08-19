#include <iostream>
using namespace std;

int palindrome(int number) {
	int num = number;
	int dummy = 0;
	int rem =0;
	while(num != 0) {
  		rem = num % 10;
  		dummy = dummy * 10;
  		dummy = dummy + rem;
   	num = num / 10;
	}
	return dummy;
}

int main() {
	int number;
	cout << " \n Enter Number = ";
	cin >> number;
	int dummy = palindrome(number);
	(dummy == number) ? cout << " \n Number is palindrome": cout << "\n Number is not palindrome";
}
