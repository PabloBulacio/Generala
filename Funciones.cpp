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


///JUEGO PARA UNO
void juegode1(char ganador[30], int puntaje[], int vueltas[]){



    const bool azar=true;
    const int t=5;

    int dados[t], dadosBand[t], repetido[8];
    int y, x, c, c2, cont, r, doblejugador=0, l, bandera;
    int lanzamientos, rondas=0, puntos=0, cuantos=0, cual=0;

    char seguir='S';
    char reiniciar='S';
    char nombre[30];



        setlocale(LC_ALL,"spanish");

        recuadro(25, 2, 60, 30);
        setColor(LIGHTGREEN);
        locate(43,8);
        cout <<"BIENVENIDO A ***GENERALA***";
        locate(45,10);
        setColor(LIGHTMAGENTA);
        cout <<"MODALIDAD: UN JUGADOR";
        locate(34,12);
        setColor(LIGHTRED);
        cout<<"NOMBRE: ";
        locate(42,12);
        setColor(WHITE);
        cin.ignore();
        cin.getline(nombre, 30);
        mayuscula(nombre, 30);
        locate(34,14);
        setColor(LIGHTCYAN);
        cout<<"HOLA "<<nombre<<"!";


        do{
        locate(34,16);
        setColor(LIGHTBLUE);
        cout <<"CUANTAS RONDAS QUIERES JUGAR?: ";
        setColor(WHITE);
        cin>> rondas;
        system("cls");

        for(y=1; y<=rondas; y++){

        lanzamientos=0;
        lanzamientos++;


        recuadro(25, 2, 60, 30);
        locate(26,13);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(49,15);
        setColor(LIGHTGREEN);
        cout<<"RONDA NRO: "<<y;
        locate(42,17);
        setColor(LIGHTCYAN);
        cout<<"PUNTAJE DE " <<nombre <<" : "<<puntos <<" PUNTOS";
        locate(42,18);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador;
        locate(26,21);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        system("pause>nul");
        system("cls");

        recuadro(25, 2, 60, 30);
        locate(26,3);
        setColor(LIGHTGREEN);
        cout<<"TURNO DE: "<<nombre;
        locate(48,3);

        cout<<"RONDA Nro: " <<y;
        locate(65,3);

        cout<< "PUNTAJE TOTAL: " <<puntos;

        locate(26,4);
        setColor(WHITE);
        cout<<"___________________________________________________________";

        locate(45,6);
        setColor(LIGHTGREEN);
        cout<<"LANZAMIENTO Nro: " <<lanzamientos;

        locate(26,7);
        setColor(WHITE);
        cout<<"___________________________________________________________";

                ponerUno(dadosBand, t);

                tirarDados(dados,dadosBand, t, azar);

                c=combinacion(dados,repetido, t);



        if (c==50 && lanzamientos==1){

        system("cls");
        recuadro(25, 2, 60, 30);
        locate(26,13);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(45,15);
        setColor(LIGHTGREEN);
        cout<<"FELICIDADES "<<nombre<<"!";
        locate(27,17);
        cout<<"OBTUVISTE **GENERALA SERVIDA** EN TU PRIMER LANZAMIENTO!";
        locate(42,19);
        cout<<"SABES LO QUE ESO SIGNIFICA?";
        locate(26,21);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        system("cls");

        y=rondas;
        puntos=c;

      }
      else{

        locate(40,10);
        mostrarDados(dados, t);

        locate(27,12);
        setColor(LIGHTBLUE);
        cout<< "QUIERES LANZAR NUEVAMENTE? (S/N): ";
        setColor(WHITE);
        cin>>seguir;
        seguir=towupper(seguir);



        while(seguir!='N' && lanzamientos<3){

        cual=0;
        cont=0;
        cuantos=0;
        ponerCero(dadosBand, t);
        lanzamientos++;

        locate(27,13);
        setColor(LIGHTBLUE);
        cout<<"CUANTOS DADOS QUIERES VOLVER A LANZAR? : ";
        setColor(WHITE);
        cin>>cuantos;
        locate(27,14);
        l=14;
        setColor(LIGHTBLUE);
        cout<<"CUAL DADO? : ";
        setColor(WHITE);
        cin>>cual;
        while(cont<cuantos){

                    if (dadosBand[cual-1]==0){

                    dadosBand[cual-1]=1;
                    cont++;

                    if(cont!=cuantos){

                    l+=1;
                    locate(27,l);
                    setColor(LIGHTBLUE);
                    cout<<"CUAL MAS? : ";
                    setColor(WHITE);
                    cin>>cual;
                    }
                } else{
                        l+=1;
                        locate(27,l);
                        setColor(LIGHTRED);
                        cout<<"ESE DADO YA LO HAS ELEGIDO! **INTENTALO DE NUEVO**";
                        cout<<endl;
                        l+=1;
                        locate(27,l);
                        setColor(LIGHTBLUE);
                        cout<<"CUAL MAS? : ";
                        setColor(WHITE);
                        cin>>cual;


                        }

                            }

        tirarDados(dados, dadosBand, t, azar);

        system("cls");

        recuadro(25, 2, 60, 30);
        locate(26,3);
        setColor(LIGHTGREEN);
        cout<<"TURNO DE: "<<nombre;
        locate(48,3);
        cout<<"RONDA Nro: " <<y;
        locate(65,3);
        cout<<"PUNTAJE TOTAL: " <<puntos;

        locate(26,4);
        setColor(WHITE);
        cout<<"___________________________________________________________";

        locate(45,6);
        setColor(LIGHTGREEN);
        cout<<"LANZAMIENTO Nro: " <<lanzamientos;

        locate(26,7);
        setColor(WHITE);
        cout<<"___________________________________________________________";


        locate(40,10);
        mostrarDados(dados, t);


        cout<<endl;
            if (lanzamientos<3){
                locate(27,12);
                setColor(LIGHTBLUE);
                cout<<"CONTINUAS LANZANDO? (S/N): ";
                setColor(WHITE);
                cin>>seguir;
                seguir=towupper(seguir);
            }
                if(seguir=='S'){
                seguir='S';
                } else{
                seguir='N';
                          }

        }

        c=combinacion(dados, repetido, t);



        switch (c){
        case 25:

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
         setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***ESCALERA***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");

        break;

        case 30:
        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***FULL***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;

        case 40:
        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***POCKER***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;

        case 50:

        doblejugador += 1;
        if(doblejugador==2){

        bandera=y;
        y=rondas;

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<nombre<<" SOS MUY AFORTUNADO!";
        locate(38,18);
        cout<<"HAS OBTENIDO ***GENERALA DOBLE***";
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        system("pause>nul");
        } else{

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***GENERALA***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
       }
        break;

        default:

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***JUEGO DE "<<repetido[8]<<" ***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;
        }
        puntos+=c;
        system("cls");


        }

      }



if (c==50 && lanzamientos==1 || doblejugador==2){


    if(doblejugador==2){

    rondas = bandera;

    system("cls");
    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(34,15);
    setColor(LIGHTGREEN);
    cout<<"HAS GANADO LA PARTIDA CON **GENERALA DOBLE**!";
    locate(41,17);
    setColor(YELLOW);
    cout<<"PUNTAJE DE " <<nombre <<" : "<<puntos <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador;
    locate(45,19);
    cout<<"CANTIDAD DE RONDAS: "<<rondas;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    }
    else{

    rondas = y - rondas;
    system("cls");
    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(44,15);
    setColor(LIGHTGREEN);
    cout<<"HAS GANADO LA PARTIDA!";
    locate(41,17);
    setColor(YELLOW);
    cout<<"PUNTAJE DE " <<nombre <<" : "<<puntos <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador;
    locate(45,19);
    cout<<"CANTIDAD DE RONDAS: "<<rondas;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    }

    system("pause>nul");
    system("cls");


} else{

        recuadro(25, 2, 60, 30);
        locate(26,13);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(48,15);
        setColor(LIGHTGREEN);
        cout<<"RESULTADO FINAL: ";
        locate(41,17);
        setColor(LIGHTCYAN);
        cout<<"PUNTAJE DE " <<nombre <<" : "<<puntos <<" PUNTOS";
        locate(43,18);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador;
        locate(45,19);
        cout<<"CANTIDAD DE RONDAS: "<<rondas;
        locate(26,21);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        system("pause>nul");
        system("cls");



}

    recuadro(25, 2, 60, 30);

    locate(34,14);
    setColor(LIGHTBLUE);
    cout<<"QUIERES EMPEZAR UNA NUEVA PARTIDA? (S/N): ";
    setColor(WHITE);
    cin>>reiniciar;
    reiniciar=towupper(reiniciar);

    if(reiniciar=='S'){

        strcpy(ganador,nombre);
        puntaje[1]=puntos;
        vueltas[1]=rondas;
        puntos=0;
        rondas=0;
        doblejugador=0;



    }




        }while (reiniciar=='S');

        strcpy(ganador,nombre);
        puntaje[1]=puntos;
        vueltas[1]=rondas;

        system("cls");
        recuadro(25, 2, 60, 30);
        locate(26,13);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(42,15);
        setColor(LIGHTGREEN);
        cout<<"ESPERO TE HAYAS DIVERTIDO!";
        locate(44,18);
        setColor(LIGHTBLUE);
        cout<<"COPYRIGHT BULACIO PABLO";
        locate(26,21);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";




}

