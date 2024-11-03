#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir (node **head);
void hapusAwal(node **head);
void hapusTengah(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void hitungData(node *head);
void jumlahData (node *head);
void tranverse(node *head);


//========================================================

int main()
{
  node *head;
  int pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. cetak isi list\n");
     printf("2. tambah data di awal list\n");
     printf("3. tambah data di tengah list\n");
     printf("4. tambah data di akhir list\n");
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
            tranverse(head);
            getch();
     }
     else if (pilih == 2){
            tambahAwal(&head);
     }

     else if (pilih == 3){
            tambahData(&head);
     }

     else if (pilih == 4){
   			tambahAkhir(&head);

     }
     else if (pilih == 5){
            hapusAwal(&head);
     }
     else if (pilih == 6){
            hapusTengah(&head);
     }
     else if (pilih == 7){
            hapusAkhir(&head);
     }
     else if (pilih == 8){
            cariData(head);
     }
     else if (pilih == 9) {
            hitungData(head);
     }
     else if (pilih == 10){
            jumlahData(head);
     }

  } while (pilih != 0);

  return 0;
}

//========================================================
void tranverse(node *head){
   //traverse a linked list
	node *pWalker;

   system("cls");
	pWalker = head;
	printf("NULL <-");
	while (pWalker != NULL){
        printf(" %d ", pWalker->data);
        if(pWalker -> right != NULL) {
            printf("<->");
        }
   	pWalker = pWalker->right;
	}
   printf("-> NULL");
}


//========================================================

void tambahAwal(node **head){
  int bil;
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = *head;
        if (*head != NULL) {
            (*head)->left = pNew;
        }
        pNew->left = NULL;
        *head = pNew;
} else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================

void tambahData(node **head){
  int pos, bil;
  node *pNew, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nposisi penyisipan setelah data bernilai : ");
  fflush(stdin);
  scanf("%d", &pos);
  printf("\nbilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> right;
  }

  pNew = (node *)malloc(sizeof(node));
  pNew->data = bil;
  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memori gagal");
     getch();
  }
  else if (pCur->right == NULL){
    pNew->left = pCur;
    pNew->right = pCur->right;
    pCur->right = pNew;
  }
  else{
    pNew->left = pCur;
    pNew->right = pCur->right;
    pCur->right->left = pNew;
    pCur->right = pNew;
  }
}

//========================================================
void tambahAkhir(node **head) {
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        pNew->right = NULL;

        if (*head == NULL) {
            *head = pNew;
        } else {
            pCur = *head;
            while (pCur->right != NULL) {
                pNew->left = pCur;
                pCur = pCur->right;
            }
            pCur->right = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}
//========================================================
void hapusAwal(node **head) {
    node *pCur;


    if (*head == NULL) {
        printf("List kosong, tidak ada node yang dapat dihapus.\n");
        getch();
        return;
    }
    pCur = *head;
    *head = pCur ->right;
    pCur -> right -> left = NULL;
    free(pCur);

    printf("Node pertama berhasil dihapus.\n");
    getch();
}
//========================================================
void hapusTengah(node **head) {
    int bil;
    node *pCur;

    system("cls");
    tranverse(*head);
    fflush(stdin);
    printf("\nMasukkan nilai node yang ingin dihapus: ");
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong, tidak ada node yang dapat dihapus.\n");
        getch();
        return;
    }

    pCur = *head;
    while (pCur && pCur->data != bil) {
        pCur = pCur->right;
    }

    if (pCur == NULL) {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
        getch();
        return;
    }

    if (pCur->left) {
        pCur->left->right = pCur->right;
    }
    else {
        *head = pCur->right;
    }
     if (pCur->right){
        pCur->right->left = pCur->left;
    }

    free(pCur);
    printf("Node dengan nilai %d berhasil dihapus.\n", bil);
    getch();
}

//========================================================
void hapusAkhir(node **head) {
    node *pCur;

    system("cls");
    if (*head == NULL) {
        printf("List kosong, tidak ada node yang dapat dihapus.\n");
        getch();
        return;
    }
    pCur = *head;
    while (pCur->right != NULL) {
        pCur = pCur->right;
    }

    if (pCur->left == NULL) {
        free(*head);
        *head = NULL;
    } else {
        pCur->left->right = NULL;
    }
    free(pCur);
    printf("Node terakhir berhasil dihapus.\n");
    getch();
}
//========================================================
void cariData(node *head) {
    int bil;
    node *pCur;

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    if (head == NULL) {
        printf("List kosong, tidak ada node yang dapat dicari.\n");
        getch();
        return;
    }

    pCur = head;
    while (pCur != NULL && pCur->data != bil) {
        pCur = pCur->right;
    }

    if (pCur != NULL) {
        printf("Node dengan nilai %d ditemukan.\n", bil);
    } else {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
    }

    getch();
}
//========================================================
void hitungData(node *head) {
    int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->right;
    }
        system("cls");
        tranverse(head);
        printf("\nJumlah total data dalam linked list adalah: %d\n", count);
        getch();

}

//========================================================
void jumlahData(node *head) {
    int total = 0;
    node *pCur = head;

    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->right;
    }

    system("cls");
    tranverse(head);
    printf("\nJumlah total nilai data dalam linked list adalah: %d\n", total);
    getch();
}

//========================================================
