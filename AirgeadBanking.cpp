#include "AirgeadBanking.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


AirgeadBanking::AirgeadBanking() {
	double initailInvestment = 0;
	double monthlyDeposit = 0;
	double anuaInterest = 0;
	double years = 0;
	double months = 0;
	double totalBalance = 0;
	double totalInterest = 0;
	double yearlyInterest = 0;
}
// this function prompts the user for input for the initial ivestment amount, 
//monthly deposit, anual interest rate, and number of years
void AirgeadBanking::SetData() {

	cout << "*************************" << endl;
	cout << "********Data Input*******" << endl;
	cout << "Initial Investment Amount: ";
	try {
		cin >> initialInvestment;
		if (initialInvestment < 0) {
			throw runtime_error("Invalid input.");
		}
		cout << "Monthly Deposit: ";
		cin >> monthlyDeposit;
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid input.");
		}
		cout << "Annual Interest: ";
		cin >> anualInterest;
		if (anualInterest < 0) {
			throw runtime_error("Invalid input.");
		}
		cout << "Number of years: ";
		cin >> years;
		if (years < 0) {
			throw runtime_error("Invalid input.");
		}
		months = years * 12;

	}
	catch (runtime_error& excpt) {
		// Prints the error message passed by throw statement
		cout << excpt.what() << endl;
		cout << "must be >= 0" << endl;
	}
}

// this function prints the balance for each year that that
//interest is compunded with out a monthly deposit and formats 
// it in a way that makes it easy to read and understand
void AirgeadBanking::BalanceWithoutMothnlyDeposit() {

	//Set totalBalance = initInv
	totalBalance = initialInvestment;
	//Display year data without monthly deposits
	cout << "\nBalance and Interest Without Additional Monthly Deposits" << endl;
	cout << "==============================================================" << endl;
	cout << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int i = 0; i < years; ++i) {
		//Calculate yearly interest
		totalInterest = (totalBalance) * ((anualInterest / 100));
		//Calculate  totalbalance
		totalBalance = totalBalance + totalInterest;
		//We set fixed and set precision to show only 2 decimal points
		cout << (i + 1) << setw(25) << fixed << setprecision(2) << totalBalance << setw(25) << totalInterest << endl;

	}

}

// this function prints the balance for each year that that
//interest is compunded with a monthly deposit and formats 
// it in a way that makes it easy to read and understand
void AirgeadBanking::BalanceWithMonthlyDeposit() {

	//For monthly
	totalBalance = initialInvestment;
	//Display year data with monthly deposits
	cout << "\n\nBalance and Interest With Additional Monthly Deposits" << endl;
	cout << "==============================================================" << endl;
	cout << "Year" << setw(25) << "Year End Balance" << setw(30) << "Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (int i = 0; i < years; ++i) {
		//Set yearly interest to 0 at the start of each year
		yearlyInterest = 0;
		for (int j = 0; j < 12; ++j) {
			//Calculates total monthly interest
			totalInterest = (totalBalance + monthlyDeposit) * ((anualInterest / 100) / 12);
			//Calculates yearly interest
			yearlyInterest = yearlyInterest + totalInterest;
			//Calculates total balance
			totalBalance = totalBalance + monthlyDeposit + totalInterest;
		}
		cout << (i + 1) << setw(25) << fixed << setprecision(2) << totalBalance << setw(25) << yearlyInterest << endl;


	}
}


