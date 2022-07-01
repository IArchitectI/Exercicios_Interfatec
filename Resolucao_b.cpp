#include <iostream>

using namespace std;

struct Coordenadas{
    int coordenada_i;
    int coordenada_j;
};

int Maior_grupo_vetor(int, int *);
Coordenadas Retorna_Vetor_Melhor_Movimento(int ,int*,int );
void Altera_vetor_com_as_coordenadas(Coordenadas , int*);

int main(){
    int vetor_booleano[100000]={}, pedido_cliente, armarios_disponiveis, posicao,grupo_comparacao,saida=0,aux;
    Coordenadas auxiliar;

    cin>>pedido_cliente>>armarios_disponiveis;

    for(int i=0 ; i<armarios_disponiveis ; i++){
        cin>>posicao;
        vetor_booleano[posicao-1]=1;
    }

    grupo_comparacao=Maior_grupo_vetor(posicao,vetor_booleano);


    if(grupo_comparacao>=pedido_cliente){
        saida=0;
    }    
    else{
        do{
            auxiliar=Retorna_Vetor_Melhor_Movimento(posicao,vetor_booleano,grupo_comparacao);
            Altera_vetor_com_as_coordenadas(auxiliar,vetor_booleano);
            aux=Maior_grupo_vetor(posicao,vetor_booleano);
            grupo_comparacao=aux;
            saida++;
        }while(aux<pedido_cliente);
    }    
    
    cout<<saida;    
}    
int Maior_grupo_vetor(int posicao, int *vetor_analisado){

    int sequencia=0;
    int maior_grupo=0;
    for(int i=0 ; i<posicao ; i++){
        if(vetor_analisado[i]==1){
            sequencia++;
            
            if(sequencia>maior_grupo){
                maior_grupo=sequencia;
            }
        }
        else{
            sequencia=0;            
        }
    }
    return maior_grupo;
}    
Coordenadas Retorna_Vetor_Melhor_Movimento(int posicao,int*vetor_para_permutacao,int grupo_comparacao){
    int aux;
    Coordenadas valores;
   
    int maior_grupo=grupo_comparacao;

    for(int i=0 ; i<posicao ; i++){
        for(int j=i+1 ; j<posicao ; j++){
            aux=vetor_para_permutacao[i];
            vetor_para_permutacao[i]=vetor_para_permutacao[j];
            vetor_para_permutacao[j]=aux;

            if(maior_grupo<Maior_grupo_vetor(posicao,vetor_para_permutacao)){
                maior_grupo=Maior_grupo_vetor(posicao,vetor_para_permutacao);
                valores.coordenada_i=i;
                valores.coordenada_j=j;

                aux=vetor_para_permutacao[j];
                vetor_para_permutacao[j]=vetor_para_permutacao[i];
                vetor_para_permutacao[i]=aux;
            }
            else{
                aux=vetor_para_permutacao[j];
                vetor_para_permutacao[j]=vetor_para_permutacao[i];
                vetor_para_permutacao[i]=aux;
            }          
        }
    }
    return valores;
}
void Altera_vetor_com_as_coordenadas(Coordenadas valor, int* vetor_a_ser_trocado){
    int aux;
    aux=vetor_a_ser_trocado[valor.coordenada_i];
    vetor_a_ser_trocado[valor.coordenada_i]=vetor_a_ser_trocado[valor.coordenada_j];
    vetor_a_ser_trocado[valor.coordenada_j]=aux;
}   