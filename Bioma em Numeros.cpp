#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>  // Necessario para CRIAR E SALVAR ARQUIVOS .txt
#include <limits>

using namespace std;

// ============================================================================
// CONSTANTES DE REFERENCIA AMBIENTAL
// ============================================================================
const double FATOR_CO2_ENERGIA_KWH   = 0.085;   // kg CO2 por kWh
const double FATOR_CO2_GASOLINA_L     = 2.269;   // kg CO2 por Litro
const double FATOR_CO2_DIESEL_L       = 2.603;   // kg CO2 por Litro
const double CO2_ABSORVIDO_ARVORE_ANO = 22.0;    // kg CO2 por arvore/ano
const double AGUA_BANHO_MINUTO        = 9.0;     // Litros por minuto de banho

// Função auxiliar para pausar a tela
void pausarTela() {
    cout << "\n--------------------------------------------------------\n";
    cout << "Pressione ENTER para voltar ao menu principal...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ============================================================================
// 1. GERAR E SALVAR LISTA DE EXERCICIOS (TERMINAL + ARQUIVO TXT)
// ============================================================================
void gerarListaExercicios() {
    // 1. Criar e abrir o arquivo de texto
    ofstream arquivo("Lista_de_Exercicios.txt");

    string conteudo = "";
    conteudo += "====================================================================\n";
    conteudo += "      ESCOLA: _________________________________________________     \n";
    conteudo += "      ALUNO(A): _________________________________ TURMA: ______     \n";
    conteudo += "      LISTA DE EXERCICIOS: MATEMATICA E IMPACTO AMBIENTAL           \n";
    conteudo += "====================================================================\n\n";

    conteudo += "TABELA DE CONSTANTES E FATORES DE CONVERSAO:\n";
    conteudo += " - Energia Eletrica: 0,085 kg CO2 por kWh\n";
    conteudo += " - Gasolina:         2,269 kg CO2 por Litro\n";
    conteudo += " - Diesel:           2,603 kg CO2 por Litro\n";
    conteudo += " - Consumo no Banho: 9,0 Litros por Minuto\n";
    conteudo += " - Arvores (Absorcao): 22,0 kg CO2 por arvore ao ano\n";
    conteudo += "--------------------------------------------------------------------\n\n";

    conteudo += "EXEMPLO MODELO (RESOLVIDO PASSO A PASSO):\n";
    conteudo += "   Problema: Uma familia gasta 200 kWh de energia eletrica por mes.\n";
    conteudo += "             Quantos kg de CO2 essa familia emite em um ano?\n\n";
    conteudo += "   Resolucao:\n";
    conteudo += "   1 Passo (Emissao Mensal): 200 kWh * 0,085 kg/kWh = 17,00 kg CO2/mes\n";
    conteudo += "   2 Passo (Emissao Anual):  17,00 kg * 12 meses   = 204,00 kg CO2/ano\n";
    conteudo += "   Resposta: A emissao e de 204 kg de CO2 por ano.\n";
    conteudo += "--------------------------------------------------------------------\n\n";

    conteudo += "--- EXERCICIOS PARA RESOLVER MANUALMENTE ---\n\n";

    conteudo += "QUESTAO 1 (Consumo Hidrico):\n";
    conteudo += "Um estudante toma banho por 12 minutos todos os dias.\n";
    conteudo += "a) Quantos litros de agua ele gasta em 1 dia?\n";
    conteudo += "   Calculo: ________________________________________________________\n";
    conteudo += "b) Quantos litros de agua ele gastara ao final de um mes (30 dias)?\n";
    conteudo += "   Calculo: ________________________________________________________\n\n";

    conteudo += "QUESTAO 2 (Pegada de Carbono em Transportes):\n";
    conteudo += "O veiculo de uma empresa consome 150 litros de gasolina em um mes.\n";
    conteudo += "a) Calcule a quantidade de CO2 emitida no mes (em kg).\n";
    conteudo += "   Calculo: ________________________________________________________\n";
    conteudo += "b) Calcule a emissao anual total (em kg) e converta para toneladas.\n";
    conteudo += "   Calculo: ________________________________________________________\n\n";

    conteudo += "QUESTAO 3 (Proporcionalidade e Arredondamento):\n";
    conteudo += "A emissao anual de uma pequena fabrica e de 1.500 kg de CO2.\n";
    conteudo += "Sabendo que cada arvore absorve 22 kg de CO2 por ano, determine o numero\n";
    conteudo += "MINIMO de arvores inteiras necessarias para neutralizar esse impacto.\n";
    conteudo += "   Calculo: ________________________________________________________\n";
    conteudo += "====================================================================\n";

    // Mostra na tela
    cout << conteudo;

    // Salva no arquivo
    if (arquivo.is_open()) {
        arquivo << conteudo;
        arquivo.close();
        cout << "\n>>> SUCESSO! A lista foi salva no arquivo 'Lista_de_Exercicios.txt' <<<\n";
    } else {
        cout << "\n[Aviso: Nao foi possivel salvar o arquivo txt no disco.]\n";
    }

    pausarTela();
}

// ============================================================================
// 2. GERAR E SALVAR AVALIACAO COM GABARITO (TERMINAL + ARQUIVO TXT)
// ============================================================================
void gerarAvaliacaoComGabarito() {
    ofstream arquivo("Avaliacao_Ambiental.txt");

    string conteudo = "";
    conteudo += "====================================================================\n";
    conteudo += "      AVALIACAO DE MATEMATICA APLICADA A ECOLOGIA                   \n";
    conteudo += "      NOME: ______________________________________ DATA: __/__/____ \n";
    conteudo += "====================================================================\n\n";

    conteudo += "[PROVA - QUESTOES DE MULTIPLA ESCOLHA]\n\n";

    conteudo += "1. Se um chuveiro gasta 9 litros de agua por minuto, quanto consumira\n";
    conteudo += "   uma pessoa que toma banhos diarios de 15 minutos ao longo de 30 dias?\n";
    conteudo += "   A) 135 Litros\n";
    conteudo += "   B) 2.700 Litros\n";
    conteudo += "   C) 4.050 Litros\n";
    conteudo += "   D) 5.400 Litros\n\n";

    conteudo += "2. Um caminhao movido a diesel consome 100 litros de combustivel em uma viagem.\n";
    conteudo += "   Sabendo que 1 litro de diesel emite 2,603 kg de CO2, qual e a emissao total?\n";
    conteudo += "   A) 26,03 kg\n";
    conteudo += "   B) 260,30 kg\n";
    conteudo += "   C) 2.603,00 kg\n";
    conteudo += "   D) 260,30 toneladas\n\n";

    conteudo += "3. A emissao anual de CO2 de uma escola foi calculada em 1.100 kg.\n";
    conteudo += "   Quantas arvores (que absorvem 22 kg de CO2/ano) devem ser plantadas?\n";
    conteudo += "   A) 40 arvores\n";
    conteudo += "   B) 45 arvores\n";
    conteudo += "   C) 50 arvores\n";
    conteudo += "   D) 55 arvores\n\n";

    conteudo += "--------------------------------------------------------------------\n";
    conteudo += "                    FOLHA DE RESPOSTAS (ALUNO)                      \n";
    conteudo += "--------------------------------------------------------------------\n";
    conteudo += "   Questao 1:  [  ]     Questao 2:  [  ]     Questao 3:  [  ]\n";
    conteudo += "--------------------------------------------------------------------\n\n";

    conteudo += "====================================================================\n";
    conteudo += "                    GABARITO E RESOLUCOES (PROFESSOR)               \n";
    conteudo += "====================================================================\n";
    conteudo += "• QUESTAO 1: RESPOSTA C (4.050 Litros)\n";
    conteudo += "  Calculo: (15 min * 9 L/min) = 135 L/dia. Em 30 dias: 135 * 30 = 4.050 L.\n\n";

    conteudo += "• QUESTAO 2: RESPOSTA B (260,30 kg)\n";
    conteudo += "  Calculo: 100 L * 2,603 kg/L = 260,30 kg de CO2.\n\n";

    conteudo += "• QUESTAO 3: RESPOSTA C (50 arvores)\n";
    conteudo += "  Calculo: 1.100 kg / 22 kg por arvore = 50 arvores exatas.\n";
    conteudo += "====================================================================\n";

    // Mostra na tela
    cout << conteudo;

    // Salva no arquivo
    if (arquivo.is_open()) {
        arquivo << conteudo;
        arquivo.close();
        cout << "\n>>> SUCESSO! A avaliacao foi salva no arquivo 'Avaliacao_Ambiental.txt' <<<\n";
    } else {
        cout << "\n[Aviso: Nao foi possivel salvar o arquivo txt no disco.]\n";
    }

    pausarTela();
}

// ============================================================================
// 3. CALCULADORA DE IMPACTOS
// ============================================================================
void calcularImpactos() {
    double kwh = 0.0, gasolina = 0.0, diesel = 0.0, minBanho = 0.0;

    cout << "\n========================================================\n";
    cout << "          CALCULADORA DE IMPACTOS AMBIENTAIS            \n";
    cout << "========================================================\n";
    cout << "1. Consumo mensal de energia eletrica (kWh): "; cin >> kwh;
    cout << "2. Consumo mensal de gasolina (Litros): "; cin >> gasolina;
    cout << "3. Consumo mensal de diesel (Litros): "; cin >> diesel;
    cout << "4. Tempo medio de banho diario (Minutos): "; cin >> minBanho;

    double co2TotalMensal = (kwh * FATOR_CO2_ENERGIA_KWH) + 
                            (gasolina * FATOR_CO2_GASOLINA_L) + 
                            (diesel * FATOR_CO2_DIESEL_L);
    double co2TotalAnual  = co2TotalMensal * 12.0;
    double aguaAnual      = minBanho * AGUA_BANHO_MINUTO * 365.0;
    int arvores           = static_cast<int>(ceil(co2TotalAnual / CO2_ABSORVIDO_ARVORE_ANO));

    cout << "\n--------------------------------------------------------\n";
    cout << "                 RESULTADOS CALCULADOS                  \n";
    cout << "--------------------------------------------------------\n";
    cout << "• Emissao mensal de CO2: " << co2TotalMensal << " kg\n";
    cout << "• Emissao anual de CO2:  " << co2TotalAnual << " kg (" << (co2TotalAnual/1000.0) << " toneladas)\n";
    cout << "• Consumo anual de agua no banho: " << aguaAnual << " Litros\n";
    cout << "• Arvores para neutralizar CO2: " << arvores << " arvore(s)\n";
    
    pausarTela();
}

// ============================================================================
// MENU PRINCIPAL
// ============================================================================
int main() {
    int opcao = -1;
    cout << fixed << setprecision(2);

    while (opcao != 0) {
        cout << "\n========================================================\n";
        cout << "    SISTEMA BIOMAS EM NUMEROS                             \n";
        cout << "========================================================\n";
        cout << " [1] Executar Calculadora de Impactos Ambientais\n";
        cout << " [2] Gerar Lista de Exercicios (Imprime e Salva .TXT)\n";
        cout << " [3] Gerar Avaliacao com Gabarito (Imprime e Salva .TXT)\n";
        cout << " [0] Sair do Programa\n";
        cout << "--------------------------------------------------------\n";
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                calcularImpactos();
                break;
            case 2:
                gerarListaExercicios();
                break;
            case 3:
                gerarAvaliacaoComGabarito();
                break;
            case 0:
                cout << "\nPrograma encerrado.\n";
                break;
            default:
                cout << "\nOpcao invalida!\n";
                break;
        }
    }

    return 0;
}