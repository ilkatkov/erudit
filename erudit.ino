
#include <Adafruit_GFX_rus.h>
#include <Adafruit_PCD8544_rus.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); //CLK, DIN, DC, CE, RST

int score = 0;
// генерируются вопрос, 2 случайных числа от -99 до 99, генерируется математический оператор, и два возможных ответа
void getQuestion(){

  float temp_num;
  float ans1;
  float ans2;
  
  display.clearDisplay();
  Serial.print("Новый пример: ");
  display.print("Сколько будет ");
  float rand_num1 = random(-99, 100);
  float rand_num2 = random(-99, 100);
  while (rand_num1 == rand_num2){
//    Serial.print("Были одинаковые числа в вопросе:");
//    Serial.print(rand_num1);
//    Serial.print(" и ");
//    Serial.println(rand_num2);
  float rand_num1 = random(-99, 100);
  float rand_num2 = random(-99, 100);
  }
  Serial.print((int)rand_num1);
  display.print((int)rand_num1);

// рандом выражения
  int rand_operator = random(4);
  if (rand_operator == 0){
    display.print(" + ");
    Serial.print(" + ");
    temp_num = rand_num1+rand_num2;
  } else if (rand_operator == 1){
    display.print(" - ");
    Serial.print(" - ");
    temp_num = rand_num1-rand_num2;
  } else if (rand_operator == 2){
    display.print(" * ");
    Serial.print(" * ");
    temp_num = rand_num1*rand_num2;
  } else if (rand_operator == 3){
     if (rand_num2 == 0){
        display.print(" * ");
        Serial.print(" * ");
        temp_num = rand_num1*rand_num2;
     }
     else {
        display.print(" / ");
        Serial.print(" / ");
        temp_num = rand_num1/rand_num2;
      }
  }
  Serial.print((int)rand_num2);
  display.print((int)rand_num2);
  Serial.println("?");
  display.println("?");
  display.println();

  int rand_right = random(0,2);
  if (rand_right == 0){
    ans1 = temp_num;
    ans2 = temp_num-random(10);
    while (ans1 == ans2){
//      Serial.println("Были одинаковые числа в ответах 2.");
      ans1 = temp_num;
      ans2 = temp_num-random(10);
    }
      Serial.print("Правильный ответ: ");
  Serial.print(ans1);
    Serial.print(" (");
  Serial.print(rand_right+1);
    Serial.println(")");
  }
  else if (rand_right == 1){
    ans1 = temp_num-random(10);
    ans2 = temp_num;
    while (ans1 == ans2){
//      Serial.println("Были одинаковые числа в ответах 1.");
      ans1 = temp_num-random(10);
      ans2 = temp_num;
    }
          Serial.print("Правильный ответ: ");
  Serial.print(ans2);
    Serial.print(" (");
  Serial.print(rand_right+1);
    Serial.println(")");
  }
  display.print("1 - ");
  display.println(ans1);
  display.print("2 - ");
  display.println(ans2);
  display.print("Счет:");
  display.println(score);
  display.display();

  bool finish = true;
  while (finish){
    if (digitalRead(10) == 0 and rand_right == 0){
      Serial.println("Выбран правильный вариант 1");
      score++;
      finish  = false;
      }
    else if (digitalRead(9) == 0 and rand_right == 1){
      Serial.println("Выбран правильный вариант 2");
      score++;
      finish  = false;
    } else if (digitalRead(10) == 0 and rand_right == 1){
      Serial.println("Ответ неверный!");
      finish  = false;
    }
    else if (digitalRead(9) == 0 and rand_right == 0){
      Serial.println("Ответ неверный!");
      finish  = false;
    }
  }  
      delay(1000);
      return;
}

void setup() {
    randomSeed(analogRead(micros()));
  Serial.begin(9600);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  display.begin();
  Serial.println("Game started!");
  display.clearDisplay();
  display.setContrast(80);
  display.setCursor(0, 0); 
  display.setTextSize(2); 
  display.println("ЭРУДИТ");
  display.setTextSize(1);
  display.println();
  display.println("Автор:");
  display.println("Катков Илья");
  display.display();
  delay(1000);
}

 
void loop() {
  
  getQuestion();
}
