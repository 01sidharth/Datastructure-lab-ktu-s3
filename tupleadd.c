#include <stdio.h>

struct tuple {
    int row;
    int col;
    int val;
};

void printTuple(struct tuple t[20], int n) {
    int i;

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d", t[i].row, t[i].col, t[i].val);
        printf("\n");
    }

    printf("\n");
}

void transTuple(struct tuple t[20], int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        temp = t[i].row;
        t[i].row = t[i].col;
        t[i].col = temp;
    }
}

void fastTrans(struct tuple a[20]) {
    struct tuple b[20];
    int row_terms[a[0].col], start_pos[a[0].col];
    int i, j, num_cols = a[0].col, num_terms = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    for (i = 0; i < num_cols; i++)
        row_terms[i] = 0;

    for (i = 1; i <= num_terms; i++)
        row_terms[a[i].col]++;

    start_pos[0] = 1;

    for (i = 1; i <= num_cols; i++)
        start_pos[i] = start_pos[i-1] + row_terms[i-1];

    for (i = 1; i <= num_terms; i++) {
        j = start_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].val = a[i].val;
    }

    printTuple(b, b[0].val+1);

}
void addTuple(struct tuple a[20], int n1, struct tuple b[20], int n2) {
    int i = 1, j = 1, k = 1;

    struct tuple c[40];
    
    c[0] = a[0];

    while(i != n1 && j != n2) {
        if(a[i].row < b[j].row) {
            c[k] = a[i];
            k++; i++;
        }
        else if(a[i].row > b[j].row) {
            c[k] = b[j];
            k++; j++;
        }
        else {
            if(a[i].col < b[j].col) {
                c[k] = a[i];
                k++; i++;
            }
            else if(a[i].col > b[j].col) {
                c[k] = b[j];
                k++; j++;
            }
            else {
                c[k] = a[i];
                c[k].val = a[i].val + b[j].val;
                k++; i++; j++;
            }
        }
    }
    
    if(i != n1 && j == n2)
        while(i != n1) {
            c[k] = a[i];
            k++; i++;
        }
    
    if(i == n1 && j != n2)
        while(j != n2) {
            c[k] = b[j];
            k++; j++;
        }
    
    c[0].val = k-1;
    
    printf("Sum of tuples :-");
    printTuple(c, k);
}

int main() {
    int row1, col1, row2, col2, m1count = 0, m2count = 0, i, j, k;

    printf("\nMatrix 1 :-");
    printf("\nHow many rows? : ");
    scanf("%d", &row1);
    printf("\nHow many columns? : ");
    scanf("%d", &col1);

    int mat1[row1][col1];

    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Enter element [%d][%d] :", i, j);
            scanf("%d", &mat1[i][j]);
            if (mat1[i][j] != 0)
                m1count++;
        }
    }

    printf("\nMatrix 2 :-");
    printf("\nHow many rows? : ");
    scanf("%d", &row2);
    printf("\nHow many columns? : ");
    scanf("%d", &col2);

    int mat2[row2][col2];

    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Enter element [%d][%d] :", i, j);
            scanf("%d", &mat2[i][j]);
            if (mat2[i][j] != 0)
                m2count++;
        }
    }

    struct tuple tup1[m1count+1], tupTrans1[m1count+1], tup2[m2count+1];

    k = 1;

    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            if (mat1[i][j] != 0) {
                tup1[k].row = i;
                tup1[k].col = j;
                tup1[k].val = mat1[i][j];
                k++;
            }
        }
    }

    tup1[0].row = row1;
    tup1[0].col = col1;
    tup1[0].val = m1count;

    k = 1;

    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            if (mat2[i][j] != 0) {
                tup2[k].row = i;
                tup2[k].col = j;
                tup2[k].val = mat2[i][j];
                k++;
            }
        }
    }

    tup2[0].row = row2;
    tup2[0].col = col2;
    tup2[0].val = m2count;

    printf("\n\nTuple form of Matrix 1:\n");
    printTuple(tup1, m1count+1);

    printf("\n\nTuple form of Matrix 2:\n");
    printTuple(tup2, m2count+1);

    printf("\n\nTuple form of Transpose of Matrix 1:\n");
    fastTrans(tup1);

    printf("\n\nTuple form of Transpose of Matrix 2:\n");
    fastTrans(tup2);
    
    if(tup1[0].row == tup2[0].row && tup1[0].col == tup2[0].col)
        addTuple(tup1, m1count+1, tup2, m2count+1);
    else
        printf("Can't add the two matrices!");
}
