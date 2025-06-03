#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto{
    float x;
    float y;
} Ponto;

typedef struct circulo{
    Ponto p;
    float r;
} Circulo;

Ponto *cria_ponto();
void *exibe_ponto(Ponto *p);
float distancia(Ponto *p, Ponto *q);

int main() {
    Ponto *p1 = cria_ponto();
    scanf("%f %f", &p1->x, &p1->y);
    
    Ponto *p2 = cria_ponto();
    scanf("%f %f", &p2->x, &p2->y);
    
    exibe_ponto(p1);
    exibe_ponto(p2);
    printf("\nA distancia entre os pontos e %.2f", distancia(p1, p2));
    return 0;
}

Ponto *cria_ponto(){
    Ponto *p = (Ponto*)malloc(sizeof(Ponto));
    if(!p){
        printf("Memoria insuficiente para alocacao.");
    }
    
    return p;
}

void *exibe_ponto(Ponto *p){
    printf("(%.2f, %.2f)", p->x, p->y);
}


float distancia(Ponto *p, Ponto *q){
    return sqrt(pow(q->x - p->x, 2) + pow(q->y - p->y, 2));
}

