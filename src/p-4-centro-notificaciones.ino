#define SWITCH_PIN A4

const String FACEBOOK = "facebook";
const String GOOGLE_EMAIL = "gmail";

// Published function
unsigned short notifyService(String serviceName);

bool cloudConnection();
bool checkNotificationReset();
void flashServiceNotifications();
void flashNotification(uint32_t color);

static unsigned short facebookNotifications;
static unsigned short gmailNotifications;
static bool resetSwitch;

void setup() {
    RGB.control(true);

    pinMode(D7, OUTPUT);

    pinMode(SWITCH_PIN, INPUT_PULLUP);
    resetSwitch = !digitalRead(SWITCH_PIN);

    // Initialize notification counter variables
    facebookNotifications = 0;
    gmailNotifications = 0;

    Particle.function("notify", notifyService);
}

void loop() {
    cloudConnection();
    checkNotificationReset();
    flashServiceNotifications();

    delay(1500);
}

/** Increment the pending notification counter for the service
 *  identified by the string parameter provided.
 *  Return the current number of pending notifications for that service. */
unsigned short notifyService(String serviceName) {
    unsigned short notifications = 0;
    serviceName = serviceName.toLowerCase();
    
    if (FACEBOOK.equals(serviceName)) {
        notifications = ++facebookNotifications;
    }
    if (GOOGLE_EMAIL.equals(serviceName)) {
        notifications = ++gmailNotifications;
    }
    return notifications;
}

/** Check connection to the Particle cloud.
 *  If disconnected, try to connect.
 *  Light the D7 LED accordingly to the current connection status. */
bool cloudConnection() {
    bool connected = Particle.connected();
    if (!connected) {
        Particle.connect();
    }

    connected = Particle.connected();
    digitalWrite(D7, connected ? HIGH : LOW);
    return connected;
}

/** Read the voltage in the switch pin.
 *  If the circuit is closed and the previous time the function executed
 *  it was open (this is, the button has been pressed), the pending notification
 *  counters for all services are reset back. The variable notifReset's value
 *  is updated to the current (inverse) status of the switch pin.
 *  Return whether this execution performed a reset from a button press. */
bool checkNotificationReset() {
    bool buttonPressed = !digitalRead(SWITCH_PIN);
    bool notificationReset = !resetSwitch && buttonPressed;
    
    if (notificationReset) {
        facebookNotifications = 0;
        gmailNotifications = 0;
    }
    resetSwitch = buttonPressed;

    return notificationReset;
}

/** Flash the RGB led for those services that hold pending notifications,
 *  setting a color that indicates the service's identity. */
void flashServiceNotifications() {
    if (facebookNotifications > 0) {
        flashNotification(RGB_COLOR_BLUE);
    }
    if (gmailNotifications > 0) {
        flashNotification(RGB_COLOR_RED);
    }
}

void flashNotification(uint32_t color) {
    RGB.color(color);
    RGB.brightness(0x40);
    delay(1000);
    RGB.brightness(0);
    delay(500);
}
