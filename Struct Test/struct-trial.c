#include <stdio.h>

struct mahasiswa {
    char nama [40];
    char npm [15];
    float nilai;
};

int main (){
    struct mahasiswa mhs[10];
    int n,i;
    printf("Masukkan berapa data mahasiswa :"); scanf("%d",&n);
    for (i=0;i<n;i++){

        getchar();
        printf("Masukkan nama :"); scanf("%[^\n]", mhs[i].nama);
        printf("Masukkan npm :"); scanf("%s", mhs[i].npm);
        printf("Masukkan nilai :"); scanf("%f", &mhs[i].nilai);
    };
    printf("DATA MAHASISWA :\n");
    for (i=0;i<n;i++){
        printf("Nama : %s\n", mhs[i].nama );
        printf("npm : %s\n", mhs[i].npm );
        printf("nilai : %f\n", mhs[i].nilai );


    }


}
