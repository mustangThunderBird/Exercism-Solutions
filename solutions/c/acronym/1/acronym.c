#include "acronym.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char *abbreviate(const char *phrase){
    if (!phrase) return NULL;

    int notEmpty = strcmp("", phrase);
    if(notEmpty == 0){
        return NULL;
    }

    size_t n = strlen(phrase);
    char *out = malloc(n + 1);
    if (!out) return NULL;

    size_t j = 0;
    int take = 1;

    for (size_t i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)phrase[i];
        if (isalpha(c)) {
            if (take) out[j++] = (char)toupper(c);
            take = 0;
        } else if (c == ' ' || c == '-' || c == '_') {
            take = 1;
        } else {
            take = 0;
        }
    }

    out[j] = '\0';
    return out;  
}