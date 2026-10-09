#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
typedef enum {
    SAFE_MODE,
    NORMAL_MODE,
    IMAGING_MODE,
    COMMUNICATION_MODE,
} cubesat_mode;

typedef struct {
    uint8_t status;
    cubesat_mode mode;
    uint16_t battery_level;
    bool payload_active;
    float temperature;
} cubesat_status;

#define STATUS_EPS_OK      (1u << 0)
#define STATUS_ADCS_OK     (1u << 1)
#define STATUS_OBC_OK      (1u << 2)
#define STATUS_COMMS_OK    (1u << 3)
#define STATUS_PAYLOAD_OK  (1u << 4)

static bool is_status_set(uint8_t status, uint8_t mask)
{
    return (status & mask) != 0u;
}

static const char *get_mode_name(cubesat_mode mode)
{
    switch (mode)
    {
        case SAFE_MODE:          return "SAFE";
        case NORMAL_MODE:        return "NORMAL";
        case IMAGING_MODE:       return "IMAGING";
        case COMMUNICATION_MODE: return "COMMUNICATION";
        default:                 return "INVALID";
    }
}

cubesat_status cubesat = {
    .status = STATUS_EPS_OK | STATUS_ADCS_OK | STATUS_OBC_OK | STATUS_COMMS_OK | STATUS_PAYLOAD_OK,
    .mode = NORMAL_MODE,
    .battery_level = 100,
    .payload_active = false,
    .temperature = 25.0f
};


int main(){
    printf("Cubesat Status:\n");
    printf("Status: 0x%02X\n", cubesat.status);
    printf("Mode: %s\n", get_mode_name(cubesat.mode));
    printf("Battery Level: %u%%\n", cubesat.battery_level);
    printf("EPS OK: %s\n", is_status_set(cubesat.status, STATUS_EPS_OK) ? "Yes" : "No");
    printf("ADCS OK: %s\n", is_status_set(cubesat.status, STATUS_ADCS_OK) ? "Yes" : "No");
    printf("OBC OK: %s\n", is_status_set(cubesat.status, STATUS_OBC_OK) ? "Yes" : "No");
    printf("COMMS OK: %s\n", is_status_set(cubesat.status,STATUS_COMMS_OK) ? "Yes" : "No");
    printf("Payload Active: %s\n", cubesat.payload_active ? "Yes" : "No");
    printf("Temperature: %.2f°C\n", cubesat.temperature);
    return 0;
}