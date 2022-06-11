
#include <iostream>
#include <math.h>

// Implementacion de la clase cuaterniones 
// Tal que dados a, b, c, d ∈ R
// Quaternion(a,b,c,d) =  a + bi + cj + dk
// Se sobrecargan los operadores + * - ~ & == para trabajar con los cuaterniones y no realizar llamadas adicionales a funciones
//Implementado por Roberto Gamboa, 16-10394

class Quaternion {

    private:
    // Valores privados, se acceden desde los metodos val()
    float valor1;
    float valor2;
    float valor3;
    float valor4;
    
    public:
    
    // constructor si se llama a la clase sin argumentos
    Quaternion() {
        valor1 = 0;
        valor2 = 0;
        valor3 = 0;
        valor4 = 0;
    }
    
    // constructor de la clase dados a, b , c y d
    Quaternion(float a, float b, float c, float d) {
        valor1 = a;
        valor2 = b;
        valor3 = c;
        valor4 = d;
    }

    // funciones para retornar los valores asociados al cuaternion
    float val1() const { return valor1; }
    float val2() const { return valor2; }
    float val3() const { return valor3; }
    float val4() const { return valor4; }

    // Sobrecarga del operador  ~
    // Para devolver la conjugada del cuaternion
    Quaternion operator~(){
        return Quaternion(val1(), -val2(), -val3(), -val4());
    }

    // Sobrecarga del operador  ==
    // Para poder comparar cuaterniones (se usa para realizar las pruebas unitarias)
    bool operator==(const Quaternion& q) const {

        if (val1() == q.val1() && val2() == q.val2() && val3() == q.val3() && val4() == q.val4() ) { return true;}
        return false;

    }

    // Sobrecarga del operador  &
    // Para retornar el modulo del cuaternion
    float operator&(){
        int suma;
        suma = pow(val1(),2) + pow(val2(),2) + pow(val3(),2) + pow(val4(),2);
        
        return sqrt(suma);
        
    }

    // Sobrecarga del operador  *
    // Para multiplicar dos cuaterniones
    Quaternion operator*(const Quaternion& q) const {
        return Quaternion(
                        val1()*q.val1() - val2()*q.val2() - val3()*q.val3() - val4()*q.val4(),
                        val1()*q.val2() + val2()*q.val1() + val3()*q.val4() - val4()*q.val3(),
                        val1()*q.val3() - val2()*q.val4() + val3()*q.val1() + val4()*q.val2(),
                        val1()*q.val4() + val2()*q.val3() - val3()*q.val2() + val4()*q.val1());
    }

    // Sobrecarga del operador  *
    // Para multiplicar un cuaternion con un numero entero o punto flotante
    Quaternion operator*(float s) const {
        return Quaternion(val1()*s, val2(), val3(), val4());
    }

    // Sobrecarga del operador  +
    // Para sumar dos cuaterniones
    Quaternion operator+(const Quaternion& q) const {
        return Quaternion(
                        val1()+q.val1(), 
                        val2()+q.val2(), 
                        val3()+q.val3(), 
                        val4()+q.val4());
    }
    
    // Sobrecarga del operador  +
    // Para sumar un cuaternion con un numero entero o punto flotante
    Quaternion operator+(float s) const {
        return Quaternion(val1()+s, val2(), val3(), val4());
    }

    // Sobrecarga del operador  -
    // Para restar dos cuaterniones
    Quaternion operator-(const Quaternion& q) const {
        return Quaternion(
                        val1()-q.val1(), 
                        val2()-q.val2(), 
                        val3()-q.val3(), 
                        val4()-q.val4()); 
    }

    // Sobrecarga del operador  -
    // Para restar un cuaternion con un numero entero o punto flotante
    Quaternion operator-(float s) const {
        return Quaternion(val1()-s, val2(), val3(), val4());
    }
    
    // Funcion que muestra el cuaternion como un string por terminal
    // Se muestran los numeros con dos decimales
    void mostrar() {
        printf("(%.2f)+(%.2f)i+(%.2f)j+(%.2f)k\n",val1(),val2(),val3(),val4());
    }
};