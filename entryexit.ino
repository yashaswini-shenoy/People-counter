#define sensor1 2
#define sensor2 3
#define led 5
int count=0;

boolean led_status=0;
int counter=0;
void setup() {
  Serial.begin(9600);
//  Serial.println("welcome");
 pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
   pinMode(led , OUTPUT);
}
void loop() {
  
LOOP: int counter=0;
if(digitalRead(sensor1)==1)
  {

while(digitalRead(sensor1)==1);
while(digitalRead(sensor2)==0)
{
  counter++;
  delay(1);
  if(counter==3000)
  {Serial.println("INVALID ENTRY");
  delay(200);
    goto LOOP;
    
  }
}
 
 
   
    while(digitalRead(sensor2)==1);
   count++;
    Serial.println(count);
  
  }
  
else if(digitalRead(sensor2)==1)
  { 
      //while(digitalRead(sensor2)==1);
     while(digitalRead(sensor1)==0)
     { 
      counter++;
      delay(1);
        if(counter==3000)
        {
           
            Serial.println("INVALID EXIT");
              delay(200);
             delay(400);
             goto LOOP;        
         }
      }
      
      while(digitalRead(sensor1)==1);
      {
     
        if(count>0)
        count--;
        Serial.println(count);
      }

      

  }
  if(count>0)
  {
    digitalWrite(led,1);
  }
  else
  {
    digitalWrite(led,0);
  }
  
}    
