#ifndef _funcoes_h_
#define _funcoes_h_


#define MAX_SEGMENTOS 1000
#define TAM_SEGMENTO 10



int y_cobra;
typedef struct {
    int x;
    int y;
} Segmento;

typedef struct {
    Segmento segmentos[MAX_SEGMENTOS];
    int direcao;
    int tamanho;
} Cobra;

typedef struct {
    
    char nome[50];
    int  pontuacao;
} jogador;
//game over 
void game_over(){
   
    abre_janela(640,480);
    
    toca_som("assets/game_over.mp3");
    
    while (janela_esta_aberta()) {
    


    fonte("assets/ubuntu.ttf", 50);
    cor(VERMELHO);
    desenha_texto(200, 150, " GAME OVER !");

    fonte("assets/ubuntu.ttf", 20);
    cor(BRANCO);
    desenha_texto(10, 20, " clique (ESC) para sair ");

    fonte("assets/ubuntu.ttf", 20);
    cor(BRANCO);
    desenha_texto(10, 40, " entre no arquivo para ver seu score e e outros jogadores  ");

    
    
    //teclas 
    if (tecla_acabou_de_ser_apertada(ESC))
            janela_deve_fechar();
    
    
    }
            
}

//-----------------------------------------------------------------------------------------------------------
//criação cobra
Cobra *cria_cobra(){
    Cobra *cobra = (Cobra*)malloc(sizeof(Cobra));
    cobra->segmentos[0].x = 320;
    cobra->segmentos[0].y = 240;   
    cobra->segmentos[1].x = 310;
    cobra->segmentos[1].y = 240;    
    cobra->segmentos[2].x = 300;
    cobra->segmentos[2].y = 240;    
    cobra->segmentos[3].x = 290;
    cobra->segmentos[3].y = 240;    
    cobra->direcao = DIREITA;
    cobra->tamanho = 1;
    return cobra;
    
}


void atualiza_cobra(Cobra *cobra){
    //cria movimentação
    Segmento nova_cabeca;
    int tamanho_cobra = cobra->tamanho;
    nova_cabeca.x = cobra->segmentos[0].x;
    nova_cabeca.y = cobra->segmentos[0].y;

    if(cobra->direcao == CIMA){
        nova_cabeca.y -= TAM_SEGMENTO;
    }
    if(cobra->direcao == BAIXO){
        nova_cabeca.y += TAM_SEGMENTO;
    }
    if(cobra->direcao == DIREITA){
        nova_cabeca.x += TAM_SEGMENTO;
    }
    if(cobra->direcao == ESQUERDA){
        nova_cabeca.x -= TAM_SEGMENTO;
    }

    for(int i=tamanho_cobra-1; i>=0; i--){
        cobra->segmentos[i+1] = cobra->segmentos[i];
    }
    cobra->segmentos[0] = nova_cabeca;
}
// limite esta aqui
void desenha_cobra(Cobra *cobra,int score){
    //movimentação da cobra e onde ela "nasce"
     for(int i=0; i < cobra->tamanho; i++){
        int x = cobra->segmentos[i].x;
        int y = cobra->segmentos[i].y;
        cor(VERDE);
        desenha_retangulo(x, y, TAM_SEGMENTO, TAM_SEGMENTO);
        
        //limite 
        if((x == 660)||(x == 0)){
            toca_som("assets/morte.mp3");
            
            fecha_janela();
            game_over(score);
            FILE *placar;
    
   
    placar = fopen("arquivo.txt","a");

    if(placar == NULL){
        printf("erro ao abrir arquivo\n");
        
    }
        fscanf(placar,"%s %d\n",score,"\n");
      
    
    fclose(placar);
    printf("%d",score);

   
   
    
        }
        //limite Y
        if((y == 500)||(y == 0)){
            toca_som("assets/morte.mp3");
           
           fecha_janela();
          
           game_over(score);
          
           FILE *placar;
    
   
    placar = fopen("arquivo.txt","a");

    if(placar == NULL){
        printf("erro ao abrir arquivo\n");
        
    }
        fscanf(placar,"%s %d\n",score,"\n");
      
    
    fclose(placar);
    printf("%d",score);
    
        
    
        }
    }
}


