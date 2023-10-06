#include <Arduino.h>
#include <Network.h>

const char *api_key = "API_KEY";
const char *user_email = "USER_EMAIL";
const char *user_password = "USER_PASSWORD";
const char *firebase_project_id = "FIREBASE_PROJECT_ID";

const char *ssid = "SSID";
const char *password = "PASSWORD";

Network *network;

void network_init();

void setup()
{
  Serial.begin(115200);
  network_init();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

void network_init()
{
  network = new Network();
  network->init_wifi(ssid, password);
  network->init_firebase(api_key, user_email, user_password, firebase_project_id);
}