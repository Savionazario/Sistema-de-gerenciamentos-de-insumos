#include <iostream>
#include <string>
#include "estruturas.h"
#include "funcoes.h"
#define MAX 10

using namespace std;

int main(){

    int casee, vVerificador[MAX] = {0}, mVerificador[MAX] = {0}, epiVerificador[MAX] = {0}, estadosVerificador[26] = {0};
    short n, x, continuar;
    string nomeEstado;
    tVacina vacinas[MAX];
    tMedicamento medicamentos[MAX];
    tEPI EPIs[MAX];
    tEstados estados[26];

    cout << "------UFPB 2021 - ENGENHARIA DE COMPUTACAO - PROJETO POO------" << endl
         << "Grupo: Leonardo Chianca, Savio Nazario e Yuri Fernandes\n" << endl
         << "------Bem-vindo ao Sistema de Gerenciamento de Insumos------\n" << endl;

    while(true)
    {
        cout << "Digite o numero correspondente a operacao que deseja executar: \n" << endl
             << "[0] - Fechar Sistema" << endl
             << "[1] - Cadastro de Insumos no estoque do MS" << endl
             << "[2] - Consulta de Insumos disponiveis no estoque do MS" << endl
             << "[3] - Consulta da descricao de Insumos disponiveis no estoque do MS" << endl
             << "[4] - Consulta de Insumos disponiveis no estoque do MS por tipo" << endl
             << "[5] - Consulta de Insumos distribuidos para os estados" << endl
             << "[6] - Consulta da descricao de Insumos disponiveis nos Estados" << endl
             << "[7] - Consulta de Insumos disponiveis no estoque dos Estados por tipo" << endl
             << "[8] - Consulta de Insumos disponiveis no estoque por Estado" << endl
             << "[9] - Distribuir Insumos entre Estados\n" << endl
             << "---------------------------------------------------------------------------" << endl;

        cin >> casee;

        system("CLS");

        switch(casee)
        {
            default: return 0;
                break;

            case 1: cadastroInsumos(vacinas, medicamentos, EPIs, vVerificador, mVerificador, epiVerificador);
                    break;

            case 2: printConsulta(vacinas, medicamentos, EPIs, vVerificador, mVerificador, epiVerificador);
                    cout << endl << "[1] - Voltar ao menu" << endl
                         << "-----------------------------------------" << endl;
                    cin >> continuar;
                    system("CLS");
                    break;                

            case 3: printConsultaDescricao(vacinas, medicamentos, EPIs, vVerificador, mVerificador, epiVerificador);
                    cout << endl << "[1] - Voltar ao menu" << endl
                         << "-----------------------------------------" << endl;
                    cin >> continuar;
                    system("CLS");
                    break;

            case 4: printIsumosTipo(vacinas, medicamentos, EPIs, vVerificador, mVerificador, epiVerificador);
                    break;

            case 5: consultaInsumosDistribuidos(estados, estadosVerificador);
                    break;

            case 6: printConsultaDescricaoEstados(estados, estadosVerificador);
                    cout << endl << "[1] - Voltar ao menu" << endl
                         << "-----------------------------------------" << endl;
                    cin >> continuar;
                    system("CLS");
                    break;

            case 7: printInsumosEstadosTipo(estados, estadosVerificador);
                    break;

            case 8:
                    while(true){
                        cout << "Digite o nome do estado: ";
                        getline(cin.ignore(), nomeEstado);
                        cout << endl;

                        consultaInsumosEstados(estados, nomeEstado);

                        cout << endl << "Deseja consultar outro estado?" << endl << endl
                             << "[1] - Consultar outro estado" << endl << "[2] - Voltar ao menu" << endl
                             << "-----------------------------------------" << endl;
                        cin >> continuar;

                        if(continuar == 2){
                            system("CLS");
                            break;
                        }

                        system("CLS");
                    }
                    break;

            case 9: 
                    while(true){
                        cout << "UF do estado: ";
                        getline(cin.ignore(), nomeEstado);
                        cout << endl << endl;

                        printConsulta(vacinas, medicamentos, EPIs, vVerificador, mVerificador, epiVerificador);
                        
                        cout << endl << "Qual insumo deseja distribuir?" << endl << endl
                             << "[1] - Vacina" << endl << "[2] - Medicamento" << endl
                             << "[3] - EPI" << endl
                             << "-----------------------------------------" << endl;
                        cin >> n;
                        getchar();
                        cout << endl;

                        distribuiInsumos(estados, vacinas, medicamentos, EPIs, estadosVerificador, nomeEstado, n);

                        cout << endl << "\n[1] - Distribuir outro insumo\n" << "[2] - Voltar ao menu" << endl
                             << "-----------------------------------------" << endl;
                        cin >> x;

                        if(x == 2)
                        {
                            system("CLS");
                            break;
                        }
                        system("CLS");
                    }
                    break;
        }
    }
}