#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
//char hurufpertama;
int total;
int jumlahtambah;
int tambahmax;

void red () {
  printf("\033[1;31m");
}

void resetcolor () {
  printf("\033[0m");
}

void enterkembali(){
    printf ("\n\n\tTekan Enter untuk Kembali . . ");
    system("pause>nul");
    system ("cls");
}

struct buah
{
    char nama[20];
    int harga;
    int ascinama;

};


int isEmpty(){
	if(total == 0){
		return 1;
	} else {
		return 0;
	}
}

void inputbuah(struct buah arr[20], int i, int n)
{
    int ceknum = 0;
    for (i = i; i < n; i++)
    {
        printf("\n\n\tMasukan Buah ke-%d", i + 1);

        printf("\n\tNama Buah  : ");
        scanf("%s",arr[i].nama);

        arr[i].ascinama=tolower(arr[i].nama[0]);
        //printf("huruf pertama : %d \n",arr[i].ascinama);


        hrgbh:
        printf("\tHarga Buah : ");
        ceknum=scanf("%d",&arr[i].harga);
        while (ceknum !=1){
                red();
            printf("\n\tMasukan Angka!");
                resetcolor();
            printf("\n\tTekan apa saja untuk mengulang...");
            system("pause>null");
            system("cls");
            printf("\n\n\tMasukan Buah ke-%d", i + 1);
            printf("\n\tNama Buah  : %s\n",arr[i].nama);
            scanf("%*[^\n]");
            goto hrgbh;
        }
        //printf("Acii nama Buah : %d",arr[i].ascinama);

    }
}

void printbuah(struct buah arr[20], int n)
{
    //arr[i].ascinama
    int i;
    printf("\n\n");
    printf("\t-------------------------------------------\n");
    printf("\t|       Daftar Nama dan Harga Buah        |\n");
    printf("\t------------------------------------------|\n");
    printf("\t| No | Nama Buah           | Harga Buah   |\n");
    printf("\t|----|---------------------|--------------|\n");
    for (i = 0; i < n; i++)
    {

        if (i >= 0 && i <= 8){
            printf("\t| %d. |",i+1);
        } else if (i >= 9 ){
            printf("\t| %d.|",i+1);
        }
        printf(" %s", arr[i].nama);
        int length = strlen(arr[i].nama);
        for (int x = 0; x < 20 - length ;x++){
            printf(" ");
        }
        printf("|");
        printf(" %d", arr[i].harga);
        int lenharga = floor(log10(abs(arr[i].harga))) + 1;
        for (int x = 0; x < 13 - lenharga ;x++){
        printf(" ");
        }
        printf("|\n");
    }
    printf("\t-------------------------------------------\n");

}


//Urutkan Dengan Harga
void sortbyhargaAscend(struct buah arr[20], int n)
{
    int i, j;
    struct buah temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (arr[j].harga > arr[j + 1].harga)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n\tDaftar Buah Berhasil Diurutkan, cek menu Daftar Buah Untuk melihat hasilnya\n");
}

void sortbyhargaDescend(struct buah arr[20], int n)
{
    int i, j;
    struct buah temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (arr[j].harga < arr[j + 1].harga)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n\tDaftar Buah Berhasil Diurutkan, cek menu Daftar Buah Untuk melihat hasilnya\n");
}

void urutNamaAcendDescend()
{
    printf("\n\n\tPilih Jenis Urutan Data!\n");
    printf("\t1. Ascending (A-Z)\n");
    printf("\t2. Descending (Z-A)\n");
    printf("\tPilih : ");

}

//Urutkan Dengan Nama
void sortbynamaAscend(struct buah arr[20], int n)
{
    int i, j;
    struct buah temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (arr[j].ascinama > arr[j + 1].ascinama)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n\tDaftar Buah Berhasil Diurutkan, cek menu Daftar Buah Untuk melihat hasilnya\n");
}

void sortbynamaDescend(struct buah arr[20], int n)
{
    int i, j;
    struct buah temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (arr[j].ascinama < arr[j + 1].ascinama)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n\tDaftar Buah Berhasil Diurutkan, cek menu Daftar Buah Untuk melihat hasilnya\n");
}

void urutHargaAcendDescend()
{
    printf("\n\n\tPilih Jenis Urutan Data!\n");
    printf("\t1. Ascending (Dari Kecil ke Besar)\n");
    printf("\t2. Descending (Dari Besar ke Kecil)\n");
    printf("\tPilih : ");

}

