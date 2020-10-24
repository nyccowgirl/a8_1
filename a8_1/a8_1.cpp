/*
 Trang Hoang
 CS110B
 Dave Harden
 10/19/20
 a8_1.cpp
 
 Assignment 8.1
 
 Write a Fraction class whose objects will represent fractions. You must provide the
 following member functions:
 
    - A set() operation that takes two integer arguments, a numerator and a denominator,
      and sets the calling object accordingly.

    - Arithmetic operations that add, subtract, multiply, and divide Fractions. These
      should be implemented as value returning functions that return a Fraction object.
      They should be named addedTo, subtract, multipliedBy, and dividedBy. In these
      functions you will need to declare a local "Fraction" variable, assign to it the
      result of the mathematical operation, and then return it.

    - A boolean operation named isEqualTo that compares two Fraction objects for equality.
      Since you aren't reducing your Fractions, you'll need to do this by
      cross-multiplying. A little review: if numerator1 * denominator2 equals denominator1
      * numerator2, then the Fractions are equal.

    - An output operation named print that displays the value of a Fraction object on the
      screen in the form numerator/denominator.
 
 Created by nyccowgirl on 10/19/20.
 Copyright © 2020 nyccowgirl. All rights reserved.
*/

#include <iostream>
using namespace std;


class Fraction
{
    public:
        void set(int inNum, int inDenom);
        Fraction addedTo(Fraction frac);
        Fraction subtract(Fraction frac);
        Fraction multipliedBy(Fraction frac);
        Fraction dividedBy(Fraction frac);
        bool isEqualTo(Fraction frac);
        void print();
    
    private:
        int numerator;
        int denominator;
};






/*
 Definition of class function set. Function passes in two integers, numerator and
 denominator, and assigns them the the related class members.
 
 Pre: Two integers for numerator and denominator
 Post: Assigns the two integers into respective class members for the fraction object
*/

void Fraction::set(int inNum, int inDenom) {
    numerator = inNum;
    denominator = inDenom;
}





/*
 Definition of class function addedTo. Function passes in a fraction object, and adds it to
 the calling object.
 
 Pre: None
 Post: Returns a fraction object (not reduced) with the sum of the two fractions
 */

Fraction Fraction::addedTo(Fraction frac) {
    int sum;
    Fraction temp;
    
    sum = (numerator * frac.denominator) + (frac.numerator * denominator);
    temp.set(sum, (denominator * frac.denominator));
    return temp;
}






/*
 Definition of class function subtract. Function passes in a fraction object, and subtracts
 it from the calling object.
 
 Pre: None
 Post: Returns a fraction object (not reduced) with the difference of the two fractions
 */

Fraction Fraction::subtract(Fraction frac) {
    int diff;
    Fraction temp;
    
    diff = (numerator * frac.denominator) - (frac.numerator * denominator);
    temp.set(diff, (denominator * frac.denominator));
    return temp;
}






/*
 Definition of class function multipliedBy. Function passes in a fraction object, and
 multiplies it to calling object.
 
 Pre: None
 Post: Returns a fraction object (not reduced) with the product of the two fractions
 */

Fraction Fraction::multipliedBy(Fraction frac) {
    Fraction temp;
    
    temp.set((numerator * frac.numerator), (denominator * frac.denominator));
    return temp;
}






/*
 Definition of class function dividedBy. Function passes in a fraction object, divides the
 calling object by the fraction object passed in and returns the quotient.
 
 Pre: None
 Post: Returns a fraction object (not reduced) with the quotient of the two fractions
 */

Fraction Fraction::dividedBy(Fraction frac) {
    Fraction temp;
    
    temp.set((numerator * frac.denominator), (denominator * frac.numerator));
    return temp;
}






/*
 Definition of class function isEqualTo. Function passes in a fraction object, compares it
 to the calling object and returns whether the two fractions are equal.
 
 Pre: None
 Post: Returns true if two fractions are equal and false otherwise
 */

bool Fraction::isEqualTo(Fraction frac) {
    return ((numerator * frac.denominator) == (denominator * frac.numerator));
}






/*
 Definition of class function print. Function displays the numerator and denominator in
 fraction format.
 
 Pre: None
 Post: Displays the numerator and denominator of the calling object in fraction format
 */

void Fraction::print() {
    cout << numerator << "/" << denominator;
}






int main(int argc, const char * argv[]) {
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}


/*
 
 The product of 9/8 and 2/3 is 18/24
 The quotient of 9/8 and 2/3 is 27/16
 The sum of 9/8 and 2/3 is 43/24
 The difference of 9/8 and 2/3 is 11/24
 The two Fractions are not equal.
 Program ended with exit code: 0
 
 */

