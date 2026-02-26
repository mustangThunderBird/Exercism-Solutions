#include "rna_transcription.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_rna(const char *dna)
{
    size_t size = strlen(dna) +1;
    char* rna = (char *)malloc(size * sizeof(char));
    strcpy(rna, dna);
    char* start = rna;
    while(*rna != '\0')
    {
        if(*rna == 'G'){
            *rna = 'C';
        } 
        else if(*rna == 'C'){
            *rna = 'G';
        }  
        else if(*rna == 'T'){
            *rna = 'A';
        }  
        else if(*rna == 'A'){
            *rna = 'U';
        }
        ++rna;
    }
    return start;
}