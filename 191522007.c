#include <stdio.h>
#include <locale.h> 
int main() {
	setlocale(LC_ALL, "Turkish");  // T�rk�e Karakter Kullan�m� ��in Gerekli Olan Sat�r.
	char yazi[20]; // Kullan�c�n�n girece�i yaz�.
 	int a,i,j,k=0,sayac=0,uzunluk=0; // D�ng�lerin ve belirtilerin tan�mlamalar�.
 	printf("L�tfen Kelimenizi giriniz:");
 	gets(yazi); // Yaz�y� al�yoruz.
 	//UZUNLUK BULMA
 	uzunluk=strlen(yazi);
 	if(uzunluk<=4)
 		a=2;
 	else if(uzunluk<=9)
 		a=3;
 	else if(uzunluk<=16)
 		a=4;
 	else if(uzunluk<=20)
 		a=5;
 	char matris[a][a]; // �ifresiz matrisimizi tan�ml�yoruz.
 	for(i=0; i<a; i++)
 		for(j=0; j<a; j++){
		 	if(uzunluk==k){
		 		matris[i][j]=0;
			}else{
 				matris[i][j]=yazi[k]; // Sayac� kullanarak �ifresiz matrisimize yaz�n�n elemanlar�n� yerle�tiriyoruz.
 				k += 1;
			}
 					
 		}
 	printf("Girdi�iniz Kelimenin Matrisi : \n");
 	for(i = 0; i < a; i++){
        for(j = 0; j < a; j++){
            printf("%10d", matris[i][j]); // Char tan�ml� �ifresiz matrisimizi int g�sterimi ile ascii kodlar�n� kullanarak g�steriyoruz
            }
        printf("\n");
        }
        
    printf("Anahtar Matrisinizi Giriniz:\n");
	float anahtarmatris[a][a];
    for(i = 0; i < a; i++){
        for(j = 0; j < a; j++){
            printf("\t [%d][%d] : ",i+1,j+1); // Boyuta g�re anahtar matrisimizi kullan�c�dan girmesini istiyoruz.
            scanf("%f", &anahtarmatris[i][j]);
            } printf("\n");
        }
    printf("\n�ifreli Matrisiniz:\n");
    int deger;
    int sifrelimatris[a][a],ssifre;
    for(i = 0; i<a; i++){
        for(j = 0; j<a; j++){
            deger = 0;
            for(sayac = 0; sayac<a; sayac++){  		// Anahtar matrisimizi �ifresiz matrisimiz ile �arparak �ifreli matrisimizi olu�turuyoruz.
                ssifre=(int)matris[sayac][j];
				deger += anahtarmatris[i][sayac]*ssifre ;
                }       
            sifrelimatris[i][j] = deger;  			// Kodda deger de�i�keni tutarak �ifreli matrisimizi ayarl�yoruz.(Birbirine kar��mas�n diye)
            }
    
	}
	for(i = 0; i < a; i++){
       for(j = 0; j < a; j++){
           printf("%10d", sifrelimatris[i][j]);    // �ifreli matrisimizi g�steriyoruz.
        }
        printf("\n");
	}
        printf("\n�ifremiz: \n");
	for(i=0; i<a; i++)
		for(j=0; j<a; j++)
			printf("%c",sifrelimatris[i][j]); 	 	// �ifreli matrisimizi char'a �evirerek ekranda yaz� olarak g�r�nt�l�yoruz. Yani �ifremizi g�steriyoruz.
	printf("\n\n\n\n�ifre ��zmek �sterseniz 1'i, �stemezseniz 0'� Tu�lay�n�z.''\n");
	int cevap=0;
	scanf("%d",&cevap);
	if(cevap==0){
		return 0;
	}
	else if(cevap==1)
	{
	// Anahtar Matrisin Tersini Alma
	float birimmatris[a][a]; // Ters matriste kullanmak i�in birim matrisimizi tan�ml�yoruz.
	float d,k; // Tersini al�rken kullanmak ad�na iki de�i�ken tutucu tan�ml�yoruz.
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){
			if(i==j){
				birimmatris[i][j]=1;
			}							// Birim Matrisimizi Dolduruyoruz.
			else
				birimmatris[i][j]=0;
		}
	}
	// Ters Matris ��lemleri
	for(i=0; i<a; i++){
		d=anahtarmatris[i][i];		// �nce anahtar matrisimizi bir de�i�kende tutuyoruz.
		for(j=0; j<a; j++){
			anahtarmatris[i][j]=anahtarmatris[i][j]/d;	// Anahtar Matrisimizi kendine b�lerek anahtar matris de�i�kenini de�i�tiriyoruz.
			birimmatris[i][j]=birimmatris[i][j]/d;		// Birim Matrisimizi kendine b�lerek birim matris de�i�kenini de�i�tiriyoruz.
		}
		int x;		// �lk for d�ng�m�zde s�rekli tekrarlanmak ad�na bir saya� de�i�keni tan�ml�yoruz.
		for(x=0; x<a; x++){
			if(x!=i){	// Sayac�m�z ilk for d�ng�m�zdeki sayaca e�it olana dek b�l�nen anahtar matrisimizi tutup i�lemleri ger�ekle�tiriyoruz.
				k=anahtarmatris[x][i];
				for(j=0; j<a; j++){
					anahtarmatris[x][j]=anahtarmatris[x][j]-(anahtarmatris[i][j]*k);
					birimmatris[x][j]=birimmatris[x][j]-(birimmatris[i][j]*k);
				}
			}
		}
	}
	printf("\n _________Ters Matris___________ \n ");
	float tersmatris[a][a];		// Ters Matrisimizi tan�ml�yoruz.
	for(i=0; i<a; i++)
		for(j=0; j<a; j++)
			tersmatris[i][j]=0;	// �nce i�ini s�f�rlarla dolduruyoruz ki bellekte �zerine yazma s�ras�nda bir sorun ya�amayal�m.		
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){						// Ters matrisimizin i�ini i�lemlerde belirledi�imiz ters matrisin sonucu ile dolduruyoruz.
			tersmatris[i][j]=birimmatris[i][j];
			printf("\t %f",birimmatris[i][j]);
		}
		printf("\n");
 }
	int sifresiz[a][a];		// Anahtar matrisin tersi ile �ifreli matrisin �arp�m� sonucu olu�acak �ifremiz i�in bir matris tan�ml�yoruz.
	int sifresiz2[20];		// Yukar�da ki tan�mlad���m�z matrisi yaz�ya d�kmek i�in tek boyutlu bir matris tan�ml�yoruz.
    for(i = 0; i<a; i++){
        for(j = 0; j<a; j++){
            deger = 0;
            for(sayac = 0; sayac<a; sayac++){ 
                deger += tersmatris[i][sayac]*sifrelimatris[sayac][j];	// Anahtar Matrisimizin tersi ile �ifreli Matrisimizi �arparak �firesiz matrisi olu�turuyoruz.
                }       
            sifresiz[i][j] = deger;  			// Kodda deger de�i�keni tutarak �ifresiz matrisimizi ayarl�yoruz.(Birbirine kar��mas�n diye)
            }
    
	}
	int say=0;	// �ift boyutlu �ifresiz matrisimizi tek boyutlu �ifresiz matrisimize d�n��t�r�rken kullanmak i�in bir sayac belirliyoruz.
	for(i=0; i<a; i++)
 		for(j=0; j<a; j++){
 			sifresiz2[say]=sifresiz[i][j];	// Sayac� kullanarak �ifresiz matrisimize yaz�n�n elemanlar�n� yerle�tiriyoruz.
 			say += 1;
		 	if(uzunluk==say){
		 		i=a+1; j=a+1;
			 }
 					
 		}
    printf("\n _________�ifreniz____________ \n ");
 	for(i=0; i<say; i++)
 		printf(" %c",sifresiz2[i]);		// ��z�len �ifreyi G�steriyoruz.
	printf("\n");		
 	for(i = 0; i < a; i++){
    	for(j = 0; j < a; j++){
    		printf(" %d", sifresiz[i][j]);   // �ifresiz Matrisimizi Tekrardan G�steriyoruz.
            }
        printf("\n");
        }		
}
	return 0;
}
