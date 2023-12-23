#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to insert a term into a polynomial
void insertTerm(Term** poly, int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = *poly;
    *poly = newTerm;
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 && poly2) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

// Function to print a polynomial
void printPolynomial(Term* poly) {
    while (poly) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free memory used by a polynomial
void freePolynomial(Term* poly) {
    while (poly) {
        Term* temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    // Initialize and insert terms into the first polynomial
    Term* poly1 = NULL;
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 4, 1);
    insertTerm(&poly1, 5, 0);

    // Initialize and insert terms into the second polynomial
    Term* poly2 = NULL;
    insertTerm(&poly2, 2, 3);
    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 1, 0);

    // Add the polynomials
    Term* result = addPolynomials(poly1, poly2);

    // Print the polynomials
    printf("First Polynomial: ");
    printPolynomial(poly1);

    printf("Second Polynomial: ");
    printPolynomial(poly2);

    printf("Sum of Polynomials: ");
    printPolynomial(result);

    // Free memory used by the polynomials
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}

