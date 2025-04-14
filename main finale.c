#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

// Structure contenant tous les informations nécessaires de l'utilisateur pour créer leur compte.
typedef struct info_personnelles{
    char nom[15];
    char prenom[15];
    char nationalite[10];
    char email[50];
    char m_passe1[9];
    char m_passe2[9];
    int destination;
}perso;

// Définition de la structure pour une activité
typedef struct {
    char activite[100];
    char details[200];
} Activite;

// Définition de la structure pour une journée
typedef struct {
    char jour[20];
    Activite* activites;
    int nbActivites;
} Journee;

// Structure pour représenter un hôtel
typedef struct Hotel {
    char nom[50];
    float prix;
    int note;
    char theme[50];
}Hotel;

//Les prototypes de fonctions
void verification_m_passe(perso utilisateur);
void afficherCalendrier(int mois, int annee);
void affichage_ville();
void choix_periode();
void afficherhotel(Hotel hotel);
void suggestions_marrakech();
void suggestions_agadir();
void detailsMarrakech();
void detailsAgadir();
void color(int t,int f);
void plannification_semaine();
void attendreSecondes(int secondes);


int main()
{
    int i, choix, choix_ville, jourDebut, jourFin, moisDebut, moisFin, detail,nblieu;
    int nbJourneesParSemaine = 7;
    int annee = 2024; // Année 2024
    float prixmax, prixmin, nb;
    char hotel_choisi[40];
    char jours_semaine[7][20] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    perso utilisateur;

    Journee journees[] = {
        {"Lundi", NULL, 0},
        {"Mardi", NULL, 0},
        {"Mercredi", NULL, 0},
        {"Jeudi", NULL, 0},
        {"Vendredi", NULL, 0},
        {"Samedi", NULL, 0},
        {"Dimanche", NULL, 0}
    };
    int nbJournees = sizeof(journees) / sizeof(journees[0]);
    Hotel hotels1[13] = {
      {"Riad Aymane", 985,4, "Traditionnel"},
      {"Riad Bayti", 952,4, "Traditionnel"},
      {"Riad Dama & Spa", 1840,4, "Traditionnel"},
      {"Riad Ekla Boutique Hotel", 697,4, "Traditionnel"},
      {"H\223tel Royal Mirage Deluxe",793,5, "Moderne"},
      {"RAWABI Hotel & SPA MARRAKECH",425,4, "Moderne"},
      {"H\223tel Oudaya & Spa",512,3, "Moderne"},
      {"Zephyr Marrakech - H\223tel, Centre de Vacances, Resort & SPA",616,4, "Moderne"},
      {"H\223tel Atlas",324,3, "Moderne"},
      {"H\223tel Toulousain",414,3, "Moderne"},
      {"H\223tel Medina",167,2, "Moderne"},
      {"H\223tel Ichbilia",397,2, "Moderne"},
      {"Riad Salman",831, 3, "Traditionnel & Moderne"},

  };
    Hotel hotels2[14] =
    {
      {"H\223tel Timoulay and Spa Agadir", 895.90, 4, "Moderne"},
      {"Tikida Golf Palace", 1623.40, 5, "Moderne"},
      {"Iberostar Founty Beach", 2022.11, 4, "Moderne"},
      {"Bahia City Hotel", 203, 3, "Moderne"},
      {"HAMILTON Agadir", 340, 4, "Moderne"},
      {"Omega Hotel", 214, 3, "Moderne"},
      {"The View Agadir", 118.511, 5, "Moderne"},
      {"Appart-Hotel Tagadirt", 353, 3, "Moderne"},
      {"Anezi Tower Hotel", 519, 4, "Moderne"},
      {"H\223tel Ibis Budget Agadir", 384, 4, "Moderne"},
      {"Riad Les Chtis d'Agadir", 615, 3, "Traditionnel"},
      {"Riad Asmaa Agadir", 1678, 4, "Traditionnel & Moderne"},
      {"Riad Palmi magnifique Riad centre ville", 1623, 4, "Traditionnel & Moderne"},
      {"Keriad - Magnifique Riad - Rooftop", 1860, 4, "Traditionnel"},
  };
    // Introduction du programme
    color(3,0);
    printf("\t\t\t\t======================================================\n");
    printf("\t\t\t\t\t Bienvenue dans notre guide touristique \n");
    printf("\t\t\t\t======================================================\n\n\n");
    color(15,0);
    color(14,0);
    printf("\t\t\t---------------------------------------------------------------------------------\n\n");
    printf("\t\t\t  Nous sommes ravis de vous accueillir dans votre guide touristique \2.\n\n");
    printf("\t\t\tNous somme l%c pour vous aider %c savoir plus sur votre destination et cr%cer \n\t\t\tvotre propre plan cotenant les %cv%cnements que vous voulez faire lors de votre\n",133,133,130,130,130);
    printf("\t\t\t         voyage au cours de mois Juillet et Ao%ct de l'ann%ce 2024. \n\n",150,130);
    printf("\t\t\t---------------------------------------------------------------------------------\n\n\n");
    color(15,0);
    printf("\t\t\tD'abord cr%cez votre compte s'il vous pla%ct en remplissant les informations suivantes: \n\n", 130, 140);


    // Saisie des informations personnelles de l'utilisateur
    printf("\20 Nom : ");
    gets(utilisateur.nom);
    printf("\n\20 Pr%cnom: ", 130);
    gets(utilisateur.prenom);
    printf("\n\20 Nationalit%c : " ,130);
    scanf("%s" , utilisateur.nationalite);
    printf("\n\20Le domaine de votre email est de type : 1- @gmail   2- @Outlook   3- @Yahoo   4- Autre\n");
    printf("\n  Votre choix : ");
    scanf("%d", &choix);

    // Saisie de l'email en fonction du domaine choisi
    while(choix > 4){
            printf("Votre choix est erron%c. Entrez de nouveau votre choix s'il vous pla%ct: ", 130, 140);
            scanf("%d", &choix);
    }
    switch(choix){
        case 1:
            printf("\n\20 Le nom d'utilisateur : ");
            scanf("%s", utilisateur.email);
            printf("\nVotre %cmail est comme suit : %s%cgmail.com.\n", 130, utilisateur.email, 64);
            break;
        case 2:
            printf("\n\20 Le nom d'utilisateur : ");
            scanf("%s", utilisateur.email);
            printf("\nVotre %cmail est comme suit : %s%coutlook.com.\n", 130, utilisateur.email, 64);
            break;
        case 3:
            printf("\n\20 Le nom d'utilisateur : ", 130);
            scanf("%s", utilisateur.email);
            printf("\nVotre %cmail est comme suit : %s%cyahoo.com.\n", 130, utilisateur.email, 64);
            break;
        default:
            printf("\nEntrez votre %cmail s'il vous pla%ct : ", 130, 140);
            scanf("%s", utilisateur.email);
            printf("\nVotre %cmail est comme suit : %s.\n", 130, utilisateur.email, 64);
            break;
    }

    printf("\n\20Mot de passe (Maximum 8 caract%cres et sans espaces) : ", 138);
    scanf("%s", utilisateur.m_passe1);

    // Vérification de mot de passe.
    verification_m_passe(utilisateur);
    color(2,0);
    printf("\t\t\t\t\tVotre compte a %ct%c cr%c%c avec succ%cs!\n\n", 130, 130, 130, 130, 138);
    color(15,0);
    printf("\t\t\t\t   Patientez quelques secondes s'il vous pla%ct...\n", 140);
    attendreSecondes(2);
    printf("\n");
    color(3,0);
    printf("\t\t\t\t\t---------------------------------------\n");
    printf("\t\t\t\t\t\t    Bonjour %s %s\n", utilisateur.prenom, utilisateur.nom);
    printf("\t\t\t\t\t---------------------------------------\n\n");
    color(15,0);

    // Affichage du calendrier pour les mois de juillet et août de l'année 2024
    printf("\t\t\t\t     Voil%c les mois disponibles %c notre service.\n\n", 133, 133);
    afficherCalendrier(7, annee);
    afficherCalendrier(8, annee);


    // Choix de la période pour les activités touristiques
    choix_periode();

    // Demande de l'utilisateur de choisir de ces destinations ci-dessous.
    printf("\t  Voici les destinations disponibles %c notre service :\n\n",133);
    affichage_ville();
    do {
            printf("\n\n  \20Veuillez saisir votre choix en tapant (1) pour Marrakech ou (2) pour Agadir : ");
            scanf("%d", &choix);


            if (choix != 1 && choix != 2) {
                color(4,0);
                printf("Merci de rentrer un choix valide : ");
                color(15,0);

            // Nettoyage du flux d'entrée pour éviter les boucles infinies
            }
            } while (choix != 1 && choix != 2);
    switch(choix){

        //La destination est Marrakech
        case 1:

          // do-while pour entrer des choix valides

          color(10,0);
          printf("\n\n\t\t\t\t\t****Super! Votre destination est Marrakech!****\n\n\n");
          color(8,0);
          printf("\t\t\tMarrakech, surnomm%ce 'la perle du sud' est une ville fascinante au Maroc r%cput%ce pour sa m%cdina\n", 130, 130, 130, 130);
          printf("\t\t\thistorique, ses souks  et anim%c ses palais somptueux et sa c%cl%cbre place Jemaa el Fna, c'est un\n", 130, 130, 130);
          printf("\t\t\tv%critable m%clange de cultures et d'architecture de traditions offrant une exp%criance sensorielle\n",130,130,130);
          printf("\t\t\t\t\t\tinoubliable pour les visiteurs. \n\n\n");
          color(15,0);
          // Demander à l'utilisateur de saisir un prix minimum et un prix maximum
          printf(" Entrez s'il vous pla%ct l'intervalle du prix que vous souhaitez que les h%ctels seront dans cet intervalle.\n\n", 140, 147);
          printf("  \20Entrez le prix minimum que vous souhaitez payer en DH: ");
          scanf("%f", &prixmin);
          printf("  \20Entrez le prix maximum que vous souhaitez payer en DH: ");
          scanf("%f", &prixmax);
          while(prixmax<prixmin){
            printf(" S'il vous plait entrer un prix maximale\n");
            scanf("%f", &prixmax);
          }

          // Affichage des hôtels disponibles dans Marrakech en respectant l'intervalle des prix séléctionnés
          for(i = 0; i < 13; i++){
                if (hotels1[i].prix >= prixmin && hotels1[i].prix <= prixmax) {
                    int nbhotels = sizeof(hotels1) / sizeof(Hotel);
                    afficherHotel(hotels1[i]);
                }
            }
          printf("  Veuillez choisir s'il vous pla%ct l'h%ctel convenable %c votre s%cjour en mentionnant le nom d'h%ctel: ", 140, 147, 133, 130, 147);
          scanf("%s", hotel_choisi);
          FILE *hotel1 = fopen("activites.txt", "a");
          if (hotel1 != NULL) {
          fprintf(hotel1, "\n\n\n\t\t\tLe nom de l'Hotel est: %s", hotel_choisi);
          color(2,0);
          printf("\n Sauvegarde de l'h%ctel avec succ%cs!\n\n",147,138);
          color(15,0);
          fclose(hotel1);
            } else {
                printf(" Echec de l'ouverture du fichier\n\n");
            }
          printf("\n Nous esp%crons que nous vous avons aid%c %c prendre la d%ccision sur le choix d'h%ctel voulu.\n", 130, 130, 133, 130, 147);

          printf("   Le tableau suivant contient les lieux que vous pouvez visiter lors de votre voyage %c Marrakech :\n\n", 133);
          //Afficher les suggestions des activités à Marrakech
          suggestions_marrakech();

         // DETAILS DES LIEUX A MARRAKECH
          printf("  Si vous voulez plus de d%ctails taper 1, sinon taper 0: ",130);
          scanf("%d",&detail);
          if(detail==1){
            detailsMarrakech();
          }
          else{
            printf("\n");
          }
          int condition;
          printf("  Si vous souhaitez voir les activit%cs que vous pouvez faire %c Marrakech, appuyez sur 1, sinon appuyez sur 0: ",130,133);
          scanf("%d",&condition);
          if (condition == 1)
            detailsMarrakech();
          else
            break;
          plannification_semaine();

        //La destination est Agadir
        case 2:
          color(10,0);
          printf("\n\n\t\t\t\t\t****Super! Votre destination est Agadir!****\n\n\n");
          color(8,0);
          printf("\t\t\tAgadir, est une destination baln%caire pris%ce pour son ambiance d%ccontract%ce et ses paysages cotiers \n",130,130,130,130);
          printf("\t\t\tenchanteurs. La ville offre %cgalement une palette culturelle riche et les restaurants locaux invitent \n",130);
          printf("\t\t\t%c d%ccouvrir les d%clices de la cuisine marocaine. Pour les amateurs de sensations fortes, Agadir est \n",133,130,130);
          printf("\t\t\t  %cgalement un point de d%cpart id%cal pour explorer les tr%csors naturels et culturels de la r%cgion. \n\n\n",130,130,130,130,130);
          color(15,0);

          // Demander à l'utilisateur de saisir un prix minimum et un prix maximum
          printf(" Entrez s'il vous pla%ct l'intervalle du prix que vous souhaitez que les h%ctels seront dans cet intervalle.\n\n", 140, 147);
          printf("  \20Entrez le prix minimum que vous souhaitez payer en DH: ");
          scanf("%f", &prixmin);
          printf("  \20Entrez le prix maximum que vous souhaitez payer en DH: ");
          scanf("%f", &prixmax);
          while(prixmax<prixmin){
            color(4,0);
            printf(" S'il vous plait entrer un prix maximale\n");
            color(15,0);
            scanf("%f", &prixmax);
          }

          // Affichage des hôtels disponibles dans Agadir en respectant l'intervalle des prix séléctionnés
          for(i = 0; i < 14; i++){
                if (hotels2[i].prix >= prixmin && hotels2[i].prix <= prixmax) {
                    int nbhotels = sizeof(hotels1) / sizeof(Hotel);
                    afficherHotel(hotels2[i]);
                }
            }
          printf("  Veuillez choisir s'il vous pla%ct l'h%ctel convenable %c votre s%cjour en mentionnant le nom d'h%ctel: ", 140, 147, 133, 130, 147);
          scanf("%s", hotel_choisi);
          FILE *hotel2 = NULL;
          hotel2 = fopen("activites.txt", "a");
          if (hotel2 != NULL) {
          fprintf(hotel2, "\n\n\n\t\t\tLe nom de l'Hotel est: %s", hotel_choisi);
          color(2,0);
          printf("\nSauvegarde de l'h%ctel avec succ%cs!\n\n",147,138);
          color(15,0);
          fclose(hotel2);
            } else {
                color(4,0);
                printf("Echec de l'ouverture du fichier\n\n");
                color(15,0);
            }
          printf("\nNous esp%crons que nous avons aid%c vous %c prendre la d%ccision sur le choix d'h%ctel voulu.\n", 130, 130, 133, 130, 147);


          printf("Le tableau suivant contient les lieux que vous pouvez visiter lors de votre voyage %c Agadir :\n", 133);
          //Afficher les suggestions des activités à agadir
          suggestions_agadir();

          // Detail des lieux a agadir
          printf("  Si vous voulez plus de d%ctails taper 1, sinon taper 0: ",130);
          scanf("%d",&detail);
          if(detail==1){
            detailsAgadir();
          }
          else{
            printf("\n");
          }

          // Demande à l'utilisateur de saisir le nombre de semaines
          printf("  Si vous souhaitez voir les activit%cs que vous pouvez faire %c Marrakech, appuyez sur 1, sinon appuyez sur 0: ",130,133);
          scanf("%d",&condition);
          if (condition == 1)
            detailsAgadir();
          else
            break;
          plannification_semaine();
          printf("  Merci de donner toutes les activit%cs que vous souhaitez faire durant votre s%cjour. Si vous n'avez aucune veuillez tapez 0.\n", 130, 130, 130, 130);


        default:
            printf("Veuillez saisir un choix valid%c.\n", 130);
            break;
    }

    return 0;
}



