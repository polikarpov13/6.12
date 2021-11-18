#include <iostream> 

#include <iomanip> 

#include <time.h> 

using namespace std;



void create_array(int* a, const int array_size, const int number1, const int number2, int array_component) {
    a[array_component] = number1 + rand() % (number2 - number1 + 1);
    if (array_component < array_size - 1)
        create_array(a, array_size, number1, number2, array_component + 1);
}



void print_array(int* a, const int array_size, int array_component) {

    cout << a[array_component] << " ";
    if (array_component < array_size - 1)
        print_array(a, array_size, array_component + 1);
}



int elements_counter(int* a, const int array_size, int array_component, int number) {

    if ((a[array_component] > 0) || (a[array_component] % 2 != 0))
            number++;
    if (array_component < array_size - 1) {
        if ((a[array_component] > 0) || (a[array_component] % 2 != 0))
            elements_counter(a, array_size, array_component + 1, number);
    }
    else
        return number;
}



int elements_sum(int* a, const int array_size, int array_component, int sum) {

    if ((a[array_component] > 0) || (a[array_component] % 2 != 0))
        sum += a[array_component];
    if (array_component < array_size - 1) {
        if ((a[array_component] > 0) || (a[array_component] % 2 != 0))
            elements_sum(a, array_size, array_component + 1, sum);
    }

    return sum;

}



void elements_change(int* a, const int array_size, int array_component) {

    if ((a[array_component] > 0) || (a[array_component] % 2 != 0))
        a[array_component] = 0;
    if (array_component < array_size - 1) {
        if ((a[array_component] > 0) || (a[array_component] % 2 != 0))
            elements_change(a, array_size, array_component + 1);
    }
}





int main()

{

    srand((unsigned)time(NULL));



    const int array_size = 27;

    int a[array_size];



    int number1 = -35;

    int number2 = 25;



    create_array(a, array_size, number1, number2, 0);

    print_array(a, array_size, 0);

    cout << endl;



    cout << "Sum : " << elements_sum(a, array_size, 0, 0) << endl;

    cout << "Amount of elements : " << elements_counter(a, array_size, 0, 0) << endl;



    elements_change(a, array_size, 0);

    print_array(a, array_size, 0);



    return 0;

    system("pause");

}