#include<LiquidCrystal.h>
#include <string.h>

String text;
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  text = "";
   while( Serial.available() ){
    delay(10);
    char c = Serial.read();
    text += c;
   }
//   digitalWrite(13, 1);
//   delay(1000);
//   digitalWrite(13, 0);
//   delay(1000);
   
   if(text.length()>0){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Project Nidhi");
    lcd.setCursor(0, 1);
    lcd.print(text);
    //Serial.println(text);
    if(text == "hello"){
      Serial.print("bolun ki lagbe?");
    }
    else if (text == "start"){
      digitalWrite(13, HIGH);
      Serial.print("Light is on.");
    }
    else if(text == "of"){
      digitalWrite(13, LOW);
      Serial.print("Light is off.");
    }
    else if(text == "how are you"){
      Serial.print("I am fine.");
      delay(10);
      Serial.print("What about you?");
    }
    else if(text == "who are you"){
      Serial.print("I am called project Nidhi.");
      delay(10);
      Serial.print("Develop by Al Amin.");
      
    }
    else if(text == "count 125"){
      for(int i=0; i<5; i++){
         Serial.print(i+1);
        delay(1000);
      }
    }
    else if(doMathMaticalOperetion(text)){
        Serial.print(result(text));
    }else if(text == "what time is it"){
      Serial.print(F(__TIME__));
    }
    else{
      Serial.print("bujhlam nah!");
    }
    //
   }   
}

int doMathMaticalOperetion(String st){
  int flag = 0;
  for(int i=0; i<st.length(); i++){
    if(st[i]=='+' || st[i]=='x' || st[i]=='/' || st[i]=='-'){
      flag = 1;
      break;
    }
  }
  return flag;
}
int result(String st){
  int plus = 0;
  int minus = 0;
  int mul = 0;
  int dived = 0;
  for(int i=0; i<st.length(); i++){
    if(st[i]=='+'){
      plus = 1;
      break;
    }
    if(st[i]=='-'){
      minus = 1;
      break;
    }
    if(st[i]=='x'){
      mul = 1;
      break;
    }
    if(st[i]=='/'){
      dived = 1;
      break;
    }
  }//loop end 
  
  //  get rwo number
  String getN1;
  String getN2;
  int spaceFlag = 0;
  for(int i=0; i<st.length(); i++){
    if(st[i]==' '){
      spaceFlag++;
    }
    if(spaceFlag == 0){
     getN1 += st[i]; 
    }
    if(spaceFlag == 2){
     getN2 += st[i]; 
    }
     
  }
//  operations
  if(plus == 1){
    return getN1.toInt() + getN2.toInt();
  }
  if(minus == 1){
    return getN1.toInt()-getN2.toInt();
  }
  if(mul == 1){
    return getN1.toInt()*getN2.toInt();
  }
  if(dived == 1){
    return getN1.toInt()/getN2.toInt();
  }
//  return getN1.toInt()+getN2.toInt();   
}
