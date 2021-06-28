/*
This program will output the total amount of money earned from compunded interest
with and without a monthly deposit. The user will be asked to enter an initial investment,
a monthly deposit amount, an interest rate, and an amount of yeers to simulate the effects
the the coumpouded interest
Author: Martin Reyes
Date: 06/06/21
*/
#include "AirgeadBanking.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	AirgeadBanking userInvestment;

	userInvestment.SetData();

	cout << endl;
	system("PAUSE");// for the 'press any key to continue'
	cout << endl;

	userInvestment.BalanceWithoutMothnlyDeposit();

	userInvestment.BalanceWithMonthlyDeposit();

	return 0;
}
