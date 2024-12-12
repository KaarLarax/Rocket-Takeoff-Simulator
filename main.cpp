#include <iostream>
#include <cstdio>
#include <cmath>
#include <windows.h>
#include <limits>

using namespace std;

const int Combustible1 = 446200;
const int Combustible2 = 351000;
const int Combustible3 = 336900;

void portada();

void consola();

void menu();

void dibujo();

void velocidad(float);

void peso_max(float);

void combustible(float, const string&);

bool regresar();

float gravedad_planetas(string);

///    SetConsoleTextAttribute(hConsole, 10);

int main() {
    consola();
    portada();
    menu();
    return 0;
}

void portada() {
    cout << endl;
    cout << "\t    d8888b. d888888b d88888b d8b   db db    db d88888b d8b   db d888888b d8888b.  .d88b.  " << endl;
    cout << "\t    88  `8D   `88'   88'     888o  88 88    88 88'     888o  88   `88'   88  `8D .8P  Y8. " << endl;
    cout << "\t    88oooY'    88    88ooooo 88V8o 88 Y8    8P 88ooooo 88V8o 88    88    88   88 88    88 " << endl;
    cout << "\t    88~~~b.    88    88~~~~~ 88 V8o88 `8b  d8' 88~~~~~ 88 V8o88    88    88   88 88    88 " << endl;
    cout << "\t    88   8D   .88.   88.     88  V888  `8bd8'  88.     88  V888   .88.   88  .8D `8b  d8' " << endl;
    cout << "\t    Y8888P' Y888888P Y88888P VP   V8P    YP    Y88888P VP   V8P Y888888P Y8888D'  `Y88P'  " << endl
         << endl;
    Sleep(2000);
    cout << endl;
    cout << "\t\t\t\t|--------------------------------------------------|" << endl;
    cout << "\t\t\t\t|  ><<     ><<      ><       ><<<<<<<<><<     ><<  |" << endl;
    cout << "\t\t\t\t|  ><<     ><<     >< <<     ><<      ><<     ><<  |" << endl;
    cout << "\t\t\t\t|  ><<     ><<    ><  ><<    ><<      ><<     ><<  |" << endl;
    cout << "\t\t\t\t|  ><<     ><<   ><<   ><<   ><<<<<<  ><<<<<< ><<  |" << endl;
    cout << "\t\t\t\t|  ><<     ><<  ><<<<<< ><<  ><<      ><<     ><<  |" << endl;
    cout << "\t\t\t\t|  ><<     ><< ><<       ><< ><<      ><<     ><<  |" << endl;
    cout << "\t\t\t\t|    ><<<<<   ><<         ><<><<<<<<<<><<     ><<  |" << endl;
    cout << "\t\t\t\t|--------------------------------------------------|" << endl;
    cout << "\t\t\t\t|--- INSTITUTO DE CIENCIAS BÁSICAS E INGENIERÍA ---|" << endl;
    cout << "\t\t\t\t|---- LICENCIATURA EN CIENCIAS COMPUTACIONALES ----|" << endl;
    cout << "\t\t\t\t|------------ PROTOTIPO: PROYECTO FINAL -----------|" << endl;
    cout << "\t\t\t\t|---------- CARLOS  ALBERTO LARA HERNANDEZ --------|" << endl;
    cout << "\t\t\t\t|------------- SEMESTRE: PRIMERO GRUPO: 1 ---------|" << endl;
    cout << "\t\t\t\t|-----------     No.CUENTA: 476759      -----------|" << endl;
    cout << "\t\t\t\t|--------------------------------------------------|" << endl;
    cout << "\t\t\t\t    Presiona <enter> para continuar... ";
    getchar();
    system("cls");
}

void consola() {
    // Establecer el idioma a español
    setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para máquinas Linux
    SetConsoleCP(1252); // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252); // Cambiar STDOUT - Para máquinas Windows

    system("cls");
    system("color 05");
}

bool regresar() {
    char regresar;
    cout << endl << endl << "\t\t\t\t ¿Desea regresar al menú principal?" << endl;
    cout << "\t\t\t\t Presionar [Y] si es así" << endl;
    cin >> regresar;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (regresar == 'y' || regresar == 'Y') {
        cout << "\t\t\t Regresando" << endl;
        return true;
    }
    return false;
}