void verification_m_passe(perso utilisateur){
    // Boucle qui vérifie si le mot de passe est en plus 8 caractères ou non.
    if(strlen(utilisateur.m_passe1) >= 9){
            do{
                printf("\nLe mot de passe d%cpasse 8 caract%cres.\nEntrez %c nouveau votre mot de passe s'il vous pla%ct: ", 130, 138, 133, 140);
                scanf("%s", utilisateur.m_passe1);

                printf("\n\20Confirmez s'il vous pla%ct votre mot de passe : ", 140);
                scanf("%s", utilisateur.m_passe2);
                // Boucle qui assure que la confirmation est identique au mot de passe.
                while(strcmp(utilisateur.m_passe1, utilisateur.m_passe2) != 0){
                        printf("Mot de passe est erron%c.\nV%crifiez s'il vous pla%ct la confirmation du mot de passe : ", 130, 130, 140);
                        scanf("%s", utilisateur.m_passe2);
                    }
                }while(strlen(utilisateur.m_passe1) >= 9);
    }
    else if(strlen(utilisateur.m_passe1) < 9){
            printf("\n\20Confirmez s'il vous pla%ct votre mot de passe : ", 140);
            scanf("%s", utilisateur.m_passe2);

            while(strcmp(utilisateur.m_passe1, utilisateur.m_passe2) != 0){
                    printf("Mot de passe est erron%c.\nV%crifiez s'il vous pla%ct la confirmation du mot de passe : ", 130, 130, 140);
                    scanf("%s", utilisateur.m_passe2);
                }
        }
   color(2,0);
   printf("\nLa confirmation est valid%ce!\n", 130);
   color(15,0);
}

