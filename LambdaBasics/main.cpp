#include <iostream>

using namespace std;

int main()
{
    /*
    [capture list] (parameter list) {function body}
    */

    auto helloWorld = [](){
    cout << "Hello World!" << endl;
    };
    helloWorld();

    auto multiplication = [](float a, float b)->int{
        return a * b;
    };

    auto c = multiplication(5.25,5.25);
    cout << "a * b = "<< c <<endl;


    int d = 6;
    int e = 4;

    auto printNumbers = [d,e](){

      cout << "d is : " << d << endl;
      cout << "e is : " << e << endl;
    };

    printNumbers();

    auto func = [c](){
        cout << "The inner value of c is: " << c << endl;
    };

    auto func1 = [=](){
        cout << "The inner value of d is: " << d << endl;
    };

    func1();

    for (int i = 1; i < 5; i++){
        cout << "The outer value of c is: " << c << endl;
        func();
        c = c + 1;
    }

    cout << c << endl;
    func();
    return 0;
}
