#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int inputnumerator); 
      Rational(int inputnumerator, int inputdenominator); 
      Rational add(const Rational &inputnumber_A) const; 
      Rational subtract(const Rational &inputnumber_S) const; 
      Rational multiply(const Rational &inputnumber_M) const; 
      Rational divide(const Rational &inputnumber_D) const;
      void simplify();
      void display() const;
   private:
      int gcd(int num, int den) const;
};

// Implement Rational class member functions here
Rational::Rational(){
   numerator = 0;
   denominator = 1;
}

Rational::Rational(int inputnumerator){
   numerator = inputnumerator;
   denominator = 1;
}

Rational::Rational(int inputnumerator, int inputdenominator){
   numerator = inputnumerator;
   denominator = inputdenominator;
}

Rational Rational::add(const Rational &inputnumber_A)const{
   Rational A;
   // (a/b) + (c/d) = (ad + bc) / (b*d)
   A.numerator = numerator * inputnumber_A.denominator + denominator * inputnumber_A.numerator;
   A.denominator = denominator * inputnumber_A.denominator;
   return A;
}

Rational Rational::subtract(const Rational &inputnumber_S)const{
   Rational S;
   // (a/b) - (c/d) = (ad - bc) / (b*d)
   S.numerator = numerator * inputnumber_S.denominator - denominator * inputnumber_S.numerator;
   S.denominator = denominator * inputnumber_S.denominator;
   return S;

}

Rational Rational::multiply(const Rational &inputnumber_M)const{
   Rational M;
   // (a/b) * (c/d) = (ac) / (bd)
   M.numerator = numerator * inputnumber_M.numerator;
   M.denominator = denominator * inputnumber_M.denominator;
   return M;

}

Rational Rational::divide(const Rational &inputnumber_D)const{
   Rational D;
   // (a/b) / (c/d) = (ad) / (cb)
   D.numerator = numerator * inputnumber_D.denominator;
   D.denominator = inputnumber_D.numerator * denominator;
   return D;

}

int Rational::gcd(int num, int den) const{
   int GCD;
   for (int i = 1; i <= num && i <= den; i++){
        if (num % i == 0 && den % i == 0){
            GCD = i;
        }
   }
   return GCD;
}

void Rational::simplify(){
   int GCD = gcd(numerator, denominator);
   numerator = numerator/GCD;
   denominator = denominator/GCD;
}

void Rational::display() const{
   cout << numerator << " / " << denominator;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

