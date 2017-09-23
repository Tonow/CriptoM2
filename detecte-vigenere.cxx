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
  bool reponse = false;

  //std::cout << "le texte est :\n" << s << '\n';

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
      reponse = true;
      cout << "\n\n--> Semble etre du francais pour saut : " << saut << endl;

      std::vector<char> cle( saut );

      for (int lettreCle = 0; lettreCle < saut; lettreCle++)
      // On cherche donc la bonne cle en testant les 26 lettre de A a Z
      // qui maximise la coincidence mutuelle avec indiceFR
      {

        string subTextCheckLettre = subtext(s, saut, lettreCle);
        frequen = frequencies(subTextCheckLettre);

        float bestSommeFrequanceMutuel = 10.0;
        int meilleurLettre = 0;

        //DEBUG
        /*
        for ( int i = 0; i < 26; i++ )
         {
           //affiche la frequance de chaque lettre
           cout << (char)('A'+i) << " = " << frequen[i]  << " Fr francais : "<< freqN(i)
           << " diff : "<< fabs(freqN(i) - frequen[i]) << endl;
         }
         */


         //Calcule la differance de frequance pour toute les lettre avec celle
         // du francais
         for ( int lettreTester = 0; lettreTester < 26; lettreTester++ )
         {
           float differanceFrequanceMutuelTest = 0;
           for (int valeurTest = 0; valeurTest < 26; valeurTest++)
           {
             // pour chaque frequance des lettre en francais calcule la diffence a la frequance
             // avec la lettre tester
             differanceFrequanceMutuelTest = differanceFrequanceMutuelTest + fabs(freqN(valeurTest) - frequen[(lettreTester + valeurTest)%26]);
           }

          //Si la differace de frequence est la plus faible alors on a bien decaler
          if(bestSommeFrequanceMutuel > differanceFrequanceMutuelTest)
          {
            bestSommeFrequanceMutuel = differanceFrequanceMutuelTest;
            meilleurLettre = lettreTester;
          }

         }

          // Decalage de l'alphabet (comme pour un chiffre de Cesare)
          cle[lettreCle] = (char) ('A' + meilleurLettre);

          // DEBUG
          std::cout << "position : " << lettreCle << " lettre " << (char) ('A' + meilleurLettre )
          << " somme frequence mutuel : " << bestSommeFrequanceMutuel << "\n\n";

        }


      // ######## Affiche la clé
      for ( int clePosition = 0; clePosition < saut; clePosition++ )
      {
        cout << "--> la " << clePosition << " eme lettre de la cle = " << cle[clePosition] << endl;
      }
      // ######## FIN Affiche la clé

      break;
    }
  }
  if (reponse == false) {
    std::cout << "Desole la cle n'a pas ete trouver" << '\n';
  }
  return 0;
}
