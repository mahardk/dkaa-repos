#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node node;

// Deklarasi fungsi
void tambahAwal(node **pList);
void tambahData(node **pList);
void tambahAkhir(node **pList);
void hapusAwal(node **pList);
void hapusTengah(node **pList);
void hapusAkhir(node **pList);
void cariData(node *pList);
void hitungData(node *pList);
void jumlahData(node *pList);
void tranverse(node *pList);

int main()
{
  node *pList;
  int pilih;

  pList = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. cetak isi list\n");
     printf("2. tambah data di awal list\n");
     printf("3. tambah data di tengah setelah head dari pList\n");
     printf("4. tambah data di akhir sebelum tail dari pList\n");
     printf("5. hapus data di awal list\n");
     printf("6. hapus data di tengah list\n");
     printf("7. hapus data di akhir list\n");
     printf("8. cari data\n");
     printf("9. informasi jumlah data\n");
     printf("10. Penjumlahan seluruh nilai data\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf(" %d", &pilih);
     if (pilih == 1){
            tranverse(pList);
            getch();
     }
     else if (pilih == 2){
            tambahAwal(&pList);
     }
     else if (pilih == 3){
            tambahData(&pList);
     }
     else if (pilih == 4){
            tambahAkhir(&pList);
     }
     else if (pilih == 5){
            hapusAwal(&pList);
     }
     else if (pilih == 6){
            hapusTengah(&pList);
     }
     else if (pilih == 7){
            hapusAkhir(&pList);
     }
     else if (pilih == 8){
            cariData(pList);
     }
     else if (pilih == 9) {
            hitungData(pList);
     }
     else if (pilih == 10){
            jumlahData(pList);
     }

} while (pilih != 0);

  return 0;
}


//===========================================================
void tambahAwal(node **pList) {
    int bil;
    node *pNew, *pPre;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;
        if (*pList == NULL) {
            pNew->next = pNew;
            *pList = pNew;
        } else {
            pPre = *pList;
            while (pPre->next != *pList) {
                pPre = pPre->next;
            }
            pNew->next = *pList;
            *pList = pNew;
            pPre->next = *pList;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//===========================================================
void tambahData(node **pList) {
    int pos, bil;
    node *pNew, *pCur;

    if (*pList == NULL) {
        printf("List kosong, tidak bisa tambah di tengah.");
        getch();
        return;
    }

    system("cls");
    tranverse(*pList);
    printf("\nPosisi penyisipan setelah data bernilai: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan: ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *pList;
    do {
        if (pCur->data == pos) break;
        pCur = pCur->next;
    } while (pCur != *pList);

    if (pCur->data != pos) {
        printf("\nNode tidak ditemukan");
        getch();
    } else {
        pNew = (node *)malloc(sizeof(node));
        if (pNew == NULL) {
            printf("\nAlokasi memori gagal");
            getch();
        } else {
            pNew->data = bil;
            pNew->next = pCur->next;
            pCur->next = pNew;
        }
    }
}

//===========================================================
void tambahAkhir(node **pList) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &bil);
    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL) {
        pNew->data = bil;

        if (*pList == NULL) {
            pNew->next = pNew;
            *pList = pNew;
        } else {
            pCur = *pList;
            while (pCur->next != *pList) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *pList;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//===========================================================
void hapusAwal(node **pList) {
    if (*pList == NULL) {
        printf("List kosong, tidak ada yang dihapus.");
        getch();
        return;
    }

    node *temp = *pList, *pPre = *pList;

    if ((*pList)->next == *pList) {
        free(*pList);
        *pList = NULL;
    } else {
        while (pPre->next != *pList) {
            pPre = pPre->next;
        }
        *pList = (*pList)->next;
        pPre->next = *pList;
        free(temp);
    }
    printf("Node di awal berhasil dihapus.\n");
    getch();
}

//===========================================================
void hapusTengah(node **pList) {
    int bil;
    node *pCur = *pList, *pPre;

    if (*pList == NULL) {
        printf("List kosong, tidak ada yang dihapus.");
        getch();
        return;
    }

    system("cls");
    tranverse(*pList);
    printf("\nMasukkan data yang ingin dihapus: ");
    fflush(stdin);
    scanf("%d", &bil);

    do {
        if (pCur->data == bil) break;
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *pList);

    if (pCur->data != bil) {
        printf("Data tidak ditemukan.");
        getch();
        return;
    }

    if (pCur == *pList && pCur->next == *pList) {
        free(*pList);
        *pList = NULL;
    } else {
        if (pCur == *pList) {
            node *pLast = *pList;
            while (pLast->next != *pList) {
                pLast = pLast->next;
            }
            *pList = (*pList)->next;
            pLast->next = *pList;
        } else {
            pPre->next = pCur->next;
        }
        free(pCur);
    }
    printf("Node di tengah berhasil dihapus.\n");
    getch();
}

//===========================================================
void hapusAkhir(node **pList) {
    if (*pList == NULL) {
        printf("List kosong, tidak ada yang dihapus.");
        getch();
        return;
    }

    node *pCur = *pList, *pPre = NULL;

    if ((*pList)->next == *pList) {
        free(*pList);
        *pList = NULL;
    } else {
        while (pCur->next != *pList) {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = *pList;
        free(pCur);
    }
    printf("Node di akhir berhasil dihapus.\n");
    getch();
}

//===========================================================
void cariData(node *pList) {
    int bil;
    node *pCur = pList;

    if (pList == NULL) {
        printf("List kosong.");
        getch();
        return;
    }

    system("cls");
    tranverse(pList);
    printf("\nMasukkan data yang dicari: ");
    fflush(stdin);
    scanf("%d", &bil);

    do {
        if (pCur->data == bil) {
            printf("Data %d ditemukan.\n", bil);
            getch();
            return;
        }
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Data tidak ditemukan.\n");
    getch();
}

//===========================================================
void hitungData(node *pList) {
    int count = 0;
    node *pCur = pList;

    if (pList == NULL) {
        printf("Jumlah data dalam list: 0\n");
        getch();
        return;
    }

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Jumlah data dalam list: %d\n", count);
    getch();
}

//===========================================================
void jumlahData(node *pList) {
    int sum = 0;
    node *pCur = pList;

    if (pList == NULL) {
        printf("Perjumlah total dari semua data: 0\n");
        getch();
        return;
    }

    do {
        sum += pCur->data;
        pCur = pCur->next;
    } while (pCur != pList);

    printf("Perjumlah total dari semua data: %d\n", sum);
    getch();
}

//===========================================================
void tranverse(node *pList) {
    node *pWalker;

    system("cls");
    if (pList == NULL) {
        printf("List kosong.\n");
        return;
    }

    pWalker = pList;
    printf("List berisi:\n");

    printf("%d -> ", pWalker->data);

    pWalker = pWalker->next;
    while (pWalker != pList) {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    }


    printf("%d\n", pList->data);
}
