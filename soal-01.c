#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//BUAH DIKULKAS: apel 5, jeruk 4, mangga 4, nanas 3, kiwi 4
int main() {
    //INISIASI 
    //data => variabel untuk menyimpan kata dari file
    //fruits => variabel untuk menyimpan nama buah untuk dicek 
    char data[100][20], fruits[100][20];
    //count_word => variabel untuk menghitung jumlah kata dalam file
    //count_fruit => variabel untuk menghitung jumlah buah x dalam kulkas. 
    //check => jumlah jenis buah yang akan dicek. 
    //stock => minimal stock per jenis buah dalam kulkas.
    //total_yang_dibeli => variabel untuk menyimpan total buah x yang perlu dibeli 
    int count_word=0, count_fruit=0, item=0, check, stock[20], total_yang_dibeli, count_item=0;
    
    FILE *file;
    file = fopen("in.txt", "r");
    //Menyimpan kata dalam file ke variabel data dan menghitung jumlah kata dalam file
    while (fscanf(file, " %s", data[count_word]) == 1) {
        count_word++;
    }

    printf("Jumlah jenis buah yang ingin diperiksa dalam kulkas: ");
    scanf("%d",&check);
    if (check==0){
        printf("Tidak ada yang diperiksa");
    } else if (check>0){
        for(int i=0; i<check; i++){
            printf("Masukkan nama buah ke-");
            printf("%d: ",i+1);
            scanf("%s",fruits[i]);
            printf("Masukkan minimal stock buah ke-");
            printf("%d: ",i+1);
            scanf("%d",&stock[i]);
        }

        printf("Buah yang perlu dibeli:\n");
        //Looping selama jumlah jenis buah yang perlu dicek
        while (item<check){
            for(int i=0; i<count_word; i++){
                //Jika fruit ke item == data ke i, maka menghitung jumlah buah x dalam data ada berapa
                //Misal apel ada 2 dalam data
                if (strcmp(fruits[item], data[i]) == 0){
                    count_fruit++;
                }
            }
            //Jika jumlah buah x lebih kecil dari minimal stock, maka menghitung total buah x yang perlu dibeli
            //Misal apel ada 2 dalam data, namun minimal stock harus 5, maka perlu membeli 3 lagi
            if (count_fruit<stock[item]){
                printf("-%s ", fruits[item]);
                total_yang_dibeli = stock[item]-count_fruit;
                printf("%d\n", total_yang_dibeli);
            } 
            //Jika jumlah buah x >= stock
            else if(count_fruit>=stock[item]){
                count_item++;
                //Jika count_item==check yang artinya semua item sudah memenuhi stock, maka tidak ada yang perlu dibeli
                if (count_item==check){
                    printf("Tidak ada\n");
                }
            }
            item++;
            count_fruit=0;
        }
    }
   return 0;
}
