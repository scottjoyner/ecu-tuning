#include "driver/twai.h"
#include <map>  // To track seen CAN IDs

std::map<uint32_t, bool> seen_ids;

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing CAN Inspector...");

  // Configure CAN pins and speed
  twai_general_config_t g_config = TWAI_GENERAL_CONFIG_DEFAULT(GPIO_NUM_5, GPIO_NUM_4, TWAI_MODE_NORMAL); // TX = GPIO5, RX = GPIO4
  twai_timing_config_t t_config = TWAI_TIMING_CONFIG_500KBITS();
  twai_filter_config_t f_config = TWAI_FILTER_CONFIG_ACCEPT_ALL();

  // Install and start the CAN driver
  twai_driver_install(&g_config, &t_config, &f_config);
  twai_start();

  Serial.println("CAN Bus Initialized at 500 kbps...");
}

void loop() {
  twai_message_t message;
  if (twai_receive(&message, pdMS_TO_TICKS(1000)) == ESP_OK) {
    // Check if this ID has been seen before
    bool is_new_id = (seen_ids.find(message.identifier) == seen_ids.end());
    if (is_new_id) {
      seen_ids[message.identifier] = true;
    }

    // Print message
    Serial.printf("[CAN] ID: 0x%03X DLC: %d%s Data:", message.identifier, message.data_length_code,
                  is_new_id ? " [NEW]" : "");
    for (int i = 0; i < message.data_length_code; i++) {
      Serial.printf(" %02X", message.data[i]);
    }
    Serial.println();
  }
}
