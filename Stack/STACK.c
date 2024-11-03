#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct stack {
	int data;
	int count;
    struct stack *next;
};
typedef struct stack stack;

int stackmax = 10;

void pushdata(stack **top);
void popdata(stack **top);
void stacktop(stack *top);
void stackempty(stack *top);
void stackfull(stack *top);
void stackcount(stack *top);
void destroystack(stack **top);

//========================================================

int main()
{
  stack *top;
  int pilih;

  top = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. push data\n");
     printf("2. pop data\n");
     printf("3. stack top\n");
     printf("4. stack empty (cek stack kosong/tidak)\n");
     printf("5. stack full (cek satck penuh/tidak)\n");
     printf("6. jumlah data stack\n");
     printf("7. destroy stack (hapus seluruh data stack)\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf(" %d", &pilih);
     if (pilih == 1){
            pushdata(&top);
            getch();
     }
     else if (pilih == 2){
            popdata(&top);
     }

     else if (pilih == 3){
            stacktop(top);
     }

     else if (pilih == 4){
   			stackempty(top);

     }
     else if (pilih == 5){
            stackfull(top);
     }
     else if (pilih == 6){
            stackcount(top);
     }
     else if (pilih == 7){
            destroystack(&top);
     }

  } while (pilih != 0);

  return 0;
}

//========================================================

void pushdata(stack **top){
  int bil;
  stack *pNew;

  system("cls");
  stackcount(*top);
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);

  if(*top != NULL && (*top)->count >= stackmax){
    printf("Stack telah penuh, tidak dapat mengisi");
    getch();
    return;
  }

  pNew = (stack *)malloc(sizeof(stack));

  if (pNew != NULL){
  	  pNew->data = bil;
	  pNew -> next = *top;
	  pNew->count = 1;
	  if (*top != NULL){
        pNew->count = (*top)->count + 1;
	  }

      *top = pNew;
      printf("Bilangan %d ditambahkan\n", bil);
  }
  else{
      printf("Alokasi memori gagal");
      getch();
  }
}

//========================================================
void popdata(stack **top) {
    stack *temp;

     if (*top == NULL) {
        printf("List kosong, tidak ada data yang dapat dihapus.\n");
        getch();
        return;
    }

    temp = *top;
    *top = (*top)->next;
    if (*top != NULL) {
        (*top)->count = temp->count - 1;
    }
    printf("Telah men-pop(hapus) %d dari stack.\n", temp->data);
    free(temp);
    getch();
}
//========================================================
void stacktop(stack *top) {

    system("cls");
    if (top == NULL) {
        printf("Stack kosong.\n");
        getch();
    } else {
        printf("Data teratas: %d\n", top->data);
        getch();
    }
}
//========================================================
void stackempty(stack *top) {
    if (top == NULL) {
        printf("Stack kosong.\n");
        getch();
    } else {
        printf("Stack terisi.\n");
        getch();
    }
}

//========================================================
void stackfull(stack *top) {
    if (top == NULL) {
        printf("Stack kosong.\n");
    } else if (top->count >= stackmax) {
        printf("Stack Penuh.\n");
    } else {
        printf("Masih ada tempat di Stack, bisa diisi.\n");
    }
    getch();
}
//========================================================
void stackcount(stack *top) {
    if (top == NULL) {
        printf("Stack terisi : 0\n");
        getch();
    }
    else{
        printf("Stack terisi : %d\n", top->count);
        getch();
    }
}
//========================================================
void destroystack(stack **top){
    stack *temp;
    if(*top == NULL){
        printf("List kosong, tidak ada data yang dapat dihapus.\n");
        getch();
        return;
    }
    while (*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    printf("Stack telah dikosongkan");
    getch();
}

