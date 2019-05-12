#include "EEPROM.h"
//소숫점 2자리까지 저장.
#define QUAD_CNT 4
#define HEIGHT_CNT 3
#define DEG_CNT 4
int addr = 0;
//sin2a,sin2b,con2a,cos2b
float offset_val[4][3][4] = {
  {{0.9851,-0.0384,-0.1719,-0.9993},
  {0.9974,-0.0523,0.0715,-0.9986},
  {0.9942,-0.0297,-0.1080,-0.9996}},
  {{-0.9936,-0.0349,-0.1132,-0.9994},
  {0.9995,0.2554,0.0314,-0.9668},
  {0.9969,-0.1426,-0.0785,-0.9898}},
  {{0.9998,0.0488,0.0175,-0.9988},
  {0.9999,0.0906,-0.0105,-0.9959},
  {0.9959,0.0017,-0.0906,-1.0000}},
  {{0.9885,0.0558,0.1513,-0.9984},
  {0.9285,0.1409,0.3714,-0.9900},
  {0.9995,0.1149,0.0322,-0.9934},}
};


#define EEPROM_SIZE 256
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("start...");
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }
  Serial.println("===READ===");
  for(int quad = 0; quad<QUAD_CNT; quad++){
   for(int height = 0; height<HEIGHT_CNT; height++){
      for(int deg = 0; deg<DEG_CNT; deg++){
           addr +=4;
           Serial.println(EEPROM.readFloat(addr), 4);
       }
    }
  }
  addr = 0;
  Serial.println("===WRITE===");
  for(int quad = 0; quad<QUAD_CNT; quad++){
    for(int height = 0; height<HEIGHT_CNT; height++){
       for(int deg = 0; deg<DEG_CNT; deg++){
           addr +=4;
           EEPROM.writeFloat(addr, offset_val[quad][height][deg]);
           Serial.print(offset_val[quad][height][deg],4); Serial.println(" ");
       }
    }
  }
  EEPROM.commit();
}

void loop() {
  // put your main code here, to run repeatedly:
  
 
}
