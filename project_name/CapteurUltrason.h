#ifndef CAPTEUR_ULTRASON_H
#define CAPTEUR_ULTRASON_H

#include "Composant.h"

class CapteurUltrason : public Composant
{
private:
    int pinTrig;
    int pinEcho;

public:
    CapteurUltrason(int trig, int echo);

    void initialiser() override;

    long mesurerDistance();
};

#endif
