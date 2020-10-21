//
//  Sales.h
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//

#ifndef Sales_h
#define Sales_h
#include <string>
#include <iostream>
using namespace std;
class Sales{
public:
    //Constructors
    Sales();
    
    Sales(string gameName, string platform, int yearOfRelease, double NASales, double EUSales, double JPSales, double otherSales, double globalSales);
    
    //Accessors
    
    string getGameName() const;
    
    string getPlatform() const;
    
    int getYearOfRelease() const;
    
    double getNASales() const;
    
    double getEUSales() const;
    
    double getJPSales() const;
    
    double getOtherSales() const;
    
    double getGlobalSales() const;
    
    void printInfo() const;
    
    void printSalesOnly() const;
    
    friend ostream &operator<<(ostream &os, const Sales sales);
private:
    string id;
    string gameName;
    string platform;
    int yearOfRelease;
    double NASales;
    double EUSales;
    double JPSales;
    double otherSales;
    double globalSales;

};

#endif /* Sales_h */
