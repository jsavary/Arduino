/* Version 1
 * Programme pour arduino uno
 * par J. SAVARY Fevrier 2015
 * Licence GNU GPLv3
 *
 * Permet de choisir entre deux mode d'exploitation des LED en broche 4 à 9 (6 LEDs)
 * les deux modes d'exploitation ne sont pas du developpement personnel.
 * seul la derniere loop est de mon cru.
 */
    // Initialisation des variables
    const byte A1V = 4 ;
    const byte A1O = 5 ;
    const byte A1R = 6 ;
    const byte B1V = 7 ;
    const byte B1O = 8 ;
    const byte B1R = 9 ;
    const byte LedArduino = 13 ;
    const byte INT3 = 3 ;
    const byte INT2 = 2 ;
    
    //Délai des différents temps mis en const pour changer facilement 
    // si le délai imparti ne vous satisfait pas. Il s'agit de millisecondes
    const long TempsAttenteFeuRougeSeul = 1000;
    const long TempsAttenteFeuVert = 7500;
    const long TempsAttenteFeuOrange = 2500;
         
    // Initialisation des lignes 4 à  9 en sortie
    // Initialisation de la broche 13 en sortie
    // Initialisation des broches 2 et 3 en entrée
    // Initialisation du mode Serie pour permettre le monitoring .// debug
    void setup () {
//      Serial.begin(9600); //debug
      pinMode (A1V, OUTPUT) ;
      pinMode (A1O, OUTPUT) ;
      pinMode (A1R, OUTPUT) ;
      pinMode (B1V, OUTPUT) ;
      pinMode (B1O, OUTPUT) ;
      pinMode (B1R, OUTPUT) ;
      pinMode (LedArduino, OUTPUT) ;
      pinMode (INT3, INPUT) ;
      pinMode (INT2, INPUT) ;
    }

         void enseigne () 
         /*
         * Programme pour arduino uno
         * par C. Bézanger Octobre 2013
         * Licence GNU GPLv3
         *
         * Ce programme réalise le clignotement d'une enseigne publicitaire.
         * Il fait clignoter selon un certain rythme six DEL reliées aux sorties 4 à  9.
         * Il utilise des fonctions pour alterner les rythmes.
         */

         {
          // Extinction de toutes les DEL au départ du programme
          for (byte i = 4 ; i <= 9 ; i++) 
          {
            digitalWrite (i, LOW) ; // éteint la DEL reliée à la broche i
          }
              
          // Séquence N°1 ; chenillard
          sequence_Un () ;
          delay (500) ;  // délai de 500 millisecondes
         
          // Séquence N°2 : cumul sur la gauche du mouvement de DEL
          sequence_Deux () ;
          delay (500) ;  // délai de 500 millisecondes
          
          // Séquence N°3 : clignotement de l'ensemble 3 fois
          sequence_Trois () ;
          delay (2000) ; // délai de 2 secondes
         
          // Séquence 4 : extinction successive de la gauche vers la droite
          sequence_Quatre () ;
          delay (2000) ; 
          
          // Recommence la séquence
        }
         
        /*
         * Séquence N°1 ; chenillard
         */
        void sequence_Un ()
        {
          for (byte n = 0 ; n <= 2 ; n++)
          {
            for (byte i = 4 ; i <= 9 ; i++)
            {
              digitalWrite (i, HIGH) ;    // allume la DEL sur broche i
              delay (100) ;               // durée du flash 150 millisecondes
              digitalWrite (i, LOW) ;     // éteint la DEL
              delay (50) ;
            }
          }
        }
         
        /*
         * Séquence N° 2 : cumul sur la gauche du mouvement de DEL
         */
        void sequence_Deux ()
        {
          for (byte n = 0 ; n <= 5 ; n++)
          {
            for (byte i = 4 ; i <= (9-n) ; i++)
            {
              digitalWrite (i, HIGH) ; // allume la DEL sur broche i
              delay (150) ;            // durée du flash 150 millisecondes
              digitalWrite (i, LOW) ;  // éteint la DEL
            }
            digitalWrite ( (9 - n) , HIGH ) ; // dernière DEL reste allumée
          }
        }
         
        /*
         * Séquence N°3 : clignotement de l'ensemble 3 fois
         */
        void sequence_Trois ()
        {
          for (byte j = 1 ; j <= 3 ; j++) 
          {
            for (byte k = 4 ; k <= 9 ; k++) 
            {
              digitalWrite (k , LOW) ;
            }
            delay (500) ;
            for (byte l = 4 ; l <= 9 ; l++) 
            {
              digitalWrite (l, HIGH) ;
            }
            delay (500) ;
          }
        }
         
        /*
         * Séquence 4 : extinction successive de la gauche vers la droite
         */
        void sequence_Quatre ()
        {
          for (byte i = 9 ; i >= 4 ; i--) 
          {
            digitalWrite (i, LOW) ;
            delay (150);
          }
        }

         void feux(){
             /*
             * Programme pour arduino uno
             * par C. Bézanger Octobre 2013
             * Licence GNU GPLv3
             * 
             * Ce programme fait fonctionner des feux tricolores.
             * Six LED (vertes, oranges et rouge) sont reliées aux sorties 4 à  9
             * Les sorties 4 à  6 forment le feu A1
             * Les sorties 7 à  9 forment le feu B1
             */
                              
              // Extinction de toutes les LED au départ
              digitalWrite (A1V, LOW) ;
              digitalWrite (A1O, LOW) ;
              digitalWrite (A1R, LOW) ;
              digitalWrite (B1V, LOW) ;
              digitalWrite (B1O, LOW) ;
              digitalWrite (B1R, LOW) ; 
            
                 
              // Allumage de A1V et B1R
              digitalWrite (A1V, HIGH) ;
              digitalWrite (B1R, HIGH) ;
                 
              // Début de cycle
               
              // Concerne le feu A1
              delay (TempsAttenteFeuVert) ; // Feu vert A1V pendant 30 secondes
              digitalWrite (A1V, LOW) ; // Extinction de A1V
              digitalWrite (A1O, HIGH) ; // et allumage de A1O
              delay (TempsAttenteFeuOrange) ; //durée 5 secondes
              digitalWrite (A1O, LOW) ; // Extinction de A1O
              digitalWrite (A1R, HIGH) ; // et allumage de A1R
              delay (TempsAttenteFeuRougeSeul) ; // Temporisation du chauffard !
            
                 
              // Concerne l'autre feu B1
              digitalWrite (B1R, LOW) ; // Extinction de B1R
              digitalWrite (B1V, HIGH) ; // et allumage de B1V
              delay (TempsAttenteFeuVert) ; // Feu vert B1V pendant 30 secondes
              digitalWrite (B1V, LOW) ; // Extinction de B1V
              digitalWrite (B1O, HIGH) ; // et allumage de B1O
              delay (TempsAttenteFeuOrange) ; // durée 5 secondes
              digitalWrite (B1O, LOW) ; // Extinction de B1O
              digitalWrite (B1R, HIGH) ; // et allumage de B1R
              delay (TempsAttenteFeuRougeSeul) ; // Temporisation du chauffard !
              digitalWrite (A1V, HIGH) ; // On est revenu au point de départ
                 
              // Feu A1 vert et feu B1 rouge : le cycle peut recommencer
            }

void loop() {
//  int sensorValue = digitalRead(INT2); // Stock la valeur de INT2 dans la variable "sensorValue". //debug
//  Serial.println(sensorValue, DEC); // affiche la valeur de INT2 dans la console serie.           //debug
  if (digitalRead(INT2) == HIGH) {
    digitalWrite (LedArduino, HIGH) ; //force l'allumage de la LED de l'arduino (valide le test)
    enseigne(); //lancement du mode Enseigne Magasin.
    } else {
    digitalWrite (LedArduino, LOW) ; //force l'extinction de la LED de l'arduino (valide le test)
    feux(); //lancement du mode Feux Tricolor.
    }
}
