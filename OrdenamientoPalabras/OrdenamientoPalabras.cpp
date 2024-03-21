

#include <iostream>
const int MAX_PALABRAS= 50;
const int  MAX_LETRAS = 33;
using namespace std;

void IniWord(char word[MAX_LETRAS]);
void IniPalabras(char palabras[MAX_PALABRAS][MAX_LETRAS]);
int wordlen(char word[MAX_LETRAS]);
void storeWord(char word[MAX_LETRAS], char palabras[MAX_PALABRAS][MAX_LETRAS], int i);
void OrdenarPalabras(char palabras[MAX_PALABRAS][MAX_LETRAS], int n, int lens[MAX_LETRAS]);
void ImpPalabras(char palabras[MAX_PALABRAS][MAX_LETRAS], int n);
void Intercambiar(char palabras[MAX_PALABRAS][MAX_LETRAS], int i);


int main()
{
    int wordNum,i=1,validNum=0,validW=0, lens[33] ;
    char palabras[MAX_PALABRAS][MAX_LETRAS];
    char word[MAX_LETRAS];

    IniWord(word);
    IniPalabras(palabras);


    while (!validNum) {
        cout << "Ingrese la cantidad de palabras a evaluar (max. 50):";
        cin >> wordNum;
        if (wordNum > 50) {
            cout << "La cantidad de palabras debe ser maximo 50." << endl;
        }
        else {
            validNum = 1;
            while (i <= wordNum) {
                validW = 0;
                while (!validW) {
                    if (wordlen(word)<=33) { 
                        validW = 1;
                        cout << "Ingrese la palabra " << i << ":";
                        cin >> word;
                        
                        lens[i] =wordlen(word);
                        storeWord(word,palabras,i);
                        i++;
                    }
                    else {
                        cout << "La cantidad maxima de letras de una palabra es de 33."<< endl; 
                    }
                }
            }
        }
    }
   OrdenarPalabras(palabras, wordNum, lens);
   ImpPalabras(palabras,wordNum);

}

void IniWord(char word[MAX_LETRAS]) {
    for (int i = 0; i < MAX_LETRAS;i++) {
        word[i] = ' ';
    }
}
void IniPalabras(char palabras[MAX_PALABRAS][MAX_LETRAS]) {
    for (int i = 0; i < MAX_PALABRAS; i++){
        for (int j = 0; j < MAX_LETRAS; j++) {
            palabras[i][j] = ' ';
        }
    }
}

int wordlen(char word[MAX_LETRAS]) {
    int n=0;

    for (int i = 0; i < MAX_LETRAS; i++) {
        if (word[i]!=' ') {
            n++;
        }
    }
    return n;
}

void storeWord(char word[MAX_LETRAS], char palabras[MAX_PALABRAS][MAX_LETRAS], int i) {

    for (int j = 0; j < wordlen(word); j++) {
        palabras[i-1][j] = word[j];
    }
}

void OrdenarPalabras(char palabras[MAX_PALABRAS][MAX_LETRAS], int n, int lens[MAX_LETRAS]) {
    int templen;
    int j = 0,exit=0;
    for (int i = 0; i < n; i++) {
        while (j < 33 && !exit) {
            if (palabras[i][j]>palabras[i+1][j]) {
                Intercambiar(palabras,i);
                templen = lens[i+1];
                lens[i] = lens[i];
                lens[i] = templen;  
                exit = 1;
            }
            j++;
        }
    }
}

void Intercambiar(char palabras[MAX_PALABRAS][MAX_LETRAS], int i) {
    char temp[MAX_LETRAS];

    for (int k = 0; k < 33; k++) {
        temp[k] = palabras[i + 1][k];
    }
    for (int k = 0; k < 33; k++) {
        palabras[i + 1][k] = palabras[i][k];
    }

    for (int m = 0; m < 33; m++) {
        palabras[i][m] = temp[m];
    }
}
void ImpPalabras(char palabras[MAX_PALABRAS][MAX_LETRAS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 33; j++) {
            cout<<palabras[i][j]<< " ";
        }
        cout << endl;
    }
}