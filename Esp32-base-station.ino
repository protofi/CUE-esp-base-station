
#include "esp32-mqtt.h"
#include <ArduinoJson.h>

#define uS_TO_M_FACTOR 60000000  /* Conversion factor for micro seconds to seconds */

const uint32_t TIME_TO_SLEEP = 60;  /* Time ESP32 will go to sleep (in minuts) */ 

const String sensorId = "74bf6730-6692-11e9-9aad-5f278de1925b";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  setupCloudIoT();
  
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_M_FACTOR); //wake up every hour
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_34,1); //1 = High, 0 = Low  
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
  Serial.print("Battery Voltage = "); Serial.print(battery_level, 2); Serial.println(" V"); 

  JsonObject heartbeatPayloadObject = heartbeatPayloadDoc.to<JsonObject>();
  heartbeatPayloadObject["id"] = sensorId;
  heartbeatPayloadObject["battery_level"] = battery_level;
  heartbeatPayloadObject["signal_strength"] = "123";
  
  String heartbeatPayload;
  serializeJson(heartbeatPayloadDoc, heartbeatPayload);

  mqttClient->loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!mqttClient->connected()) {
    connect();
  }

  esp_sleep_wakeup_cause_t wakeup_reason;
  wakeup_reason = esp_sleep_get_wakeup_cause();

  if(wakeup_reason == ESP_SLEEP_WAKEUP_EXT0)
  {
      Serial.println("Sending notification");
      publishTelemetry("/notification", notificationPayload);
  }

  //if(wakeup_reason == ESP_SLEEP_WAKEUP_TIMER)
  //{
      publishTelemetry("/heartbeat", heartbeatPayload);    
  //}

  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }

  delay(2000);
  
  //Go to sleep now
  Serial.println("Going to sleep now");
  esp_deep_sleep_start();
}
