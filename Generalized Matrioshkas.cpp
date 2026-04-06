#include <bits/stdc++.h>
using namespace std;


struct Brinquedo {
    int tamanho;
    int somaFilhos;
};

bool verificarMatrioshka(const vector<int>& seq) {
    stack<Brinquedo> pilha;

    for (int x : seq) {
        if (x < 0) {
            int tamanhoAtual = -x;

            if (!pilha.empty()) {
            }

            pilha.push({tamanhoAtual, 0});
        }
        else {
            if (pilha.empty()) return false;

            Brinquedo topo = pilha.top();
            pilha.pop();


            if (topo.tamanho != x) return false;

            if (topo.somaFilhos >= topo.tamanho) return false;

            if (!pilha.empty()) {
                pilha.top().somaFilhos += x;
            }
        }
    }
    return pilha.empty();
}

int main() {
    string linha;
    while (getline(cin, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        vector<int> sequencia;
        int num;
        while (ss >> num) {
            sequencia.push_back(num);
        }

        if (verificarMatrioshka(sequencia)) {
            cout << ":-) Matrioshka!" << endl;
        } else {
            cout << ":-( Try again." << endl;
        }
    }
    return 0;
}