#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10000000
void trocar(int vet[], int num1, int num2);
//void imprimir(int vet[], int n);
void subir(int i, int vet[]);
void descer(int i, int n, int ver[]);
void inserir(int novo, int pos, int vet[]);
void remover(int vet[], int n);
void construir(int vet[], int n);
void copiar(int vet_novo[], int vet_antigo[]);
void heap_sort(int vet[], int n);
void insertion_sort(int vet[], int tam);

int main(){
    int vetor_original[TAM], vetor_novo[TAM];
    clock_t temp_ini_heapsort, temp_fin_heapsort, temp_ini_insertionsort, temp_fin_insertionsort;
    
    //função srand gera valores aleatoriamente a cada execução
    srand(time(NULL));
    for (int k=1; k<=TAM; k++){
        vetor_original[k] = rand() % 10000000;
    }
    //função faz uma cópia do vetor para que possa ser usado tanto no insertion-sort quanto pro heap-sort
    copiar(vetor_novo, vetor_original);
    //imprimir(vetor_original,TAM);

    //printf("\n----ORDENAÇÃO----\n");

    temp_ini_heapsort = clock();
    heap_sort(vetor_original,TAM);
    temp_fin_heapsort = clock();

    temp_ini_insertionsort = clock();
    insertion_sort(vetor_novo, TAM);
    temp_fin_insertionsort = clock();

    printf("\n\n----TEMPO DE EXECUÇÃO----");
    printf ("\nTempo gasto no Heap-sort: %.0f ms", 1000*( double ) ( temp_fin_heapsort - temp_ini_heapsort)/(double)(CLOCKS_PER_SEC));
    printf ("\nTempo gasto no Insertion-sort: %.0f ms\n", 1000*( double ) ( temp_fin_insertionsort - temp_ini_insertionsort)/(double)(CLOCKS_PER_SEC));

    return 0;
}

void trocar(int vet[], int num1, int num2){
    int aux;
    aux = vet[num1];
    vet[num1] = vet[num2];
    vet[num2] = aux;
}

/*void imprimir(int vet[], int n){
    printf("[ ");
    for(int i=1; i<=n; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}*/   

void subir(int i, int vet[]){
    int pai = i/2;
    if(pai>0){
        if(vet[i]>vet[pai]){
            trocar(vet, i, pai);
            subir(pai, vet);        
        }
    }
}

void descer(int i, int n, int vet[]){
    int filho = 2*i;
    if(filho<=n){
        if(filho<n){
            if(vet[filho+1] > vet[filho]){
                filho = filho+1;
            }
        }
        if(vet[filho] > vet[i]){
            trocar(vet, i, filho);
            descer(filho, n, vet);  
        }
    }
}

/*void inserir(int novo, int pos, int vet[]){
    if(pos<TAM){
        printf("\nInserindo elemento: %d", novo);
        vet[pos] = novo;
        subir(pos, vet);
    }else{
        printf("\nOverflow.\n");
    }
    imprimir(vet,pos);
}*/

/*void remover(int vet[], int n){
    if(n!=0){
        int aux;
        aux = vet[1];
        vet[1] = vet[n];
        n = n-1;
        descer(1,n,vet);
        printf("\nElemento removido: %d\n", aux);
        imprimir(vet,n);
    }else{
        printf("\nUnderflow.\n");
    }
}*/

void construir(int vet[], int n){
    for(int i=(n/2); i>=1; i--){
        descer(i,n,vet);
    }
}

void copiar(int vet_novo[], int vet_antigo[]){
    for(int aux=1; aux<=TAM; aux++)
        vet_novo[aux] = vet_antigo[aux];
}

void heap_sort(int vet[], int n){
    construir(vet,n);
    int m;
    m = n;
    while(m>1){
        trocar(vet,1,m);
        m = m-1;
        descer(1,m,vet);
    }
    //printf("Heap-Sort: ");
    //imprimir(vet,n);
}

void insertion_sort(int vet[], int tam){
    int i, j, chave;

    for(j=1; j<tam; j++){
        chave = vet[j];
        i = j-1;
        while((vet[i]>chave) && (i>=0)){
            vet[i+1] = vet[i];
            i = i-1;
        }
        vet[i+1] = chave;
    }
    //printf("\nInsertion-Sort: ");
    //imprimir(vet,tam);
}