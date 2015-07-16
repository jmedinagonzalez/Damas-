#include "comun.h"

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

void Llenarlo(string T[10][10]) {

    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {

            if (i < 3) {
                if (j % 2 == 0 && i % 2 == 0)
                    T[i][j] = "1";
                else
                    T[i][j] = " ";
                if (i % 2 != 0 && j % 2 != 0)
                    T[i][j] = "1";
            }
            if (i > 6) {
                if (j % 2 == 0 && i % 2 == 0)
                    T[i][j] = "0";
                else
                    T[i][j] = " ";
                if (i % 2 != 0 && j % 2 != 0)
                    T[i][j] = "0";
            }
            if (i > 2 and i < 7)
                T[i][j] = " ";

        }

    }
}

void Mostrar(string T[10][10]) {

    int i, j;

    for (i = 0; i < 10; i++) {

        for (j = 0; j < 10; j++) {

            cout << "[" << T[i][j] << "]";

        }

        cout << "   " << i << "   " << endl;
    }
    for (int m = 0; m < 10; m++) {
        cout << " " << m << " ";
    }
    cout << endl << endl << endl;
}


