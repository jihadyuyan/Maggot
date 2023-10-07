#ifndef Network_H_
#define Network_H_

#include <WiFi.h>
#include <Firebase_ESP_Client.h>

class Network
{
private:
    /* data */
    FirebaseData fbdo;
    FirebaseAuth auth;
    FirebaseConfig config;

    friend void WiFiEventConnected(WiFiEvent_t event, WiFiEventInfo_t info);
    friend void WiFiEventDisconnected(WiFiEvent_t event, WiFiEventInfo_t info);
    friend void WiFiEventGotIP(WiFiEvent_t event, WiFiEventInfo_t info);

public:
    Network();
    void init_wifi(const char *ssid, const char *password);
    void init_firebase(const char *api_key, const char *user_email, const char *user_password, const char *firebase_project_id);
};

#endif // !Network_H_
