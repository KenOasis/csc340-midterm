//
//  Sales.cpp
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//

#include "Sales.h"
#include <iomanip>
/*
    The empty constructor should be never used in this project since
    we read from.csv file only.
*/
Sales::Sales(){
    gameName = "None";
    platform = "None";
    yearOfRelease = 1900;
    NASales = 0.0;
    JPSales = 0.0;
    EUSales = 0.0;
    otherSales = 0.0;
    globalSales = 0.0;
    id = gameName + platform;
}

Sales::Sales(string gameName, string platform, int yearOfRelease, double NASales, double EUSales, double JPSales, double otherSales, double globalSales){
    this->gameName = gameName;
    this->platform = platform;
    this->yearOfRelease = yearOfRelease;
    this->NASales = NASales;
    this->EUSales = EUSales;
    this->JPSales = JPSales;
    this->otherSales = otherSales;
    this->globalSales = globalSales;
    id = gameName + platform;
}

string Sales::getGameName() const{
    return gameName;
}

string Sales::getPlatform() const{
    return platform;
}

int Sales::getYearOfRelease() const{
    return yearOfRelease;
}

double Sales::getNASales() const{
    return NASales;
}

double Sales::getEUSales() const{
    return EUSales;
}

double Sales::getJPSales() const{
    return JPSales;
}

double Sales::getOtherSales() const{
    return otherSales;
}

double Sales::getGlobalSales() const{
    return globalSales;
}

void Sales::printInfo() const{
    cout << setfill('-') << setw(24) << "" << endl;
    cout << "Name: " << gameName << endl;
    cout << "Platform: " << platform << endl;
    cout << "Year of Release: " << yearOfRelease << endl;
    cout << "North America Sales: " << NASales << endl;
    printSalesOnly();
}

void Sales::printSalesOnly() const{
    cout << "North America sales: " << NASales << endl;
    cout << "Euro sales: " << EUSales << endl;
    cout << "Japan sales: " << JPSales << endl;
    cout << "Other area sales: " << otherSales << endl;
    cout << "Global sales(Total): " << globalSales << endl;
}
// this functio act exactly as printSalesOnly()
ostream &operator<<(ostream &os, const Sales sales){
    os << "North America sales: " << sales.getNASales() << endl
       << "Euro sales: " << sales.getEUSales() << endl
       << "Japan sales: " << sales.getJPSales() << endl
       << "Other area sales: " << sales.getOtherSales() << endl
       << "Global sales(Total): " << sales.getGlobalSales()<< endl;
    return os;
}
