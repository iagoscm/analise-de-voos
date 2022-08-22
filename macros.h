#ifndef MACROS_H
#define MACROS_H

// Macro para definir menor que
#define LESS(A, B) (A < B)

// Macro para fazer troca
#define EXCH(A, B) \
    {              \
        int t = B; \
        B = A;     \
        A = t;     \
    }

// Macro para comparar e trocar
#define CMPEXCH(A, B)   \
    {                   \
        if (LESS(B, A)) \
            EXCH(A, B); \
    }

typedef struct {
    char nome[3];
    short int delay;
} rawData;

#endif