//Searching by nama atau harga
int linearSearchChar(int jumlahData, char dicari[],struct buah arr[20])
{
    int arrcharsave[5];
    int x = 0;
    //tolower dicari
    for(int i = 0 ; i <=strlen(dicari);i++)
    {
        if (dicari[i]>=65&&dicari[i]<90)
        dicari[i]=dicari[i]+32;
    }

    for(int i = 0; i< jumlahData; i++){
        //tolower arr[].nama
        for(int y = 0 ; y <=strlen(arr[i].nama);y++)
        {
            if (arr[i].nama[y]>=65&&arr[i].nama[y]<90)
            arr[i].nama[y]=arr[i].nama[y]+32;
        }

            if(strcmp(arr[i].nama, dicari) == 0){
                arrcharsave[x]=i;
                x++;
            }
    }
        if(x>0){
            for(int z = 0 ; z < x ; z++){
            printf("\tBuah %s ditemukan pada nomor %d dengan harga %d\n",arr[arrcharsave[z]].nama,arrcharsave[z]+1,arr[arrcharsave[z]].harga);
            }
            return x;
        }
        else{
            printf("\tBuah Tidak Ditemukan!");
            return -1;
        }
}

int linearSearchInt(int jumlahData, int dicari,struct buah arr[20])
{
    int arrintsave[5];
    int x = 0;
    for(int i = 0; i< jumlahData; i++){
        if(arr[i].harga == dicari){
            arrintsave[x]=i;
                x++;
        }
    }
    if(x>0){
        for(int z = 0 ; z < x ; z++){
        printf("\tBuah seharga %d ditemukan pada nomor %d dengan nama buah %s\n",dicari,arrintsave[z]+1,arr[arrintsave[z]].nama);
        }
        return x;
    }
    else {
        printf("\tHarga Buah Tidak Ditemukan!\n\n");
        return -1;
    }
}


void menu()
{
    printf("\n");
    printf("\t                 MENU                    \n");
    printf("\t=========================================\n");
    printf("\t    1. Input buah\t\t\t\n");
    printf("\t    2. Daftar Buah\t\t\t\n");
    printf("\t    3. Urutkan Berdasarkan Nama\t\t\n");
    printf("\t    4. Urutkan Berdasarkan Harga\t\n");
    printf("\t    5. Cari data Berdasarkan nama\t\n");
    printf("\t    6. Cari data berdasarkan harga\t\n");
    printf("\t    7. Exit program\t\t\t\n");
    printf("\t=========================================\n");
    printf("\tPilihan : ");

}

void menureset()
{
    printf("\n\n\tSudah Ada Data!\n");
    printf("\t1. Tambah data\n");
    printf("\t2. Reset data\n");
    printf("\t3. Kembali ke menu\n");
    printf("\tpilih : ");
}

