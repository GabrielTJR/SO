#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> perguntas = {
        "Você gosta de esportes?",
        "Você gosta de música?",
        "Você gosta de filmes?",
        "Você gosta de programar?",
        "Você gosta de viajar?"
    };
    vector<int> respostas;

    cout << "Responda com 1 para Sim e 2 para Não.\n" << endl;

    for (int i = 0; i < perguntas.size(); i++) {
        int resposta;
        cout << perguntas[i] << " ";
        
        while (true) {
            cin >> resposta;
            if (resposta == 1 || resposta == 2) {
                respostas.push_back(resposta);
                break;
            } else {
                cout << "Resposta inválida. Responda com 1 para Sim ou 2 para Não: ";
            }
        }
    }

    cout << "\nSuas respostas foram:\n" << endl;
    for (int i = 0; i < perguntas.size(); i++) {
        cout << perguntas[i] << " ";
        if (respostas[i] == 1) {
            cout << "Sim";
        } else {
            cout << "Não";
        }
        cout << endl;
    }

    return 0;
}
