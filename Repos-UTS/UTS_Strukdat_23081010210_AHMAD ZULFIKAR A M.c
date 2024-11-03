#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct peserta {
    char nama[20];
    char gender;
    struct peserta *next;
};
typedef struct peserta peserta;

int hitungpeserta = 0;

void tranverse(peserta *head);
void tambahCindy(peserta *head, int *tambah);
void tambahIrsyad(peserta **head);
void tambahpeserta(peserta **head);
void hapuspeserta(peserta **head);
void pisahlingkaran(peserta *head);

int main()
{
  peserta *head;
  int pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. cetak isi peserta\n");
     printf("2. tambah Irsyad dan Arsyad\n");
     printf("3. tambah peserta\n");
     printf("4. hapus peserta\n");
     printf("5. cetak lingkaran mahasiswa dan mahasiswi\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf(" %d", &pilih);
     if (pilih == 1){
            tranverse(head);
            getch();
     }
     else if (pilih == 2){
            tambahIrsyad(&head);
     }
     else if (pilih == 3){
            tambahpeserta(&head);
     }
     else if (pilih == 4){
            hapuspeserta(&head);
     }
     else if (pilih == 5){
            pisahlingkaran(head);
     }

  } while (pilih != 0);

  return 0;
}

void tranverse(peserta *head) {
    peserta *pWalker;

    system("cls");
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }

    pWalker = head;
    printf("Lingkaran berisi:\n");

    printf("%s (%c) -> ", pWalker->nama, pWalker->gender);

    pWalker = pWalker->next;
    while (pWalker != head) {
        printf("%s (%c) -> ", pWalker->nama, pWalker->gender);
        pWalker = pWalker->next;
    }

    printf("%s (%c)\n", head->nama, head->gender);
}

void tambahCindy(peserta *head, int *tambah) {
    peserta *temp = head;
    *tambah = 0;

    if (temp == NULL) {
        printf("Cindy tidak bisa ditambahkan karena lingkaran kosong.\n");
        return;
    }

    do {
        if (temp->gender == 'P' && temp->next->gender == 'P') {
            *tambah = 1;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Cindy tidak bisa ditambahkan karena tidak bergandengan dengan mahasiswi.\n");
}

void tambahIrsyad(peserta **head) {
    if (hitungpeserta + 2 > 20) {
        printf("Tidak bisa menambahkan Irsyad dan Arsyad, lingkaran penuh.\n");
        getch();
        return;
    }

    peserta *irsyad = (peserta *)malloc(sizeof(peserta));
    peserta *arsyad = (peserta *)malloc(sizeof(peserta));

    strcpy(irsyad->nama, "Irsyad");
    irsyad->gender = 'L';
    strcpy(arsyad->nama, "Arsyad");
    arsyad->gender = 'L';

    if (*head == NULL) {
        *head = irsyad;
        irsyad->next = arsyad;
        arsyad->next = *head;
    } else {
        peserta *temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = irsyad;
        irsyad->next = arsyad;
        arsyad->next = *head;
    }

    printf("Irsyad dan Arsyad ditambahkan.\n");
    getch();
    hitungpeserta += 2;
}

void tambahpeserta(peserta **head) {
    if (hitungpeserta >= 20) {
        printf("Lingkaran penuh.\n");
        getch();
        return;
    }

    peserta *pNew = (peserta *)malloc(sizeof(peserta));

    printf("Masukkan nama: ");
    scanf("%s", pNew->nama);
    printf("Gender (L/P): ");
    scanf(" %c", &pNew->gender);

    if (strcmp(pNew->nama, "Cindy") == 0) {
        int tambah = 0;
        tambahCindy(*head, &tambah);
        if (!tambah) {
            free(pNew);
            getch();
            return;
        }
    }

    if (*head == NULL) {
        *head = pNew;
        pNew->next = *head;
    } else {
        peserta *temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = pNew;
        pNew->next = *head;
    }

    hitungpeserta++;
    printf("%s ditambahkan.\n", pNew->nama);
    getch();
}

void hapuspeserta(peserta **head) {
    if (*head == NULL) {
        printf("List kosong. Tidak ada peserta untuk dihapus.\n");
        getch();
        return;
    }

    char nama[20];
    printf("Masukkan nama peserta yang akan dihapus: ");
    scanf("%s", nama);

    peserta *temp = *head;
    peserta *prev = NULL;

    do {
        if (strcmp(temp->nama, nama) == 0) {
            if (prev == NULL) {
                if (temp->next == *head) {
                    free(temp);
                    *head = NULL;
                } else {
                    peserta *last = *head;
                    while (last->next != *head) last = last->next;
                    last->next = temp->next;
                    free(temp);
                    *head = last->next;
                }
            } else {
                prev->next = temp->next;
                free(temp);
            }
            hitungpeserta--;
            printf("%s telah dihapus.\n", nama);
            getch();
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != *head);

    printf("Peserta dengan nama %s tidak ditemukan.\n", nama);
    getch();
}

void pisahlingkaran(peserta *head) {

    if (head == NULL) {
        printf("List kosong. Tidak ada peserta untuk dipisahkan.\n");
        getch();
        return;
    }

    peserta *headL = NULL, *headP = NULL, *temp = head, *pNew;

    do {
        pNew = (peserta *)malloc(sizeof(peserta));
        strcpy(pNew->nama, temp->nama);
        pNew->gender = temp->gender;
        pNew->next = pNew;

        if (temp->gender == 'L') {
            if (headL == NULL) {
                headL = pNew;
            } else {
                peserta *pWalker = headL;
                while (pWalker->next != headL) pWalker = pWalker->next;
                pWalker->next = pNew;
            }
            pNew->next = headL;
        } else if (temp->gender == 'P') {
            if (headP == NULL) {
                headP = pNew;
            } else {
                peserta *pWalker = headP;
                while (pWalker->next != headP) pWalker = pWalker->next;
                pWalker->next = pNew;
            }
            pNew->next = headP;
        }

        temp = temp->next;
    } while (temp != head);

    printf("\nLingkaran Laki-laki:\n");
    tranverse(headL);
    getch();
    printf("\nLingkaran Perempuan:\n");
    tranverse(headP);
    getch();
}