// Fonction pour afficher le calendrier mensuel
void afficherCalendrier(int mois, int annee) {
    int joursDansMois;

    // Détermination du nombre de jours dans le mois
    switch (mois) {
        case 7:
            joursDansMois = 31;
            break;
        case 8:
            joursDansMois = 31;
            break;
        default:
            printf("Mois invalide\n");
            return;
    }

    // Affichage de l'en-tête du calendrier
    printf("\n\tCalendrier pour %d/%d\n", mois, annee);
    printf(" Lun  Mar  Mer  Jeu  Ven  Sam  Dim\n");

    // Déterminer le jour de la semaine où commence et finit le mois
    int jourDebut, jourFin;
    if (mois == 7) {
        jourDebut = 1; // Lundi
        jourFin = 3; // Mercredi
    } else if (mois == 8) {
        jourDebut = 4; // Jeudi
        jourFin = 6; // Samedi
    }

    // Boucle pour afficher les jours du mois
    int jourCourant = 1;
    for (int semaine = 1; semaine <= (joursDansMois + jourDebut - 1) / 7 + 1; semaine++) {
        // Boucle pour chaque jour de la semaine
        for (int jour = 1; jour <= 7; jour++) {
            // Si c'est avant le début du mois ou après la fin, afficher un espace
            if ((semaine == 1 && jour < jourDebut) || (semaine == (joursDansMois - jourCourant) / 7 + 1 && jour > jourFin)) {
                printf("     ");
            } else if (jourCourant <= joursDansMois) {
                printf("%4d ", jourCourant);
                jourCourant++;
            }
            // Si c'est dimanche, passer à la ligne
            if (jour == 7)
                printf("\n");
        }
    }
}

