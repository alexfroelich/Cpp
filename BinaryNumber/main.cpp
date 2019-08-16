/*
  Alexander A. Froelich
  A program that converts a decimal number to binary
*/

#include <iostream>
#include <stack>
using namespace std;

//Declaration of the functions
void print_instructions();
void decimal_to_binary(int number, stack<int> *binaryNumber);
void print_binary(stack <int> *s);


int main(int argc, char const *argv[]) {
  //Create the variable to store the input
  int number = 1;
  //Create a stack to store the binary form
  stack <int> binaryNumber;
  while (number != 0) {

    //Asks for the number
    print_instructions();
    //Get input from the user
    cin >> number;
    //If the program can't use the cin (invalid input from the user)
    if(cin.fail() || number < 0){
      do{
        cin.clear();
        cin.ignore();
        //Inform wrong input
        cout << "Error!! You must enter a number!" << '\n';
        //Ask Again
        print_instructions();

        cin >> number;
      }while (cin.fail() || number < 0);
    }

    if(number == 0){
      cout << "Closing..." << '\n';
      return 0;
    }


    //Convert the number and store the binary form in the stack
    decimal_to_binary(number , &binaryNumber);
    //show the result
    cout << "The number "<< number << " in binary is: ";
    print_binary(&binaryNumber);

  }
  return 0;



}

void print_instructions(){
    cout << "Please enter a number bigger than 0 to convert, or 0 to exit" << '\n';
}

void decimal_to_binary(int number, stack<int> *binaryNumber){
    if(number / 2 == 0){
      binaryNumber->push(number%2);
    }
    else{
      binaryNumber->push(number%2);
      decimal_to_binary(number/2, binaryNumber);
    }
}

void print_binary(stack <int> *binaryNumber)
{
    while (!binaryNumber->empty())
    {
        cout << binaryNumber->top();
        binaryNumber->pop();
    }
    cout << '\n';
}
