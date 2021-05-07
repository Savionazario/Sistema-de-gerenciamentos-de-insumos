#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include "Estruturas.h"
#include <string.h>
#include <iostream>

#define MAX 10

using namespace std;

void criarVacinas(tVacina vacinas[], int vCheck[])
{
    int i;

    for(i = 0; i< MAX; i++)
    {
        if(vCheck[i] == 0)
        {
            vCheck[i] = 1;

            cout << "Nome: ";
            getline(cin.ignore(), vacinas[i].dadosVacina.nome);

            cout << "---------------------------------------------" << endl << endl
                 << "Valor unitario: ";
            cin >> vacinas[i].dadosVacina.valorUnitario;

            cout << "---------------------------------------------" << endl << endl
                 << "Quantidade: ";
            cin >> vacinas[i].dadosVacina.qItens;

            cout << "---------------------------------------------" << endl << endl
                 << "Data de vencimento (dd/mm/aaaa): ";
            cin >> vacinas[i].dadosVacina.dataVencimento;

            cout << "---------------------------------------------" << endl << endl
                 << "Nome do fabricante: ";
            getline(cin.ignore(), vacinas[i].dadosVacina.nomeFabricante);

            cout << "---------------------------------------------" << endl << endl
                 << "Tecnologia: ";
            getline(cin, vacinas[i].tecnologia);

            cout << "---------------------------------------------" << endl << endl
                 << "Quantidade de doses: ";
            cin >> vacinas[i].qDoses;

            cout << "---------------------------------------------" << endl << endl
                 << "Intervalo entre as doses (dias): ";
            cin >> vacinas[i].intervalo;

            system("CLS");
            break;
        }
    }
}

void criarMedicamentos(tMedicamento medicamento[], int mCheck[])
{
    int i;

    for(i = 0; i< MAX; i++)
    {
        if(mCheck[i] == 0)
        {
            mCheck[i] = 1;

            cout << "Nome: ";
            getline(cin.ignore(), medicamento[i].dadosMedicamento.nome);

            cout << "---------------------------------------------" << endl << endl
                 << "Valor unitario: ";
            cin >> medicamento[i].dadosMedicamento.valorUnitario;

            cout << "---------------------------------------------" << endl << endl
                 << "Quantidade: ";
            cin >> medicamento[i].dadosMedicamento.qItens;

            cout << "---------------------------------------------" << endl << endl
                 << "Data de vencimento (dd/mm/aaaa): ";
            cin >> medicamento[i].dadosMedicamento.dataVencimento;

            cout << "---------------------------------------------" << endl << endl
                 << "Nome do fabricante: ";
            getline(cin.ignore(), medicamento[i].dadosMedicamento.nomeFabricante);

            cout << "---------------------------------------------" << endl << endl
                 << "Dosagem (mg): ";
            cin >> medicamento[i].dosagem;

            cout << "---------------------------------------------" << endl << endl
                 << "Forma (liquido, comprimido): ";
            getline(cin.ignore(), medicamento[i].forma);

            cout << "---------------------------------------------" << endl << endl
                 << "Modo de uso (oral, intravenoso): ";
            getline(cin, medicamento[i].uso);

            system("CLS");
            break;
        }
    }
}

void criarEPIs(tEPI EPIs[], int epiCheck[])
{
    int i;

    for(i = 0; i < MAX; i++)
    {
        if(epiCheck[i] == 0)
        {
            epiCheck[i] = 1;

            cout << "Tipo: ";
            getline(cin.ignore(), EPIs[i].tipo);

            cout << "---------------------------------------------" << endl << endl
                 << "Nome: ";
            getline(cin, EPIs[i].dadosEPI.nome);

            cout << "---------------------------------------------" << endl << endl
                 << "Valor unitario: ";
            cin >> EPIs[i].dadosEPI.valorUnitario;

            cout << "---------------------------------------------" << endl << endl
                 << "Quantidade: ";
            cin >> EPIs[i].dadosEPI.qItens;

            cout << "---------------------------------------------" << endl << endl
                 << "Data de vencimento (dd/mm/aaaa): ";
            cin >> EPIs[i].dadosEPI.dataVencimento;

            cout << "---------------------------------------------" << endl << endl
                 << "Nome do fabricante: ";
            getline(cin.ignore(), EPIs[i].dadosEPI.nomeFabricante);

            cout << "---------------------------------------------" << endl << endl
                 << "Detalhes: ";
            getline(cin, EPIs[i].detalhesEPI);

            system("CLS");
            break;
        }
    }
}

