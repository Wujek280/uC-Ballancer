#include "charger.h"

float maxVoltage = 5.00;
int d = 8; 
int precision = 3; //decimal precision 

int soc(float U);

double Rw=0;
double Ro=6.2;
double U[3]={0,0,0};
double Ucutoff=4.15;

unsigned long int a=0;

/**********************************************************************/

void setup()
{
 Serial.begin(115200);
 set_up();
 Serial.print("OCV");Serial.print("\t ");Serial.print("U_load");Serial.print(" \t");
  Serial.println();
}

void loop()
{
    off();delay(1000);
    reading(); U[1]=U[0]; U[0]=0; //  OCV
    resistor_on(); 
    
    delay(1000);
    
    resistor_off();
    reading(); U[2]=U[0]; U[0]=0; //  U on load
    charge(); delay(5000);
              
    Rw = Ro*(U[1]/U[2] - 1);
    serial_write();

    if(U[1]>Ucutoff || U[2]>Ucutoff){off_emergency();}
}

/**********************************************************************/

void reading()
{
for(int i=0; i<d; i++){a+=analogRead(A1);} U[0]=a/d/1023.00*maxVoltage;
a=0;
}



void serial_write()
{
Serial.print(U[1],precision); Serial.print(" \t "); Serial.print(U[2],precision); Serial.print(" \t "); Serial.print(soc(U[2])); Serial.print(" \t "); Serial.print(abs(Rw),precision-1); Serial.print(" \t ");Serial.print(" Ohm");if(Rw<0){Serial.print(" - ");}
Serial.println();
U[0]=0;
}

int soc(float U)
{ 
 
if(U <3.27){return 0;}
if( U < 3.44  ) return (  3 );
if( U < 3.61  ) return (  5 );
if( U < 3.65  ) return (  8 );
if( U < 3.69  ) return (  10  );
if( U < 3.70  ) return (  13  );
if( U < 3.71  ) return (  15  );
if( U < 3.72  ) return (  18  );
if( U < 3.73  ) return (  20  );
if( U < 3.74  ) return (  23  );
if( U < 3.75  ) return (  25  );
if( U < 3.76  ) return (  28  );
if( U < 3.77  ) return (  30  );
if( U < 3.78  ) return (  33  );
if( U < 3.79  ) return (  35  );
if( U < 3.80  ) return (  38  );
if( U < 3.80  ) return (  40  );
if( U < 3.81  ) return (  43  );
if( U < 3.82  ) return (  45  );
if( U < 3.83  ) return (  48  );
if( U < 3.84  ) return (  50  );
if( U < 3.85  ) return (  53  );
if( U < 3.85  ) return (  55  );
if( U < 3.86  ) return (  58  );
if( U < 3.87  ) return (  60  );
if( U < 3.89  ) return (  63  );
if( U < 3.91  ) return (  65  );
if( U < 3.93  ) return (  68  );
if( U < 3.95  ) return (  70  );
if( U < 3.97  ) return (  73  );
if( U < 3.98  ) return (  75  );
if( U < 4.00  ) return (  78  );
if( U < 4.02  ) return (  80  );
if( U < 4.05  ) return (  83  );
if( U < 4.08  ) return (  85  );
if( U < 4.10  ) return (  88  );
if( U < 4.11  ) return (  90  );
if( U < 4.13  ) return (  93  );
if( U < 4.15  ) return (  95  );
if( U < 4.18  ) return (  98  );
if( U < 4.19  ) return (  99  );
if( U < 4.20  ) return (  100 );

return(0xFF);

}