int main()
{
    struct buah input[5];
    int pilih,urutHarga,urutNama,reset,cariharga;
    int ceknum = 0;
    char carinama[20];
    mainn:
    do{
    menu();
    ceknum=scanf("%d",&pilih);
        while (ceknum !=1){
                red();
            printf("\n\tPilih Menu Yang Tersedia! (1-7)! ");
                resetcolor();
            printf("\n\tTekan apa saja untuk mengulang...");
            system("pause>null");
            system("cls");
            scanf("%*[^\n]");
            menu();
            ceknum = scanf("%d",&pilih);
        }
    system("cls");

    if (pilih == 1){
            //sec1
        if (isEmpty()){
    inptjmlh:
        printf ("\n\n\tMasukan Berapa Macam Buah (Max 5): ");
            ceknum=scanf("%d",&jumlahtambah);
            while (ceknum !=1){
                    red();
                printf("\n\tMasukan Angka!");
                    resetcolor();
                printf("\n\tTekan apa saja untuk mengulang...");
                system("pause>null");
                system("cls");
                scanf("%*[^\n]");
                goto inptjmlh;
            }
            if(jumlahtambah>5){
                    red();
                printf("\tMasukan Buah Maksimal 5!");
                    resetcolor();
                system("pause>nul");
                system("cls");
                goto inptjmlh;
            }

        system("cls");
        //printf("%d & %d",jumlah,jumlahtambah);
        inputbuah(input, total,jumlahtambah);
        total=jumlahtambah;
        enterkembali();

        //sec2
        } else{
    menuresetgoto:
        system("cls");
        ulangreset:
            menureset();
    ceknum=scanf("%d",&reset);
    while (ceknum !=1){
            red();
        printf("\n\tMasukan Angka!");
            resetcolor();
        printf("\n\tTekan apa saja untuk mengulang...");
        system("pause>null");
        system("cls");
        scanf("%*[^\n]");
        goto ulangreset;
    }
            if(reset == 1)
            {
                if(total < 5){
              tambahbuah:
                printf ("\n\n\tTambah Berapa Macam Buah : ");
        ceknum=scanf("%d",&jumlahtambah);
            while (ceknum !=1){
                    red();
                printf("\n\tMasukan Angka!");
                    resetcolor();
                printf("\n\tTekan apa saja untuk mengulang...");
                system("pause>null");
                system("cls");
                scanf("%*[^\n]");
                goto tambahbuah;
            }
                        tambahmax = 5-total;
                        if (jumlahtambah > 0 && jumlahtambah <=tambahmax){

                            system("cls");
                            jumlahtambah = total +jumlahtambah;
                            //printf("%d & %d",jumlah,jumlahtambah);
                            inputbuah(input, total,jumlahtambah);
                            total=jumlahtambah;
                            enterkembali();
                        } else if (jumlahtambah > tambahmax){
                                red();
                            printf("\tTerlalu banyak data, maksimal tambah data %d",tambahmax);
                                resetcolor();
                            goto tambahbuah;
                        } else{
                            red();
                        printf("Minimal Tambah 1 Macam! ");
                            resetcolor();
                        system ("pause>nul");
                        system ("cls");
                        goto tambahbuah;
                        }
                    } else {
                        red();
                    printf("\tSudah mencapai batas maksimum data!, Tekan enter untuk kembali ke menu");
                        resetcolor();
                    system("pause>nul");
                    system("cls");
                    goto mainn;


                    }
            }

            else if (reset == 2)
            {
                total = 0; jumlahtambah=0;
                printf("data berhasil di reset!");
                enterkembali();
            }
            else if (reset == 3)
            {
                enterkembali();
            }
            else
            {
                    red();
                printf("Pilih Angka 1 atau 2 !");
                    resetcolor();
                system("pause>nul");
                goto menuresetgoto;
            }
        }
    }
    else if (pilih == 2){
        printbuah(input, jumlahtambah);
        enterkembali();
    }
    else if (pilih == 3){
        if(isEmpty()){
            printf("\n\n\tData Kosong, Silahkan Input data dahulu!");
        } else{
        nomor3:
            urutNamaAcendDescend();
                ceknum=scanf("%d",&urutHarga);
                while (ceknum !=1){
                        red();
                    printf("\tMasukan Angka!");
                        resetcolor();
                    printf("\n\n\tTekan apa saja untuk mengulang...");
                    system("pause>null");
                    system("cls");
                    scanf("%*[^\n]");
                    goto nomor3;
                }
            if (urutHarga == 1){
                sortbynamaAscend(input,total);

            }
            else if (urutHarga == 2){
                sortbynamaDescend(input,total);
            }
            else{
                    red();
                printf("\tPilih Angka 1 atau 2!");
                    resetcolor();
                system("pause>nul");
                system("cls");
                goto nomor3;
            }
        }
        enterkembali();
    }
    else if (pilih == 4){
        if(isEmpty()){
            printf("\n\n\tData Kosong, Silahkan Input data dahulu!");
        } else{
        nomor4:
            urutHargaAcendDescend();
                ceknum=scanf("%d",&urutNama);
                while (ceknum !=1){
                    printf("\n\tMasukan Angka!");
                    printf("\n\tTekan apa saja untuk mengulang...");
                    system("pause>null");
                    system("cls");
                    scanf("%*[^\n]");
                    goto nomor4;
                }
            if (urutNama == 1){
                sortbyhargaAscend(input,total);

            }
            else if (urutNama == 2){
                sortbyhargaDescend(input,total);
            }
            else{
                    red();
                printf("Pilih Angka 1 atau 2!");
                    resetcolor();
                system("pause>nul");
                system("cls");
                goto nomor4;
            }
        }
        enterkembali();
    }
    else if (pilih == 5){
        if(isEmpty()){
            printf("\n\n\tData Kosong, Silahkan Input data dahulu!");
        } else{
            printf ("\n\n\tMasukan nama buah yang ingin dicari : ");
            scanf("%s",carinama);
            linearSearchChar(total,carinama,input);
        }
        enterkembali();
    }
    else if (pilih == 6){
        if(isEmpty()){
            printf("\n\n\tData Kosong, Silahkan Input data dahulu!");
        } else{
        nomor6:
            printf ("\n\n\tMasukan Harga buah yang ingin dicari : ");
            ceknum=scanf("%d",&cariharga);
                while (ceknum !=1){
                        red();
                    printf("\n\tMasukan Angka!");
                        resetcolor();
                    printf("\n\tTekan apa saja untuk mengulang...");
                    system("pause>null");
                    system("cls");
                    scanf("%*[^\n]");
                    goto nomor6;
                }
            linearSearchInt(total,cariharga,input);
        }
        enterkembali();
    }
    else if (pilih == 7){
        printf("Program Exit Sucessfully . . .");
        return 0;

    }
    else
    {
        red();
        printf("\tPilih Menu Yang Tersedia! (1-7)");
        resetcolor();
        enterkembali();
    }
    }while(pilih!=7);


    return 0;
}

