#ifndef Sensor_H_
#define Sensor_H_

#include <MQUnifiedsensor.h>

class Sensor
{
private:
    /* data */

public:
    Sensor();
    void init_MQ4(int mq4_pin);
    void init_MQ135(int mq135_pin);
    float get_MQ4();
    float get_MQ135();
};

#endif // !Sensor_H_