void menu() {
    char respuesta;
    float gravedad;
    string nombrePlaneta = "Tierra";
    bool errorOpcion;
    do {
        system("cls");
        dibujo();
        cout << endl << "\t\t\t Escribe el nombre del planeta sobre el que quieres hacer los calculos: ";
        cin >> nombrePlaneta;
        gravedad = gravedad_planetas(nombrePlaneta);
        if (gravedad == -1.00f) {
            cout << "\t\t\t Planeta inexistente, intente nuevamente." << endl;
        }
    } while (gravedad == -1.00f);
    cout << "\t\t\t Los cálculos se harán con la gravedad del planeta: " << nombrePlaneta << endl;
    Sleep(2000);
    do {
        errorOpcion = false;
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|------------------------- MENÚ DE SELECCIÓN --------------------------|" << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|----- V) Cálculo de velocidad necesaria máxima alcanzada         -----|" << endl;
        cout << "\t\t\t|----- M) Cálculo de peso máximo tolerable respecto a velocidad   -----|" << endl;
        cout << "\t\t\t|----- C) Cálculo de peso de la nave en distintos planetas        -----|" << endl;
        cout << "\t\t\t|----- S) Salir de programa                                       -----|" << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|Elige una opción: ";
        cin >> respuesta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (respuesta) {
            case 'V':
            case 'v':
                system("cls");
                velocidad(gravedad);
                break;
            case 'M':
            case 'm':
                system("cls");
                peso_max(gravedad);
                break;
            case 'C':
            case 'c':
                system("cls");
                combustible(gravedad, nombrePlaneta);
                break;
            case 'S':
            case 's':
                cout << "\t\t\t Programa creado por : Carlos Alberto Lara Hernandez" << endl;
                respuesta = 's';
                continue;
            default:
                cout << "\t\t\t El valor que ingresaste no es correcto." << endl;
                cout << "\t\t\t Favor de intentar de nuevo." << endl;
                errorOpcion = true;
        }
    } while (respuesta != 's' && (errorOpcion || regresar()));
}

float gravedad_planetas(string nombrePlaneta) {
    float gravedad; // Gravedad de la tierra por defecto
    for (char& c: nombrePlaneta) c = (char) tolower(c); // Cambia a minúsculas las letras del nombre del planeta
    if (nombrePlaneta == "venus" || nombrePlaneta == "urano") {
        gravedad = 8.87f;
    } else if (nombrePlaneta == "mercurio") {
        gravedad = 3.70f;
    } else if (nombrePlaneta == "tierra") {
        gravedad = 9.81f;
    } else if (nombrePlaneta == "marte") {
        gravedad = 3.71f;
    } else if (nombrePlaneta == "jupiter") {
        gravedad = 24.79f;
    } else if (nombrePlaneta == "saturno") {
        gravedad = 10.44f;
    } else if (nombrePlaneta == "neptuno") {
        gravedad = 11.15f;
    } else {
        gravedad = -1.00f;
        // No ingresó correctamente el planeta, se asignará automáticamente la Tierra
    }
    return gravedad;
}

