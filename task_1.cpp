#include <iostream>
#include <cstdlib> 

int* find_zero(int** matrix, int rows, int cols, int& zero_cnt) {
    int* has_zero = (int*)calloc(cols, sizeof(int));
    if (!has_zero) return nullptr;
    zero_cnt = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                has_zero[j] = 1;
                zero_cnt++;
                break;
            }
        }
    }

    if (zero_cnt == 0) {
        free(has_zero);
        return nullptr;
    }

    int* zero_cols = (int*)malloc(zero_cnt * sizeof(int));
    if (!zero_cols) {
        free(has_zero);
        return nullptr;
    }

    int index = 0;
    for (int j = 0; j < cols; j++) {
        if (has_zero[j] == 1) {
            zero_cols[index++] = j;
        }
    }
    free(has_zero);

    return zero_cols;
}

void remove_columns(int**& matrix, int rows, int& cols, int* zero_cols, int zero_cnt) {
    if (zero_cnt == 0 || !zero_cols) return;

    int new_cols_count = cols - zero_cnt;

    int** temp_matrix = (int**)malloc(rows * sizeof(int*));
    if (!temp_matrix) return;

    for (int i = 0; i < rows; i++) {
        temp_matrix[i] = (int*)malloc(new_cols_count * sizeof(int));
        if (!temp_matrix[i]) {

            for (int k = 0; k < i; k++) free(temp_matrix[k]);
            free(temp_matrix);
            return;
        }

        int new_j = 0;
        for (int j = 0; j < cols; j++) {
            bool skip = false;
            for (int k = 0; k < zero_cnt; k++) {
                if (j == zero_cols[k]) {
                    skip = true;
                    break;
                }
            }

            if (!skip) {
                temp_matrix[i][new_j++] = matrix[i][j];
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    matrix = temp_matrix;
    cols = new_cols_count;
}

void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int rows = 2;
    int cols = 2;

    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (!matrix) return 1;

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (!matrix[i]) {

            for (int k = 0; k < i; k++) free(matrix[k]);
            free(matrix);
            return 1;
        }
    }

    int a, b, c, d;
    do {
        std::cout << "Число А: ";
        std::cin >> a;
        std::cout << "Число В: ";
        std::cin >> b;

        if ((a < 0) || (b < 0)) {
            std::cout << "Ошибка! A и B должны быть неотрицательными. Повторите ввод." << std::endl;
        }
    } while ((a < 0) || (b < 0));

    std::cout << "Введите C: ";
    std::cin >> c;
    std::cout << "Введите D: ";
    std::cin >> d;

    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;

    std::cout << "\nИсходная матрица 2x2:" << std::endl;
    print_matrix(matrix, rows, cols);

    int new_rows = 2 + a;
    int new_cols = 2 + b;

    int** temp = (int**)realloc(matrix, new_rows * sizeof(int*));
    if (!temp) {
        std::cout << "Ошибка выделения памяти!" << std::endl;

        for (int i = 0; i < rows; i++) free(matrix[i]);
        free(matrix);
        return 1;
    }
    matrix = temp;

    for (int i = 0; i < new_rows; i++) {
        if (i < rows) {
            int* row_temp = (int*)realloc(matrix[i], new_cols * sizeof(int));
            if (!row_temp) {
                std::cout << "Ошибка выделения памяти!" << std::endl;
                for (int k = 0; k < i; k++) free(matrix[k]);
                for (int k = rows; k < new_rows; k++) free(matrix[k]);
                free(matrix);
                return 1;
            }
            matrix[i] = row_temp;

            for (int j = cols; j < new_cols; j++) {
                matrix[i][j] = 0; 
            }
        }
        else {
            matrix[i] = (int*)calloc(new_cols, sizeof(int));
            if (!matrix[i]) {
                std::cout << "Ошибка выделения памяти!" << std::endl;
                for (int k = 0; k < i; k++) free(matrix[k]);
                free(matrix);
                return 1;
            }
        }
    }
    rows = new_rows;
    cols = new_cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i < 2) && (j < 2)) {
                continue;
            }
            else {
                matrix[i][j] = ((i - 1) * c) + ((j - 1) * d);
            }
        }
    }
    std::cout << "\nРасширенная матрица " << rows << "x" << cols << ":" << std::endl;
    print_matrix(matrix, rows, cols);

    int zero_cnt;
    int* zero_cols = find_zero(matrix, rows, cols, zero_cnt);

    if (zero_cnt > 0) {
        std::cout << "\nНайдено столбцов с нулями: " << zero_cnt << std::endl;
        remove_columns(matrix, rows, cols, zero_cols, zero_cnt);

        std::cout << "\nМатрица после удаления столбцов с нулями:" << std::endl;
        print_matrix(matrix, rows, cols);
    }
    else {
        std::cout << "\nСтолбцов с нулевыми значениями не найдено." << std::endl;
    }
    if (zero_cols) free(zero_cols);

    if (matrix) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i]) free(matrix[i]);
        }
        free(matrix);
    }

    return 0;
}