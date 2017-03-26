
#define  CHARGER    5    // pinout
#define  BALANCE    6    //
#define  CELL_1     7    //
#define  CELL_2     8    //

#define  OFF        HIGH // neg
#define  ON         LOW  // neg

void set_up();
void charge();
void cell_1();
void cell_2();
void off();
void off_emergency();
void on();
void resistor_on();
void resistor_off();

/*----------------------------------------*/

void set_up()
             {
  pinMode(CHARGER, OUTPUT); 
  pinMode(BALANCE, OUTPUT);
  pinMode(CELL_1,  OUTPUT);
  pinMode(CELL_2,  OUTPUT);
  off();
             }
            
void charge(){
  digitalWrite(CHARGER, ON);
  digitalWrite(BALANCE, OFF);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_2,  OFF);
}
void cell_1(){
  digitalWrite(CHARGER, OFF);
  digitalWrite(BALANCE, ON);
  digitalWrite(CELL_1,  ON);
  digitalWrite(CELL_2,  OFF);
}
void cell_2(){
  digitalWrite(CHARGER, OFF);
  digitalWrite(BALANCE, ON);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_2,  ON);
}
void off(){
  digitalWrite(CHARGER, OFF);
  digitalWrite(BALANCE, OFF);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_2,  OFF);
}
void off_emergency(){
  while(1)
  {
  digitalWrite(CHARGER, OFF);
  digitalWrite(BALANCE, OFF);
  digitalWrite(CELL_1,  OFF);
  digitalWrite(CELL_2,  OFF);
  }
}
void on(){ /* BE CAREFULL */ 
  digitalWrite(CHARGER, ON);
  digitalWrite(BALANCE, ON);
  digitalWrite(CELL_1,  ON);
  digitalWrite(CELL_2,  ON);
}

void resistor_on()  {
  digitalWrite(BALANCE, ON);
  }

void resistor_off()  {
  digitalWrite(BALANCE, OFF);
  }