void velocidad(float graF) {
    char resp, respCom;
    float masaNave, masaCombustible, masaExtra = 0, VelComb, t;
    cout << endl << "\t\t\t|------------------------------------------------------|" << endl;
    cout << "\t\t\t|--------------- CALCULO DE VELOCIDAD -----------------|" << endl;
    cout << "\t\t\t|------------------------------------------------------|" << endl;
    cout << "\t\t\t|Estos calculo se determinan por la 2da Ley de Newton" << endl;
    cout << "\t\t\t|para un sistema de masa variable: " << endl;
    cout << "\t\t\t|V = Vi - gt + u In|Mi/Mn|" << endl;
    cout << endl
         << " Para poder realizar el cálculo se necesita conocer la Masa de la nave y el tipo de Combustible que este usa."
         << endl;
    Sleep(3000);
    cout << endl << "\t\t\t -> Ingresa la masa de la NAVE (Toneladas): ";
    cin >> masaNave;
    while (true) {
        if (masaNave > 0) {
            break;
        } else {
            cout << endl << "\t\t\t Valor introducido no válido." << endl;
            cout << "\t\t\t -> Ingresa la masa de la NAVE (Toneladas): ";
            cin >> masaNave;
        }
    }
    cout << endl << "\t\t\t -> ¿La nave cuenta con tripulación y suministros? [Y/N] ";
    fflush(stdin);
    cin >> resp;
    while (true) {
        if (resp == 'Y' || resp == 'y' || resp == 'N' || resp == 'n') {
            break;
        } else {
            cout << endl << "\t\t\t Valor introducido no válido." << endl;
            cout << "\t\t\t -> ¿La nave cuenta con tripulación y suministros [Y/N]?";
            fflush(stdin);
            cin >> resp;
        }
    }
    if (resp == 'Y' || resp == 'y') {
        cout << endl << "\t\t\t Ingresa la masa de la tripulación junto con la de los suministros (Ton): ";
        cin >> masaExtra;
        while (true) {
            if (masaExtra > 0 || masaExtra > masaNave) {
                break;
            } else {
                cout << endl << "\t\t\t Valor introducido no válido." << endl;
                cout << "\t\t\t Ingresa la masa de la tripulación junto con la de los suministros (Ton): ";
                cin >> masaExtra;
            }
        }
    }

    masaNave = masaNave + masaExtra;
    masaCombustible = masaNave * 0.1f;
    cout << endl << "\t\t\t -> Elige uno de los 3 tipos de combustible usados en cohetes..." << endl;
    cout << "\t\t\t A) oxígeno líquido/hidrógeno líquido" << endl;
    cout << "\t\t\t B) oxígeno líquido/queroseno (RP-1)" << endl;
    cout << "\t\t\t C) tetróxido de dinitrógeno/hidrazina" << endl;
    fflush(stdin);
    cin >> respCom;
    while (true) {
        if (respCom == 'A' || respCom == 'a' || respCom == 'B' || respCom == 'b' || respCom == 'C' ||
            respCom == 'c') {
            break;
        } else {
            cout << endl << "\t\t\t Valor introducido no válido." << endl;
            cout << endl << "\t\t\t -> Elige uno de los 3 tipos de combustible usados en cohetes..." << endl;
            cout << "\t\t\t A) oxígeno líquido/hidrógeno líquido" << endl;
            cout << "\t\t\t B) oxígeno líquido/queroseno (RP-1)" << endl;
            cout << "\t\t\t C) tetróxido de dinitrógeno/hidrazina" << endl;
            fflush(stdin);
            cin >> respCom;
        }
    }
    if (respCom == 'A' || respCom == 'a') {
        VelComb = Combustible1;
        t = 455;
    } else if (respCom == 'B' || respCom == 'b') {
        VelComb = Combustible2;
        t = 358;
    } else {
        VelComb = Combustible3;
        t = 354;
    }

    cout << endl << "\t\t\t Una vez teniendo las masas, podemos realizar el cálculo..." << endl;
    cout << endl << "\t\t\t -> La velocidad necesaria para salir a la atmósfera es: "
         << 0 - (graF * t) + (VelComb * (log((masaNave + masaCombustible) / masaNave))) << " m/s" << endl;
}

void peso_max(float graF) {
    char resp;
    double M_nave, M_comb, MT_nave, M_ext = 0;
    cout << endl << "\t\t\t|------------------------------------------------------|" << endl;
    cout << "\t\t\t|----------------- CALCULO DE PESO  -------------------|" << endl;
    cout << "\t\t\t|------------------------------------------------------|" << endl;
    cout << endl << "\t\t\t Estos calculo se determinan por la 2da Ley de Newton para un sistema de masa variable." << endl;
    cout << endl << "\t\t\t Para poder realizar el cálculo se necesita conocer la Masa Total de la nave." << endl;
    Sleep(3000);

    cout << endl << "\t\t\t -> Ingresa la Masa Total de la NAVE (Toneladas): ";
    cin >> M_nave;
    while (true) {
        if (M_nave > 0) {
            break;
        } else {
            cout << endl << "\t\t\t Valor introducido no válido." << endl;
            cout << "\t\t\t -> Ingresa la Masa Total de la NAVE (Toneladas): ";
            cin >> M_nave;
        }
    }
    cout << endl << "\t\t\t -> ¿La nave cuenta con tripulación y suministros? [Y/N] ";
    fflush(stdin);
    cin >> resp;
    while (true) {
        if (resp == 'Y' || resp == 'y' || resp == 'N' || resp == 'n') {
            break;
        } else {
            cout << endl << "\t\t\t Valor introducido no válido." << endl;
            cout << "\t\t\t -> ¿La nave cuenta con tripulación y suministros? [Y/N] ";
            fflush(stdin);
            cin >> resp;
        }
    }
    if (resp == 'Y' || resp == 'y') {
        cout << endl << "\t\t\t Ingresa la masa de la tripulación junto con la de los suministros (Ton): ";
        cin >> M_ext;
        while (true) {
            if (M_ext > 0 || M_ext > M_nave) {
                break;
            } else {
                cout << endl << "\t\t\t Valor introducido no válido." << endl;
                cout << "\t\t\t Ingresa la masa de la tripulación junto con la de los suministros (Ton): ";
                cin >> M_ext;
            }
        }
    }

    MT_nave = M_nave + M_ext;
    M_comb = M_nave * 0.1;

    cout << endl << "\t\t\t Considerando la gravedad de: " << graF << "m/s^2." << endl;
    cout << endl << "\t\t\t -> La nave, contando con tripulación, suministros y combustible, pesaría: "
         << (MT_nave + M_comb) * graF << " Toneladas." << endl;
    cout << endl << "\t\t\t -> El peso Total de solo la nave, sería: " << M_nave * graF << " Toneladas." << endl;

}

