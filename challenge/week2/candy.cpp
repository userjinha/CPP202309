#include <iostream>
using namespace std;

int main()
{
	int money;
	int candy_price;

	cout << "ÇöÀç °¡Áö°í ÀÖ´Â µ·: ";
	cin >> money;
	cout << "ÄµµðÀÇ °¡°Ý: ";
	cin >> candy_price;


	int n_candies = money / candy_price;
	cout << "Äµµð ±¸ÀÔ ÈÄ ³²Àº µ·=" << money << endl;
	return 0;


}