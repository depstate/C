int trigPin = 2;
int echoPin = 3;


#define MASK_LENGTH   10
int raw_array[MASK_LENGTH] = {0,};
int raw_array_index = 0;
float x;
/* Mask 크기만큼 데이터를 평균낸다. */
float movingAverageFilter()
{
    int i = 0;
    int sum = 0;

    for (i = 0; i < MASK_LENGTH; i++) {
      sum += raw_array[i];
    }
    return ((float)sum / MASK_LENGTH);
}

/* 새로운 데이터를 array에 넣는다. */
void insertIntoRawArray(int value)
{
    raw_array[raw_array_index] = value;

    raw_array_index++;

    if (raw_array_index >= MASK_LENGTH) {
      raw_array_index = 0;
    }
}



void setup(){
  Serial.begin(9600);       // 시리얼 속도 설정
  pinMode(echoPin, INPUT);   // echoPin 입력
  pinMode(trigPin, OUTPUT);  // trigPin 출력
  Serial.println("mm,평균");
}
 
void loop(){
  long duration, distance;
  digitalWrite(trigPin, HIGH);  // trigPin에서 초음파 발생(echoPin도 HIGH)
  //delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);    // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  distance = ((float)(340 * duration) / 1000) / 2; 

  //Serial.print("DIstance : "); // 물체와 초음파 센서간 거리를 표시
  Serial.print(distance);
  //Serial.println("mm");
  Serial.print(",");
  
  
   insertIntoRawArray(distance);
   // Serial.println("평균 : ");
    Serial.println(movingAverageFilter());
  delay(200);
}    
