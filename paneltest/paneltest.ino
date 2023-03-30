#define PIN 13
#define pin1 digitalWrite(PIN,HIGH)
#define pin0 digitalWrite(PIN,LOW)
#define delay0 delayMicroseconds(100);
#define delay1 delayMicroseconds(200);


void sendTimbre(uint32_t value, uint32_t value2, uint8_t size){
  pin0;
  delay(15);
  for (int i=0;i<32;i++){
    pin1;
    delay0;
    if (value & (1<<i)){
      pin0;
      delay1;
      pin1;
      delay0;
      
      
    }else{
      
      pin0;
      delay0;
      
    }
  }
  
  for (int i=0;i<size-32;i++){
    if (value2 & (1<<i)){
      
      pin0;
      delay1;
      pin1;
      delay0;
    }else{
      pin0;
      delay0;
    }
    pin1;
    delay0;

    
    
  }
  
  pin0;
  delayMicroseconds(1200);
  pin1;
}

void setup() {
  pinMode(PIN,OUTPUT);
  pin1;
  // put your setup code here, to run once:

}

void loop() {


delay(1000);
sendTimbre(0x54000040,0x10A80,55);
  // put your main code here, to run repeatedly:

}
