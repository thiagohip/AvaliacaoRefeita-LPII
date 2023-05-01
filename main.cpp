//thiago hipolito

#include <iostream>
#include "time.h"

using namespace std;

class Rifa{
    public:
        const static int RIFA_POSICOES = 5;
        

        Rifa(int num_sorteios){
            posicoes_sorteadas = new int[num_sorteios];
            for(int i=0; i<RIFA_POSICOES; i++){
                nomes[i] = "";
            }
            this -> num_sorteios = num_sorteios;
        }

        ~Rifa(){
            delete[] posicoes_sorteadas;
        }

        string getNome(int pos){
            return nomes[pos];
        }

        int getNumSorteios(){
            return num_sorteios;
        }

        void setNome(int pos, string nome){
            nomes[pos] = nome;
        }

        void sortear(){
            for(int i=0; i<num_sorteios; i++){
                posicoes_sorteadas[i] = rand()%RIFA_POSICOES;
            }
        }

        bool foi_sorteado(int pos){
            for(int i=0; i<num_sorteios; i++){
                if(posicoes_sorteadas[i] == pos){
                    return true;
                }
            }
            return false;
        }
    private:
        int num_sorteios, *posicoes_sorteadas;
        string nomes[RIFA_POSICOES];

};

int main(){
    srand(time(NULL));
    int num_sort;
    cout << "Digite a quantidade de sorteios a ser realizada: ";
    cin >> num_sort;
    Rifa r(num_sort);
    cout << "\nDigite os nomes a serem sorteados: " << endl;
    for(int i=0; i<r.RIFA_POSICOES; i++){
        string nome;
        cin >> nome;
        r.setNome(i, nome); 
    }
    cout << endl;

    r.setNome(2, "Thiago");
    r.sortear();
    cout << "Nomes sorteados: " << endl;
    for(int i=0; i<r.RIFA_POSICOES; i++){
        if(r.foi_sorteado(i)){
            cout << r.getNome(i) << endl;
        }
    }

    return 0;
}
