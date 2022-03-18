#define  pin_r 4
#define pin_y 5
#define pin_g 6
#define pin_button 7

int sinal = 0;
int ped;

unsigned long tempo_at;
unsigned long tempo_prev = millis();
unsigned long intervalo;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_r, OUTPUT);
  pinMode(pin_y, OUTPUT);
  pinMode(pin_g, OUTPUT);
  pinMode(pin_button, INPUT_PULLUP);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  sinal++;
  tempo_at = millis();
  intervalo = tempo_at - tempo_prev;
  ped = digitalRead(pin_button);
  if(ped == HIGH){
    if(intervalo >= 0 && intervalo < 2000){
      digitalWrite(pin_r,LOW);
      digitalWrite(pin_g, HIGH);
      }
    else if (intervalo >= 2000 && intervalo < 3000){
      digitalWrite(pin_g,LOW);
      digitalWrite(pin_y, HIGH);
      }
    else if (intervalo >= 3000 && intervalo < 6000){
      digitalWrite(pin_y,LOW);
      digitalWrite(pin_r, HIGH);
      }
    else{
      tempo_prev = millis();
      }
    }
  else{
    digitalWrite(pin_g,HIGH);
    digitalWrite(pin_y,LOW);
    digitalWrite(pin_r,LOW);
    tempo_prev = millis();
    }
}