void choix_periode(){
    // Choix de période de voyage
    int jourDebut, jourFin, moisDebut, moisFin;
    printf("\n\n-Choisissez le premier jour de votre voyage s'il vous pla%ct (entre 1 et 31) : ", 140);
    scanf("%d", &jourDebut);
    while (jourDebut < 1 || jourDebut > 31) {
        printf("Jour de d%cbut invalide! Vous avez saisi une valeur illogique.\n", 130);
        printf("Le premier jour : ");
        scanf("%d", &jourDebut);
    }

    printf("\n--Merci de choisir le mois de d%cbut (7 pour juillet, 8 pour ao%ct) : ", 130, 150);
    scanf("%d", &moisDebut);
    while (moisDebut != 7 && moisDebut != 8) {
        printf("\nMois de d%cbut invalide! V%crifiez si vous avez saisi un mois diff%crent de mois 7 et 8.\n", 130, 130, 130);
        printf("Le mois de d%cbut : ", 130);
        scanf("%d", &moisDebut);
    }

    printf("\n-Le dernier jour de votre voyage s'il vous pla%ct (entre 1 et 31) : ", 140);
    scanf("%d", &jourFin);
    while (jourFin < 1 || jourFin > 31) {
        printf("Jour de fin invalide! Vous avez saisi une valeur illogique\n");
        printf("Le dernier jour : ");
        scanf("%d", &jourFin);
    }

    printf("\n--Et merci de saisir le mois de fin (7 pour juillet, 8 pour ao%ct) : ", 150);
    scanf("%d", &moisFin);
    while (moisFin != 7 && moisFin != 8) {
        printf("Mois de fin invalide! V%crifiez si vous avez saisi un mois diff%crent de mois 7 et 8.\n", 130, 130);
        printf("Le mois de fin : ");
        scanf("%d", &moisFin);
    }
    // Boucle qui assure que le choix de mois de début et mois de fin est logique
    while(moisDebut > moisFin || moisDebut != 7 && moisDebut != 8 && moisFin != 7 && moisFin != 8){
        printf("Le mois de d%cbut est sup%crieur au mois de fin! V%crifiez s'il vous pla%ct votre choix de mois.\n", 130, 130, 130, 140);
        printf("Le mois de d%cbut : ", 130);
        scanf("%d", &moisDebut);
        printf("Le mois de fin : ");
        scanf("%d", &moisFin);
    }
    color(2,0);
    printf("\n\n\n\t\t\tLes activit%cs touristiques planifi%ces seront entre le %d/%d/2024 et le %d/%d/2024.\n\n\n", 130, 130, jourDebut, moisDebut, jourFin, moisFin);
    color(15,0);
    FILE *date = NULL;
    date = fopen("activites.txt", "w");
    if (date != NULL) {
        color(3,0);
        printf("Sauvegarde de la date avec succ%cs dans le fichier activites!\n\n",138);
        color(15,0);
        fprintf(date, "\n\n\n\t\t\tLes activités touristiques planifiées seront entre le %d/%d/2024 et le %d/%d/2024.\n\n\n", jourDebut, moisDebut, jourFin, moisFin);
        fclose(date);
    } else {
        printf("Echec de l'ouverture du fichier\n\n");
    }
}
// Fonction qui permet d'afficher les hôtels selon les prix sélectionnés par l'utilisateur
void afficherHotel(Hotel hotel) {
      color(3,0);
      printf("\t\t    ============================================================\n");
      printf("\n\t\t\tNom: %s\n", hotel.nom);
      printf("\t\t\tPrix: %f MAD\n", hotel.prix);
      printf("\t\t\tNote: %d/5\n", hotel.note);
      printf("\t\t\tTheme: %s\n", hotel.theme);
      printf("\t\t    ============================================================\n");
      printf("\n");
      color(15,0);
}

