#include<iostream>
#include<string>
using namespace std;
class Fraction {
public:
        int num;
        int denum;

        Fraction(int num, int denum){
            if(denum == 0){
                throw invalid_argument("Denominator cannot be zero");
            }
            this->num = num;
            this->denum = denum;
            simplify();
        }
        int gcd(int a, int b){
            return b==0 ? a : gcd(b, a%b);
        }

        void simplify() {
            int Gcd = gcd(this->num, this->denum);
            num /= Gcd;
            denum /= Gcd;
            if (denum < 0) {
                num = -num;
                denum = -denum;
            }
        }
        void display(){
            cout << num << " / " << denum << endl;
        }

        Fraction operator+(Fraction f){
            int newNum = this->num*f.denum + f.num*this->denum;
            int newDenum = this->denum*f.denum;
            Fraction ans(newNum, newDenum);
            return ans;
        }

        Fraction operator-(Fraction f){
            int newNum = this->num*f.denum - f.num*this->denum;
            int newDenum = this->denum*f.denum;
            Fraction ans(newNum, newDenum);
            return ans;
        }

        Fraction operator*(Fraction f){
            int newNum = this->num*f.num;
            int newDenum = this->denum*f.denum;
            Fraction ans(newNum, newDenum);
            return ans;
        }
        Fraction operator/(Fraction f){
            int newNum = this->num*f.denum;
            int newDenum = this->denum*f.num;
            Fraction ans(newNum, newDenum);
            return ans;
        }
};
int main(){
    Fraction f1(1,2);
    Fraction f2(2,3);
    // Fraction f3 = f1.add(f2);
    Fraction f3 = f1 + f2;  // f1.operator+(f2)
    f3.display();
    Fraction f4 = f1 - f2;
    f4.display();
    Fraction f5 = f1 * f2;
    f5.display();
    Fraction f6 = f1 / f2;
    f6.display();
    return 0;
}

// g++ fraction.cpp -o fraction_program && fraction_program