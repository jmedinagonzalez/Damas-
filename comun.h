/* 
 * File:   comun.h
 * Author: Sebastián Salazar Molina <sebasalazar@gmail.com>
 *
 * Created on 5 de julio de 2015, 21:27
 */

#ifndef COMUN_H
#define	COMUN_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int string2int(string texto);

vector<string> tokenizer(string texto);

vector<int> numerizar(string texto);

bool contiene(vector<string> arreglo, string elemento);

void retornar(string T, int &x, int &y, string &h);

void Llenarlo(string T[10][10]);

void Mostrar(string T[10][10]);

#endif	/* COMUN_H */
