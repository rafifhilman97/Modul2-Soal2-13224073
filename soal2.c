// PRAKTIKUM PMP 
// Modul      : DATA MANIPULATION, EXTERNAL FILES,  STRUCTURES AND DYNAMIC ARRAYS
// Nama       : Rafif Hilman Muhammad
// NIM        : 13224073
// Nomor Soal : 2 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // JANGAN LUPA UBAH PIP

struct bunga {
    int tinggi; // tinggi bunga batahari                       
    int posisi; // urutan bunga ke berapa       
    struct bunga* next;
    struct bunga* prev;
};

struct bunga* tanambunga(int tinggiBaru, int posisiBaru) {
    struct bunga* bungaBaru = (struct bunga*)malloc(sizeof(struct bunga));
    
    if (bungaBaru == NULL) {
        printf("Alokasi memori gagal!\n");
        exit(1);
    }
    
    bungaBaru->tinggi = tinggiBaru;
    bungaBaru->posisi = posisiBaru;
    bungaBaru->next = NULL;
    bungaBaru->prev = NULL;
    
    return bungaBaru;
}

void tambahDiAkhir(struct bunga** head_ref, int tinggiBaru, int posisiBaru) {
    struct bunga* bungaBaru = tanambunga(tinggiBaru, posisiBaru);
    
    if (*head_ref == NULL) {
        *head_ref = bungaBaru;
        return;
    }

    struct bunga* terakhir = *head_ref;
    while (terakhir->next != NULL) {
        terakhir = terakhir->next;
    }
    terakhir->next = bungaBaru;
    bungaBaru->prev = terakhir;
}

void tidakKena(struct bunga* head_ref){
    if (head_ref == NULL) {
        printf("NONE\n");
        return;
    }
    while (head_ref != NULL){
        if (head_ref->prev != NULL && head_ref->next != NULL){
            if (head_ref->tinggi < head_ref->next->tinggi && head_ref->tinggi < head_ref->prev->tinggi){
                printf("%d ", head_ref->posisi);
            }
        }
        head_ref = head_ref->next;
    }
}

int main(void){
    struct bunga *head = NULL;\

    for (int i = 1; i <= MAX; i++){
        int n = 0;
        scanf("%d", &n);
        tambahDiAkhir(&head, n, i);
        char c = getchar();
        if (c == '\n'){
            break;
        }
    }

    tidakKena(head);
    return 0;
}
