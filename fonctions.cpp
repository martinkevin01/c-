#include <iostream>
#include <conio.h>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <cmath>

using namespace std;

void MenuPrincipal(){
cout<<" ============================== Menu Principal ==============================\n";
cout<<"\t A|a........Op"<<char(130)<<"ration de conversion Binaire ou Octal\n";
cout<<"\t\t 1.......Decimal en Binaire\n";
cout<<"\t\t 2.......Decimal en Octal\n";
cout<<"\t\t 3.......Revenir au menu principal\n";
cout<<"\t B|b........Op"<<char(130)<<"ration de conversion d'heure ou de seconde\n";
cout<<"\t\t 1.......Conversion secondes en heures/minutes/secondes\n";
cout<<"\t\t 2.......Conversion heures/minutes/secondes en secondes\n";
cout<<"\t\t 3.......Revenir au menu principal\n";
cout<<"\t C|c........Resoudre equation du second ordre\n";
cout<<"\t\t 1.......Resolution de l'equation \n";
cout<<"\t\t 2.......Revenir au menu principal\n";
cout<<"\t Q|q........Quitter le programme\n";
cout<<" ============================================================================\n\n";
}

void MenuHeure(){
cout<<"========= MENU CONVERSION HEURE/SECONDE========\n";
cout<<"\t 1.......Conversion secondes en heures/minutes/secondes\n";
cout<<"\t 2.......Conversion heures/minutes/secondes en secondes\n";
cout<<"\t 3.......Revenir au Menu Principal\n";
cout<<"=================================================\n\n";
}

void MenuCodage(){
cout<<"================== MENU CONVERSION BINAIRE/OCTAL ==================\n";
cout<<"\t 1.......Decimal en Binaire\n";
cout<<"\t 2.......Decimal en Octal\n";
cout<<"\t 3.......Revenir au Menu Principal\n";
cout<<"==================================================\n\n";
}

void MenusecondDegre(){
cout<<"============== Resoudre equation du second ordre ==============\n";
cout<<"\t 1.......Resolution de l'equation\n";
cout<<"\t 2.......Revenir au Menu Principal\n";
cout<<"=======================================================================\n\n";
}

void NettoyerEcran(){
    system("cls");
}

void Clean(){
cin.clear(); //pour effacer toutes les erreurs dans le flux et donc permettre à cin de faire son boulot par la suite
cin.seekg(0, ios::end); // On se positionne à la fin du buffer
if(!cin.fail()){
    cin.ignore(numeric_limits<streamsize>::max()); //pour vider entièrement le buffer
}
else{
    cin.clear();
}
}

void SecondeEnHeure(int time){
	int h,m,s;

    s=time;
	h = s/3600; //1 heure = 3600 secondes
	s = s%3600; //% : Le reste de division entiere
	m = s/60;   //1 minute = 60 secondes
	s = s%60;
	cout<<(h)<<" heures "<<(m)<<" minutes "<<(s)<<" secondes ";
	cout<<("\n");
}
void HeureEnSeconde(int h, int m, int s){
	int heure = h;
	int minute = m;
	int seconde =s;

    int time;
	time = heure * 3600; //1 heure = 3600 secondes
	time += minute * 60; //% : Le reste de division entiere
	time += seconde;
	cout<<"Le nombre de secondes est de: "<<(time)<<" secondes ";
	cout<<("\n\n");
}

int EntrerEntier(int *n){
string temp;

while(true){
    cout<<"Entrez le nombre de votre choix : ";
    cin>>temp;
    if(cin.eof() || cin.bad()){
        cerr<<"Une erreur interne est survenue."<<endl;
        if(cin.eof())
        {
        break;
        }
        Clean();
        continue;
    }

    else if(cin.fail() || temp.find_first_not_of("0123456789") != string::npos){
        cerr<<"Erreur, saisie incorrecte; vous n'avez pas saisi un entier."<<endl;
        Clean();
        continue;
    }

    istringstream stream(temp);
    stream>>*n;

    if(stream.fail() || !stream.eof()){
        cerr<<"Erreur, saisie incorrecte."<<endl;
    }
    else{
        break;
    }
}
}





void DecBinaire(long Dec){
vector<int> Bin;
while(Dec/2!=1){
    Bin.push_back(Dec%2);
    Dec/=2;
}
Bin.push_back(Dec%2);
Bin.push_back(Dec/2);

for(int i=(Bin.size()-1);i>=0;i--){
    cout<<Bin[i];
}
}

int EntrerBinaire(int *n){
string temp;

while(true){
    cout<<"Entrez un nombre binaire quelconque : ";
    cin>>temp;
    if(cin.eof() || cin.bad()){
        cerr<<"Une erreur interne est survenue."<<endl;
        if(cin.eof())
        {
        break;
        }
        Clean();
        continue;
    }

    else if(cin.fail() || temp.find_first_not_of("01") != string::npos){
        cerr<<"Erreur, saisie incorrecte."<<endl;
        Clean();
        continue;
    }

    istringstream stream(temp);
    stream>>*n;

    if(stream.fail() || !stream.eof()){
        cerr<<"Erreur, saisie incorrecte."<<endl;
    }
    else{
        break;
    }
}
}



void DecOctal(int Dec){
vector<int> Octal;
while(Dec/8!=0){
    Octal.push_back(Dec%8);
    Dec/=8;
}
Octal.push_back(Dec%8);


for(int i=(Octal.size()-1);i>=0;i--){
    cout<<Octal[i];
}
}



void EquationSecond(){
    // Declaration des variables
float a,b,c; // Les coefficient reels de l'equation
float x1,x2; // x1 et x2 sont les solutions de l'equation
// La solution unique sera stockee dans x1
float delta; // Le discriminant
// Presentation du programme
cout << "Recherche des solutions reelles d'une equation du second degre.";
cout << endl;
cout << "L'equation est : ax**2+bx+c = 0, avec a,b et c reels." << endl;
cout << endl;
// Saisie des donnees
cout << "Entrez la valeur de a : ";
cin >> a;
cout << "Entrez la valeur de b : ";
cin >> b;
cout << "Entrez la valeur de c : ";
cin >> c;
if (a == 0)
// On peut reprendre l'algorithme precedent
// ou considerer que l'utilisateur du programme a fait une erreur
cout << "Erreur ! Votre equation n'est pas du second degre." << endl;
else
{
delta = b*b - 4*a*c;
if (delta < 0)
cout << "Aucune solution reelle." << endl;
else
if (delta == 0)
{
x1 = -b/(2*a);
cout << "Une seule solution reelle : " << x1 << endl;
}
else // Cas ou delta > 0
{
x1 = (-b+sqrt(delta))/(2*a);
x2 = (-b-sqrt(delta))/(2*a);
cout << "Il y a deux solutions reelles." << endl;
cout << "Premiere solution reelle : " << x1 << endl;
cout << "Deuxieme solution reelle : " << x2 << endl;
}
}

}




