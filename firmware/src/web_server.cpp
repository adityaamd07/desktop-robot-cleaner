#include "web_server.hpp"

web_server::web_server(const char* ssid, const char* password)
    : ssid(ssid), password(password), server(80),
      current_command(drive_state::STOPPED), last_command_time(0) {}

void web_server::begin() {
    
    if(!password){
        WiFi.begin(ssid);
    }else{
        WiFi.begin(ssid, password);
    }
    Serial.print("Connecting to WiFi");
    
    int attempts = 0;

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        attempts++;
        if (attempts > 20) {
            Serial.println();
            Serial.print("WiFi status code: ");
            Serial.println(WiFi.status());
            attempts = 0;
        }
    }

    Serial.print("Connected. IP: ");
    Serial.println(WiFi.localIP());

    setup_routes();
    server.begin();
}

void web_server::setup_routes() {
    auto makeRoute = [this](const char* path, drive_state cmd) {
        server.on(path, HTTP_GET, [this, cmd](AsyncWebServerRequest *request) {
            handle_command(cmd);
            request->send(200, "text/plain", "ok");
        });
    };

    makeRoute("/forward/start",  drive_state::FORWARD);
    makeRoute("/backward/start", drive_state::BACKWARD);
    makeRoute("/left/start",     drive_state::TURNING_LEFT);
    makeRoute("/right/start",    drive_state::TURNING_RIGHT);
    makeRoute("/stop",           drive_state::STOPPED);  // all */stop routes can hit this

    // Heartbeat while a button stays held — resets the watchdog clock
    // without changing which direction is active
    server.on("/ping", HTTP_GET, [this](AsyncWebServerRequest *request) {
        last_command_time = millis();
        request->send(200, "text/plain", "ok");
    });
}

void web_server::handle_command(drive_state cmd) {
    current_command = cmd;
    last_command_time = millis();
}

void web_server::update() {
    bool timedOut = (millis() - last_command_time) > timeout_ms;
    if (current_command != drive_state::STOPPED && timedOut) {
        current_command = drive_state::STOPPED;  // dead man's switch firing
    }
}

drive_state web_server::get_current_command() {
    return  current_command;
}