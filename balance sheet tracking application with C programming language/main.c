// SERKAN-ÖÐÜTCÜOÐLU-200205062-NORMALÖÐRETÝM-4.FONKSÝYONUM YARIM
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>

char gun[3]; char detay[50]; char tutar[5];	
int gungetir[30][3]; int guniste;char detaygetir[30][50];int fiyatgetir[30];
int deger;
bool kont = true;
char devam[6];
int i;
int aynumarasi;
FILE *AyDos;
char veri[300][25];
int toplam=0;
int gunal;
int temp;
int tut[30];
 int max, min;
void menu()
{	
	
	while(kont)
	{	
		hata:	
		printf("1-Dosya Boyutunu Goster\n");
		printf("2-Harcama Ekle\n");
		printf("3-Gun Bazinda Harcama Ara\n");
		printf("4-Fiyat Bazinda Harcama Ara\n");
		printf("5-Tum Harcamalari Goster\n");
		printf("6-Toplam Harcamayi Goster\n\n");
		printf("Lutfen Yapacaginiz Islemi seciniz: "); 	scanf("%d",&deger);
		printf("\n");
		
		switch(deger)
		{ 	
			case 1:
		
				
				fseek(AyDos,0,SEEK_END);
				printf("Bu dosya %d byte boyutundadir.\n",ftell(AyDos));	
			
				break;
				
			case 2:
			
				printf("Gun giriniz: ");scanf("%s",&gun);
				printf("Harcama detayi giriniz(bosluk yerine - kullaniniz!!!!): ");scanf("%s",detay);
				printf("Harcama tutarini giriniz(TL): "); scanf("%s",&tutar);
				fprintf(AyDos,"%s\t%s\t%s\n",gun,detay,tutar);
		
				break;
			case 3:
				
				printf("lutfen kacinci gunu aradiginizi yaziniz..: "); scanf("%d",&gunal);
				printf("\n");
				rewind(AyDos);
				while (!feof(AyDos))
				{	
					for (i =0 ; i < 90;i++ ) 
					{
						fscanf(AyDos, "%s", &veri[i]);	
					}
				}
				for(i=0;i<90;i+=3)
				{
					if(gunal==atoi(veri[i]))
					{
						printf("%s.gun yaptiginiz harcama detayi ve tutari: %s %sTL\n\n",&veri[i],veri[i+1],&veri[i+2]);
						break;
					}
				}
				break;
			case 4:
				rewind(AyDos);
				while (!feof(AyDos))
				{	
					for (i =0 ; i < 90;i++ ) 
					{
					
						fscanf(AyDos, "%s", &veri[i]);
						
					}
				}
				for(i=2; i<90;i+=3)
				{
					tut[i]=atoi(veri[i]);
				}
				
			  max = tut[2];
			 
			 
			  for(i=2; i<90; i+=3) 
			   {
			  
			   
			    if(tut[i] > max)
				max = tut[i];
				}
			
			  
			  printf("Bu ayki en fazla harcanan tutar = %dTL\n\n", max);
			  
						
				break;
			case 5:
					rewind(AyDos);
					while(!feof(AyDos))
					{
						fscanf(AyDos,"%s %s %s",&gungetir[i],&detaygetir[i],&fiyatgetir[i]);
						printf("%s %s %s\n",&gungetir[i],&detaygetir[i],&fiyatgetir[i]);
						i++;
					}
				break;
			case 6:		
				toplam =0;
				rewind(AyDos);
				while (!feof(AyDos))
				{	
					for (i =0 ; i < 90;i++ ) 
					{
					
						fscanf(AyDos, "%s", &veri[i]);	
					}
				}
				for(i=2;i<90;i+=3)
				{ 	
					
					toplam+=atoi(veri[i]);
				}
				printf("Bu Ay Toplam %d TL harcadiniz...\n\n",toplam);	
					
				break;
			default:
				printf("gecersiz deger girdiniz!!!!!\n\n");
				goto hata;
				break;						
		}
		printf("Islem yapmak istiyor musunuz?(evet-hayir): "); 	scanf("%s",devam);
		
		printf("\n");
			
		if(strcmp(devam, "evet")==0)
		{
		
		}
		else
		{
			kont = false;
			printf("Isleminiz sonlanmistir iyi gunler...\n");
		}
				 
		}
	
}

int main() {

	devam1:
	printf("Lutfen Islem Yapacaginiz Ay Numarasi Giriniz(1-12): "); scanf("%d", &aynumarasi);

	printf("\n");
	
	switch(aynumarasi)
	{
		case 1:
			AyDos=fopen("Aylar\\Ocak.txt","a+");
			menu();
			fclose(AyDos);
			break;
		case 2:
			AyDos =fopen("Aylar\\Þubat.txt","a+");
			menu();
			fclose(AyDos);
			break;
		case 3:
			AyDos =fopen("Aylar\\Mart.txt","a+");
			menu();
			fclose(AyDos);
			break;	
		case 4:
			AyDos =fopen("Aylar\\Nisan.txt","a+");
			menu();
			fclose(AyDos);
			break;
		case 5:
			AyDos =fopen("Aylar\\Mayis.txt","a+");
			menu();
			fclose(AyDos);
			break;							
		case 6:
			AyDos =fopen("Aylar\\Haziran.txt","a+");
			menu();
			fclose(AyDos);
			break;	
		case 7:
			AyDos =fopen("Aylar\\Temmuz.txt","a+");
			menu();
			fclose(AyDos);
			break;
		case 8:
			AyDos =fopen("Aylar\\Agustos.txt","a+");
			menu();
			fclose(AyDos);
			break;
		case 9:
			AyDos =fopen("Aylar\\Eylul.txt","a+");
			menu();
			fclose(AyDos);
			break;
		case 10:
			AyDos =fopen("Aylar\\Ekim.txt","a+");
			menu();
			fclose(AyDos);
			break;	
		case 11:
			AyDos =fopen("Aylar\\Kasim.txt","a+");
			menu();
			fclose(AyDos);
			break;	
		case 12:
			AyDos =fopen("Aylar\\Aralýk.txt","a+");
			menu();	
			fclose(AyDos);
			break;	
		default:
			printf("Yanlis bir deger girdiniz  lutfen 1-12 arasi bir deger giriniz!!!\n");
			goto devam1;
			break;	
	}


}


	