void cadastroInsumos(tVacina vacinas[], tMedicamento medicamento[], tEPI EPIs[], int vCheck[], int mCheck[], int epiCheck[])
{
    int casee;

    cout << "Qual insumo voce deseja cadastrar?\n" << endl
         << "[1] - Vacina" << endl
         << "[2] - Medicamento" << endl
         << "[3] - EPI" << endl
         << "-----------------------------------------" << endl;

    cin >> casee;

    system("CLS");

    switch(casee)
    {
        case 1: criarVacinas(vacinas, vCheck);
            break;
        case 2: criarMedicamentos(medicamento, mCheck);
            break;
        case 3: criarEPIs(EPIs, epiCheck);
            break;
    }
}

void printIsumosTipo(tVacina vacinas[], tMedicamento medicamentos[], tEPI EPIs[], int vCheck[], int mCheck[], int epiCheck[]){
    int i, insumo, n;

    while(1){
        cout << "Qual insumo deseja consultar?\n" << endl
             << "[1] - Vacinas" << endl
             << "[2] - Medicamentos" << endl
             << "[3] - EPIs" << endl
             << "-----------------------------------------" << endl;

        cin >> insumo;

        system("CLS");

        if(insumo == 1){
            cout << "----------Vacinas disponiveis----------\n" << endl;

            for(i = 0; i < MAX; i++){
                if(vCheck[i] == 1){
                    cout << "---------------------------------------------" << endl
                         << "Nome da vacina: " << vacinas[i].dadosVacina.nome << endl
                         << "---------------------------------------------" << endl
                         << "Quantidade de doses necessarias: " << vacinas[i].qDoses << endl
                         << "Intervalo de dias entre as doses: " << vacinas[i].intervalo << endl
                         << "Valor unitario: " << vacinas[i].dadosVacina.valorUnitario << endl
                         << "Data de vencimento: " << vacinas[i].dadosVacina.dataVencimento << endl
                         << "Nome do fabricante: " << vacinas[i].dadosVacina.nomeFabricante << endl
                         << "Quantidade disponivel: " << vacinas[i].dadosVacina.qItens << endl << endl;
                }
            }
        }

        if(insumo == 2){
            cout << "----------Medicamentos disponiveis----------\n" << endl;

            for(i = 0; i < MAX; i++){
                if(mCheck[i] == 1){
                    cout << "---------------------------------------------" << endl
                         << "Nome do medicamento: " << medicamentos[i].dadosMedicamento.nome << endl
                         << "---------------------------------------------" << endl
                         << "Dosagem (mg): " << medicamentos[i].dosagem << endl
                         << "Forma de administracao: " << medicamentos[i].uso << endl
                         << "Disponibilizacao: " << medicamentos[i].forma << endl
                         << "Valor unitario: " << medicamentos[i].dadosMedicamento.valorUnitario << endl
                         << "Data de vencimento: " << medicamentos[i].dadosMedicamento.dataVencimento << endl
                         << "Nome do fabricante: " << medicamentos[i].dadosMedicamento.nomeFabricante << endl
                         << "Quantidade disponivel: " << medicamentos[i].dadosMedicamento.qItens << endl << endl;
                }
            }
        }

        if(insumo == 3){
            cout << "----------EPIs disponiveis----------\n" << endl;

            for(i = 0; i < MAX; i++){
                if(epiCheck[i] == 1){
                    cout << "---------------------------------------------" << endl
                         << "Nome do EPI: " << EPIs[i].dadosEPI.nome << endl
                         << "---------------------------------------------" << endl
                         << "Detalhes: " << EPIs[i].detalhesEPI << endl
                         << "Valor unitario: " << EPIs[i].dadosEPI.valorUnitario << endl
                         << "Data de vencimento: " << EPIs[i].dadosEPI.dataVencimento << endl
                         << "Nome do fabricante: " << EPIs[i].dadosEPI.nomeFabricante << endl
                         << "Quantidade disponivel: " << EPIs[i].dadosEPI.qItens << endl << endl;
                }
            }
        }
        cout << "\n[1] - Consultar outro insumo\n" << "[2] - Voltar ao menu" << endl
             << "-----------------------------------------" << endl;
        cin >> n;
        if(n == 2){
            system("CLS");
            break;
        }

        system("CLS");
    }
}