//-------------------------------------------------------------------------------------------------------
//criação da fruta
int fruta_cordenadaX(){
 int x;
  
srand(time(NULL));
     
x=(rand()%(610/10))*10;

return x;
}
int fruta_cordenadaY(){
   int y;
   srand(time(NULL));
     
y=(rand()%(330/10))*10;

return y; 
}





///---------------------------------------------------------------------------------------------------
//jogo
void inicia_jogo(int velocidade,jogador jogador_atual){
   int deve_abrir_game_over=0;
   int posica_cobrax,posica_cobray;;
   int score=0;
   int frutaX =fruta_cordenadaX();
   int frutaY =fruta_cordenadaY();

 abre_janela(640, 480);
     
     toca_som("assets/song_menu.mp3");
   
   
    
    Cobra *cobra = cria_cobra();
    
    toca_som_em_loop("assets/musica.mp3");
 
 
   

    while (janela_esta_aberta()) {

 posica_cobrax = cobra->segmentos[0].x;
 posica_cobray = cobra->segmentos[0].y; 
  
    desenha_imagem(320, 240, "assets/fundo_gameplay.jpg");
   
   // imprime score atualizado
   fonte("assets/ubuntu.ttf", 35);
   cor(PRETO);
   desenha_texto(10,20,"score: %d", score);


  //fruta e sua interação      
    cor(VERMELHO);
   desenha_retangulo(frutaX,frutaY,TAM_SEGMENTO,TAM_SEGMENTO);
 
   
    
 
  if((cobra->segmentos[0].x == frutaX) && (cobra->segmentos[0].y == frutaY)){
    
    toca_som("assets/morte.mp3");
    
    cobra->tamanho++;
    
    frutaX =fruta_cordenadaX();
    
    frutaY =fruta_cordenadaY();
    
    score++;
    
    jogador_atual.pontuacao++;
   }
//--------------------------------------------------------------------------------------------------------------
   
   //intereçao cobra-cobra
   for(int i=1;i < cobra->tamanho; i++){
    if(posica_cobrax == cobra->segmentos[i].x && posica_cobray == cobra->segmentos[i].y){
        deve_abrir_game_over=1;
        fecha_janela();
        
        
        
   }}
   if(deve_abrir_game_over == 1){
   game_over();
   FILE *placar;
    
   
    placar = fopen("arquivo.txt","a");

    if(placar == NULL){
        printf("erro ao abrir arquivo\n");
        
    }
        fscanf(placar,"%s %d\n",score,"\n");
      
    
    fclose(placar);
    printf("%d",score);
   }
   
     //---------------------------------------------------------      
       //elementoscobra 
        atualiza_cobra(cobra);
        desenha_cobra(cobra,score);
     
       
        

        //movimento
        if (tecla_acabou_de_ser_apertada('W')) {
            toca_som("assets/song_menu.mp3");
            cobra->direcao = CIMA;
            }
            
        if (tecla_acabou_de_ser_apertada('S')) {
             toca_som("assets/song_menu.mp3");
            cobra->direcao = BAIXO;
        }
        if (tecla_acabou_de_ser_apertada('A')) {
            toca_som("assets/song_menu.mp3");
            cobra->direcao = ESQUERDA;
        }
        if (tecla_acabou_de_ser_apertada('D')) {
            toca_som("assets/song_menu.mp3");
            cobra->direcao = DIREITA;
        }
        if (tecla_acabou_de_ser_apertada(ESC))
            janela_deve_fechar();
        
        //velocidade
        int i=0;
        if(velocidade == 1){
        while(i < 100000000){
            i++;
        }
        }
        if(velocidade == 2){

        while(i < 19999990){
            i++;
        }
    }
    if(velocidade == 3){
        while(i < 10000000){
            i++;
        }
}
}

 fecha_janela();


    
}
#endif
