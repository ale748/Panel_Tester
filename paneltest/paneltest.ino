#define PIN 13
#define pin1 digitalWrite(PIN,HIGH)
#define pin0 digitalWrite(PIN,LOW)
#define delay0 delayMicroseconds(100);
#define delay1 delayMicroseconds(200);
uint8_t data[8];
uint8_t maxbits = 64;

bool sending = false;
uint8_t bitcount = 0;
uint8_t interval = 0;
hw_timer_t *Timer0_Cfg = NULL;


void IRAM_ATTR Timer0_ISR()
{
  if (sending){
    uint8_t byte = data[bitcount/8];
    bool bittosend = ((byte >> (7-(bitcount%8)))) & 0x01 == 0x01?true:false;
    if (interval == 0){

    }else if (interval%2 == 1){
      if (bitcount>=maxbits){
        sending = false;
        pin1;
      }else{
        if (bittosend){
          pin0;
        }else{
          pin1;
        }
      }
      
    }else if(interval%2 == 0){
      if (bittosend){
        pin1;
      }else{
        pin0;
      }
      bitcount++;
      

    }
    interval++;
  }
}

void setup() {
  pinMode(PIN,OUTPUT);
  pin1;
  sending = false;
  // put your setup code here, to run once:
  Timer0_Cfg = timerBegin(0, 80, true);
  timerAttachInterrupt(Timer0_Cfg, &Timer0_ISR, true);
  timerAlarmWrite(Timer0_Cfg, 100, true);
  timerAlarmEnable(Timer0_Cfg);
  data[0]=0x01;
  data[1]=0x00;
  data[2]=0x00;
  data[3]=0x09;
  data[4]=0x30;
  data[5]=0x09;
  data[6]=0x30;
  data[7]=0x80;
  


}

void sendData(){
  pin0;
  delay(12);
  bitcount=0;
  interval = 0;
  sending=true;
}

void loop() {
delay(5000);
  sendData();

delay(40);
for (int i=0;i<100;i++){
  pin1;
  delay(1);
  pin0;
  delay(1);
  
}
  // put your main code here, to run repeatedly:

}
