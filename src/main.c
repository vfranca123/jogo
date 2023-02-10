#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include <time.h>
#include "funcoes.h"
#define MAX_SEGMENTOS 1000
#define TAM_SEGMENTO 10


//----------------------------------------------------------------------------------------------------------
//menu
int main() {
   
   jogador jogador_atual;
   jogador todos_jogadores[5];

   printf(" digite seu nick:");
   scanf("%s",jogador_atual.nome);
   jogador_atual.pontuacao = 0;

   FILE *placar = fopen("placar.txt","w");

    if(placar == NULL){
        printf("erro ao abrir arquivo\n");
        return 1;
    }else{

    fscanf(placar,"%s",jogador_atual.nome);
    }
fclose(placar);


        
        
     //-------------------------------------------------------------------------------------------------   


    abre_janela(640, 480);// inicio menu 
    
    toca_som_em_loop("assets/musica.mp3");

   

    while (janela_esta_aberta()) {
        int dificuldade;
      

desenha_imagem(320, 240, "assets/fundo_jogo.jpg");
        

       

        //textos (menu)

        cor(VERDE);
        fonte("assets/ubuntu.ttf", 50);
        desenha_texto(250, 30, " SNAKE !");
        
        fonte("assets/ubuntu.ttf", 32);
         cor(AMARELO);
        desenha_texto(10, 130, "ESCOLHA A DIFICULDADE: ");
        
         cor(AMARELO);
        desenha_texto(10, 200, "(start) iniciante (lenta ) ");
        
         cor(AMARELO);
        desenha_texto(10, 300, "(start) pegando experiencia  (norma) ");

         cor(VERMELHO);
        desenha_texto(10, 400, "(start)a cobra vai fumar (rapida) ,clique W");
         
         fonte("assets/ubuntu.ttf", 10);
        cor(BRANCO);
        desenha_texto(10, 20, " made by Vitor ferreira Franca in windows  ");
//---------------------------------------------------------------------------------------------------
        
        // botoes
        if (tecla_acabou_de_ser_apertada(ESC))
            janela_deve_fechar();
        
        
        if (tecla_acabou_de_ser_apertada('W')){
            dificuldade =3;
            fecha_janela();
            inicia_jogo(dificuldade,jogador_atual);}

        if (botao_mouse_acabou_de_ser_apertado(BOTAO_ESQUERDO)){
            toca_som("assets/song_menu.mp3");
            if((mouse_x >0)&&(mouse_x<400)){
                if((mouse_y >180)&&(mouse_y<280)){
                    dificuldade =1;
                    fecha_janela();
                    inicia_jogo(dificuldade,jogador_atual);
                    
                }
                if((mouse_y >280)&&(mouse_y<380)){
                    dificuldade =2;
                    fecha_janela();
                    inicia_jogo(dificuldade,jogador_atual);
                    
                
            }        
        }
        //---------------------------------------------------------------------------------------------------
    }
}

}


        

      
        
        
        

    

 

         

        
   
   
   