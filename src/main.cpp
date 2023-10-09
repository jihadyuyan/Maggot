#include <Arduino.h>
#include <Network.h>
#include <Sensor.h>
#include <FuzzyLogic.h>

/********************** Firebase configuration*********************/
// const char *api_key = "AIzaSyC9Ms27sIya3-n0YC--HWss-ACAcM-PZIM";
// const char *user_email = "test@test.com";
// const char *user_password = "12345678";
// const char *firebase_project_id = "bismillah-sempro";

// /********************** WiFi configuration ************************/
// const char *ssid = "vivo 1719";
// const char *password = "onlyme1234";

/********************** Sensor configuration **********************/
int mq4_pin = 25;
int mq135_pin = 26;

FuzzyLogic *fuzzyLogic;
Network *network;
Sensor *sensor;

// void network_init();
void sensor_init();
void fuzzy_logic_init();

void setup()
{
  Serial.begin(115200);
  // network_init();
  sensor_init();
  fuzzy_logic_init();
}

void loop()
{
  // put your main code here, to run repeatedly:

  float nh3 = sensor->get_MQ135();
  float ch4 = sensor->get_MQ4();
  Serial.print("MQ135: ");
  Serial.println(nh3);
  Serial.print("MQ4: ");
  Serial.println(ch4);
  fuzzyLogic->fuzzy_compute(nh3, ch4, 10);
  delay(5000);
}

// void network_init()
// {
//   network = new Network();
//   network->init_wifi(ssid, password);
// network->init_firebase(api_key, user_email, user_password, firebase_project_id);
// }

void sensor_init()
{
  sensor = new Sensor();
  sensor->init_MQ4();
  sensor->init_MQ135();
}

void fuzzy_logic_init()
{
  fuzzyLogic = new FuzzyLogic();
  fuzzyLogic->fuzzy_init();
}