// NeuralNetwork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MLP.h"

int main()
{
    srand(time(NULL));
    rand();

    cout << "\n\n------ OR Gate ------\n\n";
    Perceptron* p = new Perceptron(2);

    p->set_weights({ 10,10,-15 }); // AND
    std::cout.precision(4);
    cout << "AND Gate: " << endl << std::fixed;
    cout << p->run({ 0,0 }) << endl;
    cout << p->run({ 0,1 }) << endl;
    cout << p->run({ 1,0 }) << endl;
    cout << p->run({ 1,1 }) << endl;

    p->set_weights({15,15,-10}); // OR
    cout << "OR Gate: " << endl;
    cout << p->run({ 0,0 }) << endl;
    cout << p->run({ 0,1 }) << endl;
    cout << p->run({ 1,0 }) << endl;
    cout << p->run({ 1,1 }) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
