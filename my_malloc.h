#if !defined(MY_MALLOC_H)
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MY_MALLOC_H
#define TAMANHO_MAX_MALLOC (2048)

static unsigned char Buff[TAMANHO_MAX_MALLOC];
static struct bloco_struct *ListaLivre=(void*)Buff;
struct bloco_struct
{
    size_t tamanho;
    bool livre;
    struct bloco_struct *proximo;
};

int MyMallocInit();
void *MyMalloc(size_t numBytes);
void MyMallocSplit(struct bloco_struct *fitting_slot,size_t tamanho);
void MyMallocMerge();
int MyMallocFree(void *buffer);
void MyMallocGerency();

#endif