///JUEGO PARA DOS
void juegode2(char ganador[30], int puntaje[], int vueltas[]){

    const bool azar=true;

    bool generalaservida1=false;
    bool generalaservida2=false;

    const int t=5;
    int dados[t], dadosBand[t], repetido[8];

    int y, x, c, c2, cont, r, doblejugador1=0, doblejugador2=0, l, bandera=1;
    int lanzamientos, rondas=0, puntos=0, puntos1=0, puntos2=0, cuantos=0, cual=0;

    char seguir='S';
    char reiniciar='S';
    char nombre[30], nombre1[30], nombre2[30];



        setlocale(LC_ALL,"spanish");

        recuadro(25, 2, 60, 30);
        setColor(LIGHTGREEN);
        locate(43,8);
        cout <<"BIENVENIDO A ***GENERALA***";
        locate(45,10);
        setColor(LIGHTMAGENTA);
        cout <<"MODALIDAD: DOS JUGADORES";
        locate(34,12);
        setColor(LIGHTRED);
        cout<<"NOMBRE JUGADOR 1: ";
        locate(52,12);
        setColor(WHITE);
        cin.ignore();
        cin.getline(nombre1, 30);
        mayuscula(nombre1,30);
        locate(34,14);
        setColor(LIGHTRED);
        cout<<"NOMBRE JUGADOR 2: ";
        locate(52,14);
        setColor(WHITE);
        cin.getline(nombre2, 30);
        mayuscula(nombre2,30);



        do{

        locate(34,16);
        setColor(LIGHTBLUE);
        cout <<"CUANTAS RONDAS QUIERES JUGAR?: ";
        setColor(WHITE);
        cin>> rondas;
        system("cls");

        for(y=1; y<=rondas; y++){

        lanzamientos=0;
        lanzamientos++;


        recuadro(25, 2, 60, 30);
        locate(26,11);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(49,13);
        setColor(LIGHTGREEN);
        cout<<"RONDA NRO: "<<y;
        locate(45,15);
        setColor(LIGHTBLUE);
        cout<<"PROXIMO TURNO: "<<nombre1;
        locate(42,17);
        setColor(LIGHTCYAN);
        cout<<"PUNTAJE DE " <<nombre1 <<" : "<<puntos1 <<" PUNTOS";
        locate(42,18);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador1;
        locate(42,20);
        cout<<"PUNTAJE DE " <<nombre2 <<" : "<<puntos2 <<" PUNTOS";
        locate(42,21);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador2;
        locate(26,23);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        system("pause>nul");
        system("cls");

        recuadro(25, 2, 60, 30);
        locate(26,3);
        setColor(LIGHTGREEN);
        cout<<"TURNO DE: "<<nombre1;
        locate(48,3);
        cout<<"RONDA Nro: " <<y;
        locate(65,3);
        cout<< "PUNTAJE TOTAL: " <<puntos1;

        locate(26,4);
        setColor(WHITE);
        cout<<"___________________________________________________________";

        locate(45,6);
        setColor(LIGHTGREEN);
        cout<<"LANZAMIENTO Nro: " <<lanzamientos;

        locate(26,7);
        setColor(WHITE);
        cout<<"___________________________________________________________";

                ponerUno(dadosBand, t);

                tirarDados(dados,dadosBand, t, azar);

                c=combinacion(dados, repetido, t);

                locate(40,10);
                mostrarDados(dados, t);



        if (c==50 && lanzamientos==1){


        locate(26,13);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(45,16);
        setColor(LIGHTGREEN);
        cout<<"FELICIDADES "<<nombre1<<"!";
        locate(27,19);
        cout<<"OBTUVISTE **GENERALA SERVIDA** EN TU PRIMER LANZAMIENTO!";
        locate(26,21);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        generalaservida1=true;
        puntos1 += 50;


        system("pause>nul");
        system("cls");

      }
      else{

        locate(40,10);
        mostrarDados(dados, t);

        locate(27,12);
        setColor(LIGHTBLUE);
        cout<< "QUIERES LANZAR NUEVAMENTE? (S/N): ";
        setColor(WHITE);
        cin>>seguir;
        seguir=towupper(seguir);



        while(seguir!='N' && lanzamientos<3){

        cual=0;
        cont=0;
        cuantos=0;
        ponerCero(dadosBand, t);
        lanzamientos++;

        locate(27,13);
        setColor(LIGHTBLUE);
        cout<<"CUANTOS DADOS QUIERES VOLVER A LANZAR? : ";
        setColor(WHITE);
        cin>>cuantos;
        locate(27,14);
        l=14;
        setColor(LIGHTBLUE);
        cout<<"CUAL DADO? : ";
        setColor(WHITE);
        cin>>cual;
        while(cont<cuantos){

                    if (dadosBand[cual-1]==0){

                    dadosBand[cual-1]=1;
                    cont++;

                    if(cont!=cuantos){

                    l+=1;
                    locate(27,l);
                    setColor(LIGHTBLUE);
                    cout<<"CUAL MAS? : ";
                    setColor(WHITE);
                    cin>>cual;
                    }
                } else{
                        l+=1;
                        locate(27,l);
                        setColor(LIGHTRED);
                        cout<<"ESE DADO YA LO HAS ELEGIDO! **INTENTALO DE NUEVO**";
                        cout<<endl;
                        l+=1;
                        locate(27,l);
                        setColor(LIGHTBLUE);
                        cout<<"CUAL MAS? : ";
                        setColor(WHITE);
                        cin>>cual;


                        }

                            }

        tirarDados(dados, dadosBand, t, azar);

        system("cls");

        recuadro(25, 2, 60, 30);
        locate(26,3);
        setColor(LIGHTGREEN);
        cout<<"TURNO DE: "<<nombre1;
        locate(48,3);
        cout<<"RONDA Nro: " <<y;
        locate(65,3);
        cout<<"PUNTAJE TOTAL: " <<puntos1;

        locate(26,4);
        setColor(WHITE);
        cout<<"___________________________________________________________";

        locate(45,6);
        cout<<"LANZAMIENTO Nro: " <<lanzamientos;

        locate(26,7);
        setColor(WHITE);
        cout<<"___________________________________________________________";


        locate(40,10);
        mostrarDados(dados, t);


        cout<<endl;
            if (lanzamientos<3){
                locate(27,12);
                cout<<"CONTINUAS LANZANDO? (S/N): ";
                cin>>seguir;
                seguir=towupper(seguir);
            }
                if(seguir=='S'){
                seguir='S';
                } else{
                seguir='N';
                          }

        }

        c=combinacion(dados, repetido, t);


        switch (c){
        case 25:

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***ESCALERA***";
        locate(43,18);setColor(LIGHTBLUE);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");

        break;

        case 30:
        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***FULL***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;

        case 40:
        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***POCKER***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;

        case 50:

        doblejugador1 += 1;
        if(doblejugador1==2){

        bandera=y;
        y=rondas;

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<nombre1<<" SOS MUY AFORTUNADO!";
        locate(38,18);
        cout<<"HAS OBTENIDO ***GENERALA DOBLE***";
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        system("pause>nul");
        } else{

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***GENERALA***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
       }
        break;

        default:

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***JUEGO DE "<<repetido[8]<<" ***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;
        }
        puntos1+=c;
        system("cls");


        }

        if(doblejugador1!=2){


        lanzamientos=0;
        lanzamientos++;


        recuadro(25, 2, 60, 30);
        locate(26,11);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(49,13);
        setColor(LIGHTGREEN);
        cout<<"RONDA NRO: "<<y;
        locate(45,15);
        setColor(LIGHTBLUE);
        cout<<"PROXIMO TURNO: "<<nombre2;
        locate(42,17);
        setColor(LIGHTCYAN);
        cout<<"PUNTAJE DE " <<nombre1 <<" : "<<puntos1 <<" PUNTOS";
        locate(42,18);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador1;
        locate(42,20);
        cout<<"PUNTAJE DE " <<nombre2 <<" : "<<puntos2 <<" PUNTOS";
        locate(42,21);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador2;
        locate(26,23);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        system("pause>nul");
        system("cls");

        recuadro(25, 2, 60, 30);
        locate(26,3);
        setColor(LIGHTGREEN);
        cout<<"TURNO DE: "<<nombre2;
        locate(48,3);
        cout<<"RONDA Nro: " <<y;
        locate(65,3);
        cout<< "PUNTAJE TOTAL: " <<puntos2;

        locate(26,4);
        setColor(WHITE);
        cout<<"___________________________________________________________";

        locate(45,6);
        setColor(LIGHTGREEN);
        cout<<"LANZAMIENTO Nro: " <<lanzamientos;

        locate(26,7);
        setColor(WHITE);
        cout<<"___________________________________________________________";

                ponerUno(dadosBand, t);

                tirarDados(dados,dadosBand, t, azar);

                c=combinacion(dados, repetido, t);

                locate(40,10);
                mostrarDados(dados, t);

                /*system("pause>nul");*/


        if (c==50 && lanzamientos==1){


        locate(26,13);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(45,16);
        setColor(LIGHTGREEN);
        cout<<"FELICIDADES "<<nombre2<<"!";
        locate(27,19);
        cout<<"OBTUVISTE **GENERALA SERVIDA** EN TU PRIMER LANZAMIENTO!";
        locate(26,21);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        system("cls");

        generalaservida2=true;
        puntos2 += 50;


        system("pause>nul");
        system("cls");

      }
      else{

        locate(40,10);
        mostrarDados(dados, t);

        locate(27,12);
        setColor(LIGHTBLUE);
        cout<< "QUIERES LANZAR NUEVAMENTE? (S/N): ";
        setColor(WHITE);
        cin>>seguir;
        seguir=towupper(seguir);



        while(seguir!='N' && lanzamientos<3){

        cual=0;
        cont=0;
        cuantos=0;
        ponerCero(dadosBand, t);
        lanzamientos++;

        locate(27,13);
        setColor(LIGHTBLUE);
        cout<<"CUANTOS DADOS QUIERES VOLVER A LANZAR? : ";
        setColor(WHITE);
        cin>>cuantos;
        locate(27,14);
        l=14;
        setColor(LIGHTBLUE);
        cout<<"CUAL DADO? : ";
        setColor(WHITE);
        cin>>cual;
        while(cont<cuantos){

                    if (dadosBand[cual-1]==0){

                    dadosBand[cual-1]=1;
                    cont++;

                    if(cont!=cuantos){

                    l+=1;
                    locate(27,l);
                    setColor(LIGHTBLUE);
                    cout<<"CUAL MAS? : ";
                    cin>>cual;
                    }
                } else{
                        l+=1;
                        locate(27,l);
                        setColor(LIGHTRED);
                        cout<<"ESE DADO YA LO HAS ELEGIDO! **INTENTALO DE NUEVO**";
                        cout<<endl;
                        l+=1;
                        locate(27,l);
                        setColor(LIGHTBLUE);
                        cout<<"CUAL MAS? : ";
                        setColor(WHITE);
                        cin>>cual;


                        }

                            }

        tirarDados(dados, dadosBand, t, azar);

        system("cls");

        recuadro(25, 2, 60, 30);
        locate(26,3);
        setColor(LIGHTGREEN);
        cout<<"TURNO DE: "<<nombre2;
        locate(48,3);
        cout<<"RONDA Nro: " <<y;
        locate(65,3);
        cout<<"PUNTAJE TOTAL: " <<puntos2;

        locate(26,4);
        setColor(WHITE);
        cout<<"___________________________________________________________";

        locate(45,6);
        setColor(LIGHTGREEN);
        cout<<"LANZAMIENTO Nro: " <<lanzamientos;

        locate(26,7);
        setColor(WHITE);
        cout<<"___________________________________________________________";


        locate(40,10);
        mostrarDados(dados, t);


        cout<<endl;
            if (lanzamientos<3){
                locate(27,12);
                setColor(LIGHTBLUE);
                cout<<"CONTINUAS LANZANDO? (S/N): ";
                setColor(WHITE);
                cin>>seguir;
                seguir=towupper(seguir);
            }
                if(seguir=='S'){
                seguir='S';
                } else{
                seguir='N';
                          }

        }

        c=combinacion(dados, repetido, t);


        switch (c){
        case 25:

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***ESCALERA***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");

        break;

        case 30:
        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***FULL***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;

        case 40:
        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***POCKER***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;

        case 50:

        doblejugador2 += 1;
        if(doblejugador2==2){

        bandera=y;
        y=rondas;

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<nombre2<<" SOS MUY AFORTUNADO!";
        locate(38,18);
        cout<<"HAS OBTENIDO ***GENERALA DOBLE***";
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";

        system("pause>nul");
        } else{

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***GENERALA***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
       }
        break;

        default:

        locate(26,16);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(41,17);
        setColor(LIGHTGREEN);
        cout<<"HAS OBTENIDO: ***JUEGO DE "<<repetido[8]<<" ***";
        locate(43,18);
        cout<<"PUNTAJE DE LA RONDA: "<<c;
        locate(26,19);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        system("pause>nul");
        break;
        }
        puntos2+=c;
        system("cls");


        }

        }

if(generalaservida1==true && generalaservida2==false){

    puntos=puntos1;
    strcpy(nombre,nombre1);



    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(30,15);
    setColor(LIGHTGREEN);
    cout<<nombre1<<" HAS GANADO LA PARTIDA CON **GENERALA SERVIDA**";
    locate(47,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos1 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador1;
    locate(46,19);
    cout<<"CANTIDAD DE RONDAS: "<<y;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    y=rondas;

    system("pause>nul");

        }

if(doblejugador1==2){



    y=bandera;
    puntos=puntos1;
    strcpy(nombre,nombre1);



    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(30,15);
    setColor(LIGHTGREEN);
    cout<<nombre1<<" HAS GANADO LA PARTIDA CON **GENERALA DOBLE**";
    locate(47,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos1 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador1;
    locate(46,19);
    cout<<"CANTIDAD DE RONDAS: "<<y;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";


    y=rondas;


    system("pause>nul");

        }


if(generalaservida2==true && generalaservida1==false){

    puntos=puntos2;
    strcpy(nombre,nombre2);


    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(30,15);
    setColor(LIGHTGREEN);
    cout<<nombre2<<" HAS GANADO LA PARTIDA CON **GENERALA SERVIDA**";
    locate(47,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos2 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador2;
    locate(46,19);
    cout<<"CANTIDAD DE RONDAS: "<<y;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    y=rondas;

    system("pause>nul");

        }

if(doblejugador2==2){


    y=bandera;
    puntos=puntos2;
    strcpy(nombre,nombre2);


    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(30,15);
    setColor(LIGHTGREEN);
    cout<<nombre2<<" HAS GANADO LA PARTIDA CON **GENERALA DOBLE**";
    locate(47,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos2 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador2;
    locate(46,19);
    cout<<"CANTIDAD DE RONDAS: "<<y;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    y=rondas;

    system("pause>nul");

        }

if (generalaservida1==true && generalaservida2==true){


    system("cls");


    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(34,15);
    setColor(LIGHTGREEN);
    cout<<"HAN OBTENIDO UN EMPATE **AMBOS SON GANADORES**";
    locate(41,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE DE " <<nombre1 <<" : "<<puntos1 <<" PUNTOS";
    locate(41,18);
    cout<<"PUNTAJE DE " <<nombre2 <<" : "<<puntos2<<" PUNTOS";
    locate(44,19);
    cout<<"CANTIDAD DE RONDAS: "<<y;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    y=rondas;

    system("pause>nul");

}

}

if(generalaservida1==true && generalaservida2==false || doblejugador1==2){rondas=bandera;}
if(generalaservida2==true && generalaservida1==false || doblejugador2==2){rondas=bandera;}


        system("cls");

        recuadro(25, 2, 60, 30);
        locate(26,11);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(47,13);
        setColor(LIGHTGREEN);
        cout<<"RESULTADO FINAL: ";
        locate(42,17);
        setColor(LIGHTCYAN);
        cout<<"PUNTAJE DE " <<nombre1 <<" : "<<puntos1 <<" PUNTOS";
        locate(42,18);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador1;
        locate(42,20);
        setColor(LIGHTBLUE);
        cout<<"PUNTAJE DE " <<nombre2 <<" : "<<puntos2 <<" PUNTOS";
        locate(42,21);
        cout<<"CANTIDAD DE GENERALAS: " <<doblejugador2;
        locate(26,23);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";


        system("pause>nul");


if(generalaservida1 == false && generalaservida2 == false){


if (puntos1 > puntos2 || doblejugador1 >= 2){

    puntos=puntos1;
    strcpy(nombre,nombre1);

    if(doblejugador1>=2){rondas=bandera;}

    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(35,15);
    setColor(LIGHTGREEN);
    cout<<"FELICIDADES "<<nombre1<<" GANASTE LA PARTIDA CON: ";
    locate(43,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos1 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador1;
    locate(43,19);
    cout<<"CANTIDAD DE RONDAS: "<<rondas;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    system("pause>nul");
}
if (puntos2 > puntos1 || doblejugador2 >= 2){

    puntos=puntos2;
    strcpy(nombre,nombre2);

    if(doblejugador2>=2){rondas=bandera;}

    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(35,15);
    setColor(LIGHTGREEN);
    cout<<"FELICIDADES "<<nombre2<<" GANASTE LA PARTIDA CON: ";
    locate(43,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos2 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador2;
    locate(43,19);
    cout<<"CANTIDAD DE RONDAS: "<<rondas;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    system("pause>nul");

}
if (puntos1==puntos2 && doblejugador1 == doblejugador2){

    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(34,15);
    setColor(LIGHTGREEN);
    cout<<"FELICIDADES "<<nombre1<<" y "<<nombre2<<" HAN EMPATADO!";
    locate(43,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE DE " <<nombre1 <<" : "<<puntos1 <<" PUNTOS";
    locate(43,18);
    cout<<"PUNTAJE DE " <<nombre2 <<" : "<<puntos2<<" PUNTOS";
    locate(45,19);
    cout<<"CANTIDAD DE RONDAS: "<<rondas;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    system("pause>nul");


}
if (puntos1==puntos2 && doblejugador1 >= 2){

    puntos=puntos1;
    strcpy(nombre,nombre1);
    if(doblejugador1>=2){rondas=bandera;}

    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(35,15);
    setColor(LIGHTGREEN);
    cout<<"FELICIDADES "<<nombre1<<" GANASTE LA PARTIDA CON: ";
    locate(43,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos1 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador1;
    locate(43,19);
    cout<<"CANTIDAD DE RONDAS: "<<rondas;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    system("pause>nul");

}
if (puntos1==puntos2 && doblejugador2 >= 2){

    puntos=puntos2;
    strcpy(nombre,nombre2);
    if(doblejugador2>=2){rondas=bandera;}

    system("cls");

    recuadro(25, 2, 60, 30);
    locate(26,13);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";
    locate(35,15);
    setColor(LIGHTGREEN);
    cout<<"FELICIDADES "<<nombre2<<" GANASTE LA PARTIDA CON: ";
    locate(43,17);
    setColor(LIGHTCYAN);
    cout<<"PUNTAJE: "<<puntos2 <<" PUNTOS";
    locate(43,18);
    cout<<"CANTIDAD DE GENERALAS: " <<doblejugador2;
    locate(43,19);
    cout<<"CANTIDAD DE RONDAS: "<<rondas;
    locate(26,21);
    setColor(WHITE);
    cout<<"-----------------------------------------------------------";

    system("pause>nul");

}

}

    recuadro(25, 2, 60, 30);

    locate(34,14);
    setColor(LIGHTBLUE);
    cout<<"QUIEREN EMPEZAR UNA NUEVA PARTIDA? (S/N): ";
    setColor(WHITE);
    cin>>reiniciar;
    reiniciar=towupper(reiniciar);



    if(reiniciar=='S'){

        generalaservida1=false;
        generalaservida2=false;
        doblejugador1=0;
        doblejugador2=0;
        puntos1=0;
        puntos2=0;

        strcpy(ganador,nombre);
        puntaje[1]=puntos;
        vueltas[1]=rondas;

    }


        }while (reiniciar=='S');


        strcpy(ganador,nombre);
        puntaje[1]=puntos;
        vueltas[1]=rondas;

        system("cls");
        recuadro(25, 2, 60, 30);
        locate(26,13);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";
        locate(42,15);
        setColor(LIGHTGREEN);
        cout<<"ESPERO SE HAYAN DIVERTIDO!";
        locate(44,18);
        setColor(LIGHTCYAN);
        cout<<"COPYRIGHT BULACIO PABLO";
        locate(26,21);
        setColor(WHITE);
        cout<<"-----------------------------------------------------------";





}







///FUNCIONES PARA EL JUEGO
void tirarDados(int vecDados[],int vecDadosBand[], int otro, const bool azar){
    int i, n;
    if(azar==true){
    srand(time(NULL));
    for(i=0;i<otro;i++){
       if(vecDadosBand[i]==1){
       vecDados[i]=(rand()%6)+1;
       /*dibujarDado(i+1, vecDados[i]);*/
     }
    }
    }
    else {
    locate(30,9);
    cout<<"DADO 1: ";
    locate(38,9);
    cin>>vecDados[0];
    locate(40,9);
    cout<<"DADO 2: ";
    locate(48,9);
    cin>>vecDados[1];
    locate(50,9);
    cout<<"DADO 3: ";
    locate(58,9);
    cin>>vecDados[2];
    locate(60,9);
    cout<<"DADO 4: ";
    locate(68,9);
    cin>>vecDados[3];
    locate(70,9);
    cout<<"DADO 5: ";
    locate(78,9);
    cin>>vecDados[4];
    }
}
void mostrarDados(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){

        cout<<v[i]<<"\t";

    }
    cout<<endl;
 }
int sumarPuntos(int dados[], int tam){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=dados[i];

    }
    return suma;
 }
int combinacion(int dados[], int repetido[8], int tam){
    int x, y, j,r, e=25, f=30, p=40, g=50, ce=0, cf=0, cp=0, cg=0, c=1, full=0, poker=0;

    bool esc=true;

    for(x=0; x<6; x++){
     r=contarNumerosRepetidos(dados, c, tam);
     repetido[x]=r;
     c++;
    }

    for(y=0; y<6; y++){
        if (repetido[y]==1){
            ce++;
            } else{
                if (y==5 || y==0){
                    esc=true;
                        } else{
                            esc=false;
                                }

                                    }
         if (repetido[y]==3 || repetido[y]==2){

            full+=repetido[y];
            cf++;
         }

        if (repetido[y]==4 || repetido[y]==1){

            poker+=repetido[y];
            cp++;
         }

         if (repetido[y]==5){
            cg++;
         }

    }

    if(ce==5 && esc==true){
        return e;
    }
    if(cf==2 && full==5){
        return f;
    }
    if(cp==2 && poker==5){
        return p;
    }
    if(cg==1){
        return g;
    }

    juegode(repetido, 8);
    return repetido[7];



}
void juegode(int repetido[], int tam){
    int x, maximo=1, m=0;

    for(x=0; x<tam-2; x++){
        if (repetido[x] != 0){
            m = repetido[x] * (x+1);
            if (m>maximo){
                maximo=m;
                repetido[tam-1]=m;
                repetido[tam]=x+1;
            }
        }
    }



}
void topranking(char v[], int puntos){

}
void mayuscula(char v[], int tam){
int i;
for(i=0; i<tam; i++){
    v[i] = towupper(v[i]);

}
}




///FUNCIONES PARA DIBUJAR RECUADROS Y DADO
void recuadro(int x, int y, int ancho, int alto){
    /// Reemplazar éstos códigos por los de Windows para correr en Windows.
    const char *UI_BOTTOM_RIGHT = "\e(0\x6a\e(B"; // 188 - ┘
    const char *UI_BOTTOM_LEFT = "\e(0\x6d\e(B"; // 200 - └
    const char *UI_TOP_LEFT = "\e(0\x6c\e(B"; // 201 - ┌
    const char *UI_TOP_RIGHT = "\e(0\x6b\e(B"; // 187 - ┐
    const char *UI_CROSS = "\e(0\x6e\e(B"; // 206 - ┼
    const char *UI_HORIZONTAL_LINE = "\e(0\x71\e(B"; // 205 - ─
    const char *UI_HORIZONTAL_LINE_TOP =  "\e(0\x76\e(B"; // 202 - ┴
    const char *UI_HORIZONTAL_LINE_BOTTOM =  "\e(0\x77\e(B"; // 203 - ┬";
    const char *UI_VERTICAL_LINE = "\e(0\x78\e(B"; // 186 - │
    const char *UI_VERTICAL_LINE_LEFT =  "\e(0\x74\e(B"; // 204 - ├
    const char *UI_VERTICAL_LINE_RIGHT =  "\e(0\x75\e(B"; // 185 - ┤


    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){
            /*setBackgroundColor(RED);*/
            locate(i, j);
            cout << " ";

        }
    }
    setColor(WHITE);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){
        locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;
    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
        locate(x, i);
        cout << UI_VERTICAL_LINE;
        locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    locate(x, y);
    cout << UI_TOP_LEFT;
    locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
}

void dibujarDado(int nroDado, int valor){
    const int Y = 8;
    const int ALTO = 3;
    const int INI = 22;
    const int X = INI + (nroDado * 10);
    const int ANCHO = 6;

    /// Ubicaciones del punto
    const int CENTRO_X = X + ANCHO/2;
    const int CENTRO_Y = Y + ALTO/2;
    const int IZQUIERDA = CENTRO_X - 2;
    const int ARRIBA = CENTRO_Y - 1;
    const int DERECHA= CENTRO_X + 2;
    const int ABAJO= CENTRO_Y + 1;


    recuadro(X, Y, ANCHO, ALTO);

    /// Dibujar los puntos

    const char *DOT = "+";           /*"\u2022";*/



    /*setBackgroundColor(RED);*/
    setColor(WHITE);
    switch(valor){
        case 1:
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 2:
            if (nroDado%2 == 0){
                locate(IZQUIERDA, ARRIBA);
                cout << DOT;
                locate(DERECHA, ABAJO);
                cout << DOT;
            }
            else{
                locate(DERECHA, ARRIBA);
                cout << DOT;
                locate(IZQUIERDA, ABAJO);
                cout << DOT;
            }
        break;
        case 3:
            if (nroDado%2 == 0){
                locate(IZQUIERDA, ARRIBA);
                cout << DOT;
                locate(DERECHA, ABAJO);
                cout << DOT;
            }
            else{
                locate(DERECHA, ARRIBA);
                cout << DOT;
                locate(IZQUIERDA, ABAJO);
                cout << DOT;
            }
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 4:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
        break;
        case 5:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
            locate(CENTRO_X, CENTRO_Y);
            cout << DOT;
        break;
        case 6:
            locate(IZQUIERDA, ARRIBA);
            cout << DOT;
            locate(DERECHA, ABAJO);
            cout << DOT;
            locate(DERECHA, ARRIBA);
            cout << DOT;
            locate(IZQUIERDA, ABAJO);
            cout << DOT;
            locate(DERECHA, CENTRO_Y);
            cout << DOT;
            locate(IZQUIERDA, CENTRO_Y);
            cout << DOT;
        break;
    }
    resetColor();
    /*setBackgroundColor(DARKGREY);*/
}





int posicionNumeroEnVector( int v[], int tam, int numero){
int i;
for (i= 0 ;i<tam;i++){
if (v[i]==numero) return i;
}
return -1 ;
}

///Devuelve el indice donde esta el minimo valor dentro del vector
int minimoVector( int v[], int tam){
int i, posMin= 0 ;
for (i= 1 ;i<tam;i++){
if (v[i]<v[posMin]) {
posMin=i;
}
}
return posMin;
}

///Ordena el vector de menor a mayor
void ordenarVector( int v[], int tam ){
int i,j, posmin, aux;
for (i= 0 ;i<tam -1 ;i++){
posmin=i;
for (j=i+ 1 ;j<tam;j++){
if (v[j]<v[posmin]) posmin=j;
}
aux=v[i];
v[i]=v[posmin];
v[posmin]=aux;
}
}

///Devuelve el indice donde esta el maximo valor dentro del vector.
int maximoVector( int v[], int tam){
int i, posMax= 0 ;
for (i= 1 ;i<tam;i++){
if (v[i]>v[posMax]) {
posMax=i;
}
}
return posMax;
}

///Carga el vector en forma aleatoria segun los parametros recibidos
void cargarAleatorio( int v[], int tam, int limite){
int i;
srand(time( NULL ));
for ( i= 0 ; i<tam; i++ ){
v[i]=(rand()%limite)+ 1 ;
}
}

///Muestra el vector de enteros
void mostrarVector( int v[], int tam){
int i;
for (i= 0 ;i<tam;i++){
cout <<v[i]<< "\t" ;
}
}

///Cuenta los numeros repetidos al recibir un numero entero
int contarNumerosRepetidos( int v[], int numero, int tam){
int i, cant= 0 ;
for (i= 0 ;i<tam;i++){
        if (v[i]==numero) cant++;


}
return cant;
}
///Pone en cero todo el vector
void ponerCero( int v[], int tam){
int i;
for (i= 0 ;i<tam;i++){
v[i]= 0 ;
}
}

///Pone en uno todo el vector
void ponerUno( int v[], int tam){
int i;
for (i= 0 ;i<tam;i++){
v[i]= 1 ;
}
}

///Suma los valores dentro del vector
int sumarVector( int v[], int tam ){
int i, suma= 0 ;
for (i= 0 ;i<tam;i++){
suma+=v[i];
}
return suma;
}

///Copia un vector de numeros enteros a otro vector
int copiarVector( int v[], int v2[], int tam ){
int i;
for (i= 0 ;i<tam;i++){
v2[i]=v[i];
}
}

///Compara los valores de cada vector
bool compararVectores( int v[], int v2[], int tam ){
int i;
for (i= 0 ;i<tam;i++){
if (v2[i]!=v[i]) return false ;
}
return true ;
}

///Carga un vector de numeros enteros segun ingreso por teclado
void cargarVector(int v[], int tam){
int i;
for(i=0;i<tam;i++){
cout<<"INGRESE NUMERO: ";
cin>>v[i];
}
}