void printConsulta(tVacina vacinas[], tMedicamento medicamentos[], tEPI EPIs[], int vCheck[], int mCheck[], int epiCheck[])
{
    int i = 0;

    for(i = 0; i < MAX; i++)
    {
        if(i == 0 && vCheck[0] != 0)
        {
            cout << "----------Vacinas disponiveis----------\n" << endl;
        }
        if(vCheck[i] == 1)
        {
            cout << "Nome da vacina: " << vacinas[i].dadosVacina.nome << endl
                 << "Quantidade disponivel: " << vacinas[i].dadosVacina.qItens << endl
                 << "---------------------------------------------" << endl << endl;
        }
    }

    for(i = 0; i < MAX; i++)
    {
        if(i == 0 && mCheck[0] != 0)
        {
            cout << "----------Medicamentos disponiveis----------\n" << endl;

        }
        if(mCheck[i] == 1)
        {
            cout << "Nome do Medicamento: " << medicamentos[i].dadosMedicamento.nome << endl
                 << "Quantidade disponivel: " << medicamentos[i].dadosMedicamento.qItens << endl
                 << "---------------------------------------------" << endl << endl;
        }
    }

    for(i = 0; i < MAX; i++){

        if(i == 0 && epiCheck[0] != 0)
        {
            cout << "----------EPIs disponiveis----------\n" << endl;
        }
        if(epiCheck[i] == 1)
        {
            cout << "Nome do EPI: " << EPIs[i].dadosEPI.nome << endl
                 << "Quantidade disponivel: " << EPIs[i].dadosEPI.qItens << endl
                 << "---------------------------------------------" << endl << endl;
        }
    }
}

void printConsultaDescricao(tVacina vacinas[], tMedicamento medicamentos[], tEPI EPIs[], int vCheck[], int mCheck[], int epiCheck[])
{
    int i = 0;

    for(i = 0; i < MAX; i++)
    {
        if(i == 0 && vCheck[0] != 0)
        {
            cout << "-------------Vacinas disponiveis-------------\n" << endl;
        }
        if(vCheck[i] == 1)
        {
                    cout << "Nome da vacina: " << vacinas[i].dadosVacina.nome << endl
                         << "---------------------------------------------" << endl
                         << "Quantidade de doses necessarias: " << vacinas[i].qDoses << endl
                         << "Intervalo de dias entre as doses: " << vacinas[i].intervalo << endl
                         << "Valor unitario: " << vacinas[i].dadosVacina.valorUnitario << endl
                         << "Data de vencimento: " << vacinas[i].dadosVacina.dataVencimento << endl
                         << "Nome do fabricante: " << vacinas[i].dadosVacina.nomeFabricante << endl
                         << "Quantidade disponivel: " << vacinas[i].dadosVacina.qItens << endl
                         << "---------------------------------------------" << endl << endl;
        }
    }

    for(i = 0; i < MAX; i++)
    {
        if(i == 0 && mCheck[0] != 0)
        {
            cout << "----------Medicamentos disponiveis-----------\n" << endl;

        }
        if(mCheck[i] == 1)
        {
                cout << "Nome do medicamento: " << medicamentos[i].dadosMedicamento.nome << endl
                     << "---------------------------------------------" << endl
                     << "Dosagem (mg): " << medicamentos[i].dosagem << endl
                     << "Forma de administracao: " << medicamentos[i].uso << endl
                     << "Disponibilizacao: " << medicamentos[i].forma << endl
                     << "Valor unitario: " << medicamentos[i].dadosMedicamento.valorUnitario << endl
                     << "Data de vencimento: " << medicamentos[i].dadosMedicamento.dataVencimento << endl
                     << "Nome do fabricante: " << medicamentos[i].dadosMedicamento.nomeFabricante << endl
                     << "Quantidade disponivel: " << medicamentos[i].dadosMedicamento.qItens << endl
                     << "---------------------------------------------" << endl << endl;
        }
    }

    for(i = 0; i < MAX; i++){

        if(i == 0 && epiCheck[0] != 0)
        {
            cout << "--------------EPIs disponiveis---------------\n" << endl;
        }
        if(epiCheck[i] == 1)
        {
                cout << "Nome do EPI: " << EPIs[i].dadosEPI.nome << endl
                     << "---------------------------------------------" << endl
                     << "Detalhes: " << EPIs[i].detalhesEPI << endl
                     << "Valor unitario: " << EPIs[i].dadosEPI.valorUnitario << endl
                     << "Data de vencimento: " << EPIs[i].dadosEPI.dataVencimento << endl
                     << "Nome do fabricante: " << EPIs[i].dadosEPI.nomeFabricante << endl
                     << "Quantidade disponivel: " << EPIs[i].dadosEPI.qItens << endl
                     << "---------------------------------------------" << endl << endl;
        }
    }
}

