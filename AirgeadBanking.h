#ifndef AIRGEADBANKING_H
#define AIRGEADBANKING_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// declares the AirgeadBanking class
class AirgeadBanking {
	public:
		AirgeadBanking();
		void SetData();
		void BalanceWithoutMothnlyDeposit();
		void BalanceWithMonthlyDeposit();

    protected:
		double initialInvestment;
		double monthlyDeposit;
		double anualInterest;
		double years;
		double months;
		double totalBalance;
		double totalInterest;
		double yearlyInterest;


};

#endif 
