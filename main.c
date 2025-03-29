#include <stdio.h>
#include <stdlib.h>

typedef struct{
int x,y;
}kisi;

double oklid(kisi a, kisi b)
{
   return sqrt(pow(a.x - b.x,2)+ pow(a.y-b.y,2));
}


int manhattan(kisi a, kisi b)
{
 return abs(a.x - b.x)+ abs(a.y - b.y);
}

 int gecerliKoordinatKontrol(int x, int y, int genislik, int yukseklik)
 {
     if (x < 0 || x >= genislik || y<0 || y>= yukseklik)
     {
     printf("Hata!Koordinat labirent sinirlari disinda.Tekrar yaziniz.\n");
     return 0;
     }


     if(x == 0 & y == 0)
     {
         printf("Hata!(0,0) koordinatlarini girmek yasaktir.Tekrar Dene. \n ");
         return 0;
     }


    return 1;

 }

 kisi kisiKoordinatiAl(int genislik, int yukseklik)
 {
     kisi k;
     while(1)
     {
         scanf("%d%d", &k.x , &k.y);

         if(gecerliKoordinatKontrol(k.x , k.y , genislik , yukseklik))
         {
             break;
         }
     }
   return k;
 }

   int main()
   {
       int genislik , yukseklik , kisiSayisi;
       kisi kisiler[kisiSayisi];
       kisi kendiKonum;
       int tespitMesafesi, uzaklikMetodu;

       printf("Labirent Genisligini Gir: ");
       scanf("%d", &genislik);

       printf("Labirent Yuksekligi Gir: ");
       scanf("%d", &yukseklik);

       printf("Labirentte Kac Kisi Var?Gir: ");
       scanf("%d", &kisiSayisi);


       for(int i=0 ; i<kisiSayisi ; i++)
       {
           printf("Kisi %d koordinatlarini girin (x y): ",i+1);
           kisiler[i]=kisiKoordinatiAl(genislik,yukseklik);
       }
       {
           printf("Kendi Konumunuzu Giriniz (x y): ");
           kendiKonum = kisiKoordinatiAl(genislik , yukseklik);

           printf("Tespit mesafesini giriniz: ");
           scanf("%d", &tespitMesafesi);

           printf("Uzaklik yontemini secin (1:oklid , 2: manhattan)");
           scanf("%d", &uzaklikMetodu);


           printf("\n Sizin noktaniz: (%d,%d)\n",kendiKonum.x, kendiKonum.y);
           printf("Etrafinizdaki kisiler (%d.00 mesafe icinde olanlar):\n", tespitMesafesi);


           double enYakinMesafe = -1;
           double enUzakMesafe = -1;
           kisi enyakinkisi, enuzakkisi;

           for(int q=0; q<kisiSayisi;q++)
           {
               double mesafe = (uzaklikMetodu == 1) ? oklid(kendiKonum,kisiler[q]) : manhattan(kendiKonum, kisiler[q]);


                    if(mesafe <= tespitMesafesi)
                    {
                        printf("kisi %d: (%d,%d) - Uzaklik: %.2f\n",q+1,kisiler[q].x , kisiler[q].y , mesafe);
                    }
                    if(enYakinMesafe == -1 || mesafe < enYakinMesafe)
                    {
                        enYakinMesafe=mesafe;
                        enyakinkisi=kisiler[q];
                    }
                    if(enUzakMesafe == -1 || mesafe > enUzakMesafe)
                    {
                        enUzakMesafe=mesafe;
                        enuzakkisi=kisiler[q];
                    }

           }


             printf("\n En yakin kisi: (%d,%d) - uzaklik: %.2f\n", enyakinkisi.x  ,enyakinkisi.y , enYakinMesafe );
             printf("\n En uzak kisi: (%d,%d) - uzaklik: %.2f\n", enuzakkisi.x , enuzakkisi.y , enUzakMesafe);




           return 0;
       }




   }




