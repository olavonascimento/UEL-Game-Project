#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


#include "main.h"


void InitAlien1(enemy alien1[], const int NUMALIEN){
    for(int i = 0; i<NUMALIEN; ++i){
        alien1[i].x = 256 + i*75;
        alien1[i].y = 0;
        alien1[i].velx = 2;
        alien1[i].vely = 15;
        alien1[i].live = true;
        alien1[i].totalframes = 2;
        alien1[i].currentframe = 0;
        alien1[i].framedelay = 50;
        alien1[i].framecounter = 0;
        alien1[i].framewidth = 65;
        alien1[i].frameheight = 52;

        alien1[i].exp.totalframes = 7;
        alien1[i].exp.currentframe = 0;
        alien1[i].exp.framedelay = 5;
        alien1[i].exp.framecounter = 0;
        alien1[i].exp.framewidth = 65;
        alien1[i].exp.start = false;



    }

}

void InitAlien2(enemy alien2[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            alien2[i][j].x = 256 + j*75;
            alien2[i][j].y = (i+1)*62;
            alien2[i][j].velx = 2;
            alien2[i][j].vely = 7.5;
            alien2[i][j].live = true;
            alien2[i][j].totalframes = 2;
            alien2[i][j].currentframe = 0;
            alien2[i][j].framedelay = 50;
            alien2[i][j].framecounter = 0;
            alien2[i][j].framewidth = 65;
            alien2[i][j].frameheight = 52;

            alien2[i][j].exp.totalframes = 7;
            alien2[i][j].exp.currentframe = 0;
            alien2[i][j].exp.framedelay = 5;
            alien2[i][j].exp.framecounter = 0;
            alien2[i][j].exp.framewidth = 65;
            alien2[i][j].exp.start = false;

        }
    }

}


void InitAlien3(enemy alien3[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            alien3[i][j].x = 256 + j*75;
            alien3[i][j].y = (i+3)*62;
            alien3[i][j].velx = 2;
            alien3[i][j].vely = 7.5;
            alien3[i][j].live = true;
            alien3[i][j].totalframes = 2;
            alien3[i][j].currentframe = 0;
            alien3[i][j].framedelay = 50;
            alien3[i][j].framecounter = 0;
            alien3[i][j].framewidth = 65;
            alien3[i][j].frameheight = 52;

            alien3[i][j].exp.totalframes = 7;
            alien3[i][j].exp.currentframe = 0;
            alien3[i][j].exp.framedelay = 5;
            alien3[i][j].exp.framecounter = 0;
            alien3[i][j].exp.framewidth = 65;
            alien3[i][j].exp.start = false;

        }
    }

}


void limitXmoveY_alien1(enemy alien1[], const int NUMALIEN){
    for(int i = 0; i< NUMALIEN; ++i){
        if(alien1[9].x + alien1[9].framewidth >= 1200){
            alien1[i].velx = -2;
            if(alien1[9].y + alien1[9].frameheight <= 245)
                alien1[i].y += alien1[i].vely;
        }

        if(alien1[0].x <= 80){
            alien1[i].velx = 2;
            if(alien1[0].y + alien1[i].frameheight <= 245)
                alien1[i].y += alien1[i].vely;
        }
    }

}

void limitXmoveY_alien2(enemy alien2[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien2[i][9].x + alien2[1][j].framewidth >= 1200){
                alien2[i][j].velx = -2;
                if(alien2[1][j].y + alien2[1][j].frameheight <= 369)
                    alien2[1][j].y += alien2[i][j].vely;
                if(alien2[0][j].y + alien2[0][j].frameheight <= 307)
                    alien2[0][j].y += alien2[i][j].vely;
            }

            if(alien2[i][0].x <= 80){
                alien2[i][j].velx = 2;
                if(alien2[1][j].y + alien2[1][j].frameheight <= 369)
                    alien2[1][j].y += alien2[i][j].vely;
                if(alien2[0][j].y + alien2[0][j].frameheight <= 307)
                    alien2[0][j].y += alien2[i][j].vely;
            }
        }
    }

}


void limitXmoveY_alien3(enemy alien3[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien3[i][9].x + alien3[i][9].framewidth >= 1200){
                alien3[i][j].velx = -2;
                if(alien3[1][j].y + alien3[1][j].frameheight <= 493)
                    alien3[1][j].y += alien3[i][j].vely;
                if(alien3[0][j].y + alien3[0][j].frameheight<= 431)
                    alien3[0][j].y += alien3[i][j].vely;
            }

            if(alien3[i][0].x <=80){
                alien3[i][j].velx = 2;
                if(alien3[1][j].y + alien3[1][j].frameheight <= 493)
                    alien3[1][j].y += alien3[i][j].vely;
                if(alien3[0][j].y + alien3[0][j].frameheight<= 431)
                    alien3[0][j].y += alien3[i][j].vely;
            }
        }
    }

}


void moveX_alien1(enemy alien1[], const int NUMALIEN){
    for(int i = 0; i< NUMALIEN; ++i)
        alien1[i].x += alien1[i].velx;

}


void moveX_alien2(enemy alien2[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i)
        for(int j = 0; j<NUM_ALIEN; ++j)
            alien2[i][j].x += alien2[i][j].velx;

}


