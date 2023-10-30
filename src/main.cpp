#include <Arduino.h>
#include <Ticker.h>
#define LedRojo 16

Ticker interrupcion;
int Variable = 0;
int VariableAnterior = 0;

void FuncionInterrupcion()
{
  Variable ++;
  digitalWrite(LedRojo, !(digitalRead(LedRojo)));
  if(Variable == 5){
    Serial.println("Llego a 5");
    Serial.println();
    Variable = 0;
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(LedRojo, OUTPUT);
  interrupcion.attach(1, FuncionInterrupcion);
}

void loop()
{
  if(Variable != VariableAnterior){
    VariableAnterior = Variable;
    Serial.print("Dato: ");
    Serial.println(Variable);
  }
}