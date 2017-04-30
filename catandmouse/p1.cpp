#include <iostream>
using namespace std;

// the Adder class has fns that perform the tasks
// specified by the 3 cases
class Adder 
{
    int subTotal; int totalValues; 

    public:
      void firstOrSecondZero(bool seenZero);
      int thirdZero(int numZeros);
      void notZero(int num);
};

// if the num is the 1st or 2nd 0 we've seen,
// we need to print the subtotal and reset it
void Adder::firstOrSecondZero(bool seenZero)
{
    cout << "Subtotal " << subTotal << "\n";
    subTotal = 0;
}

// if it's the 3rd zero we've seen,
// we need to print the subtotal and total
// and then exit the program
int Adder::thirdZero(int numZeros)
{
    cout << "Total " << totalValues << "\n";
    return 0;
}

// if num != 0, just increment subtotal and total
void Adder::notZero(int num)
{
    subTotal += num;
    totalValues += num;
}


// the main function initializes an intance of Adder,
// and calls the corresponding method in the Adder class
// for each scenario
int main () 
{
    int num; int numZeros = 0; bool seenZero;
    Adder add;

    while (true) 
    {
        cout << "Input a number to be added:\n";
        cin >> num;

        if (num == 0 and seenZero == false) 
        {  
          add.firstOrSecondZero(seenZero);
          seenZero = true;
        }
          
        else if (num == 0 and seenZero == true) 
        {
          add.thirdZero(numZeros);
          return 0;
        }

        else {
            add.notZero(num);
            seenZero = false;
        }

    } 

}