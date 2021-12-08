#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <mutex>

#define ITERATIONS 9

class ContaCorrente
{
    int idCliente;
    double saldo;
    std::mutex m;

public:
    ContaCorrente(int i, double f)
    {
        idCliente = i;
        saldo = f;
    }

    double getSaldo()
    {
        return saldo;
    }

    void addSaldo(double f)
    {
        m.lock();
        saldo += f;
        m.unlock();
    }
};

ContaCorrente cc1(1, 1000.0);

void operacoes1(int i)
{
    int counter = 0;
    while (counter < ITERATIONS + 1)
    {
        cc1.addSaldo(100.0);
        printf("[c] %lf, thread [%d]\n", cc1.getSaldo(), i);
        counter++;
    }
}

void operacoes2(int i)
{
    int counter = 0;
    while (counter < ITERATIONS)
    {
        cc1.addSaldo(-100.0);
        printf("[d] %lf, thread [%d]\n", cc1.getSaldo(), i);
        counter++;
    }
}

int main(void)
{
    std::thread t1(operacoes1, 1), t2(operacoes2, 1), t3(operacoes1, 2), t4(operacoes2, 2);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    printf("Saldo final da conta: %f\n", cc1.getSaldo());

    return 0;
}