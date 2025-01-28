// Exercice-Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include "Logger.h"

using namespace LoopEngine;

int main()
{
    //Écriture dans la console et le fichier "C63Demo/Exercice-Logger/LoopEngine.log"
    Logger* log = new Logger(Logger::TLevel::eINFO, true, true);
    assert(log != nullptr);

    

    log->Log("De l'information seulement.", Logger::TLevel::eINFO);
    log->Log("Un avertissement, peut causer des problemes mineurs.", Logger::TLevel::eWARNING);
    log->Log("Pour debogger", Logger::TLevel::eDEBUG);
    //log->Log("Une erreur, c'est grave et va casser l'application. Va suspendre avec la configuration par défaut!", Logger::TLevel::eERROR);
    //log->SetFileTraceName("JeVaisInterrompre!");
    log->ActivateFileTrace(false);
    log->SetFileTraceName("NouveauLog.log");
    log->ActivateFileTrace(true);
    log->Log("Va ecrire dans la console et NouveauLog.log.", Logger::TLevel::eINFO);

    log->SetLoggingLevel(Logger::TLevel::eWARNING);
    log->Log("Cette entree sera ignorée.", Logger::TLevel::eINFO);

    //Ne va jamais interrompre
    log->SetAbortLevel(Logger::eERROR);

    //Cause une erreur
    log->SetFileTraceName("");

    //Toujours libérer sa mémoire
    delete log;
    log = nullptr;
}