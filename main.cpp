#include <iostream>
#include <concepts>
#include <type_traits>
template <typename T>
concept FloatingPoint = std::is_floating_point<T>::value;

template<FloatingPoint T>
class ComplexNumber {
private:
    T real;
    T imag;

public:
    // Costruttore di default
    ComplexNumber() : real(0), imag(0) {}

    // Costruttore con parte reale e immaginaria
    ComplexNumber(T r, T i) : real(r), imag(i) {}

    // Metodo per ottenere la parte reale
    T getReal() const { return real; }

    // Metodo per ottenere la parte immaginaria
    T getImag() const { return imag; }

    // Metodo per ottenere il coniugato
    ComplexNumber<T> conjugate() const { return ComplexNumber<T>(real, -imag); }

    // Overload dell'operatore << per stampare il numero complesso
     friend std::ostream& operator<<(std::ostream& os, const ComplexNumber<T>& z) {
        os << z.real;
        if (z.imag >= 0) os << "+" << z.imag << "i";
        else os << z.imag << "i";
        return os;
    }
    // Overload dell'operatore +=
    ComplexNumber<T>& operator+=(const ComplexNumber<T>&other){
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Overload dell'operatore +
    ComplexNumber<T> operator+(const ComplexNumber<T>& other) const {
        return ComplexNumber<T>(real + other.real, imag + other.imag);
    }

    // Overload dell'operatore *=
    ComplexNumber<T>& operator*=(const ComplexNumber<T>&other){
        T tempReal = real* other.real-imag*other.imag;
        T tempImag = real*other.imag + imag*other.real;
        real = tempReal;
        imag = tempImag;
        return *this;
    }
    
    // Overload dell'operatore *
    ComplexNumber<T> operator*(const ComplexNumber<T>& other) const {
        T tempReal = real * other.real - imag * other.imag;
        T tempImag = real * other.imag + imag * other.real;
        return ComplexNumber<T>(tempReal, tempImag);
    }

    // Overload dell'operatore + per sommare un numero complesso con un tipo T
    ComplexNumber<T> operator+(T value) const {
        return ComplexNumber<T>(real + value, imag);
    }

    // Overload dell'operatore * per moltiplicare un numero complesso con un tipo T
    ComplexNumber<T> operator*(T value) const {
        return ComplexNumber<T>(real * value, imag * value);
    }
};

int main() {
    // Creazione di numeri complessi con float
    ComplexNumber<float> z1(3.5f, 2.0f);
    ComplexNumber<float> z2(1.0f, -4.0f);

    // Somma di due numeri complessi
    ComplexNumber<float> sum = z1 + z2;
    std::cout << "Somma: " << sum << std::endl;

    // Moltiplicazione di due numeri complessi
    ComplexNumber<float> product = z1 * z2;
    std::cout << "Prodotto: " << product << std::endl;

    // Coniugato del primo numero complesso
    std::cout << "Coniugato di z1: " << z1.conjugate() << std::endl;

    // Somma di un numero complesso con un numero reale
    ComplexNumber<float> sumWithReal = z1 + 3.0f;
    std::cout << "Somma con un reale: " << sumWithReal << std::endl;

    // Moltiplicazione di un numero complesso con un numero reale
    ComplexNumber<float> productWithReal = z1 * 2.0f;
    std::cout << "Moltiplicazione con un reale: " << productWithReal << std::endl;

    z1 += z2;
    std::cout<< "dopo z1 += z2: "<< z1<< std::endl;
    z1*=z2;
    std::cout <<"Dopo z1*= z2: "<< z1<< std::endl;
    
    return 0;
}