void affichage_ville(){
    color(14,0);
    printf("\t\t\t\t\t\t\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\n");
    printf("\t\t\t\t\t\t\20 1:   Marrakech  \21\n");
    printf("\t\t\t\t\t\t\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\n");
    printf("\t\t\t\t\t\t\20 2:   Agadir     \21\n");
    printf("\t\t\t\t\t\t\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\n");
    color(15,0);
}

void suggestions_marrakech(){
    color(3,0);
    printf("\t\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t\t \20      1 -> Place Jamaa el fna            \21\n");
    printf("\t\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t\t \20      2 -> La Mosque Koutoubia           \21\n");
    printf("\t\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t\t \20      3 -> Jardin Majorelle              \21\n");
    printf("\t\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t\t \20      4 -> Palais de la Bahia            \21\n");
    printf("\t\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t\t \20      5 -> Jardin de la M%cnara           \21\n",130);
    printf("\t\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t\t \20      6 -> Palais El badi                \21\n");
    printf("\t\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n\n");
    color(15,0);
}

void suggestions_agadir(){
    color(3,0);
    printf("\n\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      1 -> Visite de la plage                      \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      2 -> Excursion dans les montagnes            \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      3 -> Exploration du souk                     \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      4 -> Degustation de plats locaux             \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      5 -> Excursion dans la vallee du Paradis     \21\n",130);
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      6 -> Visite de la Kasbah d'Agadir Oufella    \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      7 -> Séance de surf                          \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      8 -> Observation d'un spectacle des dauphins \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20      9 -> Promenade dans les jardins d'Olhao      \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20     10 -> Visit des Hemmams traditionnels         \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20     11 -> Festival Rap / Fusion                   \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20     12 -> Festival Aheouach                       \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n");
    printf("\t\t\t\t \20     13 -> Festival Fashion Agadir                 \21\n");
    printf("\t\t\t\t \20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21 \n\n");
    color(15,0);
}

