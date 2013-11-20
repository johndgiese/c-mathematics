#include <iso646.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <tgmath.h>
#include <float.h>


#define PROBLEM(chapter, number) printf("\nPROBLEM %2d.%-4d\n", chapter, number)
#define PRINT(exp) printf("%s", #exp)
#define PRINT_INT(exp) printf("%34s = %d\n", #exp, (exp))
#define PRINT_DBL(exp) printf("%34s = %g\n", #exp, (exp))
#define PRINT_CDB(exp) printf("%34s = %g + %gi\n", #exp, creal(exp), cimag(exp))
#define PRINT_PTR(exp) printf("%34s = %p\n", #exp, (void *)(exp))

#define SECTION(exp) printf("\n\n%s\n", #exp)

int main() {

    SECTION(INDETERMINATE FORMS);
    PRINT_DBL(pow(0.0, 0.0));
    PRINT_DBL(pow(0.0, 0.0 + DBL_EPSILON));
    PRINT_DBL(pow(0.0, 0.0 - DBL_EPSILON));

    PRINT_DBL(0.0/0.0);

    PRINT_DBL(pow(1, INFINITY));
    PRINT_DBL(pow(1 + DBL_EPSILON, INFINITY));
    PRINT_DBL(pow(1 - DBL_EPSILON, INFINITY));

    PRINT_DBL(INFINITY - INFINITY);

    PRINT_DBL(0*INFINITY);
    
    PRINT_DBL(pow(INFINITY, 0.0));
    PRINT_DBL(pow(INFINITY, 0.0 + DBL_EPSILON));
    PRINT_DBL(pow(INFINITY, 0.0 - DBL_EPSILON));


    SECTION(NAN PROPAGATION);
    double d = 3.14;
    PRINT_DBL(d);
    PRINT_DBL(d + NAN);
    PRINT_DBL(d - NAN);
    PRINT_DBL(d*NAN);
    PRINT_DBL(d/NAN);


    SECTION(NAN COMPARISON);
    PRINT_INT(d > NAN);
    PRINT_INT(d == NAN);
    PRINT_INT(d < NAN);


    SECTION(COMPLEX NUMBERS AND INF AND NAN);
    complex double c = 1 + 2*I;
    PRINT_CDB(c);
    PRINT_CDB(c + INFINITY);
    PRINT_CDB(c + INFINITY*I);
    PRINT_CDB(c + NAN);
    PRINT_CDB(c + NAN*I);

    exit(0);
}
