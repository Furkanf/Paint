#include <allegro.h>
#include <math.h>


void Baslat();
void Bitir();         
void arackutusu();
void ciz_kontrol();
void ekran();
BITMAP *bmp;
int secim,secilen_renk,arkaplanrengi,renk,a,b;
void ciz();
PALETTE pal;


int main() {

    Baslat();
	bmp=create_bitmap(640,480);

	show_mouse(screen);
    ekran();

	while (!key[KEY_ENTER] && !key[KEY_ESC])
    {
    acquire_screen();
    blit(bmp, screen, 0, 0, 0, 0, 640, 480);
    release_screen();

    if(mouse_b==2){
        a=mouse_x;
        b=mouse_y;
    }

     if((mouse_x>0)&&(mouse_y>22))
         ciz();
     else if(mouse_x>420 && mouse_x<639 && mouse_y>0 && mouse_y<20)
        renk_kontrol();
     else if(mouse_x<410 && mouse_y<21)
        ciz_kontrol();
    }
	Bitir();
	return 0;
}
END_OF_MAIN()

void ekran()
{
     clear_to_color(bmp,makecol(255,0,0));
     secilen_renk=makecol(0,0,0);
     arkaplanrengi=makecol(255,255,255);
     arackutusu();
     rectfill(bmp,0,22,640,480,arkaplanrengi);
}

void arackutusu()
{
    rectfill(bmp, 0, 0, 639, 22,makecol(34,177,76));
    textprintf_centre_ex(bmp, font, 34, 7, makecol(20, 24, 100),-1,"YENI");
    textprintf_centre_ex(bmp, font, 82, 7, makecol(20, 24, 100),-1,"KAYDET");
    textprintf_centre_ex(bmp, font, 141, 7, makecol(20, 24, 100),-1,"YUKLE");
    textprintf_centre_ex(bmp, font, 195, 7, makecol(20, 24, 100),-1,"KALEM");
    textprintf_centre_ex(bmp, font, 250, 7, makecol(20, 24, 100),-1,"SILGI");

    triangle(bmp,283,18,294,2,305,18,makecol(0,0,0));
    rectfill(bmp,312,3,330,18,makecol(0,0,0));
    circlefill(bmp,349,10,8,makecol(0,0,0));
    rect(bmp,364,3,382,18,makecol(0,0,0));
    circle(bmp,398,10,8,makecol(0,0,0));

                  
    rectfill(bmp, 423, 3, 439, 20, makecol(255,255,255)); //BEYAZ
    rectfill(bmp, 443, 3, 459, 20, makecol(255,0,0)); //KIRMIZI
    rectfill(bmp, 463, 3, 479, 20, makecol(0,255,0)); //YEŞİL
    rectfill(bmp, 483, 3, 499, 20, makecol(0,0,255)); //MAVİ
    rectfill(bmp, 503, 3, 519, 20, makecol(120,120,120)); //GRİ
    rectfill(bmp, 523, 3, 539, 20, makecol(255,0,255));// MOR RENK
    rectfill(bmp, 543, 3, 559, 20, makecol(1,1,1));// SIYAH RENK
    rectfill(bmp, 563, 3, 579, 20, makecol(230,200,0));// SARI RENK
    rectfill(bmp, 583, 3, 599, 20, makecol(117,58,0));// SARI RENK
    rectfill(bmp, 603, 3, 619, 20, makecol(128,0,128));// SARI RENK
    vline(bmp,415,0,20,makecol(0,0,0));
    textprintf_centre_ex(bmp, font, 632, 7, makecol(255, 0, 0),-1,"X");

}
void renk_kontrol()
{
          if(mouse_b==1)
          {
          if(mouse_x>423 && mouse_x<439)
          secilen_renk=makecol(255,255,255);
          else if(mouse_x>443 && mouse_x<459)
          secilen_renk=makecol(255,0,0);
          else if(mouse_x>463 && mouse_x<479)
          secilen_renk=makecol(0,255,0);
          else if(mouse_x>483 && mouse_x<499)
          secilen_renk=makecol(0,0,255);
          else if(mouse_x>503 && mouse_x<519)
          secilen_renk=makecol(120,120,120);
          else if(mouse_x>523 && mouse_x<539)
          secilen_renk=makecol(255,0,255);
          else if(mouse_x>543 && mouse_x<559)
          secilen_renk=makecol(1,1,1);
          else if(mouse_x>563 && mouse_x<579)
          secilen_renk=makecol(230,200,0);
          else if(mouse_x>583 && mouse_x<599)
          secilen_renk=makecol(117,58,0);
          else if(mouse_x>603 && mouse_x<619)
          secilen_renk=makecol(128,0,128);
          else if(mouse_x>625)
          exit(-1);
          }
}

void ciz()
{
     if (mouse_b==1)
     {
            if(secim==2){
            get_pallete(pal);
            save_bitmap("abc.bmp",bmp,pal);}
            else if(secim==3){
            bmp=load_bitmap("abc.bmp",pal);            }
            else if(secim==4)
            putpixel(bmp,mouse_x,mouse_y,secilen_renk);
            else if(secim==5){
            circlefill(bmp,mouse_x,mouse_y,15,makecol(255,255,255));
            }
            else if(secim==6){
            triangle(bmp,mouse_x,mouse_y,a+(a-mouse_x),mouse_y,a,b,secilen_renk);}
            else if(secim==7){
            rectfill(bmp,a,b,mouse_x,mouse_y,secilen_renk);}
            else if(secim==8){
            circlefill(bmp,a,b,sqrt((pow(mouse_x-a,2)+pow(mouse_y-b,2))),secilen_renk);}
            else if(secim==9){
            rect(bmp,a,b,mouse_x,mouse_y,secilen_renk);}
            else if(secim==10){
            circle(bmp,a,b,sqrt((pow(mouse_x-a,2)+pow(mouse_y-b,2))),secilen_renk);}
            arackutusu();
     }
}
void ciz_kontrol()
{
          if(mouse_b==1)
          {
          if(mouse_x>0 && mouse_x<53){
          rectfill(bmp,0,22,640,480,arkaplanrengi);
          secim=4;}
          else if(mouse_x>53 && mouse_x<110)
          secim=2;
          else if(mouse_x>110 && mouse_x<165)
          secim=3;
          else if(mouse_x>165 && mouse_x<223)
          secim=4;
          else if(mouse_x>223 && mouse_x<275)
          secim=5;
          else if(mouse_x>278 && mouse_x<308)
          secim=6;
          else if(mouse_x>308 && mouse_x<336)
          secim=7;
          else if(mouse_x>336 && mouse_x<361)
          secim=8;
          else if(mouse_x>361 && mouse_x<387)
          secim=9;
          else if(mouse_x>387 && mouse_x<410)
          secim=10;
          }
}
void Baslat() {
	int derinlik, res;
	allegro_init();
	derinlik = desktop_color_depth();
	if (derinlik == 0) derinlik = 32;
	set_color_depth(derinlik);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	install_keyboard();
	install_mouse();
}
void Bitir() {
	clear_keybuf();
}