void detailsMarrakech(){
    color(3,0);
    printf("\t\t\t\t  |=====================================================================================|\n");
    printf("\t\t\t\t  |La place de Jemaa el-Fna est un lieu majeur d'%cchanges culturels et b%cn%cficie d'une  |\n",130,130,130);
    printf("\t\t\t\t  |protection depuis 1922 au titre d'%cl%cment du patrimoine artistique du Maroc.         |\n",130,130);
    printf("\t\t\t\t  |=====================================================================================|\n");
    printf("\t\t\t\t  |la Mosqu%ce Koutoubia est le plus grand %cdifice religieux de la ville. Lieu de culture|\n",130,130);
    printf("\t\t\t\t  |d'histoire et de spiritualit%c.                                                       |\n",130);
    printf("\t\t\t\t  |=====================================================================================|\n");
    printf("\t\t\t\t  |Le Jardin Majorelle est install%c en plein coeur de Marrakech, dans le quartier Gu%cliz|\n",130,130);
    printf("\t\t\t\t  |le Jardin pr%csente plus de 300 esp%cces de plantes diff%crentes.                       |\n",130,138,130);
    printf("\t\t\t\t  |=====================================================================================|\n");
    printf("\t\t\t\t  |Le Palais Bahia %c Marrakech est un exemple %cblouissant de l'architecture et du design|\n",133,130);
    printf("\t\t\t\t  |marocains. Construit %c la fin du XIXe si%ccle, c’est un vaste complexe de jardins, de |\n",133,130);
    printf("\t\t\t\t  |cours et de pi%cces qui regorgent de d%ctails complexes et de couleurs vibrantes       |\n",138,130);
    printf("\t\t\t\t  |=====================================================================================|\n");
    printf("\t\t\t\t  |La m%cnara est un monument du patrimoine de la ville, construite au 12%cme si%ccle par  |\n",130,138,138);
    printf("\t\t\t\t  |le calife Abdul-Mu'min de la dynastie des Almohades, la M%cnara est un immense jardin |\n",130);
    printf("\t\t\t\t  |plant%c d'oliviers.                                                                   |\n",130);
    printf("\t\t\t\t  |=====================================================================================|\n");
    printf("\t\t\t\t  |Le Palais El Badi %c Marrakech est un magnifique exemple de l’architecture et de la   |\n",133);
    printf("\t\t\t\t  |culture marocaine. Construit au XVIe si%ccle, ce palais est un t%cmoignage de la       |\n",130,130);
    printf("\t\t\t\t  |grandeur de la dynastie saadienne et de la beaut%c de l’art et du design marocains.   |\n",130);
    printf("\t\t\t\t  |=====================================================================================|\n\n\n");
    color(15,0);
}

