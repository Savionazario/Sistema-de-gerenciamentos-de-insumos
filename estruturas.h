#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include <string>
#define MAX 10

using namespace std;

typedef struct{
    string nome;
    float valorUnitario;
    int qItens;
    string dataVencimento;
    string nomeFabricante;
} tDados; //Todas as informações do produto.

typedef struct{
    tDados dadosVacina;
    string tecnologia; //ex: RNA mensageiro, vírus inativado, etc.
    int qDoses; //quantidade de doses necessárias.
    int intervalo; //intervalo de dias entre as doses.
    bool vTest = false;
} tVacina; //Estrutura da vacina.

typedef struct{
    tDados dadosMedicamento;
    int dosagem;
    string uso; //ex: oral, intravenosa, etc.
    string forma; //ex: líquido, comprimido, etc.
} tMedicamento; //Estrutura do medicamento.

typedef struct{
    tDados dadosEPI;
    string tipo; //ex: máscara, face shield, luvas, etc.
    string detalhesEPI; //detalhamento sobre as EPIs.
} tEPI; //Estrutura das EPIs.

typedef struct{
    string nomeEstado;
    tVacina estoqueVac[MAX];
    tMedicamento estoqueMed[MAX];
    tEPI estoqueEPI[MAX];
} tEstados;

#endif //ESTRUTURAS_H_INCLUDED