void distribuiInsumos(tEstados estados[], tVacina vacinas[], tMedicamento medicamentos[], tEPI EPIs[], int estCheck[], string nomeEst, int n){
    int i, j,quant;
    bool flag = false;
    string nome;

    for(i = 0; i < 26; i++)
    {
        if(estCheck[i] == 0)
        {
            estados[i].nomeEstado = nomeEst;
            estCheck[i] = 1;
            for(j = 0; j < MAX; j++){
                // Copia do array de vacinas do MS para estoqueVac
                estados[i].estoqueVac[j].dadosVacina.qItens = 0;
                estados[i].estoqueVac[j].dadosVacina.nome = vacinas[j].dadosVacina.nome;
                estados[i].estoqueVac[j].dadosVacina.nomeFabricante = vacinas[j].dadosVacina.nomeFabricante;
                estados[i].estoqueVac[j].dadosVacina.dataVencimento = vacinas[j].dadosVacina.dataVencimento;
                estados[i].estoqueVac[j].dadosVacina.valorUnitario = vacinas[j].dadosVacina.valorUnitario;
                estados[i].estoqueVac[j].intervalo = vacinas[j].intervalo;
                estados[i].estoqueVac[j].qDoses = vacinas[j].qDoses;
                estados[i].estoqueVac[j].tecnologia = vacinas[j].tecnologia;
                // Copia do array de medicamentos do MS para estoqueMed
                estados[i].estoqueMed[j].dadosMedicamento.qItens = 0;
                estados[i].estoqueMed[j].dadosMedicamento.nome = medicamentos[j].dadosMedicamento.nome;
                estados[i].estoqueMed[j].dadosMedicamento.nomeFabricante = medicamentos[j].dadosMedicamento.nomeFabricante;
                estados[i].estoqueMed[j].dadosMedicamento.dataVencimento = medicamentos[j].dadosMedicamento.dataVencimento;
                estados[i].estoqueMed[j].dadosMedicamento.valorUnitario = medicamentos[j].dadosMedicamento.valorUnitario;
                estados[i].estoqueMed[j].dosagem = medicamentos[j].dosagem;
                estados[i].estoqueMed[j].uso = medicamentos[j].uso;
                estados[i].estoqueMed[j].forma = medicamentos[j].forma;
                // Copia do array de epi do MS para estoqueEPI
                estados[i].estoqueEPI[j].dadosEPI.qItens = 0;
                estados[i].estoqueEPI[j].dadosEPI.nome = EPIs[j].dadosEPI.nome;
                estados[i].estoqueEPI[j].dadosEPI.nomeFabricante = EPIs[j].dadosEPI.nomeFabricante;
                estados[i].estoqueEPI[j].dadosEPI.dataVencimento = EPIs[j].dadosEPI.dataVencimento;
                estados[i].estoqueEPI[j].dadosEPI.valorUnitario = EPIs[j].dadosEPI.valorUnitario;
                estados[i].estoqueEPI[j].tipo = EPIs[j].tipo;
                estados[i].estoqueEPI[j].detalhesEPI = EPIs[j].detalhesEPI;
            }

            break;
        }
        else if(estados[i].nomeEstado == nomeEst)
        {
            for(j = 0; j < MAX; j++){
                //Checagem para caso for adicionado uma nova vacina no estoque MS, fazer a copia para estoqueVac
                if(estados[i].estoqueVac[j].dadosVacina.nome != vacinas[j].dadosVacina.nome){
                    estados[i].estoqueVac[j].dadosVacina.qItens = 0;
                    estados[i].estoqueVac[j].dadosVacina.nome = vacinas[j].dadosVacina.nome;
                    estados[i].estoqueVac[j].dadosVacina.nomeFabricante = vacinas[j].dadosVacina.nomeFabricante;
                    estados[i].estoqueVac[j].dadosVacina.dataVencimento = vacinas[j].dadosVacina.dataVencimento;
                    estados[i].estoqueVac[j].dadosVacina.valorUnitario = vacinas[j].dadosVacina.valorUnitario;
                    estados[i].estoqueVac[j].intervalo = vacinas[j].intervalo;
                    estados[i].estoqueVac[j].qDoses = vacinas[j].qDoses;
                    estados[i].estoqueVac[j].tecnologia = vacinas[j].tecnologia;
                }

                //Checagem para caso for adicionado um novo medicamento no estoque MS, fazer a copia para estoqueMed
                if(estados[i].estoqueMed[j].dadosMedicamento.nome != medicamentos[j].dadosMedicamento.nome){
                    estados[i].estoqueMed[j].dadosMedicamento.qItens = 0;
                    estados[i].estoqueMed[j].dadosMedicamento.nome = medicamentos[j].dadosMedicamento.nome;
                    estados[i].estoqueMed[j].dadosMedicamento.nomeFabricante = medicamentos[j].dadosMedicamento.nomeFabricante;
                    estados[i].estoqueMed[j].dadosMedicamento.dataVencimento = medicamentos[j].dadosMedicamento.dataVencimento;
                    estados[i].estoqueMed[j].dadosMedicamento.valorUnitario = medicamentos[j].dadosMedicamento.valorUnitario;
                    estados[i].estoqueMed[j].dosagem = medicamentos[j].dosagem;
                    estados[i].estoqueMed[j].uso = medicamentos[j].uso;
                    estados[i].estoqueMed[j].forma = medicamentos[j].forma;
                }

                //Checagem para caso for adicionado uma nova EPI no estoque MS, fazer a copia para estoqueEPI
                if(estados[i].estoqueEPI[j].dadosEPI.nome != EPIs[j].dadosEPI.nome){
                    estados[i].estoqueEPI[j].dadosEPI.qItens = 0;
                    estados[i].estoqueEPI[j].dadosEPI.nome = EPIs[j].dadosEPI.nome;
                    estados[i].estoqueEPI[j].dadosEPI.nomeFabricante = EPIs[j].dadosEPI.nomeFabricante;
                    estados[i].estoqueEPI[j].dadosEPI.dataVencimento = EPIs[j].dadosEPI.dataVencimento;
                    estados[i].estoqueEPI[j].dadosEPI.valorUnitario = EPIs[j].dadosEPI.valorUnitario;
                    estados[i].estoqueEPI[j].tipo = EPIs[j].tipo;
                    estados[i].estoqueEPI[j].detalhesEPI = EPIs[j].detalhesEPI;
                }
            }
            break;
        }
    }

    if (n == 1)
    {
        cout << "Digite o nome da vacina: ";
        getline(cin, nome);
        cout << "Digite a quantidade a ser distribuida: ";
        cin >> quant;

        for(j = 0; j < MAX; j++){
            if(estados[i].estoqueVac[j].dadosVacina.nome == nome){
                if(quant > vacinas[j].dadosVacina.qItens){
                    cout << "**Quantidade indisponivel**" << endl;
                    flag = true;
                    break;
                }else{
                    estados[i].estoqueVac[j].dadosVacina.qItens += quant;
                    vacinas[j].dadosVacina.qItens -= quant;
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false)
        {
            cout << "Vacina nao encontrada" << endl;
        }
    }
    if (n == 2)
    {
        cout << "Digite o nome do medicamento: ";
        getline(cin, nome);
        cout << "Digite a quantidade a ser distribuida: ";
        cin >> quant;

        for(j = 0; j < MAX; j++){
            if(estados[i].estoqueMed[j].dadosMedicamento.nome == nome){
                if(quant > medicamentos[j].dadosMedicamento.qItens){
                    cout << "**Quantidade indisponivel**" << endl;
                    flag = true;
                    break;
                }else{
                    estados[i].estoqueMed[j].dadosMedicamento.qItens += quant;
                    medicamentos[j].dadosMedicamento.qItens -= quant;
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false)
        {
            cout << "Medicamento nao encontrado" << endl;
        }
    }

    if (n == 3)
    {
        cout << "Digite o nome da EPI: ";
        getline(cin, nome);
        cout << "Digite a quantidade a ser distribuida: ";
        cin >> quant;

        for(j = 0; j < MAX; j++){
            if(estados[i].estoqueEPI[j].dadosEPI.nome == nome){
                if(quant > EPIs[j].dadosEPI.qItens){
                    cout << "**Quantidade indisponivel**" << endl;
                    flag = true;
                    break;
                }else{
                    estados[i].estoqueEPI[j].dadosEPI.qItens += quant;
                    EPIs[j].dadosEPI.qItens -= quant;
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false)
        {
            cout << "EPI nao encontrada" << endl;
        }
    }

}

void consultaInsumosDistribuidos(tEstados estados[], int estCheck[])
{
    int i, j, x;

    while(1){
        for(i = 0; i < MAX; i++){
            if(estCheck[i] == 1){
                cout << "-------Insumos disponiveis no estado de " << estados[i].nomeEstado << "-------\n" << endl;
            }
            for(j = 0; j < MAX; j++){
                if(estados[i].estoqueVac[j].dadosVacina.qItens > 0){
                    cout << "Vacina: " << estados[i].estoqueVac[j].dadosVacina.nome << endl
                         << "Quantidade: " << estados[i].estoqueVac[j].dadosVacina.qItens << endl << endl;
                }
            }
            for(j = 0; j < MAX; j++){
                if(estados[i].estoqueMed[j].dadosMedicamento.qItens > 0){
                    cout << "Medicamento: " << estados[i].estoqueMed[j].dadosMedicamento.nome << endl
                         << "Quantidade: " << estados[i].estoqueMed[j].dadosMedicamento.qItens << endl << endl;
                }
            }
            for(j = 0; j < MAX; j++){
                if(estados[i].estoqueEPI[j].dadosEPI.qItens > 0){
                    cout << "EPI: " << estados[i].estoqueEPI[j].dadosEPI.nome << endl
                         << "Quantidade: " << estados[i].estoqueEPI[j].dadosEPI.qItens << endl << endl;
                }
            }
        }
        cout << "\n[1] - Voltar ao menu" << endl
             << "-----------------------------------------" << endl;
        cin >> x;

        if(x == 1)
        {
            system("CLS");
            break;
        }
        system("CLS");
    }
}

void printConsultaDescricaoEstados(tEstados estados[], int estCheck[])
{
    int i, j;

    for(i = 0; i < 26; i++)
    {
        if(estCheck[i] == 1)
        {
            cout << "INSUMOS DO ESTADO: " << estados[i].nomeEstado <<endl;
            
            for (j = 0; j < MAX; j++)
            {
                if(estados[i].estoqueVac[j].dadosVacina.qItens > 0)
                {
                    cout << "-------------------------------" << endl
                         << "Nome da vacina: " << estados[i].estoqueVac[j].dadosVacina.nome << endl
                         << "-------------------------------" << endl
                         << "Quantidade de doses necessarias: " << estados[i].estoqueVac[j].qDoses << endl
                         << "Intervalo de dias entre as doses: " << estados[i].estoqueVac[j].intervalo << endl
                         << "Valor unitario: " << estados[i].estoqueVac[j].dadosVacina.valorUnitario << endl
                         << "Data de vencimento: " << estados[i].estoqueVac[j].dadosVacina.dataVencimento << endl
                         << "Nome do fabricante: " << estados[i].estoqueVac[j].dadosVacina.nomeFabricante << endl
                         << "Quantidade disponivel: " << estados[i].estoqueVac[j].dadosVacina.qItens << endl;
                }
            }

            for (j = 0; j < MAX; j++)
            {
                if(estados[i].estoqueMed[j].dadosMedicamento.qItens > 0)
                {
                    cout << "-------------------------------" << endl
                         << "Nome do medicamento: " << estados[i].estoqueMed[j].dadosMedicamento.nome << endl
                         << "-------------------------------" << endl
                         << "Dosagem (mg): " << estados[i].estoqueMed[j].dosagem << endl
                         << "Forma de administracao: " << estados[i].estoqueMed[j].uso << endl
                         << "Disponibilizacao: " << estados[i].estoqueMed[j].forma << endl
                         << "Valor unitario: " << estados[i].estoqueMed[j].dadosMedicamento.valorUnitario << endl
                         << "Data de vencimento: " << estados[i].estoqueMed[j].dadosMedicamento.dataVencimento << endl
                         << "Nome do fabricante: " << estados[i].estoqueMed[j].dadosMedicamento.nomeFabricante << endl
                         << "Quantidade disponivel: " << estados[i].estoqueMed[j].dadosMedicamento.qItens << endl;
                }
            }

            for (j = 0; j < MAX; j++)
            {
                if(estados[i].estoqueEPI[j].dadosEPI.qItens > 0)
                {
                    cout << "-------------------------------" << endl
                         << "Nome do EPI: " << estados[i].estoqueEPI[j].dadosEPI.nome << endl
                         << "-------------------------------" << endl
                         << "Detalhes: " << estados[i].estoqueEPI[j].detalhesEPI << endl
                         << "Valor unitario: " << estados[i].estoqueEPI[j].dadosEPI.valorUnitario << endl
                         << "Data de vencimento: " << estados[i].estoqueEPI[j].dadosEPI.dataVencimento << endl
                         << "Nome do fabricante: " << estados[i].estoqueEPI[j].dadosEPI.nomeFabricante << endl
                         << "Quantidade disponivel: " << estados[i].estoqueEPI[j].dadosEPI.qItens << endl;
                }
            }
            cout << "---------------------------------------------" << endl << endl;
        }
    }
}

void printInsumosEstadosTipo(tEstados estados[], int estCheck[])
{
    int i, j, n, insumo;

    while(1)
    {
        cout << "Qual insumo deseja consultar?\n" << endl
             << "[1] - Vacinas" << endl
             << "[2] - Medicamentos" << endl
             << "[3] - EPIs" << endl
             << "-----------------------------------------" << endl;

        cin >> insumo;

        system("CLS");

        if(insumo == 1)
        {
            cout << "----------Vacinas disponiveis----------\n" << endl;

            for(i = 0; i < 26; i++)
            {
                if(estCheck[i] == 1)
                {
                    for(j = 0; j < MAX; j++)
                    {
                        if(estados[i].estoqueVac[j].dadosVacina.qItens > 0)
                        {
                            cout << "Vacinas do estado: " << estados[i].nomeEstado << endl
                                 << "---------------------------------------------" << endl
                                 << "Nome da vacina: " << estados[i].estoqueVac[j].dadosVacina.nome << endl
                                 << "---------------------------------------------" << endl
                                 << "Quantidade de doses necessarias: " << estados[i].estoqueVac[j].qDoses << endl
                                 << "Intervalo de dias entre as doses: " << estados[i].estoqueVac[j].intervalo << endl
                                 << "Valor unitario: " << estados[i].estoqueVac[j].dadosVacina.valorUnitario << endl
                                 << "Data de vencimento: " << estados[i].estoqueVac[j].dadosVacina.dataVencimento << endl
                                 << "Nome do fabricante: " << estados[i].estoqueVac[j].dadosVacina.nomeFabricante << endl
                                 << "Quantidade disponivel: " << estados[i].estoqueVac[j].dadosVacina.qItens << endl << endl;
                         }
                    }
                }
            }
        }

        if(insumo == 2)
        {
            cout << "----------Medicamentos disponiveis----------\n" << endl;

            for(i = 0; i < 26; i++)
            {
                if(estCheck[i] == 1)
                {
                    for(j = 0; j < MAX; j++)
                    {
                        if(estados[i].estoqueMed[j].dadosMedicamento.qItens > 0)
                        {
                            cout << "Medicamentos do estado: " << estados[i].nomeEstado << endl
                                 << "---------------------------------------------" << endl
                                 << "Nome do medicamento: " << estados[i].estoqueMed[j].dadosMedicamento.nome << endl
                                 << "---------------------------------------------" << endl
                                 << "Dosagem (mg): " << estados[i].estoqueMed[j].dosagem << endl
                                 << "Forma de administracao: " << estados[i].estoqueMed[j].uso << endl
                                 << "Disponibilizacao: " << estados[i].estoqueMed[j].forma << endl
                                 << "Valor unitario: " << estados[i].estoqueMed[j].dadosMedicamento.valorUnitario << endl
                                 << "Data de vencimento: " << estados[i].estoqueMed[j].dadosMedicamento.dataVencimento << endl
                                 << "Nome do fabricante: " << estados[i].estoqueMed[j].dadosMedicamento.nomeFabricante << endl
                                 << "Quantidade disponivel: " << estados[i].estoqueMed[j].dadosMedicamento.qItens << endl << endl;
                        }
                    }
                }
            }
        }

        if(insumo == 3)
        {
            cout << "----------EPIs disponiveis----------\n" << endl;

            for(i = 0; i < 26; i++)
            {
                if(estCheck[i] == 1)
                {
                    for(j = 0; j < MAX; j++)
                    {
                        if(estados[i].estoqueEPI[j].dadosEPI.qItens > 0)
                        {
                            cout << "EPIs do estado: " << estados[i].nomeEstado << endl
                                 << "---------------------------------------------" << endl
                                 << "Nome do EPI: " << estados[i].estoqueEPI[j].dadosEPI.nome << endl
                                 << "---------------------------------------------" << endl
                                 << "Detalhes: " << estados[i].estoqueEPI[j].detalhesEPI << endl
                                 << "Valor unitario: " << estados[i].estoqueEPI[j].dadosEPI.valorUnitario << endl
                                 << "Data de vencimento: " << estados[i].estoqueEPI[j].dadosEPI.dataVencimento << endl
                                 << "Nome do fabricante: " << estados[i].estoqueEPI[j].dadosEPI.nomeFabricante << endl
                                 << "Quantidade disponivel: " << estados[i].estoqueEPI[j].dadosEPI.qItens << endl << endl;
                        }
                    }
                }
            }
        }
        cout << "\n[1] - Consultar outro insumo\n" << "[2] - Voltar ao menu" << endl
             << "-----------------------------------------" << endl;
        cin >> n;
        if(n == 2){
            system("CLS");
            break;
        }
        cout << endl;
    }
}

void consultaInsumosEstados(tEstados estados[], string nomeEst){
    bool encontrado = false;
    
    for(int i=0; i<26; i++){
        if(nomeEst == estados[i].nomeEstado){
            encontrado = true;

            for(int j=0; j<MAX; j++){
                if(estados[i].estoqueVac[j].dadosVacina.qItens > 0){
                    cout << "Vacina: " << estados[i].estoqueVac[j].dadosVacina.nome << endl
                         << "Quantidade: " << estados[i].estoqueVac[j].dadosVacina.qItens << endl
                         << "---------------------------------------------" << endl << endl;
                }
            }
            for(int j=0; j<MAX; j++){
                if(estados[i].estoqueMed[j].dadosMedicamento.qItens > 0){
                    cout << "Medicamento: " << estados[i].estoqueMed[j].dadosMedicamento.nome << endl
                         << "Quantidade: " << estados[i].estoqueMed[j].dadosMedicamento.qItens << endl
                         << "---------------------------------------------" << endl << endl;
                }
            }
            for(int j=0; j<MAX; j++){
                if(estados[i].estoqueEPI[j].dadosEPI.qItens > 0){
                    cout << "EPI: " << estados[i].estoqueEPI[j].dadosEPI.nome << endl
                         << "Quantidade: " << estados[i].estoqueEPI[j].dadosEPI.qItens << endl
                         << "---------------------------------------------" << endl << endl;
                }
            }
        }
    }

    if(encontrado == false){
        cout << "Estado nao encontrado!!!!!" << endl
             << "---------------------------------------------" << endl << endl;
    }
}

#endif