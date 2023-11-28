#include <VirtualWire.h>

void setup()
{
    Serial.begin(9600);  // Debugging only
    Serial.println("Receptor: setup");

    // Se inicializa el RF
    vw_setup(2000);  // velocidad: Bits per segundo
    vw_set_rx_pin(11);    //Pin 2 como entrada del RF
    vw_rx_start();       // Se inicia como receptor
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    float latitud;
    float longitud;
    float presion;
    float altitudGPS;
    float temperatura;
    float altitudBMP;
    float humedad;
    
    //verificamos si hay un dato valido en el RF
    if (vw_get_message((uint8_t *)buf,&buflen))
    {
  int i;
  String  DatoCadena="";
        if((char)buf[0]=='l') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            latitud=DatoCadena.toFloat();
            Serial.print("[1]latitud: ");
            Serial.println(latitud,5);
        }
        else if((char)buf[0]=='o') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            longitud=DatoCadena.toFloat();
            Serial.print("[2]longitud: ");
            Serial.println(longitud,5);
        }
        else if((char)buf[0]=='p') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            presion=DatoCadena.toFloat();
            Serial.print("[3]presion: ");
            Serial.println(presion);
        }
        else if((char)buf[0]=='A') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            altitudGPS=DatoCadena.toFloat();
            Serial.print("[4]altitudGPS: ");
            Serial.println(altitudGPS);
        }
        else if((char)buf[0]=='T') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            temperatura=DatoCadena.toFloat();
            Serial.print("[5]temperatura: ");
            Serial.println(temperatura);
        }
        else if((char)buf[0]=='B') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            altitudBMP=DatoCadena.toFloat();
            Serial.print("[6]altitudBMP: ");
            Serial.println(altitudBMP);
        }
        else if((char)buf[0]=='H') //verificamos el inicio de trama
        {
            for (i = 1; i < buflen; i++)
            {
          DatoCadena.concat((char)buf[i]);
            }
            humedad=DatoCadena.toFloat();
            Serial.print("[7]humedad: ");
            Serial.println(humedad);
        }
    }
}
