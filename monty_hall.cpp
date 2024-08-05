#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

std::vector<int> gerador_de_portas(int p) {
    std::vector<int> lista;

    std::mt19937 gen(time(0)); 
    
    for (int i = 0; i < p-1; ++i) {
        lista.push_back(0);
    }

    lista.push_back(1);

    std::shuffle(lista.begin(), lista.end(), gen);

    return lista;
}

int main() {
    int n;
    std::cout << "Quantidade de jogos: ";
    std::cin >> n;

    std::mt19937 gen(time(0)); 
    std::uniform_int_distribution<> distribuicao(0, 2);

    int jogos = 0;
    int acertos = 0;

    for (int i = 0; i < n; ++i) {
        std::vector<int> lista = gerador_de_portas(3);

        int escolha = distribuicao(gen); 

        int monty_escolha = distribuicao(gen);
        while (monty_escolha == escolha || lista[monty_escolha] == 1) 
        {
            monty_escolha = distribuicao(gen);
        }

        int nova_escolha = distribuicao(gen);
        while(nova_escolha == monty_escolha || nova_escolha == escolha)
        {
            nova_escolha = distribuicao(gen);
        }
        if (lista[nova_escolha] == 1) {
            acertos++;
        }
        jogos++;
    }

    float prob = static_cast<float>(acertos) / jogos;
    std::cout << "Probabilidade de acerto ao mudar de porta em " << n << " jogos: " << prob << std::endl;

    return 0;
}