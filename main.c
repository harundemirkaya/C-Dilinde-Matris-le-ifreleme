#include <stdio.h>
#include <locale.h> 
int main() {
	setlocale(LC_ALL, "Turkish");  // Türkçe Karakter Kullanımı İçin Gerekli Olan Satır.
	char yazi[20]; // Kullanıcının gireceği yazı.
 	int a,i,j,k=0,sayac=0,uzunluk=0; // Döngülerin ve belirtilerin tanımlamaları.
 	printf("Lütfen Kelimenizi giriniz:");
 	gets(yazi); // Yazıyı alıyoruz.
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
 	char matris[a][a]; // Şifresiz matrisimizi tanımlıyoruz.
 	for(i=0; i<a; i++)
 		for(j=0; j<a; j++){
		 	if(uzunluk==k){
		 		matris[i][j]=0;
			}else{
 				matris[i][j]=yazi[k]; // Sayacı kullanarak şifresiz matrisimize yazının elemanlarını yerleştiriyoruz.
 				k += 1;
			}
 					
 		}
 	printf("Girdiğiniz Kelimenin Matrisi : \n");
 	for(i = 0; i < a; i++){
        for(j = 0; j < a; j++){
            printf("%10d", matris[i][j]); // Char tanımlı şifresiz matrisimizi int gösterimi ile ascii kodlarını kullanarak gösteriyoruz
            }
        printf("\n");
        }
        
    printf("Anahtar Matrisinizi Giriniz:\n");
	float anahtarmatris[a][a];
    for(i = 0; i < a; i++){
        for(j = 0; j < a; j++){
            printf("\t [%d][%d] : ",i+1,j+1); // Boyuta göre anahtar matrisimizi kullanıcıdan girmesini istiyoruz.
            scanf("%f", &anahtarmatris[i][j]);
            } printf("\n");
        }
    printf("\nŞifreli Matrisiniz:\n");
    int deger;
    int sifrelimatris[a][a],ssifre;
    for(i = 0; i<a; i++){
        for(j = 0; j<a; j++){
            deger = 0;
            for(sayac = 0; sayac<a; sayac++){  		// Anahtar matrisimizi şifresiz matrisimiz ile çarparak şifreli matrisimizi oluşturuyoruz.
                ssifre=(int)matris[sayac][j];
				deger += anahtarmatris[i][sayac]*ssifre ;
                }       
            sifrelimatris[i][j] = deger;  			// Kodda deger değişkeni tutarak şifreli matrisimizi ayarlıyoruz.(Birbirine karışmasın diye)
            }
    
	}
	for(i = 0; i < a; i++){
       for(j = 0; j < a; j++){
           printf("%10d", sifrelimatris[i][j]);    // Şifreli matrisimizi gösteriyoruz.
        }
        printf("\n");
	}
        printf("\nŞifremiz: \n");
	for(i=0; i<a; i++)
		for(j=0; j<a; j++)
			printf("%c",sifrelimatris[i][j]); 	 	// Şifreli matrisimizi char'a çevirerek ekranda yazı olarak görüntülüyoruz. Yani şifremizi gösteriyoruz.
	printf("\n\n\n\nŞifre Çözmek İsterseniz 1'i, İstemezseniz 0'ı Tuşlayınız.''\n");
	int cevap=0;
	scanf("%d",&cevap);
	if(cevap==0){
		return 0;
	}
	else if(cevap==1)
	{
	// Anahtar Matrisin Tersini Alma
	float birimmatris[a][a]; // Ters matriste kullanmak için birim matrisimizi tanımlıyoruz.
	float d,k; // Tersini alırken kullanmak adına iki değişken tutucu tanımlıyoruz.
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){
			if(i==j){
				birimmatris[i][j]=1;
			}							// Birim Matrisimizi Dolduruyoruz.
			else
				birimmatris[i][j]=0;
		}
	}
	// Ters Matris İşlemleri
	for(i=0; i<a; i++){
		d=anahtarmatris[i][i];		// Önce anahtar matrisimizi bir değişkende tutuyoruz.
		for(j=0; j<a; j++){
			anahtarmatris[i][j]=anahtarmatris[i][j]/d;	// Anahtar Matrisimizi kendine bölerek anahtar matris değişkenini değiştiriyoruz.
			birimmatris[i][j]=birimmatris[i][j]/d;		// Birim Matrisimizi kendine bölerek birim matris değişkenini değiştiriyoruz.
		}
		int x;		// İlk for döngümüzde sürekli tekrarlanmak adına bir sayaç değişkeni tanımlıyoruz.
		for(x=0; x<a; x++){
			if(x!=i){	// Sayacımız ilk for döngümüzdeki sayaca eşit olana dek bölünen anahtar matrisimizi tutup işlemleri gerçekleştiriyoruz.
				k=anahtarmatris[x][i];
				for(j=0; j<a; j++){
					anahtarmatris[x][j]=anahtarmatris[x][j]-(anahtarmatris[i][j]*k);
					birimmatris[x][j]=birimmatris[x][j]-(birimmatris[i][j]*k);
				}
			}
		}
	}
	printf("\n _________Ters Matris___________ \n ");
	float tersmatris[a][a];		// Ters Matrisimizi tanımlıyoruz.
	for(i=0; i<a; i++)
		for(j=0; j<a; j++)
			tersmatris[i][j]=0;	// Önce içini sıfırlarla dolduruyoruz ki bellekte üzerine yazma sırasında bir sorun yaşamayalım.		
	for(i=0; i<a; i++){
		for(j=0; j<a; j++){						// Ters matrisimizin içini işlemlerde belirlediğimiz ters matrisin sonucu ile dolduruyoruz.
			tersmatris[i][j]=birimmatris[i][j];
			printf("\t %f",birimmatris[i][j]);
		}
		printf("\n");
 }
	int sifresiz[a][a];		// Anahtar matrisin tersi ile şifreli matrisin çarpımı sonucu oluşacak şifremiz için bir matris tanımlıyoruz.
	int sifresiz2[20];		// Yukarıda ki tanımladığımız matrisi yazıya dökmek için tek boyutlu bir matris tanımlıyoruz.
    for(i = 0; i<a; i++){
        for(j = 0; j<a; j++){
            deger = 0;
            for(sayac = 0; sayac<a; sayac++){ 
                deger += tersmatris[i][sayac]*sifrelimatris[sayac][j];	// Anahtar Matrisimizin tersi ile Şifreli Matrisimizi çarparak şfiresiz matrisi oluşturuyoruz.
                }       
            sifresiz[i][j] = deger;  			// Kodda deger değişkeni tutarak şifresiz matrisimizi ayarlıyoruz.(Birbirine karışmasın diye)
            }
    
	}
	int say=0;	// Çift boyutlu şifresiz matrisimizi tek boyutlu şifresiz matrisimize dönüştürürken kullanmak için bir sayac belirliyoruz.
	for(i=0; i<a; i++)
 		for(j=0; j<a; j++){
 			sifresiz2[say]=sifresiz[i][j];	// Sayacı kullanarak şifresiz matrisimize yazının elemanlarını yerleştiriyoruz.
 			say += 1;
		 	if(uzunluk==say){
		 		i=a+1; j=a+1;
			 }
 					
 		}
    printf("\n _________Şifreniz____________ \n ");
 	for(i=0; i<say; i++)
 		printf(" %c",sifresiz2[i]);		// Çözülen Şifreyi Gösteriyoruz.
	printf("\n");		
 	for(i = 0; i < a; i++){
    	for(j = 0; j < a; j++){
    		printf(" %d", sifresiz[i][j]);   // Şifresiz Matrisimizi Tekrardan Gösteriyoruz.
            }
        printf("\n");
        }		
}
	return 0;
}
