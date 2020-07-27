//CLASSES IMPORTADAS \\

#include <IRremote.h> 
#include <LiquidCrystal.h> 

//////////////////////////

////// CLASSE PARA CONTROLAR LEDS ////////////

class EstiloLuzes4Leds
{
 public:
  EstiloLuzes4Leds(int led1,int led2,int led3,int led4,
                    int led5, int led6, int led7, int led8); // CONTRUTOR
  void SetFrequencia(int freq); // CONTROLA A VELOCIDADE
  int GetFrequencia();
  void estilo_1();
  void estilo_2();
  void estilo_3();
  void estilo_4();
  void estilo_5();
  
  private:
    int led_1;
    int led_2;
    int led_3;
    int led_4;
    int led_5;
    int led_6;
    int led_7;
    int led_8;
    int Frequencia;
};

//CONSTRUTOR
EstiloLuzes4Leds::EstiloLuzes4Leds(int led1,int led2,int led3,int led4,
                                    int led5, int led6, int led7, int led8)
{ 
  led_1 = led1;
  led_2 = led2;
  led_3 = led3;
  led_4 = led4;
  led_5 = led5;
  led_6 = led6;
  led_7 = led7;
  led_8 = led8;

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

  Frequencia = 600;
}

// RETORNA A VELOCIDADE QUE ESTA
int EstiloLuzes4Leds::GetFrequencia()
{
    if(Frequencia == 600)
        return 1;

    if(Frequencia == 400)
        return 2;

    if(Frequencia == 200)
        return 3;
   
}

//CONTROLA A CIRCUNSTANCIAS QUE O ESTILO PISCA

void EstiloLuzes4Leds::SetFrequencia(int freq)
{
    if(freq == 4335){
        if(Frequencia != 600)
            Frequencia = Frequencia+200;
    }

    if(freq == 20655 ){
        if(Frequencia != 200)
            Frequencia = Frequencia-200;
    }
}

//PRIMEIRA FORMA DE PISCAR

void EstiloLuzes4Leds::estilo_1()
{
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  delay(Frequencia);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  delay(Frequencia);
}

//SEGUNDA FORMA DE PISCAR

void EstiloLuzes4Leds::estilo_2()
{
  digitalWrite(led_8, LOW);
  digitalWrite(led_1, HIGH);
  delay(Frequencia);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, HIGH);
  delay(Frequencia);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, HIGH);
  delay(Frequencia);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, HIGH);
  delay(Frequencia);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, HIGH);
  delay(Frequencia);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, HIGH);
  delay(Frequencia);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, HIGH);
  delay(Frequencia);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, HIGH);
  delay(Frequencia);
}

//TERCEIRA FORMA DE PISCAR	

void EstiloLuzes4Leds::estilo_3()
{
  digitalWrite(led_1, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_7, HIGH);
  
  digitalWrite(led_2, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_8, LOW);
  delay(Frequencia);
  digitalWrite(led_1, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_8, HIGH);
  delay(Frequencia);
  
}

//QUARTO FORMA DE PISCAR	

void EstiloLuzes4Leds::estilo_4()
{
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  delay(Frequencia);
  digitalWrite(led_1, HIGH);
  digitalWrite(led_8, HIGH);
  delay(Frequencia);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_7, HIGH);
  delay(Frequencia);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_6, HIGH);
  delay(Frequencia);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  delay(Frequencia);
  
}

////////  QUINTO ESTILO

void EstiloLuzes4Leds::estilo_5()
{
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  delay(Frequencia);
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  delay(Frequencia);
  
}



// DECLANDO VARIAVEIS DO CONTROLE \\

int pin = 7;
IRrecv ir(pin);
decode_results resultado;

//////INSTANCIANADO A CLASSE////////////

EstiloLuzes4Leds ldr(6,5,4,3,2,A5,A4,A3);

// DECLANDO VARIAVEIS DO LCD \\

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
////////////////////////////////


void setup()
{
  Serial.begin(9600);
  
  
  // CONTROLE \\
  
  ir.enableIRIn();
  
  /////////////////
  
  // EDITANDO A TELA INICAL \\

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("LUZES - PISCANTES");
  lcd.setCursor(0, 1);
  lcd.print("VALORES DE 1 A 5 ");
  lcd.setCursor(0, 1);
  
  /////////////////////////////
  
}
 
