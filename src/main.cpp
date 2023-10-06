#include <Arduino.h>
#include <Network.h>
#include <Sensor.h>

const char *api_key = "API_KEY";
const char *user_email = "USER_EMAIL";
const char *user_password = "USER_PASSWORD";
const char *firebase_project_id = "FIREBASE_PROJECT_ID";

const char *ssid = "SSID";
const char *password = "PASSWORD";

int mq4_pin = 34;
int mq135_pin = 35;

Network *network;
Sensor *sensor;

void network_init();
void sensor_init();

void setup()
{
  Serial.begin(115200);
  network_init();
  sensor_init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  float mq4 = sensor->get_MQ4();
  float mq135 = sensor->get_MQ135();
  Serial.print("MQ4: ");
  Serial.println(mq4);
  Serial.print("MQ135: ");
  Serial.println(mq135);
}

void network_init()
{
  network = new Network();
  network->init_wifi(ssid, password);
  network->init_firebase(api_key, user_email, user_password, firebase_project_id);
}

void sensor_init()
{
  sensor = new Sensor();
  sensor->init_MQ4(mq4_pin);
  sensor->init_MQ135(mq135_pin);
}