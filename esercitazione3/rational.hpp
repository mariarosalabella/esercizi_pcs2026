#pragma once
#include <concepts>
#include <iostream>

template<typename I> requires std::integral<I>
class rational
{
  I numerator;
  I denominator;
public:
    rational()
        : numerator(0), denominator(1)  //costruttore di default (inizializzo num e den a 0 e 1)
    {}	
	
	rational(I num, I den) {    //costruttore user-defined
	    if (den == 0) {
		    if (num == 0) {
			    numerator = 0;     //caso 0/0 (NaN)
			    denominator = 0;
		    }
		    else {
			    if (num>0) {         //caso num/0 (Inf)
				    numerator = 1;   //salvo solo il segno del numeratore, per distinguere +Inf e -Inf
			    }
			    else {
				    numerator = -1;
			    }
			    denominator = 0;
		    }
	    }
	    else {
		    numerator = num;
		    denominator = den;
			simplify();
	    }
    }
	
	//definisco due metodi per controllare NaN e Inf
	bool is_nan() const  {
    return numerator == 0 && denominator == 0;
    }
	
	bool is_inf() const  {
    return denominator == 0 && numerator != 0;
    }  
    
	//metodi che restituiscono i valori di numeratore e denominatore
    I num() const { return numerator; }
	I den() const { return denominator; }
	
	//implementazione del MCD
	void simplify() {
		if (is_nan() || is_inf() ) {  //controllo se è inf o nan
			return;
		}
		if (numerator == 0) {
			denominator = 1;   //standardizzo tutte le frazioni zero come 0/1
			return;
		}

		//faccio il valore assoluto di num e den per poter applicare Euclide
		I a; 
		if (numerator < 0) {
		    a = -numerator; 
		}
		else {
			a = numerator;
		}
		I b;
		if (denominator < 0) {
			b = -denominator;
		}
		else {
			b = denominator;
		}
		
		//algoritmo di Euclide
		while (b != 0) {
			I r = a%b;
			a = b;
			b = r;
		}
		I mcd = a;
		
		numerator /= mcd;
		denominator /= mcd;
		
		//sposto il segno sul numeratore 
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}
		
	
	//implementazione dell'incremento
	rational& operator+=(const rational& other) {
		//caso NaN
		if (is_nan() || other.is_nan()) {
			numerator = 0; denominator = 0; 
		}
		//caso Inf
		else if (is_inf() || other.is_inf()) {
			//Inf - Inf = NaN
			if (is_inf() && other.is_inf() && (numerator > 0 != other.numerator > 0)) {
				numerator = 0; denominator = 0;
			}
			else if (is_inf()) {
				//rimane Inf con il segno di *this
			}
			else {
				numerator = other.numerator; //rimane Inf con il segno di other
				denominator = 0;
			}
		}
		else {
			numerator = numerator * other.denominator + other.numerator * denominator;
		    denominator = denominator * other.denominator;
		    simplify();
		}
		return *this;
	}
	
	//implementazione della somma
	rational operator+(const rational& other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}
	
	//implementazione di -= 
	rational& operator-=(const rational& other) {
		//caso NaN
		if (is_nan() || other.is_nan()) {
			numerator = 0; denominator = 0; 
		}
		//caso Inf
		else if (is_inf() || other.is_inf()) {
			//Inf - Inf = NaN
			if (is_inf() && other.is_inf() && (numerator > 0 == other.numerator > 0)) {
				numerator = 0; denominator = 0;
			}
			else if (is_inf() && other.is_inf() && (numerator > 0 != other.numerator > 0)) {
				//rimane Inf 
			}
			else if (is_inf()) {
				//rimane inf con il segno di this
			}
			else { //other è inf
				numerator = -other.numerator; //rimane Inf con - il segno di other
				denominator = 0;
			}
		}
		else {
		    numerator = numerator * other.denominator - other.numerator * denominator;
		    denominator = denominator * other.denominator;
		    simplify();
		}
		return *this;
	}
	
	//implementazione della sottrazione
	rational operator-(const rational& other) const {
		rational ret = *this;
		ret -= other;
		return ret;
	}
	
	//implementazione di *=
	rational& operator*=(const rational& other) {
		//caso NaN
		if (is_nan() || other.is_nan()) {
			numerator = 0; denominator = 0; 
		}
		//Caso Inf
		//caso Inf*0 o 0*Inf
		else if ((is_inf() && other.numerator == 0 || other.is_inf() && numerator == 0)) {
			numerator = 0; denominator = 0;
		}
		//Caso Inf*numero o Inf*Inf
		else if (is_inf() || other.is_inf()) {
			if ((numerator > 0 && other.numerator > 0 || numerator < 0 && other.numerator < 0)) {
				numerator = 1; denominator = 0; //+Inf
			}
		    else {
				numerator = -1; denominator = 0; //-Inf 
			}
		}
		else {
			numerator = numerator * other.numerator;
		    denominator = denominator * other.denominator;
		    simplify();
		}
		return *this;
	}
	
	//implementazione della moltiplicazione
	rational operator*(const rational& other) const {
		rational ret = *this;
		ret *= other;
		return ret;
	}
	
	//implementazione di /=
	rational& operator/=(const rational& other) {
		//caso NaN
		if (is_nan() || other.is_nan()) {
			numerator = 0; denominator = 0; 
		}
		//Caso 0/0 oppure Inf/Inf: NaN
		else if ((numerator == 0 && other.numerator == 0) || (is_inf() && other.is_inf())) {
		    numerator = 0; denominator = 0;
        }
		//Caso numero/Inf: 0
		else if (other.is_inf()) {
			numerator = 0; denominator = 1;
		}
		//Caso numero/0: Inf
		else if (other.numerator == 0) {
        //Applico la regola dei segni per decidere se +Inf o -Inf
            if ((numerator > 0 && other.denominator > 0) || (numerator < 0 && other.denominator < 0)) {
                numerator = 1; denominator = 0;
            } 
		    else {
                numerator = -1; denominator = 0;
            }
        }
		//Caso Inf/numero: Inf
		else if (is_inf()) {
			if ((numerator > 0 && other.numerator > 0) || (numerator < 0 && other.numerator < 0)) {
            numerator = 1; denominator = 0;
            } 
			else {
            numerator = -1; denominator = 0;
            }
        }
		else {
			numerator = numerator * other.denominator;
		    denominator = denominator * other.numerator;
		    simplify();
		}
		return *this;
	}
	
	//implementazione della divisione
	rational operator/(const rational& other) const {
		rational ret = *this;
		ret /= other;
		return ret;
	}
	
};

//overload di operator<<
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
    if (r.is_nan()) {
        os << "NaN";
    } 
	else if (r.is_inf()) {
        if (r.num() > 0) os << "+Inf";
        else os << "-Inf";
    } 
	else {
        os << r.num();
        if (r.den() != 1) {
            os << "/" << r.den();
        }
    }
    return os;
}

	

	
		
	    


