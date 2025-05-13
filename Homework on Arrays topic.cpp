//Topic 6. Arrays
#include <fstream>
#include <iostream>
#include <iomanip>

//Exercise 1. A sequence of numbers is given.
//19)Display elements with even indexes (for a two-dimensional array, 
//the sum of the indexes must be even)

void task1()
{
    //One-dimensional array
    int countp = 0;
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    //Two-dimensional array
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols] = { {1, 2, 3}, {5, 6, 7}, {9, 10, 11} };

    // Opening the file in write mode
    std::ofstream outfile("elements of two arrays.txt"); //file for storing two arrays elements
    if (!outfile.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    // Writing the one-dimensional array elements to the file
    for (int i = 0; i < size; ++i) {
        outfile << arr[i] << " ";
    }
    // Writing the two-dimensional array elements to the file
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
        {
            outfile << matrix[i][j] << " ";
        }
    }

    // Closing the file
    outfile.close();

    // Opening the file in read mode
    std::ifstream infile("elements of two arrays.txt");

    // Reading the one-dimensional array elements from the file
    for (int i = 0; i < size; ++i) {
        infile >> arr[i];
    }
    // Reading the two-dimensional array elements from the file
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            infile >> matrix[i][j];
        }
    }

    // Closing the file
    infile.close();

    // Displaying the one-dimensional array elements
    std::cout << "One-dimensional array elements: \n";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "One-dimensional array elements with even indexes: \n";
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;

    // Displaying the two-dimensional array elements
    std::cout << "Two-dimensional array elements: \n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "Two-dimensional array elements with even indexes: \n";

    //Output of elements with even indexes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                std::cout << matrix[i][j] << " ";
            }
        }
    }
    std::cout << std::endl;
}

//Exercise 2. A sequence of n-real numbers is given
//19) Display a number of pairs of neighboring elements in which 
//the previous element is a multiple of the next one
void task2()
{
    int count = 0;
    int array[5] = { 1, 2, 4, 3, 5};

    // Opening the file in write mode
    std::ofstream outfile("array2.txt");
    if (!outfile.is_open()) {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    // Writing the array elements to the file
    for (int i = 0; i < 5; ++i) {
        outfile << array[i] << " ";
    }

    // Closing the file
    outfile.close();

    // Opening the file in read mode
    std::ifstream infile("array2.txt");

    // Reading the array elements from the file
    for (int i = 0; i < 5; ++i) {
        infile >> array[i];
    }

    // Closing the file
    infile.close();

    // Displaying the array elements
    std::cout << "Array elements: \n";
    for (int i = 0; i < 5; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 1; i != 5; i++) {
        if (array[i] % array[i - 1] == 0) {
            count++;
        }
    } std::cout << "Pairs of neighboring elements in which the previous element is a multiple of the next one: " << count << std::endl;
}

// Exercise 3. An array of size n*n is given (unless otherwise specified), 
// the elements of which are integers.
// 19)Find the maximum in each row and replace it with the opposite element.

void task3()
{  
    // Entering an array size
    std::cout << "Size n*n: ";
    int n;
    std::cin >> n;

    // Creating a dynamic array
    int** array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[n];
    }

    // Entering an elements array
    std::cout << "Elements:";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> array[i][j];
            }
        }

    // Opening the file in write mode
    std::ofstream outfile("array3.txt");
    if (!outfile.is_open()) 
    {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    // Writing the two-dimensional array elements to the file
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            outfile << array[i][j] << " ";
        }
    }

    // Closing the file
    outfile.close();

    // Opening the file in read mode
    std::ifstream infile("array3.txt");

    // Reading the two-dimensional array elements from the file
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            infile >> array[i][j];
        }
    }

    // Closing the file
    infile.close();

    //Displaying an original array
    std::cout << "Original array: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }

    //Finding maximum in each row and replacing with opposite element
    for (int i = 0; i < n; i++) {
        int max = array[i][0];  //1st element is maximal
        int max_j = 0;         //memorizing the maximum position

        // Finding maximum in the row
        for (int j = 1; j < n; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
                max_j = j;
            }
        }

        // Replacing element with opposite
        array[i][max_j] *= -1;
    }

    // Displaying a modified array
    std::cout << "Modified array: \n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }

    //Freeing memory
    for (int i = 0; i < n; i++) {
        delete[] array[i];
    }
    delete[] array;
}

//Exercise 4. An array of size n*n is given, the elements of which are integers.
//19)For each row, find the number of the first pair of unequal elements. 
//Write the data to a new array.

