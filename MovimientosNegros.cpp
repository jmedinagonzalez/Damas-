#include "Comun.h"

int string2int(string texto) {
    int numero = -1;
    if (!texto.empty()) {
        numero = atoi(texto.c_str());
    }
    return numero;
}

vector<string> tokenizer(string texto) {
    vector<string> tokenes;
    if (!texto.empty()) {
        istringstream flujo(texto);
        string token;
        while (getline(flujo, token, ',')) {
            tokenes.push_back(token);
        }
    }
    return tokenes;
}

vector<int> numerizar(string texto) {
    vector<int> numeros;
    if (!texto.empty()) {
        istringstream flujo(texto);
        string token;
        while (getline(flujo, token, ',')) {
            int numero = string2int(token);
            numeros.push_back(numero);
        }
    }
    return numeros;
}

bool contiene(vector<string> arreglo, string elemento) {
    bool ok = false;
    if (find(arreglo.begin(), arreglo.end(), elemento) != arreglo.end()) {
        ok = true;
    }
    return ok;
}

void retornar(string T, int &x, int &y, string &h) {
    int L;
    char b[10];
    int i = 0;
    int asd[10];
    istringstream flujo(T);
    while (getline(flujo, T, ',')) {
        if (i < 2) {
            asd[i] = string2int(T);
        } else {
            h = T;
        }
        i++;
    }
    x = asd[0];
    y = asd[1];
}