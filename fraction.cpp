#include <string>

//USE ONLY SIGNED INTEGER TYPES. OTHER TYPES
//WILL CAUSE UNDEFINED BEHAVIOUR
template <typename T>
class Fraction{
private:
	T numerator{0};
	T denominator{1};

	Fraction EvaluateFraction(){
        if (numerator == 0 || denominator == 0){
            numerator = 0;
            denominator = 1;
        } else if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        return *this;
    }

	T GCD(T a, T b) const{
        if(a == 0 && b == 0){
            return 1;
        }
        int tmp;
        while (a != 0){
            tmp = a;
            a = b % a;
            b = tmp;
        }
        return (b < 0) ? -b : b;
    }

public:
	Fraction(){}

	Fraction(const T numerator_, const T denominator_) :
             numerator(numerator_), denominator(denominator_) {
        EvaluateFraction();
    }

	Fraction(const Fraction &b){
        *this = b;
    }

	explicit Fraction(const T numerator_): //cast
                      numerator(numerator_) {}

	explicit Fraction(const std::string &s){ //cast
        std::size_t x = (s[0] == '-') ? 1 : 0;
        bool denom = false;
        while (x < s.size()) {
            if (!denom && s[x] == '/') {
                denom = true;
                denominator = 0;
            } else if (s[x] < '0' || s[x] > '9') {
                numerator = 0;
                denominator = 1;
                return;
            } else {
                if (denom) {
                    this->denominator *= 10;
                    this->denominator += s[x] - '0';
                } else {
                    this->numerator *= 10;
                    this->numerator += s[x] - '0';
                }
            }
            x++;
        }
        if (s[0] == '-') {
            this->numerator = -this->numerator;
        }
        this->EvaluateFraction();
    }

	operator float() const{
        return (float)(this->numerator) /
               (float)(this->denominator);
    }
	operator double() const{
        return (double)(this->numerator) /
               (double)(this->denominator);
    }
	operator long double() const {
        return (long double)(this->numerator) /
               (long double)(this->denominator);
    }

	bool operator < (const Fraction &b) const {
        return (double)*this < (double)b;
    }

	bool operator > (const Fraction &b) const{
        return (double)*this > (double)b;
    }

	bool operator == (const Fraction &b) const{
        Fraction frac_1(*this);
        Fraction frac_2(b);
        frac_1.Simplify();
        frac_2.Simplify();
        return frac_1.numerator == frac_2.numerator &&
            frac_1.denominator == frac_2.denominator;
    }

	bool operator != (const Fraction &b) const{
        return !(*this == b);
    }

	bool operator <= (const Fraction &b) const{
        return (*this < b || *this == b);
    }

	bool operator >= (const Fraction &b) const{
        return (*this > b || *this == b);
    }

	//Fraction operator = (const Fraction &b);

	Fraction operator += (const Fraction &b){
        return *this = (*this) + b;
    }

	Fraction operator -= (const Fraction &b){
        return *this = (*this) - b;
    }

	Fraction operator *= (const Fraction &b){
        return *this = (*this)*b;
    }

	Fraction operator /= (const Fraction &b){
        return *this = (*this) / b;
    }

	Fraction operator - () const{
        return { -this->numerator, this->denominator };
    }

	Fraction operator + (const Fraction &b) const{
        Fraction result;
        result.denominator = this->denominator*(b.denominator / GCD(this->denominator, b.denominator));
        result.numerator = (this->numerator*(result.denominator / this->denominator)) +
            (b.numerator*(result.denominator / b.denominator));
        return result.Simplify();
    }

	Fraction operator - (const Fraction &b) const{
        Fraction result;
        result.denominator = this->denominator*(b.denominator / GCD(this->denominator, b.denominator));
        result.numerator = (this->numerator*(result.denominator / this->denominator)) -
            (b.numerator*(result.denominator / b.denominator));
        return result.Simplify();
    }

	Fraction operator * (const Fraction &b) const{
        Fraction result(this->numerator*b.numerator,
            this->denominator*b.denominator);
        return result.Simplify();
    }

	Fraction operator / (const Fraction &b) const{
        Fraction result(this->numerator*b.denominator,
            this->denominator*b.numerator);
        return result.EvaluateFraction().Simplify();
    }

	int GetNumerator() const{
        return numerator;
    }

	int GetDenominator() const{
        return denominator;
    }

	Fraction Simplify(){
        if (numerator == 0) {
            denominator = 1;
            return *this;
        }
        const int div = GCD(numerator, denominator);
        numerator /= div;
        denominator /= div;
        return *this;
    }

	Fraction Reciprocal() const{
        if (numerator == 0) {
            return { 0, 1 };
        }
        return { denominator, numerator };
    }

	std::string ToString() const{
        return std::to_string(numerator) +
            ((denominator > 1) ? "/" + std::to_string(denominator) : "");
    }
};
