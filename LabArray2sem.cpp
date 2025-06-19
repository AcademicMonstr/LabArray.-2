#include <iostream>
#include <cstdlib>
#include <ctime>

void InputArray( int [], int );
void RandomArray( int [], int, int, int);
void PrintArray(int [], int);
int ProductOfEven( int [], int );
int Sum ( int[],  int  );
void TransformedArray ( int [], int );
int UniqueElements(int [], int );
int ProductAfterMax( int [], int );

const int MAX_SIZE = 100;

int main(){

    int size;
    std::cout << "Input size of array (1 - " << MAX_SIZE << "): ";
    std::cin >> size;

    if (size < 1 || size > MAX_SIZE) {
        std::cout << "Error, size: 1 to " << MAX_SIZE << "." << std::endl;
        return 1;
    }

    int arr[MAX_SIZE];

    int choice;
    std::cout << "Choose the method for filling:\n1) Keyboard\n2) Random\nYour choise : ";
    std::cin >> choice;

    if (choice == 1) {
        InputArray(arr, size);
    } else if (choice == 2) {
        int min, max;
        std::cout << "Enter range (min max): ";
        std::cin >> min >> max;
        srand(static_cast<unsigned int>(time(0)));
        RandomArray(arr, size, min, max);
    } else {
        std::cout << "Error choose 1 or 2." << std::endl;
        return 1;
    }
    PrintArray(arr, size);

    std::cout << "Product of even index elements: " <<ProductOfEven( arr, size ) << '\n';
    std::cout << "Sum between zero: " << Sum ( arr, size) << '\n';
    TransformedArray ( arr, size );
    std::cout << '\n' << "Different element: " << UniqueElements( arr, size ) << '\n';
    std::cout << "Product after max element: " << ProductAfterMax( arr, size );




    return 0;

}

void InputArray( int arr[], int size ){
    std::cout << "Input array elements" << '\n';
    
    for ( int i = 0; i < size; i++){
    
        std::cin >> arr[i];
    }

}

void RandomArray(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
void PrintArray(int arr[], int size) {
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

int ProductOfEven( int arr[], int size ){

    int product = 1;

    for ( int i = 0; i < size; i +=2 ){

        product *= arr[i];

    }

    return product;

}

int Sum ( int arr[], int size ){

    int first = -1;
    int last = -1;
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == 0) {
            if (first == -1) {
                first = i;
            }
            last = i;
        }
    }

    if (first != -1 && last != -1 && first != last) {
        for (int i = first + 1; i < last; ++i) {
            sum += arr[i];
        }
    }

    return sum;

}

void TransformedArray ( int arr[], int size){

    int temp[size];
    int h = 0;

    for ( int i = 0; i < size; ++i){

        if (arr[i] < 0){
            temp[h++] = arr[i];
        }
    }
        for (int i = 0; i < size; ++i){
        if (arr[i] >= 0){
            temp[h++] = arr[i];
        }
        }

    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << temp[i] << "\t";
    }

}

int UniqueElements(int arr[], int size) {
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        bool isUnique = true;
        for (int j = 0; j < i; ++j) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            counter++;
        }
    }

    return counter;
}

int ProductAfterMax( int arr[], int size ){

    int product = 1;
    int max = 0;
    int maxIndex = 0;
    int temp[size];

    for (int i = 0; i < size; ++i){
        if ( arr[i] < 0){
            temp[i] = -1 * arr[i];
        } 
        else {
            temp[i] = arr[i];
        }
    }

    for (int i = 0; i < size; ++i){

        if (temp[i] > max){
            max = temp[i];
            maxIndex = i;
        }
    }

    for( int i = maxIndex + 1; i < size; ++i){

        product *= arr[i];
    }

    return product;

}