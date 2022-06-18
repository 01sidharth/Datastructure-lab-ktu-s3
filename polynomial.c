#include <stdio.h>
struct poly
{
    int coeff;
    int expo;
} p1[10], p2[10], psum[20];

int readPoly(struct poly p[10]) {
    int n, i;

    printf("How many terms? : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter coeff of term %d: ", i+1);
        scanf("%d", &p[i].coeff);
        printf("Enter exponent of term %d: ", i+1);
        scanf("%d", &p[i].expo);
    }

    return(n);
}

void printPoly(struct poly p[10], int n) {
    int i;

    for(i = 0; i < n; i++) {
        if (p[i].expo == 0) {
            printf("%d", p[i].coeff);
        }
        else {
            printf("%dx^%d", p[i].coeff, p[i].expo);
        }

        if(i == n - 1)
            break;
        else
            printf(" + ");
    }

    printf("\n");
}

void sortPoly(struct poly p[10], int n) {
    int i, j;
    struct poly temp;

    for (j = 1; j < n; j++) {
        for (i = 0; i < n-j; i++) {
            if (p[i+1].expo > p[i].expo) {
                temp = p[i+1];
                p[i+1] = p[i];
                p[i] = temp;
            }
        }
    }
}

int addPoly(struct poly p1[10], int n1, struct poly p2[10], int n2, struct poly psum[20]) {
    int i=0, j=0, k=0;

    while (i != n1 && j != n2) {
        if (p1[i].expo > p2[j].expo) {
            psum[k].expo = p1[i].expo;
            psum[k].coeff = p1[i].coeff;
            k++; i++;
        }
        else if (p1[i].expo < p2[j].expo) {
            psum[k].expo = p2[j].expo;
            psum[k].coeff = p2[j].coeff;
            k++; j++;
        }
        else {
            psum[k].expo = p1[i].expo;
            psum[k].coeff = p1[i].coeff + p2[j].coeff;
            k++; i++; j++;
        }
    }

    if (i != n1 && j == n2) {
        while (i != n1) {
            psum[k].expo = p1[i].expo;
            psum[k].coeff = p1[i].coeff;
            k++; i++;
        }
    }
    if (i == n1 && j != n2) {
        while (j != n2) {
            psum[k].expo = p2[j].expo;
            psum[k].coeff = p2[j].coeff;
            k++; j++;
        }
    }

    return k;
}

int main()
{
    int n1, n2, nsum;

    printf("Enter only non-zero coefficients!!!\n");

    printf("\nPolynomial 1\n");
    n1 = readPoly(p1);

    sortPoly(p1, n1);

    printf("Polynomial 1 is ");
    printPoly(p1, n1);

    printf("\nPolynomial 2\n");
    n2 = readPoly(p2);

    sortPoly(p2, n2);

    printf("Polynomial 2 is ");
    printPoly(p2, n2);

    nsum = addPoly(p1, n1, p2, n2, psum);

    sortPoly(psum, nsum);

    printf("\nSum of polynomials is ");
    printPoly(psum, nsum);

    return 0;
}

