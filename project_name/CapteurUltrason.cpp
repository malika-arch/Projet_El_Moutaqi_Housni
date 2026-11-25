#include "Arduino.h"

class CapteurUltrason {
private:
    int pinSIG;

public:
    
    CapteurUltrason(int pin) {
        pinSIG = pin;
    }

   
    float mesurerDistance() {
        pinMode(pinSIG, OUTPUT);     // se comporte comme un trig 

        digitalWrite(pinSIG, LOW);
        delayMicroseconds(2);

        digitalWrite(pinSIG, HIGH);
        delayMicroseconds(12);

        digitalWrite(pinSIG, LOW);

        pinMode(pinSIG, INPUT);    // se comporte comme un echo 

        long duree = pulseIn(pinSIG, HIGH, 30000);

        if (duree == 0) {
            return -1;
        }

        float distance = duree * 0.034 / 2;

        return distance;
    }
};
