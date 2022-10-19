#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sysinfoapi.h>
#define MAKS 100000
void urutkan(int[], int);
void tampil(int[], int);
void sequential(int[], int, int);
void isi(int[], int[], int);
void menu();
int main()
{
    int n,pilih,key;
    int arr[n], sort[n];
    struct timeval stop, start;

    puts("Sequential Searching");
    printf("Masukkan Jumlah Data: ");
    scanf("%d", &n);
    isi(arr, sort, n);
    tampil(arr, n);
    fflush(stdin);
    menu();
    printf("Pilih Menu: ");
    scanf("%d",&pilih);
    fflush(stdin);
    printf("Masukkan Data Yang Ingin Dicari: ");
    scanf("%d", &key);
    if(pilih == 1){
        urutkan(sort,n);
        gettimeofday(&start, NULL);
        sequential(sort,n,key);
    }
    else if(pilih == 2){
        gettimeofday(&start, NULL);
        sequential(arr,n,key);
    }
    gettimeofday(&stop, NULL);
    printf("took %lu us\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));
    return 0;
}
void menu(){
    puts("1. Sequential Sorted Array");
    puts("2. Sequential Unsorted Array");
}
void isi(int array[], int sort[], int panjang)
{
    for (int i = 0; i < panjang; i++)
    {
        array[i] = sort[i] = rand();
    }
}

void tampil(int array[], int panjang)
{
    for (int i = 0; i < panjang; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sequential(int array[], int panjang, int key)
{
    int valid = 0, perbandingan = 0;

    for (int i = 0; i < panjang; i++)
    {
        usleep(1000);
        perbandingan++;
        if (key == array[i])
        {
            printf("%d ada di dalam Array indeks ke %d\n", key, i);
            valid = 1;
            break;
        }
    }
    if (!valid)
    {
        puts("Data tidak ditemukan di dalam Array");
    }
    printf("Perbandingan : %d\n", perbandingan);
}
void urutkan(int sort[], int panjang)
{
    int cek, akhir = panjang, temp;

    for (int i = 0; i < panjang; i++)
    {
        cek = 0;
        akhir--;
        for (int j = 0; j < akhir; j++)
        {
            if (sort[j] > sort[j + 1])
            {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
                cek = 1;
            }
        }
        if (cek == 0)
        {
            puts("Data telah diurutkan");
            break;
        }
    }
    tampil(sort, panjang);
}
