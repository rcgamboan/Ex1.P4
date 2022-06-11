#include "Quaternion.cpp"
#include "gtest/gtest.h"

// Programa que realiza pruebas sobre la implementacion de Cuaternones hallada en el archivo Quaternion.cpp
// Para realizar las pruebas se emplea la herramienta Google Test
// Y para medir la cobertura se usa la herramienta gcov
// Se compila el codigo con el siguiente comando:
// g++ tests.cpp -lgtest -lpthread --coverage -o tests
// Y esto genera 3 archivos, el archivo ejecutable tests , tests.gcno y tests.gcda
// ejecutamos las pruebas con ./tests
// Luego ejecutamos gcov tests.cpp -m
// y se muestra el reporte de cobertura por la terminal
// en el reporte se muestra la cobertura de varios archvos de la libreria que se usa para las pruebas
// y al final del reporte se muestra la de Quaternion.cpp

// Test suma
TEST(QuaternionTest, SumaQuaternion) {

    Quaternion a;
    Quaternion b;
    Quaternion c;
    
    // Suma nulo
    a = Quaternion(5,-2,0,4);
    b = Quaternion(0,0,0,0);
    EXPECT_EQ(a, a+b) << "a + 0 != a";

    // Suma -a
    a = Quaternion(5,-2,0,4);
    b = Quaternion(-5,2,0,-4);
    c = Quaternion(0,0,0,0);
    EXPECT_EQ(a+b, c) << "a + -a != 0";

    // Suma normal
    a = Quaternion(5,-2,0,4);
    b = Quaternion(2,8,1,-4);
    c = Quaternion(7,6,1,0);
    EXPECT_EQ(a+b, c) << "a + b != c";
}

// Test resta
TEST(QuaternionTest, RestaQuaternion) {

    Quaternion a;
    Quaternion b;
    Quaternion c;
    

    // Resta nulo
    a = Quaternion(5,-2,0,4);
    b = Quaternion(0,0,0,0);
    EXPECT_EQ(a, a-b) << "a - 0 != a";

    // Resta a
    a = Quaternion(5,-2,0,4);
    c = Quaternion(0,0,0,0);
    EXPECT_EQ(a-a, c) << "a - a != 0";

    // Resta normal
    a = Quaternion(5,-2,0,4);
    b = Quaternion(2,8,1,-4);
    c = Quaternion(3,-10,-1,8);
    EXPECT_EQ(a-b, c) << "a - b != c";
}

// Test multiplicacion
TEST(QuaternionTest, MultQuaternion) {

    Quaternion a;
    Quaternion b;
    Quaternion c;
    

    // Multiplicacion 1
    a = Quaternion(5,-2,0,4);
    b = Quaternion(1,1,1,1);
    c = Quaternion(3,-1,11,7);
    EXPECT_EQ(a*b, c) << "a * 1 != c";

    // Multiplicacion normal
    a = Quaternion(5,-2,0,4);
    b = Quaternion(2,8,1,-4);
    c = Quaternion(42,32,29,-14);
    EXPECT_EQ(a*b, c) << "a * b != c";
}

// Test conjugada
TEST(QuaternionTest, ConjQuaternion) {

    Quaternion a;
    Quaternion b;
    
    a = Quaternion(5,-2,1,4);
    b = Quaternion(5,2,-1,-4);
    EXPECT_EQ(~a, b) << "~a != b";
}

// Test modulo
TEST(QuaternionTest, MediaQuaternion) {

    Quaternion a;
    float s;
    float t;
    t = 6.78233;
    a = Quaternion(5,-2,1,4);
    s = &a;
    EXPECT_EQ(s, t);
}

int main(int argc, char **argv){
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}