void combustible(float graF, const string& nombrePlaneta) {
    float mNave, mComb, litros;
    cout << endl << "\t\t\t|------------------------------------------------------|" << endl;
    cout << "\t\t\t|---------- CALCULO DE COMBISTIBLE NECESARIO ----------|" << endl;
    cout << "\t\t\t|------------------------------------------------------|" << endl;
    cout << "\t\t\t|Estos calculo se determinan por la 2da Ley de Newton " << endl;
    cout << "\t\t\t|para un sistema de masa variable." << endl;
    cout << "\t\t\t|Para poder realizar el cálculo se necesita conocer " << endl;
    cout << "\t\t\t|la Masa de la nave." << endl;
    Sleep(2000);
    cout << "\t\t\t|-> Ingresa la masa de la NAVE (Toneladas): ";
    fflush(stdin);
    cin >> mNave;
    while (true) {
        if (mNave > 0) {
            break;
        } else {
            cout << endl << "\t\t\t Valor introducido no válido." << endl;
            cout << "\t\t\t -> Ingresa la masa de la NAVE (Toneladas): ";
            fflush(stdin);
            cin >> mNave;
        }
    }

    mComb = mNave * 0.1f;
    litros = mComb * graF;

    cout << endl << "\t\t\t La Masa del combustible respecto a la nave es (10%): " << mComb << " Toneladas." << endl;
    cout << "\t\t\t Contando con que la gravedad es: " << graF << " m/s^2 entonces..." << endl;
    cout << "\t\t\t En el planeta " << nombrePlaneta << " se requeririan de: " << litros << " litros. " << endl;
}

void dibujo() {
    cout << "\t\t\to               .        ___---___                    .       " << endl;
    cout << "\t\t\t       .              .--\\        --.     .     .         .  " << endl;
    cout << "\t\t\t                    ./.;_.\\     __/~ \\.                     " << endl;
    cout << "\t\t\t                   /;  / `-'  __\\    . \\                    " << endl;
    cout << "\t\t\t .        .       / ,--'     / .   .;   \\        |           " << endl;
    cout << "\t\t\t                 | .|       /       __   |      -O-       .   " << endl;
    cout << "\t\t\t                |__/    __ |  . ;   \\ | . |      |           " << endl;
    cout << "\t\t\t                |      /  \\\\_    . ;| \\___|                " << endl;
    cout << "\t\t\t   .    o       |      \\  .~\\\\___,--'     |           .    " << endl;
    cout << "\t\t\t                 |     | . ; ~~~~\\_    __|                   " << endl;
    cout << "\t\t\t    |             \\    \\   .  .  ; \\  /_/   .              " << endl;
    cout << "\t\t\t   -O-        .    \\   /         . |  ~/                   . " << endl;
    cout << "\t\t\t    |    .          ~\\ \\   .      /  /~          o          " << endl;
    cout << "\t\t\t  .                   ~--___ ; ___--~                         " << endl;
    cout << "\t\t\t                 .          ---         .                     " << endl;
}