void task4()
{
    // Declaring array size
    int size;

    //Inputing an array size
    std::cout << "Enter the array size (n*n): ";
    std::cin >> size;

    //Creating a dynamic two-dimensional array
    int** matrix = new int* [size];  //Declaring an array
    for (int i = 0; i < size; i++) 
    {
        matrix[i] = new int[size];
    }

    //Creating an array for storing results
    int* results = new int[size];

    //Inputing an array elements
    std::cout << "Elements: " << std::endl;
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    // Opening the file in write mode
    std::ofstream outfile("array4.txt");
    if (!outfile.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    // Writing the two-dimensional array elements to the file
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            outfile << matrix[i][j] << " ";
        }
    }

    // Closing the file
    outfile.close();

    // Opening the file in read mode
    std::ifstream infile("array4.txt");

    // Reading the two-dimensional array elements from the file
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            infile >> matrix[i][j];
        }
    }

    // Closing the file
    infile.close();

    //finding a first pair of unequal elements in the every string
    for (int i = 0; i < size; i++) 
    {
        //A flag to check if a pair has been found.
        bool found = false;

        //checking a string elements
        for (int j = 0; j < size - 1; j++) 
        {
            if (matrix[i][j] != matrix[i][j + 1]) 
            {
                results[i] = j;
                found = true;
                break;  // exit the cycle as soon as we found a pair.
            }
        }

        //If pair is not found, writing "-1"
        if (!found) 
        {
            results[i] = -1;
        }
    }

    //Displaying results
    std::cout << "The numbers of the first pairs of unequal elements:\n";
    for (int i = 0; i < size; i++) 
    {
        std::cout << results[i] << " ";
    }

    std::cout << std::endl;
}

//Exercise 5.
//In a one-dimensional array whose elements are integers, perform the following actions:
// 19th option. Example 4. Remove all elements from the array whose last digit is equal to this value. 

void task5()
{
    int arr[5];

    std::cout << "Enter the array numbers: ";

    for (int i = 0; i < 5; ++i)
    {
        std::cin >> arr[i];
    }

    // Opening the file in write mode
    std::ofstream outfile("array5.txt");
    if (!outfile.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    // Writing the array elements to the file
    for (int i = 0; i < 5; ++i)
    {
        outfile << arr[i] << " ";
    }

    // Closing the file
    outfile.close();

    // Opening the file in read mode
    std::ifstream infile("array5.txt");

    // Reading the array elements from the file
    for (int i = 0; i < 5; ++i)
    {
        infile >> arr[i];
    }

    // Closing the file
    infile.close();

    int x;

    std::cout << "Enter the number for search: ";
    std::cin >> x;

    int s = 0;

    for (int i = 0; i < 5; ++i) 
    {
        arr[i - s] = arr[i];

        if (arr[i] == x) 
        {
            ++s;
        }
    }

    //output a modified array
    std::cout << "The array after removing elements: \n";
    for (int i = 0; i < 5 - s; ++i) 
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

//Exercise 6.
//In a two - dimensional array whose elements are integers, perform the following actions :
//19th option. Example 4. 
// Insert a new column in front of all columns in which the specified number occurs.

void task6() 
{
    int n, f, m, number;

    //entering the number of rows and columns
    std::cout << "Rows: ";
    std::cin >> n;
    std::cout << "Columns: ";
    std::cin >> m;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[2 * m];

    //entering the numbers of array
    std::cout << "Numbers: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

    // Opening the file in write mode
    std::ofstream outfile("array6.txt");
    if (!outfile.is_open())
    {
        std::cerr << "Failed to open file for writing." << std::endl;
    }

    // Writing the two-dimensional array elements to the file
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            outfile << a[i][j] << " ";
        }
    }

    // Closing the file
    outfile.close();

    // Opening the file in read mode
    std::ifstream infile("array6.txt");

    // Reading the two-dimensional array elements from the file
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            infile >> a[i][j];
        }
    }

    // Closing the file
    infile.close();

    //entering the numbers for column
    int* x = new int[n];
    std::cout << "The numbers for a new column: ";
    for (int i = 0; i < n; i++)
        std::cin >> x[i];

    //entering the number for search
    std::cout << "The number for search: ";
    std::cin >> number;

    //output a source array
    std::cout << "Source array: \n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    //inserting a new column into the source array
    for (int j = 0; j < m; j++)
    {
        f = 0;
        for (int i = 0; i < n; i++)
            if (a[i][j] == number)
            {
                f = 1;
                break;
            }
        if (f == 1)
        {
            for (int k = m; k > j; k--)
                
                for (int i = 0; i < n; i++)
                    a[i][k] = a[i][k - 1];
            
            for (int i = 0; i < n; i++)
                a[i][j] = x[i];
            
            m++; 
            j++;
        }
    }

    //output a modified array
    std::cout << "The array after inserting columns: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    //freeing up memory
    for (int i = 0; i < n; i++)
        delete a[i];
    
    delete[]a;
}

int main()
{
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();

    return 0;
}
