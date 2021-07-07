/*  simple to program performing matrix operations
    
*/
#include <iostream>

   
    /* Global Variables */
    double scalar;

    // Matrix A
    const int LEN_ROW_A = 3;
    const int LEN_COLUMN_A = 3;
    const int SIZE_MATRIX_A = 3 * 3;
    // Matirix B
    const int LEN_ROW_B = 3;
    const int LEN_COLUMN_B = 3;
    const int SIZE_MATRIX_B = 3 * 3;


// Prints the matrix result
int print_matrix(int p_matrix[LEN_ROW_A][LEN_COLUMN_A]){

    for (int i = 0; i < LEN_ROW_A; i++)
    {
        for (int j = 0; j < LEN_COLUMN_A; j++)
        {
            std::cout << p_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}



// function for adding matricies
int adder(int one[LEN_ROW_A][LEN_COLUMN_A], int two[LEN_ROW_B][LEN_COLUMN_B]){
    int result_adder[LEN_ROW_A][LEN_COLUMN_A];

    for (int i = 0; i < LEN_ROW_A; i++)
    {
        for (int j = 0; j < LEN_COLUMN_A; j++)
        {
            result_adder[i][j] = one[i][j] + two[i][j];
        }
    }

    print_matrix(result_adder); // function call to print results

    return 0;
}

// function for subtracting matricies
int subtractor(int one[LEN_ROW_A][LEN_COLUMN_A], int two[LEN_ROW_B][LEN_COLUMN_B]){
    int result_subtractor[LEN_ROW_A][LEN_COLUMN_A];

    for (int i = 0; i < LEN_ROW_A; i++)
    {
        for (int j = 0; j < LEN_COLUMN_A; j++)
        {
            result_subtractor[i][j] = one[i][j] - two[i][j];
        }
    }

    print_matrix(result_subtractor); // function call to print results

    return 0;
}

// function for scalar multiplication matricies
int scalar_multiplication(int one[LEN_ROW_A][LEN_COLUMN_A]){
    int result_scalar_multiplication[LEN_ROW_A][LEN_COLUMN_A];

    for (int i = 0; i < LEN_ROW_A; i++)
    {
        for (int j = 0; j < LEN_COLUMN_A; j++)
        {
            result_scalar_multiplication[i][j] = one[i][j] * scalar;
        }
    }

    print_matrix(result_scalar_multiplication); // function call to print results

    return 0;
}


int main() {
    int choice;
    int matrix_a[LEN_ROW_A][LEN_COLUMN_A] = {{1,2,0}, {5,6,3},  {8,4,9}};
    int matrix_b[LEN_ROW_B][LEN_COLUMN_B] = {{6,3,7}, {2,5,4},  {9,0,2}};

    std::cout << "Chose an option" << std::endl;
    std::cout << "1. Matrix Addition" << std::endl;
    std::cout << "2. Matrix Subtraction" << std::endl;
    std::cout << "3. Scalar Multipilcation" << std::endl;
    std::cout << "0. Quit" << std::endl << "> ";
    std::cin >> choice;


    // Operation choices
    switch (choice)
    {
    case 1:
        std::cout << "\nMatrix A + B:" << std::endl;
        adder(matrix_a, matrix_b);
        break;
    
    case 2:
        std::cout << "\nMatrix A - B:" << std::endl;
        subtractor(matrix_a, matrix_b);
        break;

    case 3:
        std::cout << "\nInput the scalar" << std::endl;
        std::cin >> scalar;
        std::cout << scalar << " x Matrix A:" << std::endl;
        scalar_multiplication(matrix_a);
        break;

    default:
        break;
    }

    return 0;
}