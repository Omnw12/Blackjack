#include <iostream>


using namespace std;
//Valores cartas
int picas[13];
int corazones[13];
int diamantes[13];
int treboles[13];
string palobaraja;
int palo;
string numerocarta;
bool playerlose = false;
bool croupierlose = false;
string cr = "Croupier";
string pla = "Jugador";

//ValorJugador/Croupier
string player1;
string croupier = "Pablo";
int valorcartasplayer = 0;
int valorcartascroupier = 0;
int dinero;
bool playerturn = true;
bool Croupierturn = true;
int puntospla = 0;
int puntoscro = 0;
string valorcarta;



void Array(int(&puntosBaraja)[13]) {
    for (int i = 0; i < 13; i++) {
        puntosBaraja[i] = 1;
    }
}

void CardChoos(int& valorc, int& puntua, string character, string name) {
    bool turnoPlayer = false;
    int ind = 0;
    while (!turnoPlayer) {
        ind = rand() % 13;
        if (ind == 0) {
            valorcarta = "Dos";
            valorc = 2;
        }
        else  if (ind == 1) {
            valorcarta = "Tres";
            valorc = 3;
        }
        else  if (ind == 2) {
            valorcarta = "Quatro";
            valorc = 4;
        }
        else  if (ind == 3) {
            valorcarta = "Cinco";
            valorc = 5;
        }
        else  if (ind == 4) {
            valorcarta = "Seis";
            valorc = 6;
        }
        else  if (ind == 5) {
            valorcarta = "Siete";
            valorc = 7;
        }
        else  if (ind == 6) {
            valorcarta = "Ocho";
            valorc = 8;
        }
        else  if (ind == 7) {
            valorcarta = "Nueve";
            valorc = 9;
        }
        else  if (ind == 8) {
            valorcarta = "Diez";
            valorc = 10;
        }
        else  if (ind == 9) {
            valorcarta = "J";
            valorc = 10;
        }
        else  if (ind == 10) {
            valorcarta = "Q";
            valorc = 10;
        }
        else  if (ind == 11) {
            valorcarta = "K";
            valorc = 10;
        }
        else  if (ind == 12) {
            valorcarta = "As";
            valorc = 11;

        }
        palo = rand() % 4;
        if (palo == 0) {
            if (diamantes[ind] == 1) {
                diamantes[ind] = 0;
                palobaraja = "Diamantes";
                turnoPlayer = true;
            }
        }
        else if (palo == 1) {
            if (treboles[ind] == 1) {
                treboles[ind] = 0;
                palobaraja = "Treboles";
                turnoPlayer = true;
            }
        }
        else if (palo == 2) {
            if (picas[ind] == 1) {
                picas[ind] = 0;
                palobaraja = "Picas";
                turnoPlayer = true;
            }
        }
        else if (palo == 3) {
            if (corazones[ind] == 1) {
                corazones[ind] = 0;
                palobaraja = "Corazones";
                turnoPlayer = true;
            }
        }
    }
    cout << "Al " << character << " " << name << " le ha salido el " << valorcarta << " de " << palobaraja << "\n";
    puntua += valorc;

}


void gameStart() {
    cout << "Bienvenido a casino Barcelona. Hoy tendremos el placer de jugar al  famoso juego Blackjack" << "\n";
    cout << "Las reglas ya las sabes, así que no las explicaré." << croupier << " será tu croupier" << "\n";
    cout << "Como se llama usted\n";
    cin >> player1;
    cout << "Cuanto quieres apostar? Recuerda que cada vez que ganes doblarás\n";
    cin >> dinero;

}
void firstRound() {
    cout << "El croupier te reparte dos cartas" << "\n";
    cout << "Miras las cartas." << "\n";
}
void firstRoundcro() {
    cout << "El croupier se reparte una carta""\n";

}
bool checkTurnOver(int& puntosjugador, string pc, bool& turno, bool& derrota, string character, string name) {
    int option = 0;
    if (puntosjugador < 21) {
        while (option != 1 && option != 2) {
            cout << pc << " dispone de " << puntosjugador << ". Quieres seguir intentando jugar o prefieres plantarte?""\n";
            cout << "Teclea 1 si quieres seguir jugando, 2 si te quieres plantar""\n";
            cin >> option;
            if (option != 1 && option != 2) {
                cout << "Esa opción no está permitida""\n";
                cout << "Vuelve a intentarlo""\n";
            }
        }
        if (option == 1) {
            cout << "Te la has jugado y quiere seguir jugando""\n";
            turno = true;
            return true;

        }

        if (option == 2) {
            cout << "El " << character << " " << name << " se planta con " << puntosjugador << " puntos""\n";
            turno = false;
            return false;
        }

    }
    else if (puntosjugador == 21) {
        cout << pc << " dispone de 21 puntos.No puede pedir más""\n";
        turno = false;
        return false;
    }
    else if (puntosjugador > 21) {
        derrota = true;
        return true;
    }
}

int main() {
    Array(picas);
    Array(corazones);
    Array(diamantes);
    Array(treboles);
    srand(time(NULL));
    gameStart();
    firstRound();
    CardChoos(valorcartasplayer, puntospla, pla, player1);
    CardChoos(valorcartasplayer, puntospla, pla, player1);
    firstRoundcro();
    CardChoos(valorcartascroupier, puntoscro, cr, croupier);
    checkTurnOver(puntospla, player1, playerturn, playerlose, pla, player1);
    while (playerturn && !playerlose) {
        CardChoos(valorcartasplayer, puntospla, pla, player1);
        checkTurnOver(puntospla, player1, playerturn, playerlose, pla, player1);
    }
    if (playerlose) {
        cout << "El jugador " << player1 << " se ha pasado de 21. Ha perdido""\n";
        cout << "Pierdes " << dinero << " euros.""\n";
    }
    else if (!playerturn && !playerlose) {
        cout << "Ahora le tocara al croupier " << croupier << " intentar superarte. O en el caso que tengas 21 empatarte.""\n";
        cout << "El croupier tiene " << puntoscro << " puntos""\n";
        while (Croupierturn && !croupierlose) {
            CardChoos(valorcartascroupier, puntoscro, cr, croupier);
            cout << "El croupier tiene " << puntoscro << " puntos""\n";
            if (puntoscro<21 && puntoscro > puntospla) {
                Croupierturn = false;
                cout << "La banca te ha superado""\n";
                cout << "El jugador " << player1 << " ha perdido""\n";
                cout << "Pierdes " << dinero << " euros.""\n";

            }
            else if (puntoscro > 21) {
                croupierlose = true;
                cout << "La banca ha superado los 21""\n";
                cout << "El jugador " << player1 << " ha ganado""\n";
                cout << "Recibes " << (dinero * 2) << " euros.""\n";


            }
            else if (puntoscro == 21 && puntospla == 21) {
                Croupierturn = false;
                cout << "Los dos habéis sacado 21 es un empate.""\n";
                cout << "Recuperas los " << dinero << " euros.""\n";

            }
        }

    }

}
