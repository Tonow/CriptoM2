/**
 *Prend un texte chiffrer en entrer et donne la cle de vigenere si il y en a
 *une en sortie
 *
 *exemple d'utilisation
 *      --> $ cat texte.txt | ./detecte-vigenere
 *      --> $ cat lafontaine-az.txt | ./chiffre-vigenere AZERTY | ./detecte-vigenere
 */
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include  <math.h>

#include "utils.h"
#include "freqs.h"

using namespace std;

float indiceFR = 0.0780531 ;
float indiceRandom = 0.0384615 ;


int main( int argc, char** argv )
{
  string s = readInput( cin );

  std::vector<float> frequenFR( 26 );
  std::vector<float> frequenRandom( 26 );
  std::vector<float> frequen( 26 );
  std::vector<float> bestFrequen( 26 );

  frequenFR = frequenciesFrench();
  frequenRandom = frequenciesRandom();

  bool EstFR = false;

  cout << "\n##############################################\n"
       << "Taille du texte = " << s.size()
       << "  --   Nb de saut = " << s.size()/10
       << "\n##############################################\n"
       << "\n" << endl;

  for (int saut = 1; saut <= int(s.size()/10) ; saut++)
  // recherche de la bonne taille de cle
  {

    int nb_fr = 0;

    for (int shift = 0; shift <= saut-1; shift++)
    // recherche avec tout les shifts possible
    {

      string subTextATraiter = subtext(s, saut, shift);

      // tout le traitement sur la chaine
      // pour savoir si elle semble aleatoire ou proche du fr
      EstFR = itIsRandomOrFR (subTextATraiter);

      if (EstFR) {
        nb_fr++; // ce shift semble corresponde a du francais
      }
    }

    if (nb_fr == saut) // il est autement probalble qu'on ai la bonne clé
    // Pour que pour tout les saut on tombe sur un indice de coincidence
    //qui corresponde au francais
    {
      cout << "\n\n--> Semble etre du francais pour saut : " << saut << endl;

      std::vector<char> cle( saut );

      for (int lettreCle = 0; lettreCle < saut; lettreCle++)
      // On cherche donc la bonne cle en testant les 26 lettre de A a Z
      // qui maximise la coincidence mutuelle avec indiceFR
      {
        //valeur qui devra etre de plus en plus prche de indiceFR
        int max = 0;
          string subTextCheckLettre = subtext(s, saut, lettreCle);
          frequen = frequencies(subTextCheckLettre);

          //DEBUG
          /*
          for ( int i = 0; i < 26; i++ )
           {
             //affiche la frequance de chaque lettre
             cout << (char)('A'+i) << " = " << frequen[i] << endl;
           }
           */

          for ( int lettreTester = 0; lettreTester < 26; lettreTester++ )
          //Calcule la lettre qui a la  frequence max donc qui devrait etre E
           {
            if(frequen[lettreTester]>frequen[max])
            //'E' elle est la lettre avec la frequence max
            {
              max=lettreTester;
            }

           }
           // cas de la fin de l'alphabet pour ne pas se retrouver evec des signes
           if (max < 4)
           {
              max = (max + 26);
            }

            // Decalage de l'alphabet (comme pour un chiffre de Cesare)
            cle[lettreCle] = (char) ('A' + max - 4);

            // DEBUG
            /*
            std::cout << "position : " << lettreCle << " lettre " << (char) ('A' + max - 4 )
            << " max = " << max << " frequance : " << frequen[max] << '\n';
            */


        }


      // ######## Affiche la clé
      for ( int clePosition = 0; clePosition < saut; clePosition++ )
      {
        cout << "la " << clePosition << " eme lettre = " << cle[clePosition] << endl;
      }
      // ######## FIN Affiche la clé

      break;
    }
  }
  return 0;
}
