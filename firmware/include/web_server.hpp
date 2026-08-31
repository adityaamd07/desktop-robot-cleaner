# pragma once


# include <WiFi.h>
# include <ESPAsyncWebServer.h>
# include "types.hpp"
/*

 * web_Server owns the async HTTP server and allows a browser-based control
 * page to drive the robot. The server exposes the browser's most recent drive
 * command to the rest of the robot via get_command().
 *
 * REPRESENTATION INVARIANTS:
 *  - current_command always reflects the most recent command the
 *    browser is believed to still want, OR drive_state::STOPPED if
 *    the command has been timed out. A command is never left running for longer
 *    than timout_ms past the last received request.
 *  - last_command_time is updated on EVERY route that represents the
 *    browser actively communicating (start routes, /stop, /ping) --
 *    never left unset while current_command != STOPPED.
 *  - update() must be called every pass of loop(). If it isn't, the
 *   timeout logic can fail, and a dropped connection may leave the
 *    robot driving indefinitely.
 *
 * CONCURRENCY NOTE:
 *  - current_command and last_command_time are written from route
 *    callbacks, which run on the AsyncTCP task. They are read from 
 *    loop() via update() and getCurrentCommand(). Both are declared 
 *    volatile` for this reason: do not remove volatile, and do not add any derived/
 *    cached copies of these values elsewhere without the same care.
 *  - No motor or actuator code should ever be called directly from
 *    a route callback. Callbacks only ever update state; loop() is
 *    solely responsible for acting on that state.
 *
 * STATES (see types.hpp):
 *  - drive_state::STOPPED, FORWARD, BACKWARD, LEFT, RIGHT
 *  - Only one state is active at a time -- this class does not
 *    support simultaneous commands (e.g. FORWARD+LEFT is not
 *    represented; the frontend is expected to only ever hold one
 *    direction button at a time).
 *
 * OWNERSHIP:
 *  - This class owns the AsyncWebServer instance and WiFi connection
 *    lifecycle. begin() must be called once, in setup(), before any
 *    other method is used.
 */
class web_server {
    public:
        
    web_server(const char* ssid, const char* password);

        // Connects to WiFi and starts the async listener. Called once in setup().
        void begin();

        // Caled every pass of loop()
        // Nothing network-related happens here; it only reads/updates state.
        void update();

        // What the motor logic in loop() should be doing right now
        drive_state get_current_command();

    private:
        void setup_routes();
        void handle_command(drive_state cmd);

        const char* ssid;
        const char* password;
        AsyncWebServer server;

        // Written by async callbacks (other core), read by loop() (this core).
        // volatile = always re-read the real value, never assume it's unchanged.
        volatile drive_state current_command;
        volatile unsigned long last_command_time;

        static const unsigned long timeout_ms = 400;
};