void detailsAgadir(){
    color(3,0);
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |La plage d'Agadir offre des activités nautiques, des couchers de soleil magnifiques            |\n");
    printf("\t\t\t  |et stimule l'%ceconomie locale gr%ce au tourisme.                                                |\n", 130, 131);
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |Les excursions dans les montagnes d'Agadir offrent des vues spectaculaires,                    |\n");
    printf("\t\t\t  |des sentiers de randonn%ce pittoresques et une exp%crience de nature pr%cserv%ce.                  |\n", 130, 130, 130, 130);
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |L'exploration du souk d'Agadir offre une immersion vibrante dans la culture locale,            |\n");
    printf("\t\t\t  | avec ses %ctals color%cs, ses artisans talentueux et son ambiance anim%ce.                       |\n", 130, 130, 130);
    printf("\t\t\t  |=====================================================================================          |\n");
    printf("\t\t\t  |La d%cgustation de plats locaux %c Agadir inclut des d%clices tels que le tajine,                 |\n", 130, 133, 130);
    printf("\t\t\t  |le couscous, Aghroum, Amlou, Argane et les d%clicieuses p%ctisseries marocaines                  |\n", 130, 131);
    printf("\t\t\t  |comme les cornes de gazelle.                                                                   |\n");
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |Une excursion dans la vall%ce du Paradis %c Agadir offre une escapade naturelle spectaculaire,   |\n", 130, 133);
    printf("\t\t\t  |avec ses paysages pittoresques, ses rivi%cres et ses possibilit%cs de randonn%ce inoubliables.    |\n", 138, 130, 130);
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |La visite de la Kasbah d'Agadir Oufella permet d'explorer l'histoire fascinante de la r%cgion,  |\n", 130);
    printf("\t\t\t  |avec ses ruines anciennes, ses vues panoramiques sur la ville et son ambiance culturelle unique|\n");
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |Une s%cance de surf %c Agadir offre une exp%crience palpitante, avec ses vagues impressionnantes, |\n", 130, 133, 130);
    printf("\t\t\t  | ses instructeurs comp%ctents et son ambiance d%ccontract%ce sur les plages de l'Atlantique.      |\n", 130, 130, 130);
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |L'observation d'un spectacle de dauphins %c Agadir offre une exp%crience captivante,             |\n", 133, 130);
    printf("\t\t\t  | avec ses acrobaties gracieuses, ses interactions et son %cmerveillement pour toute la famille. |\n", 130);
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |Promenez-vous dans les jardins d'Olhao pour d%couvrir des espaces verdoyants,                   |\n", 130);
    printf("\t\t\t  |des fleurs exotiques et une ambiance paisible au cœur d'Agadir.                                |\n");
    printf("\t\t\t  |===============================================================================================|\n");
    printf("\t\t\t  |Hammam Traditionnel Chez Abdou : Situ%c dans le quartier historique d'Agadir.                   |\n", 130, 130);
    printf("\t\t\t  |Hammam Andaloussia : Cette adresse est populaire parmi les habitants et les visiteurs.         |\n", 130);
    printf("\t\t\t  |===============================================================================================|\n\n\n");

    color(15,0);
}

