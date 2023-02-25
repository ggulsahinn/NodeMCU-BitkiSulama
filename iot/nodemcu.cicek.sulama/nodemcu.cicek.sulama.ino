#define BLYNK_TEMPLATE_ID           "TMPLEWwzGDAA"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "rzETC-5DZ8gbdy5iFBpAZoHe_QEDF92G"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "modem";
char pass[] = "sahinhaga32";

int deger ;
int donusum; // okuma yapacağımız nem değerini deger değişkeni olarak belirliyoruz

#define sensor A0
#define pompa D0

void setup()
{
  pinMode(pompa,OUTPUT);
  pinMode(pompa,LOW);
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);

}

void loop() {

  deger = analogRead(sensor);
  deger = map(deger , 0, 1023, 0, 100);
  Serial.println(deger);

  Blynk.virtualWrite (A0, deger);

  Blynk.run();
  
}

BLYNK_WRITE(V0){ 

  int value = param.asInt();

  Serial.println(V0);
  
  if(value == 0){
    digitalWrite(pompa,HIGH);
  }

  else{
    digitalWrite(pompa,LOW);
  }

}
