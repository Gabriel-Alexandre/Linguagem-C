#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <string>

#define QTD_THREADS_ESCRITA 5

using namespace std;

class Dicionario
{
    int idDicionario;
    ofstream palavras;
    ifstream palavrasLeitura;
    std::mutex m;

public:
    Dicionario(int i)
    {
        idDicionario = i;
    }

    void addPalavra(string p)
    {
        m.lock();
        palavras.open("palavra.txt", ios::out);
        if(palavras.is_open( )) {
            palavras << p;
        }
        palavras.close();
        m.unlock();
    }

    void lerarq() {
        string aux;
        m.lock();
        palavrasLeitura.open("palavra.txt", ios::in);
        if(palavrasLeitura.is_open( )) {
            while (!palavrasLeitura.eof()) {
                getline(palavrasLeitura, aux); 
                cout << aux << endl;
            }
        }
        m.unlock();
    }
};

Dicionario d(1);

void escrita(int i)
{
    int cond = 1;
    int count = 0;
    while (cond) {
        d.addPalavra(to_string(i));
        if(count == 1000) {
            cond = 0;
        } else {
            count++;
        }
    }
}

void leitura() {
    d.lerarq();
}

int main(void)
{
    thread t[QTD_THREADS_ESCRITA];

    for(int i = 0; i < QTD_THREADS_ESCRITA; i++) {
        t[i] = thread(escrita, i);
    }

    for(int i = 0; i < QTD_THREADS_ESCRITA; i++) {
        t[i].join();
    }

    thread l(leitura);

    l.join();

    return 0;
}