// Fonction pour changer le couleur

void color(int t,int f){
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void plannification_semaine(){
    char jours_semaine[7][20] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
    Journee journees[] = {
        {"Lundi", NULL, 0},
        {"Mardi", NULL, 0},
        {"Mercredi", NULL, 0},
        {"Jeudi", NULL, 0},
        {"Vendredi", NULL, 0},
        {"Samedi", NULL, 0},
        {"Dimanche", NULL, 0}
    };
    int nbJournees = sizeof(journees) / sizeof(journees[0]);
    printf("  Merci de donner toutes les activit%cs que vous souhaitez faire durant votre s%cjour. Si vous n'avez aucune veuillez tapez 0.\n", 130, 130, 130, 130);
          // Demande à l'utilisateur de saisir le nombre de semaines
          int nbSemaines;

         color(14,0);
         printf("\n\n\t\t\t\t\t-------------------------------------\n\t\t\t\t\tLe plan de la semaine est le suivant:\n\t\t\t\t\t-------------------------------------\n\n");
         color(15,0);
        printf("\tEntrez le nombre de semaines: ");
    scanf("%d", &nbSemaines);

    FILE *fichierm = NULL;
    fichierm = fopen("activites.txt", "a");
    if (fichierm == NULL) {
        printf("Erreur lors de l'ouverture du fichier.");
        return 1;
    }



    // Boucle pour chaque semaine
    for (int semaine = 1; semaine <= nbSemaines; semaine++) {
        printf("\n\n\t\t\t\t\t\t----- Semaine %d -----\n", semaine);
        fprintf(fichierm, "\n--- Semaine %d ---\n", semaine);

        // Boucle pour chaque jour
        for (int i = 0; i < 7; i++) {
            color(3,0);
            strcpy(journees[i].jour, jours_semaine[i]);
            color(15,0);
            printf(" \n\20%s:\n", journees[i].jour);
            fprintf(fichierm, "%s:\n", journees[i].jour);

            printf("-Combien d'activit%cs voulez-vous entrer pour ce jour: ",130);
            int nbActivites;
            scanf("%d", &nbActivites);
            journees[i].activites = malloc(nbActivites * sizeof(Activite));
            journees[i].nbActivites = nbActivites;

            // Entrée des activités pour ce jour
            for (int j = 0; j < nbActivites; j++) {
                strcpy(journees[i].activites[j].details, "Activité suggérée");
                printf("  --> Activit%c N%c%d: ", 130,248,j+1);
                scanf(" %[^\n]s", journees[i].activites[j].details);
                fprintf(fichierm, "Description d'activité N° %d: %s\n", j+1, journees[i].activites[j].details);
            }
        }
        printf("Votre plan de la semaine est cr%c%c avec succ%cs. Vous pouvez le voir dans le fichier. ",130,130,138);
    }

    // Fermeture du fichier et libération de la mémoire
    fclose(fichierm);
    free(journees);



        for (int i = 0; i < nbJournees; i++) {
            free(journees[i].activites);

        }

}

void attendreSecondes(int secondes) {
    sleep(secondes);
}
