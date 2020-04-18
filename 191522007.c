#include <stdio.h>
#include <locale.h> 
int main() {
	setlocale(LC_ALL, "Turkish");  // Türkçe Karakter Kullanýmý Ýçin Gerekli Olan Satýr.
	char yazi[20]; // Kullanýcýnýn gireceði yazý.
 	int a,i,j,k=0,sayac=0,uzunluk=0; // Döngülerin ve belirtilerin tanýmlamalarý.
 	printf("Lütfen Kelimenizi giriniz:");
 	gets(yazi); // Yazýyý alýyoruz.
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
 	char matris[a][a]; // Þifresiz matrisimizi tanýmlýyoruz.
 	for(i=0; i<a; i++)
 		for(j=0; j<a; j++){
		 	if(uzunluk==k){
		 		matris[i][j]=0;
			}else{
 				matris[i][j]=yazi[k]; // Sayacý kullanarak þifresiz matrisimize yazýnýn elemanlarýný yerleþtiriyoruz.
 				k += 1;
			}
 					
 		}
 	printf("Girdiðiniz Kelimenin Matrisi : \n");
 	for(i = 0; i < a; i++){
        for(j = 0; j < a; j++){
            printf("%10d", matris[i][j]); // Char tanýmlý þifresiz matrisimizi int gösterimi ile ascii kodlarýný kullanarak gösteriyoruz
            }
        printf("\n");
        }
        
    printf("Anahtar Matrisinizi Giriniz:\n");
	float anahtarmatris[a][a];
    for(i = 0; i < a; i++){
        for(j = 0; j < a; j++){
            printf("\t [%d][%d] : ",i+1,j+1); // Boyuta göre anahtar matrisimizi kullanýcýdan girmesini istiyoruz.
            scanf("%f", &anahtarmatris[i][j]);
            } printf("\n");
        }
    printf("\nÞifreli Matrisiniz:\n");
    int deger;
    int sifrelimatris[a][a],ssifre;
    for(i = 0; i<a; i++){
        for(j = 0; j<a; j++){
            deger = 0;
            for(sayac = 0; sayac<a; sayac++){  		// Anahtar matrisimizi þifresiz matrisimiz ile çarparak þifreli matrisimizi oluþturuyoruz.
                ssifre=(int)matris[sayac][j];
				deger += anahtarmatris[i][sayac]*ssifre ;
                }       
            sifrelimatris[i][j] = deger;  			// Kodda deger deðiþkeni tutarak þifreli matrisimizi ayarlýyoruz.(Birbirine karýþmasýn diye)
            }
    
	}
	for(i = 0; i < a; i++){
       for(j = 0; j < a; j++){
           printf("%10d", sifrelimatris[i][j]);    // Þifreli matrisimizi gösteriyoruz.
        }
        printf("\n");
	}
        printf("\nÞifremiz: \n");
	for(i=0; i<a; i++)
		for(j=0; j<a; j++)
			printf("%c",sifrelimatris[i][j]); 	 	// Þifreli matrisimizi char'a çevirerek ekranda yazý olarak görüntülüyoruz. Yani þifremizi gösteriyoruz.
	printf("\n\n\n\nÞifre Çözmek Ýsterseniz 1'i, Ýstemezseniz 0'ý Tuþlayýnýz.''\n");
	int cevap=0;
	scanf("%d",&cevap);
	if(cevap==0){
		return 0;
	}
	else if(cevap==1)
	{
	// Anahtar Matrisin Tersini Alma
	float birimmatris[a][a]; // Ters matriste kullanmak için birim matrisimizi tanýmlýyoruz.
	float d,k; // Tersini alýrken kullanmak adýna iki deðiþken tutucu tanýmlýyoruz.
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){
			if(i==j){
				birimmatris[i][j]=1;
			}							// Birim Matrisimizi Dolduruyoruz.
			else
				birimmatris[i][j]=0;
		}
	}
	// Ters Matris Ýþlemleri
	for(i=0; i<a; i++){
		d=anahtarmatris[i][i];		// Önce anahtar matrisimizi bir deðiþkende tutuyoruz.
		for(j=0; j<a; j++){
			anahtarmatris[i][j]=anahtarmatris[i][j]/d;	// Anahtar Matrisimizi kendine bölerek anahtar matris deðiþkenini deðiþtiriyoruz.
			birimmatris[i][j]=birimmatris[i][j]/d;		// Birim Matrisimizi kendine bölerek birim matris deðiþkenini deðiþtiriyoruz.
		}
		int x;		// Ýlk for döngümüzde sürekli tekrarlanmak adýna bir sayaç deðiþkeni tanýmlýyoruz.
		for(x=0; x<a; x++){
			if(x!=i){	// Sayacýmýz ilk for döngümüzdeki sayaca eþit olana dek bölünen anahtar matrisimizi tutup iþlemleri gerçekleþtiriyoruz.
				k=anahtarmatris[x][i];
				for(j=0; j<a; j++){
					anahtarmatris[x][j]=anahtarmatris[x][j]-(anahtarmatris[i][j]*k);
					birimmatris[x][j]=birimmatris[x][j]-(birimmatris[i][j]*k);
				}
			}
		}
	}
	printf("\n _________Ters Matris___________ \n ");
	float tersmatris[a][a];		// Ters Matrisimizi tanýmlýyoruz.
	for(i=0; i<a; i++)
		for(j=0; j<a; j++)
			tersmatris[i][j]=0;	// Önce içini sýfýrlarla dolduruyoruz ki bellekte üzerine yazma sýrasýnda bir sorun yaþamayalým.		
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){						// Ters matrisimizin içini iþlemlerde belirlediðimiz ters matrisin sonucu ile dolduruyoruz.
			tersmatris[i][j]=birimmatris[i][j];
			printf("\t %f",birimmatris[i][j]);
		}
		printf("\n");
 }
	int sifresiz[a][a];		// Anahtar matrisin tersi ile þifreli matrisin çarpýmý sonucu oluþacak þifremiz için bir matris tanýmlýyoruz.
	int sifresiz2[20];		// Yukarýda ki tanýmladýðýmýz matrisi yazýya dökmek için tek boyutlu bir matris tanýmlýyoruz.
    for(i = 0; i<a; i++){
        for(j = 0; j<a; j++){
            deger = 0;
            for(sayac = 0; sayac<a; sayac++){ 
                deger += tersmatris[i][sayac]*sifrelimatris[sayac][j];	// Anahtar Matrisimizin tersi ile Þifreli Matrisimizi çarparak þfiresiz matrisi oluþturuyoruz.
                }       
            sifresiz[i][j] = deger;  			// Kodda deger deðiþkeni tutarak þifresiz matrisimizi ayarlýyoruz.(Birbirine karýþmasýn diye)
            }
    
	}
	int say=0;	// Çift boyutlu þifresiz matrisimizi tek boyutlu þifresiz matrisimize dönüþtürürken kullanmak için bir sayac belirliyoruz.
	for(i=0; i<a; i++)
 		for(j=0; j<a; j++){
 			sifresiz2[say]=sifresiz[i][j];	// Sayacý kullanarak þifresiz matrisimize yazýnýn elemanlarýný yerleþtiriyoruz.
 			say += 1;
		 	if(uzunluk==say){
		 		i=a+1; j=a+1;
			 }
 					
 		}
    printf("\n _________Þifreniz____________ \n ");
 	for(i=0; i<say; i++)
 		printf(" %c",sifresiz2[i]);		// Çözülen Þifreyi Gösteriyoruz.
	printf("\n");		
 	for(i = 0; i < a; i++){
    	for(j = 0; j < a; j++){
    		printf(" %d", sifresiz[i][j]);   // Þifresiz Matrisimizi Tekrardan Gösteriyoruz.
            }
        printf("\n");
        }		
}
	return 0;
}
