#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>

struct ConfigLigue {
    std::string NomDeLaLigue;  // Nombre de la liga
    int vic, matnul, def; // Victoria, Empate y Derrota
    std::vector<std::string> Equipes; // Equipos
};


ConfigLigue LireConfig(){
    std::ifstream Iconfig("../data/config.txt");
    ConfigLigue config;
    std::string v;
    if(Iconfig.is_open()){
        std::cout << "Se ha leido correctamente el archivo \n";
        while(std::getline(Iconfig , v)){
            if(v.empty() || v[0] == '#'){
                 continue;
            }

            std::string cle, valeur; // clave, valor
            std::stringstream ss(v); //stringstream se usa para separar partes de un string

            std::getline(ss , cle , '=');
            std::getline(ss, valeur);

            if(cle == "Liga"){
                config.NomDeLaLigue = valeur;
            }else if(cle == "Victoria"){
                config.vic = std::stoi(valeur); // stoi() se usa para convertir un string en un numero entero
            }else if(cle == "Empate"){
                config.matnul = std::stoi(valeur);
            }else if(cle == "Derrota"){
                config.def = std::stoi(valeur);
            }else if(cle == "equipo"){
                config.Equipes.push_back(valeur); // vector.push_back es para agregar un valor al final de un vector. 
            }

            Iconfig.close();
            return config;

        }
    } else{
    std::cout << "Hubo un error al abrir el archivo";
    std::cout <<  '\a';
    exit(1);
    }
}

void LireFechas(){

}

void LirePartidos(){
    
}

void RecevoirParti(){

}

void RecevoirJournee(){

}



int InfoMenu(std::string NomDeLaLigue){
    
    int opt;

    std::cout << "\n *|" << NomDeLaLigue<< "|* \n";
    std::cout << "1. Ver tabla de posiciones. \n";
    std::cout << "2. Registrar resultado de un partido. \n";
    std::cout << "3. Ver historial de jornadas. \n";
    std::cout << "4. Ver todos los partidos jugados. \n";
    std::cout << "5. Salir del programa. \n";
    std::cout << "Por favor indique su opcion: ";
    std::cin >> opt;

    return opt;

   
}

int menu(){
     ConfigLigue config = LireConfig();

     int opt;

    
    do{
        opt = InfoMenu(config.NomDeLaLigue);
        switch(opt){
            case 1:{
                std::cout << "Has elegido ver la tabla de posiciones. \n";
                break;
            }
            case 2:{
                std::cout << "Has elegido registrar un resultado de un partido. \n";
                break;
            }
            case 3:{
                std::cout << "Has elegido ver el historial de jornadas. \n";
                break;
            }
            case 4:{
                std::cout << "Has elegido ver los partidos jugados. \n";
                break;
            }
            case 5:{
                std::cout << "Has salido del programa. \n";
                break;
            }
            default:{
                std::cout << "Opcion no valida/Error al elegir un valor. \n";
                break;
            }
        }
       
    } while(opt != 5);

}

int main(){
    menu();
    return 0;
}