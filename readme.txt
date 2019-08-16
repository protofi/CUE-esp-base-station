/*
add

int getReturnCode();

to CloudIoTCoreMqtt.h
*/
/*
add 

int CloudIoTCoreMqtt::getReturnCode() {
  return this->mqttClient->returnCode();
}

to CloudIoTCoreMqtt.cpp
 */