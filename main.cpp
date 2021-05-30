#include"fonctions.cpp"

int main(){
char choix1;
int choix2, choix3, choix4;

do{
    MenuPrincipal();
    cout<<"Choisissez l'une des options suivantes : ";
    cin>>choix1;
    switch(choix1){
         case 'A':
    case 'a':{
        NettoyerEcran();
        MenuCodage();
        cout<<"Entrer un nombre correspondant aux possibilit"<<char(130)<<"s du menu ci-dessus (1 "<<char(133)<<" 3)\n";
        do{
            EntrerEntier(&choix3);
        }while(choix3<1||choix3>3);
        switch(choix3){
            case 1: {
                NettoyerEcran();
                cout<<"================== Decimal EN BINAIRE ==================\n";
                int Entier;
                cout<<"Entrer un entier qui sera converti en binaire\n\n";
                EntrerEntier(&Entier); //appel de la fonction obligeant l'utilisateur à entrer des entiers
                cout<<endl;
                cout<<"Le nombre binaire correspondant est ";
                DecBinaire(Entier);
                cout<<"\n\n";
                 main();
            }break;

            case 2:{
                NettoyerEcran();
                cout<<"================== Decimal EN OCTAL ==================\n";
                int Entier;
                cout<<"Entrer un entier qui sera converti en octal\n\n";
                EntrerEntier(&Entier);
                cout<<endl;
                cout<<"Le nombre octal correspondant est ";
                DecOctal(Entier);
                cout<<"\n\n";
              main();

            }break;


            case 3:{
                NettoyerEcran();
                main();
            }
        }
    }break;

    case 'B':
    case 'b':{
        NettoyerEcran();
        MenuHeure();
        do{
            cout<<"Vous devez entrer soit 1, 2 ou 3.\n";
            cout<<"Faites votre choix : ";
            cin>>choix2;
            while(!cin>>choix2){
                cout<<"Incorrect. Vous n'avez pas saisi un entier.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<int>::max(), '\n');
            }
        }while(choix2<1||choix2>3);
        switch(choix2){

            case 1:{
                int time;
                NettoyerEcran();
                cout<<"========= Conversion secondes en heures/minutes/secondes ========\n";
                cout<<"Entrer le nombre de seconde\n";
                EntrerEntier(&time);
                SecondeEnHeure(time);
                main();
            }break;

            case 2:{
                int h;
                int m;
                int s;
                NettoyerEcran();
                cout<<"========= Conversion heures/minutes/secondes en secondes ========\n";
                cout<<" Entrer l'heure, les minutes et enfin les secondes\n";
                cin>>h;
                cin>>m;
                cin>>s;
                HeureEnSeconde(h,m,s);
                main();

            }break;

            case 3:{
                NettoyerEcran();
                main();
            }
        }
    }break;


    case 'C':
    case 'c':{
        NettoyerEcran();
        MenusecondDegre();
        do{
            cout<<"Entrer un nombre correspondant aux possibilit"<<char(130)<<"s du menu ci-dessus (1 "<<char(133)<<" 2)\n";
            cout<<"Choisissez l'une des options ci-dessus : ";
            cin>>choix3;
            while(!cin>>choix3){
                cout<<"Incorrect. Vous n'avez pas saisi un entier.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<int>::max(), '\n');
            }
        }while(choix3<1||choix3>4);
        switch(choix3){
            case 1:{
                NettoyerEcran();
                cout<<"============== SAISIE D'INFORMATIONS De L'EQUATION ==============\n";
                EquationSecond();
                 cout<<"\n\n Appuiyer sur une touche pour continuer\n";
                getch();

                main();
            }break;

            case 2:{
                NettoyerEcran();
                main();
            }
        }
    }break;
    case 'Q':
    case 'q':{
        NettoyerEcran();
        cout<<"\t Merci d'avoir utilis"<<char(130)<<" le programme.\n Au revoir..........\n";
        cout<<"Pressez n'importe quel bouton du clavier pour quitter.\n\n\n";
        return 0;
    }break;
    }
    getch();
    NettoyerEcran();
}while(choix1=='A'||choix1=='a'||choix1=='B'||choix1=='b'||choix1=='C'||choix1=='c'||choix1=='C'||choix1=='Q'||choix1=='q');
}
