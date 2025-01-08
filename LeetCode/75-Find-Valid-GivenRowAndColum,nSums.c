/*int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    int** res = (int**)malloc(rowSumSize * sizeof(int*));
    for (int i = 0; i < rowSumSize; i++) {
        res[i] = (int*)calloc(colSumSize, sizeof(int));
    }

    int cur_row = 0, cur_col = 0;
    *returnSize = rowSumSize;
    *returnColumnSizes = (int*)malloc(rowSumSize * sizeof(int));
    for (int i = 0; i < rowSumSize; i++) {
        (*returnColumnSizes)[i] = colSumSize;
    }

    while (cur_row < rowSumSize || cur_col < colSumSize) {
        if (cur_row >= rowSumSize) {
            res[rowSumSize - 1][cur_col] = colSum[cur_col];
            cur_col++;
            continue;
        } else if (cur_col >= colSumSize) {
            res[cur_row][colSumSize - 1] = rowSum[cur_row];
            cur_row++;
            continue;
        }

        int value_to_put = rowSum[cur_row] < colSum[cur_col] ? rowSum[cur_row] : colSum[cur_col];
        rowSum[cur_row] -= value_to_put;
        colSum[cur_col] -= value_to_put;
        res[cur_row][cur_col] = value_to_put;

        // I write this as this because it's possible that rowSum[cur_row] == colSum[cur_col] and we'll want to move both row and col pointers
        if (rowSum[cur_row] == 0) {
            cur_row++;
        }
        if (colSum[cur_col] == 0) {
            cur_col++;
        }
    }
    return res;
}*/

int **restoreMatrix(int *rowSum, int rowSumSize, int *colSum, int colSumSize, int *returnSize, int **returnColumnSizes)
{
    int **res = (int **)malloc(rowSumSize * sizeof(int *));
    for (int i = 0; i < rowSumSize; i++)
    {
        res[i] = (int *)calloc(colSumSize, sizeof(int));
    }

    int cur_row = 0, cur_col = 0;
    *returnSize = rowSumSize;
    *returnColumnSizes = (int *)malloc(rowSumSize * sizeof(int));
    for (int i = 0; i < rowSumSize; i++)
    {
        (*returnColumnSizes)[i] = colSumSize;
    }

    while (cur_row < rowSumSize || cur_col < colSumSize)
    {
        if (cur_row >= rowSumSize)
        {
            res[rowSumSize - 1][cur_col] = colSum[cur_col];
            cur_col++;
            continue;
        }
        else if (cur_col >= colSumSize)
        {
            res[cur_row][colSumSize - 1] = rowSum[cur_row];
            cur_row++;
            continue;
        }

        int value_to_put = rowSum[cur_row] < colSum[cur_col] ? rowSum[cur_row] : colSum[cur_col];
        rowSum[cur_row] -= value_to_put;
        colSum[cur_col] -= value_to_put;
        res[cur_row][cur_col] = value_to_put;

        // I write this as this because it's possible that rowSum[cur_row] == colSum[cur_col] and we'll want to move both row and col pointers
        if (rowSum[cur_row] == 0)
        {
            cur_row++;
        }
        if (colSum[cur_col] == 0)
        {
            cur_col++;
        }
    }
    return res;
}