#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
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
//void insertNode(node **head, node *pPre, node *pNew);

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
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
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

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;
      //add before first logical node or to an empty list
	  pNew -> next = *head;
      *head = pNew;
  }
  else{
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
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
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
        pNew->next = NULL;

        if (*head == NULL) {
            // Jika list kosong, node baru menjadi head
            *head = pNew;
        } else {
            // Traverse ke node terakhir
            pCur = *head;
            while (pCur->next != NULL) {
                pCur = pCur->next;
            }
            // Tambahkan node baru di akhir
            pCur->next = pNew;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}
//========================================================
void hapusAwal(node **head) {
    node *pCur;

    // Jika list kosong
    if (*head == NULL) {
        printf("List kosong, tidak ada node yang dapat dihapus.\n");
        getch();
        return;
    }

    // Node yang akan dihapus adalah node pertama (head)
    pCur = *head;

    // Head pindah ke node berikutnya
    *head = pCur ->next;

    // Bebaskan memori node pertama
    free(pCur);

    printf("Node pertama berhasil dihapus.\n");
    getch();
}
//========================================================
void hapusTengah(node **head) {
    int bil;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    fflush(stdin);
    printf("\nMasukkan nilai node yang ingin dihapus: ");
    scanf("%d", &bil);

    // Jika list kosong
    if (*head == NULL) {
        printf("List kosong, tidak ada node yang dapat dihapus.\n");
        getch();
        return;
    }

    pCur = *head;
    pPre = NULL;

    // Traverse mencari node dengan nilai data 'bil'
    while (pCur != NULL && pCur->data != bil) {
        pPre = pCur;
        pCur = pCur->next;
    }

    // Jika node dengan nilai 'bil' tidak ditemukan
    if (pCur == NULL) {
        printf("Node dengan nilai %d tidak ditemukan.\n", bil);
        getch();
        return;
    }

    // Jika node dengan 'bil' ditemukan
    if (pPre == NULL) {
        // Jika node yang dihapus adalah node pertama
        *head = pCur->next;
    } else {
        // Menghubungkan node sebelumnya ke node setelah node yang dihapus
        pPre->next = pCur->next;
    }

    // Bebaskan memori node yang dihapus
    free(pCur);
    printf("Node dengan nilai %d berhasil dihapus.\n", bil);
    getch();
}

//========================================================
void hapusAkhir(node **head) {
    node *pCur, *pPre;

    system("cls");
    // Jika list kosong
    if (*head == NULL) {
        printf("List kosong, tidak ada node yang dapat dihapus.\n");
        getch();
        return;
    }
    pCur = *head;
    pPre = NULL;

    // Traverse ke node terakhir
    while (pCur->next != NULL) {
        pPre = pCur;
        pCur = pCur->next;
    }

    // Jika hanya ada satu node di list
    if (pPre == NULL) {
        // Menghapus node pertama dan satu-satunya
        free(*head);
        *head = NULL; // Set head ke NULL
    } else {
        // Menghapus node terakhir
        free(pCur);
        pPre->next = NULL; // Set next dari node sebelumnya ke NULL
    }

    printf("Node terakhir berhasil dihapus.\n");
    getch();
}


//========================================================
void cariData(node *head) {
    int bil;
    node *pCur;
    int urutan = 1; // Indeks node

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    if (head == NULL) {
        printf("List kosong, tidak ada node yang dapat dicari.\n");
        getch();
        return;
    }

    pCur = head;

    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Node dengan nilai %d ditemukan pada node %d.\n", bil, urutan);
            getch(); // Menunggu input untuk melanjutkan
            return; // Keluar dari fungsi setelah menemukan node
        }
        pCur = pCur->next;
        urutan++; // Meningkatkan indeks untuk setiap node yang dilalui
    }

    printf("Node dengan nilai %d tidak ditemukan.\n", bil);
    getch();
}

//========================================================
void hitungData(node *head) {
    int count = 0; // Inisialisasi penghitung
    node *pCur = head;

    while (pCur != NULL) {
        count++; // Tingkatkan penghitung untuk setiap node
        pCur = pCur->next; // Pindah ke node berikutnya
    }
        system("cls");
        printf("Jumlah total data dalam linked list adalah: %d\n", count);
        getch();

}

//========================================================
void jumlahData(node *head) {
    int total = 0; // Inisialisasi total
    node *pCur = head;

    while (pCur != NULL) {
        total += pCur->data; // Tambahkan data node ke total
        pCur = pCur->next; // Pindah ke node berikutnya
    }

    system("cls");
    tranverse(head);
    printf("\nJumlah total nilai data dalam linked list adalah: %d\n", total);
    getch();
}

//========================================================

/*void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}*/

//========================================================

