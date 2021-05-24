#include<iostream>
using namespace std;
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<ctime>
#include <conio.h>
#include <string.h>
#include<sstream>
#include "Funciones.h"
#include "rlutil.h"
using namespace rlutil;

int main(){
    const int tam=5;
    int dados[tam], puntaje[3]={0}, vueltas[3]={0};

    int puntaje1=0, puntaje2=0, puntaje3=0;
    int vueltas1=0, vueltas2=0, vueltas3=0;
    int maximo1=0, maximo2=0, maximo3=0, opc;

    char ganador[30]={"VACIO"}, puesto1[30]={"VACIO"}, puesto2[30]={"VACIO"}, puesto3[30]={"VACIO"};



    while(true){


                system("pause>nul");
                recuadro(25, 2, 60, 30);
                setColor(LIGHTGREEN);
                locate(38,8);
                cout<<"UNIVERSIDAD TECNOLOGICA NACIONAL";
                locate(40,10);
                setColor(LIGHTCYAN);
                cout<<"TRABAJO PRACTICO INTEGRADOR";
                locate(48,12);
                setColor(LIGHTRED);
                cout<<"**GENERALA**";

                locate(40,16);
                setColor(YELLOW);
                cout<<"1. MODO UN JUGADOR"<<endl;
                locate(40,18);
                cout<<"2. MODO DOS JUGADORES"<<endl;
                locate(40,20);
                cout<<"3. TOP RANKING"<<endl;
                locate(40,22);
                cout<<"0. EXIT"<<endl<<endl;
                locate(40,24);
                setColor(LIGHTMAGENTA);
                cout<<"ELIJA UNA OPCION PARA COMENZAR: ";
                setColor(WHITE);
                cin>>opc;
                system("cls");
                switch (opc){

                case 1: juegode1(ganador, puntaje, vueltas);
                    break;

                case 2:juegode2(ganador, puntaje, vueltas);
                    break;

                case 3:

                        if(puntaje[1]>maximo1){

                        maximo2 = maximo1;
                        strcpy(puesto2, puesto1);
                        vueltas2 = vueltas1;
                        maximo1 = puntaje[1];
                        strcpy(puesto1, ganador);
                        vueltas1 = vueltas[1];

                    }else{

                    if(puntaje[1]>maximo2){

                        maximo3 = maximo2;
                        strcpy(puesto3, puesto2);
                        vueltas3 = vueltas2;
                        maximo2 = puntaje[1];
                        strcpy(puesto2, ganador);
                        vueltas2 = vueltas[1];


                    } else{
                    if (puntaje[1]>maximo3){

                        maximo3 = puntaje[1];
                        strcpy(puesto3, ganador);
                        vueltas3 = vueltas[1];

                    }
                    }
                    }

                    recuadro(25, 2, 60, 30);

                    locate(28,4);
                    cout<<"RANKING";
                    locate(48,4);
                    cout<<"CANT. RONDAS";
                    locate(73,4);
                    cout<<"PUNTOS";
                    setColor(WHITE);
                    locate(26,5);
                    cout<<"___________________________________________________________";


                    locate(28,8);
                    setColor(LIGHTGREEN);
                    cout<<" #1 " <<puesto1;
                    locate(54,8);
                    cout<<vueltas1;
                    locate(73,8);
                    cout<<maximo1;

                    locate(28,14);
                    setColor(LIGHTCYAN);
                    cout<<" #2 " <<puesto2;
                    locate(54,14);
                    cout<<vueltas2;
                    locate(73,14);
                    cout<<maximo2;

                    locate(28,20);
                    setColor(LIGHTMAGENTA);
                    cout<<" #3 " <<puesto3;
                    locate(54,20);
                    cout<<vueltas3;
                    locate(73,20);
                    cout<<maximo3;


                   ponerCero(puntaje, 3);
                   ponerCero(vueltas, 3);

                    break;


                case 0: return 0;
                    break;

                default:

                    recuadro(25, 2, 60, 30);
                    locate(46,16);
                    setColor(LIGHTRED);
                    cout<<"**OPCION INCORRECTA**";
                    locate(46,18);
                    setColor(LIGHTGREEN);
                    cout<<"**INTENTALO DE NUEVO**";

                    break;

                }


                }


    return 0;
}
