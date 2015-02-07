MCP 9700A
=========

This is a fairly simple temperature sensor.

Data Sheet: http://pdf1.alldatasheet.com/datasheet-pdf/view/195326/MICROCHIP/MCP9700-E/TO.html

The Important bits: 
For the TO-92 (breadboard mount) there are three pins:

From the top (with the pins in a breadboard) and the round section facing away from you the pins go 1 - 2 -3 from right to left.

1 - Source Voltage
2 - Output Voltage
3 - Ground

Output will be a Voltage reading.  At 0C it will read 500mv (.5V) with 10mv per degree C variation.

so 600mv is 10C (500mv at 0, 100mv = 10 degrees).

The code is fairly simple to get this:

    int iTemp = analogRead(4);///1024.0;
    Serial.print("Raw Read: " );
    Serial.println(iTemp);
    float temp = (iTemp * 5) / 1024.0;
    Serial.print("Scaled temp: ");
    Serial.println(temp);

    float tempC = (temp - .5) / 0.01;
    Serial.print("Temperature C: ");
    Serial.println(tempC);

    float tempF = (tempC * 1.8 ) + 32;
    Serial.print("Temperature F: ");
    Serial.println(tempF);

The library is simple enough:

float tempReadFarenheit(PIN);
float tempReadCelcius(PIN);

Note that I'm not checking if it's an analog in pin or not.  Assuming it is