void loop()
{
  
   resultado.value = 0;
  
  if (ir.decode(&resultado)) // VERIFICA SE ALGO FOI CLIKADO  
   {
    
     if(ir.decode(&resultado) && resultado.value == 16582903) // VERIFICA SE O 1 FOI ABERTADO
     {
         lcd.clear(); // LIMPA A TELA PARA RECEBER MAIS ESCRITA

       while(resultado.value == 16582903 ||
             resultado.value == 16584943 ||
             resultado.value == 16601263) // O WHILE MANTERA AS LUZES PISCANDO CONSTANTEMENTE
        { 

            lcd.print("PISCAGEM |1|");
            lcd.setCursor(0, 1);
            lcd.print("VELOCIDADE: ");
         	lcd.print(ldr.GetFrequencia());
            lcd.print(" /3");

     	  ldr.estilo_1(); // CHAMA O METODO DAS CLASSE QUE CONTROLA UM TIPO DE PISCAR 

          if(ir.decode(&resultado) && 
            resultado.value != 16582903 &&
            resultado.value !=16584943 &&
            resultado.value !=16601263) // ESSE IF FARA AS LUZES PARAREM DE PISCAR 
  			break;                      // QUANDO OUTRO BOTAÃO FOR ABERTADO SE SER O 1 OU OS DE VELOCIDADE
         

        if(resultado.value == 16584943) // AUMENTA A VELOCIDADE
         {
             ldr.SetFrequencia(16584943);  
             resultado.value = 16582903;
         }
         	    
    
   		 if(resultado.value == 16601263) // DIMINUI A VELOCIDADE
        {
             ldr.SetFrequencia(16601263);  
             resultado.value = 16582903;
         }    
         
         ir.resume();
        }
      }

     /////// A BAIXO TERA O MESMO CODIGO QUE ACIMA SO PARA OUTROS EFEITOS DO LED 

    /////////////////////////// EFEITO 2

      if(ir.decode(&resultado) && resultado.value == 16615543) 
     {
         lcd.clear();

       while(resultado.value == 16615543 ||
             resultado.value == 16584943 ||
             resultado.value == 16601263) 
        { 

            lcd.print("PISCAGEM |2|");
            lcd.setCursor(0, 1);
            lcd.print("VELOCIDADE: ");
         	lcd.print(ldr.GetFrequencia());
            lcd.print(" /3");

     	  ldr.estilo_2(); 
            

          if(ir.decode(&resultado) && 
            resultado.value != 16615543 &&
            resultado.value !=16584943 &&
            resultado.value !=16601263)  
  			break;                      
         

         if(resultado.value == 16584943)
         {
             ldr.SetFrequencia(16584943);  
             resultado.value = 16615543;
         }
         	    
    
   		 if(resultado.value == 16601263) 
        {
             ldr.SetFrequencia(16601263);  
             resultado.value = 16615543;
         }     
         
         ir.resume();
        }
      }

    //////////////////////////////////// EFEITO 3

    if(ir.decode(&resultado) && resultado.value == 16599223) 
     {
         lcd.clear();

       while(resultado.value == 16599223 ||
             resultado.value == 16584943 ||
             resultado.value == 16601263) 
        { 

            lcd.print("PISCAGEM |3|");
            lcd.setCursor(0, 1);
            lcd.print("VELOCIDADE: ");
         	lcd.print(ldr.GetFrequencia());
            lcd.print(" /3");

     	  ldr.estilo_3();  

          if(ir.decode(&resultado) && 
            resultado.value != 16599223 &&
            resultado.value !=16584943 &&
            resultado.value !=16601263)  
  			break;                      
         

         if(resultado.value == 16584943) // AUMENTA A VELOCIDADE
         {
             ldr.SetFrequencia(16584943);  
             resultado.value = 16599223;
         }
         	    
    
   		 if(resultado.value == 16601263) // DIMINUI A VELOCIDADE
        {
             ldr.SetFrequencia(16601263);  
             resultado.value = 16599223;
         }        
         
         ir.resume();
        }
      }

    //////////////////////////////////// EFEITO 4

    if(ir.decode(&resultado) && resultado.value == 16591063) 
     {
         lcd.clear();

       while(resultado.value == 16591063 ||
             resultado.value == 16584943 ||
             resultado.value == 16601263) 
        { 

            lcd.print("PISCAGEM |4|");
            lcd.setCursor(0, 1);
            lcd.print("VELOCIDADE: ");
         	lcd.print(ldr.GetFrequencia());
            lcd.print(" /3");

     	  ldr.estilo_4();  

          if(ir.decode(&resultado) && 
            resultado.value != 16591063 &&
            resultado.value !=16584943 &&
            resultado.value !=16601263)  
  			break;                      
         

         if(resultado.value == 16584943) // AUMENTA A VELOCIDADE
         {
             ldr.SetFrequencia(16584943);  
             resultado.value = 16591063;
         }
         	    
    
   		 if(resultado.value == 16601263) // DIMINUI A VELOCIDADE
        {
             ldr.SetFrequencia(16601263);  
             resultado.value = 16591063;
         }        
         
         ir.resume();
        }
      }

    ////////////////////////////////////

    //////////////////////////////////// EFEITO 5

    if(ir.decode(&resultado) && resultado.value == 16623703) 
     {
        lcd.clear();

       while(resultado.value == 16623703 ||
             resultado.value == 16584943 ||
             resultado.value == 16601263) 
        { 

            lcd.print("PISCAGEM |5|");
            lcd.setCursor(0, 1);
            lcd.print("VELOCIDADE: ");
         	lcd.print(ldr.GetFrequencia());
            lcd.print(" /3");

     	  ldr.estilo_5();  

          if(ir.decode(&resultado) && 
            resultado.value != 16623703 &&
            resultado.value !=16584943 &&
            resultado.value !=16601263)  
  			break;                      
         

         if(resultado.value == 16584943) // AUMENTA A VELOCIDADE
         {
             ldr.SetFrequencia(16584943);  
             resultado.value = 16623703;
         }
         	    
    
   		 if(resultado.value == 16601263) // DIMINUI A VELOCIDADE
        {
             ldr.SetFrequencia(16601263);  
             resultado.value = 16623703;
         }     
         
         ir.resume();
        }
      }

    ////////////////////////////////////

   

      ir.resume();
   }
}