void moveX_alien3(enemy alien3[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i)
        for(int j = 0; j<NUM_ALIEN; ++j)
            alien3[i][j].x += alien3[i][j].velx;

}


void updateSprite_alien1(enemy alien1[], const int NUMALIEN){
    for(int i = 0; i< NUMALIEN; ++i){
        if(alien1[i].live){
            if(++alien1[i].framecounter >= alien1[i].framedelay){
                if(++alien1[i].currentframe >= alien1[i].totalframes){
                    alien1[i].currentframe = 0;
                }
                alien1[i].framecounter = 0;
            }
        }
    }

}

void updateSprite_alien2(enemy alien2[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien2[i][j].live){
                if(++alien2[i][j].framecounter >= alien2[i][j].framedelay){
                    if(++alien2[i][j].currentframe >= alien2[i][j].totalframes){
                        alien2[i][j].currentframe = 0;
                    }
                    alien2[i][j].framecounter = 0;
                }
            }
        }
    }

}

void updateSprite_alien3(enemy alien3[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien3[i][j].live){
                if(++alien3[i][j].framecounter >= alien3[i][j].framedelay){
                    if(++alien3[i][j].currentframe >= alien3[i][j].totalframes){
                        alien3[i][j].currentframe = 0;
                    }
                    alien3[i][j].framecounter = 0;
                }
            }
        }
    }

}


void draw_alien1(ALLEGRO_BITMAP *alien1img, enemy alien1[], const int NUMALIEN){
    for(int i = 0; i<NUMALIEN; ++i){
        if(alien1[i].live)
            al_draw_bitmap_region(alien1img, alien1[i].currentframe*alien1[i].framewidth, 0, alien1[i].framewidth, alien1[i].frameheight, alien1[i].x, alien1[i].y, 0);
    }

}

void draw_alien2(ALLEGRO_BITMAP *alien2img, enemy alien2[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien2[i][j].live)
                al_draw_bitmap_region(alien2img, alien2[i][j].currentframe*alien2[i][j].framewidth, 0, alien2[i][j].framewidth, alien2[i][j].frameheight, alien2[i][j].x, alien2[i][j].y, 0);
        }
    }

}

void draw_alien3(ALLEGRO_BITMAP *alien3img, enemy alien3[][NUM_ALIEN], const int x){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien3[i][j].live)
                al_draw_bitmap_region(alien3img, alien3[i][j].currentframe*alien3[i][j].framewidth, 0, alien3[i][j].framewidth, alien3[i][j].frameheight, alien3[i][j].x, alien3[i][j].y, 0);
        }
    }

}



void detectBulletCollision_alien1(enemy alien1[], const int NUMALIEN, bullet bullets[], const int bulletquantity){
    for(int i = 0; i<NUMALIEN; ++i){
        if(alien1[i].live){
            for(int j = 0; j<bulletquantity; ++j){
               if(bullets[j].live){
                    if(bullets[j].x <= alien1[i].x + alien1[i].framewidth - 2 &&
                       bullets[j].x + bullets[j].width >= alien1[i].x + 2 &&
                       bullets[j].y <= alien1[i].y + alien1[i].frameheight - 2 &&
                       bullets[j].y + bullets[j].height >= alien1[i].y + 2){
                        bullets[j].live = false;
                        alien1[i].live = false;
                        alien1[i].exp.start = true;
                    }
               }
            }

        }
    }

}

void detectBulletCollision_alien2(enemy alien2[][NUM_ALIEN], const int x, bullet bullets[], const int bulletquantity){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien2[i][j].live){
                for(int k = 0; k<bulletquantity; ++k){
                    if(bullets[k].live){
                        if(bullets[k].x <= alien2[i][j].x + alien2[i][j].framewidth - 2 &&
                           bullets[k].x + bullets[k].width >= alien2[i][j].x + 2 &&
                           bullets[k].y <= alien2[i][j].y + alien2[i][j].frameheight - 2 &&
                           bullets[k].y + bullets[k].height >= alien2[i][j].y + 2){
                            bullets[k].live = false;
                            alien2[i][j].live = false;
                            alien2[i][j].exp.start = true;
                        }
                    }
                }
            }
        }
    }

}

void detectBulletCollision_alien3(enemy alien3[][NUM_ALIEN], const int x, bullet bullets[], const int bulletquantity){
    for(int i = 0; i<x; ++i){
        for(int j = 0; j<NUM_ALIEN; ++j){
            if(alien3[i][j].live){
                for(int k = 0; k<bulletquantity; ++k){
                    if(bullets[k].live){
                        if(bullets[k].x <= alien3[i][j].x + alien3[i][j].framewidth - 2 &&
                           bullets[k].x + bullets[k].width >= alien3[i][j].x + 2 &&
                           bullets[k].y <= alien3[i][j].y + alien3[i][j].frameheight - 2 &&
                           bullets[k].y + bullets[k].height >= alien3[i][j].y + 2){
                            bullets[k].live = false;
                            alien3[i][j].live = false;
                            alien3[i][j].exp.start = true;
                        }
                    }
                }
            }
        }
    }

}

