#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto{
    float x;
    float y;
} Ponto;

typedef struct circulo{
    Ponto p; // Ponto central;
    float r;
} Circulo;

Ponto *cria_ponto();
void *exibe_ponto(Ponto *p);
float distancia(Ponto *p, Ponto *q);
int validacao(Circulo *c, Ponto *p);

int main() {
    Ponto *p1 = cria_ponto();
    scanf("%f %f", &p1->x, &p1->y);
    
    Circulo *c1 = (Circulo*)malloc(sizeof(Circulo));
    
    c1->p.x = 0;
    c1->p.y = 0;
    c1->r = 5;

    if (validacao(c1, p1) == 1){
        printf("O ponto ");
        exibe_ponto(p1);
        printf(" está dentro do círculo.\n");
    } else {
        printf("O ponto ");
        exibe_ponto(p1);
        printf(" está fora do círculo.\n");
    }

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
    printf("\n(%.2f, %.2f)", p->x, p->y);
}

float distancia(Ponto *p, Ponto *q){
    return sqrt(pow(q->x - p->x, 2) + pow(q->y - p->y, 2));
}

int validacao(Circulo *c, Ponto *p){
    float d = distancia(&c->p, p);
    return (d <= c->r);
}
