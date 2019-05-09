
#include "esp32-mqtt.h"
#include <ArduinoJson.h>

RTC_DATA_ATTR int doorbellPressedCounter = 0;

unsigned long heartbeatTimestamp = 0;
unsigned long heartbeatInterval = 30; //min

int MS_M_FACTOR = 60000;

const String sensorId = "6e039d00-6825-11e9-b740-d58f0755db70";
//const String sensorId = "74bf6730-6692-11e9-9aad-5f278de1925b";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  setupCloudIoT();
  
  pinMode(GPIO_NUM_34, INPUT);

  Serial.println("MAC: ");
  Serial.println(WiFi.macAddress());
}

void loop() {

  // allocate the memory for the document
  const size_t CAPACITY = JSON_OBJECT_SIZE(53);
  StaticJsonDocument<CAPACITY> notificationPayloadDoc;
  StaticJsonDocument<CAPACITY> heartbeatPayloadDoc;

  // create an object
  JsonObject notificationPayloadObject = notificationPayloadDoc.to<JsonObject>();
  notificationPayloadObject["id"] = sensorId;

  String notificationPayload;
  serializeJson(notificationPayloadDoc, notificationPayload);

  float battery_level = (float(analogRead(GPIO_NUM_35)) / 4095)*2*3.3*1.1;
  
  mqttClient->loop();
  
  delay(10);  // <- fixes some issues with WiFi stability

  if (!mqttClient->connected())
  {
      connect();
  }

  if(digitalRead(GPIO_NUM_34) == HIGH)
  {
      Serial.println("Sending notification");
      publishTelemetry("/notification", notificationPayload);
  
      ++doorbellPressedCounter;

      delay(1000);
  }

  long rssi = WiFi.RSSI();
  
  JsonObject heartbeatPayloadObject = heartbeatPayloadDoc.to<JsonObject>();
  heartbeatPayloadObject["id"] = sensorId;
  heartbeatPayloadObject["battery_level"] = battery_level;
  heartbeatPayloadObject["signal_strength"] = rssi;
  heartbeatPayloadObject["notification_counter"] = doorbellPressedCounter;
  
  String heartbeatPayload;
  serializeJson(heartbeatPayloadDoc, heartbeatPayload);


  if( millis() - heartbeatTimestamp > heartbeatInterval * MS_M_FACTOR )
  {
      heartbeatTimestamp += heartbeatInterval * MS_M_FACTOR;
    
      Serial.println("Sending heartbeat");
      publishTelemetry("/heartbeat", heartbeatPayload);    
  }

  delay(100);
}
