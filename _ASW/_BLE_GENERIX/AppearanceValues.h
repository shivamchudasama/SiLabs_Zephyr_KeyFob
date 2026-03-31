/**
 * @file          AppearanceValues.h
 * @brief         Header file containing Appearance Values definitions for the BLE application.
 * @date          25/02/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _APPEARANCE_VALUES_H
#define _APPEARANCE_VALUES_H

/******************************************************************************/
/*                                                                            */
/*                                  INCLUDES                                  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                  DEFINES                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @def           BLE_APPEARANCE_UNKNOWN
 * @brief         Unknown.
 */
#define BLE_APPEARANCE_UNKNOWN               ((0x000 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_PHONE
 * @brief         Phone.
 */
#define BLE_APPEARANCE_PHONE                 ((0x001 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_COMPUTER
 * @brief         Computer.
 */
#define BLE_APPEARANCE_COMPUTER              ((0x002 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_COMPUTER_DESKTOP_WORKSTATION
 * @brief         Desktop Workstation.
 */
#define BLE_APPEARANCE_COMPUTER_DESKTOP_WORKSTATION \
                                             ((0x002 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_COMPUTER_SERVER_CLASS_COMPUTER
 * @brief         Server-class Computer.
 */
#define BLE_APPEARANCE_COMPUTER_SERVER_CLASS_COMPUTER \
                                             ((0x002 << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_COMPUTER_LAPTOP
 * @brief         Laptop.
 */
#define BLE_APPEARANCE_COMPUTER_LAPTOP       ((0x002 << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_COMPUTER_HANDHELD_PC_PDA_CLAMSHELL
 * @brief         Handheld PC/PDA (clamshell).
 */
#define BLE_APPEARANCE_COMPUTER_HANDHELD_PC_PDA_CLAMSHELL \
                                             ((0x002 << 6) | 0x04)

/**
 * @def           BLE_APPEARANCE_COMPUTER_PALM_SIZE_PC_PDA
 * @brief         Palm-size PC/PDA.
 */
#define BLE_APPEARANCE_COMPUTER_PALM_SIZE_PC_PDA \
                                             ((0x002 << 6) | 0x05)

/**
 * @def           BLE_APPEARANCE_COMPUTER_WEARABLE_COMPUTER_WATCH_SIZE
 * @brief         Wearable computer (watch size).
 */
#define BLE_APPEARANCE_COMPUTER_WEARABLE_COMPUTER_WATCH_SIZE \
                                             ((0x002 << 6) | 0x06)

/**
 * @def           BLE_APPEARANCE_COMPUTER_TABLET
 * @brief         Tablet.
 */
#define BLE_APPEARANCE_COMPUTER_TABLET       ((0x002 << 6) | 0x07)

/**
 * @def           BLE_APPEARANCE_WATCH
 * @brief         Watch.
 */
#define BLE_APPEARANCE_WATCH                 ((0x003 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_WATCH_SPORTS_WATCH
 * @brief         Sports Watch.
 */
#define BLE_APPEARANCE_WATCH_SPORTS_WATCH    ((0x003 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_WATCH_SMARTWATCH
 * @brief         Smartwatch.
 */
#define BLE_APPEARANCE_WATCH_SMARTWATCH      ((0x003 << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_CLOCK
 * @brief         Clock.
 */
#define BLE_APPEARANCE_CLOCK                 ((0x004 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_DISPLAY
 * @brief         Display.
 */
#define BLE_APPEARANCE_DISPLAY               ((0x005 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_REMOTE_CONTROL
 * @brief         Remote Control.
 */
#define BLE_APPEARANCE_REMOTE_CONTROL        ((0x006 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_EYE_GLASSES
 * @brief         Eye-glasses.
 */
#define BLE_APPEARANCE_EYE_GLASSES           ((0x007 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_TAG
 * @brief         Tag.
 */
#define BLE_APPEARANCE_TAG                   ((0x008 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_KEYRING
 * @brief         Keyring.
 */
#define BLE_APPEARANCE_KEYRING               ((0x009 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_MEDIA_PLAYER
 * @brief         Media Player.
 */
#define BLE_APPEARANCE_MEDIA_PLAYER          ((0x00A << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_BARCODE_SCANNER
 * @brief         Barcode Scanner.
 */
#define BLE_APPEARANCE_BARCODE_SCANNER       ((0x00B << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_THERMOMETER
 * @brief         Thermometer.
 */
#define BLE_APPEARANCE_THERMOMETER           ((0x00C << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_THERMOMETER_EAR_THERMOMETER
 * @brief         Ear Thermometer.
 */
#define BLE_APPEARANCE_THERMOMETER_EAR_THERMOMETER \
                                             ((0x00C << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_HEART_RATE_SENSOR
 * @brief         Heart Rate Sensor.
 */
#define BLE_APPEARANCE_HEART_RATE_SENSOR     ((0x00D << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_HEART_RATE_SENSOR_HEART_RATE_BELT
 * @brief         Heart Rate Belt.
 */
#define BLE_APPEARANCE_HEART_RATE_SENSOR_HEART_RATE_BELT \
                                             ((0x00D << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_BLOOD_PRESSURE
 * @brief         Blood Pressure.
 */
#define BLE_APPEARANCE_BLOOD_PRESSURE        ((0x00E << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_BLOOD_PRESSURE_ARM_BLOOD_PRESSURE
 * @brief         Arm Blood Pressure.
 */
#define BLE_APPEARANCE_BLOOD_PRESSURE_ARM_BLOOD_PRESSURE \
                                             ((0x00E << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_BLOOD_PRESSURE_WRIST_BLOOD_PRESSURE
 * @brief         Wrist Blood Pressure.
 */
#define BLE_APPEARANCE_BLOOD_PRESSURE_WRIST_BLOOD_PRESSURE \
                                             ((0x00E << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_HUMAN_INTERFACE_DEVICE
 * @brief         Human Interface Device.
 */
#define BLE_APPEARANCE_HUMAN_INTERFACE_DEVICE \
                                             ((0x00F << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_HUMAN_INTERFACE_DEVICE_KEYBOARD
 * @brief         Keyboard.
 */
#define BLE_APPEARANCE_HUMAN_INTERFACE_DEVICE_KEYBOARD \
                                             ((0x00F << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_HUMAN_INTERFACE_DEVICE_MOUSE
 * @brief         Mouse.
 */
#define BLE_APPEARANCE_HUMAN_INTERFACE_DEVICE_MOUSE \
                                             ((0x00F << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_GLUCOSE_METER
 * @brief         Glucose Meter.
 */
#define BLE_APPEARANCE_GLUCOSE_METER         ((0x010 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_RUNNING_WALKING_SENSOR
 * @brief         Running Walking Sensor.
 */
#define BLE_APPEARANCE_RUNNING_WALKING_SENSOR \
                                             ((0x011 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_RUNNING_WALKING_SENSOR_IN_SHOE_RUNNING_WALKING_SENSOR
 * @brief         In-Shoe Running Walking Sensor.
 */
#define BLE_APPEARANCE_RUNNING_WALKING_SENSOR_IN_SHOE_RUNNING_WALKING_SENSOR \
                                             ((0x011 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_RUNNING_WALKING_SENSOR_ON_SHOE_RUNNING_WALKING_SENSOR
 * @brief         On-Shoe Running Walking Sensor.
 */
#define BLE_APPEARANCE_RUNNING_WALKING_SENSOR_ON_SHOE_RUNNING_WALKING_SENSOR \
                                             ((0x011 << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_RUNNING_WALKING_SENSOR_ON_HIP_RUNNING_WALKING_SENSOR
 * @brief         On-Hip Running Walking Sensor.
 */
#define BLE_APPEARANCE_RUNNING_WALKING_SENSOR_ON_HIP_RUNNING_WALKING_SENSOR \
                                             ((0x011 << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_CYCLING
 * @brief         Cycling.
 */
#define BLE_APPEARANCE_CYCLING               ((0x012 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_CYCLING_CYCLING_COMPUTER
 * @brief         Cycling Computer.
 */
#define BLE_APPEARANCE_CYCLING_CYCLING_COMPUTER \
                                             ((0x012 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_CYCLING_SPEED_SENSOR
 * @brief         Speed Sensor.
 */
#define BLE_APPEARANCE_CYCLING_SPEED_SENSOR  ((0x012 << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_CYCLING_CADENCE_SENSOR
 * @brief         Cadence Sensor.
 */
#define BLE_APPEARANCE_CYCLING_CADENCE_SENSOR \
                                             ((0x012 << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_CYCLING_POWER_SENSOR
 * @brief         Power Sensor.
 */
#define BLE_APPEARANCE_CYCLING_POWER_SENSOR  ((0x012 << 6) | 0x04)

/**
 * @def           BLE_APPEARANCE_CYCLING_SPEED_AND_CADENCE_SENSOR
 * @brief         Speed and Cadence Sensor.
 */
#define BLE_APPEARANCE_CYCLING_SPEED_AND_CADENCE_SENSOR \
                                             ((0x012 << 6) | 0x05)

/**
 * @def           BLE_APPEARANCE_CONTROL_DEVICE
 * @brief         Control Device.
 */
#define BLE_APPEARANCE_CONTROL_DEVICE        ((0x013 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_CONTROL_DEVICE_SWITCH
 * @brief         Switch.
 */
#define BLE_APPEARANCE_CONTROL_DEVICE_SWITCH \
                                             ((0x013 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_CONTROL_DEVICE_MULTI_SWITCH
 * @brief         Multi-switch.
 */
#define BLE_APPEARANCE_CONTROL_DEVICE_MULTI_SWITCH \
                                             ((0x013 << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_CONTROL_DEVICE_BUTTON
 * @brief         Button.
 */
#define BLE_APPEARANCE_CONTROL_DEVICE_BUTTON \
                                             ((0x013 << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_CONTROL_DEVICE_SLIDER
 * @brief         Slider.
 */
#define BLE_APPEARANCE_CONTROL_DEVICE_SLIDER \
                                             ((0x013 << 6) | 0x04)

/**
 * @def           BLE_APPEARANCE_CONTROL_DEVICE_ROTARY_SWITCH
 * @brief         Rotary Switch.
 */
#define BLE_APPEARANCE_CONTROL_DEVICE_ROTARY_SWITCH \
                                             ((0x013 << 6) | 0x05)

/**
 * @def           BLE_APPEARANCE_NETWORK_DEVICE
 * @brief         Network Device.
 */
#define BLE_APPEARANCE_NETWORK_DEVICE        ((0x014 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_NETWORK_DEVICE_ACCESS_POINT
 * @brief         Access Point.
 */
#define BLE_APPEARANCE_NETWORK_DEVICE_ACCESS_POINT \
                                             ((0x014 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_NETWORK_DEVICE_MESH_DEVICE
 * @brief         Mesh Device.
 */
#define BLE_APPEARANCE_NETWORK_DEVICE_MESH_DEVICE \
                                             ((0x014 << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_NETWORK_DEVICE_MESH_NETWORK_PROXY
 * @brief         Mesh Network Proxy.
 */
#define BLE_APPEARANCE_NETWORK_DEVICE_MESH_NETWORK_PROXY \
                                             ((0x014 << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_SENSOR
 * @brief         Sensor.
 */
#define BLE_APPEARANCE_SENSOR                ((0x015 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_SENSOR_MOTION_SENSOR
 * @brief         Motion Sensor.
 */
#define BLE_APPEARANCE_SENSOR_MOTION_SENSOR  ((0x015 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_SENSOR_TEMPERATURE_SENSOR
 * @brief         Temperature Sensor.
 */
#define BLE_APPEARANCE_SENSOR_TEMPERATURE_SENSOR \
                                             ((0x015 << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_SENSOR_HUMIDITY_SENSOR
 * @brief         Humidity Sensor.
 */
#define BLE_APPEARANCE_SENSOR_HUMIDITY_SENSOR \
                                             ((0x015 << 6) | 0x04)

/**
 * @def           BLE_APPEARANCE_SENSOR_SMOKE_SENSOR
 * @brief         Smoke Sensor.
 */
#define BLE_APPEARANCE_SENSOR_SMOKE_SENSOR   ((0x015 << 6) | 0x06)

/**
 * @def           BLE_APPEARANCE_SENSOR_OCCUPANCY_SENSOR
 * @brief         Occupancy Sensor.
 */
#define BLE_APPEARANCE_SENSOR_OCCUPANCY_SENSOR \
                                             ((0x015 << 6) | 0x07)

/**
 * @def           BLE_APPEARANCE_LIGHT_FIXTURES
 * @brief         Light Fixtures.
 */
#define BLE_APPEARANCE_LIGHT_FIXTURES        ((0x016 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_LIGHT_FIXTURES_WALL_LIGHT
 * @brief         Wall Light.
 */
#define BLE_APPEARANCE_LIGHT_FIXTURES_WALL_LIGHT \
                                             ((0x016 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_FAN
 * @brief         Fan.
 */
#define BLE_APPEARANCE_FAN                   ((0x017 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_FAN_CEILING_FAN
 * @brief         Ceiling Fan.
 */
#define BLE_APPEARANCE_FAN_CEILING_FAN       ((0x017 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_HVAC
 * @brief         HVAC.
 */
#define BLE_APPEARANCE_HVAC                  ((0x018 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_AIR_CONDITIONING
 * @brief         Air Conditioning.
 */
#define BLE_APPEARANCE_AIR_CONDITIONING      ((0x019 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_HUMIDIFIER
 * @brief         Humidifier.
 */
#define BLE_APPEARANCE_HUMIDIFIER            ((0x01A << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_HEATING
 * @brief         Heating.
 */
#define BLE_APPEARANCE_HEATING               ((0x01B << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_ACCESS_CONTROL
 * @brief         Access Control.
 */
#define BLE_APPEARANCE_ACCESS_CONTROL        ((0x01C << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_MOTORIZED_DEVICE
 * @brief         Motorized Device.
 */
#define BLE_APPEARANCE_MOTORIZED_DEVICE      ((0x01D << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_POWER_DEVICE
 * @brief         Power Device.
 */
#define BLE_APPEARANCE_POWER_DEVICE          ((0x01E << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_POWER_DEVICE_POWER_OUTLET
 * @brief         Power Outlet.
 */
#define BLE_APPEARANCE_POWER_DEVICE_POWER_OUTLET \
                                             ((0x01E << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_POWER_DEVICE_POWER_STRIP
 * @brief         Power Strip.
 */
#define BLE_APPEARANCE_POWER_DEVICE_POWER_STRIP \
                                             ((0x01E << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_POWER_DEVICE_PLUG
 * @brief         Plug.
 */
#define BLE_APPEARANCE_POWER_DEVICE_PLUG     ((0x01E << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_POWER_DEVICE_POWER_SUPPLY
 * @brief         Power Supply.
 */
#define BLE_APPEARANCE_POWER_DEVICE_POWER_SUPPLY \
                                             ((0x01E << 6) | 0x04)

/**
 * @def           BLE_APPEARANCE_POWER_DEVICE_LED_DRIVER
 * @brief         LED Driver.
 */
#define BLE_APPEARANCE_POWER_DEVICE_LED_DRIVER \
                                             ((0x01E << 6) | 0x05)

/**
 * @def           BLE_APPEARANCE_POWER_DEVICE_POWER_BANK
 * @brief         Power Bank.
 */
#define BLE_APPEARANCE_POWER_DEVICE_POWER_BANK \
                                             ((0x01E << 6) | 0x09)

/**
 * @def           BLE_APPEARANCE_LIGHT_SOURCE
 * @brief         Light Source.
 */
#define BLE_APPEARANCE_LIGHT_SOURCE          ((0x01F << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_LIGHT_SOURCE_LED_LAMP
 * @brief         LED Lamp.
 */
#define BLE_APPEARANCE_LIGHT_SOURCE_LED_LAMP \
                                             ((0x01F << 6) | 0x02)

/**
 * @def           BLE_APPEARANCE_LIGHT_SOURCE_MULTI_COLOR_LED_ARRAY
 * @brief         Multi-Color LED Array.
 */
#define BLE_APPEARANCE_LIGHT_SOURCE_MULTI_COLOR_LED_ARRAY \
                                             ((0x01F << 6) | 0x06)

/**
 * @def           BLE_APPEARANCE_WINDOW_COVERING
 * @brief         Window Covering.
 */
#define BLE_APPEARANCE_WINDOW_COVERING       ((0x020 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_WINDOW_COVERING_WINDOW_SHADES
 * @brief         Window Shades.
 */
#define BLE_APPEARANCE_WINDOW_COVERING_WINDOW_SHADES \
                                             ((0x020 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_AUDIO_SINK
 * @brief         Audio Sink.
 */
#define BLE_APPEARANCE_AUDIO_SINK            ((0x021 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_AUDIO_SINK_STANDALONE_SPEAKER
 * @brief         Standalone Speaker.
 */
#define BLE_APPEARANCE_AUDIO_SINK_STANDALONE_SPEAKER \
                                             ((0x021 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_AUDIO_SOURCE
 * @brief         Audio Source.
 */
#define BLE_APPEARANCE_AUDIO_SOURCE          ((0x022 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_AUDIO_SOURCE_MICROPHONE
 * @brief         Microphone.
 */
#define BLE_APPEARANCE_AUDIO_SOURCE_MICROPHONE \
                                             ((0x022 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_AUDIO_SOURCE_BROADCASTING_DEVICE
 * @brief         Broadcasting Device.
 */
#define BLE_APPEARANCE_AUDIO_SOURCE_BROADCASTING_DEVICE \
                                             ((0x022 << 6) | 0x05)

/**
 * @def           BLE_APPEARANCE_MOTORIZED_VEHICLE
 * @brief         Motorized Vehicle.
 */
#define BLE_APPEARANCE_MOTORIZED_VEHICLE     ((0x023 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_MOTORIZED_VEHICLE_CAR
 * @brief         Car.
 */
#define BLE_APPEARANCE_MOTORIZED_VEHICLE_CAR \
                                             ((0x023 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_MOTORIZED_VEHICLE_2_WHEELED_VEHICLE
 * @brief         2-Wheeled Vehicle.
 */
#define BLE_APPEARANCE_MOTORIZED_VEHICLE_2_WHEELED_VEHICLE \
                                             ((0x023 << 6) | 0x03)

/**
 * @def           BLE_APPEARANCE_MOTORIZED_VEHICLE_SCOOTER
 * @brief         Scooter.
 */
#define BLE_APPEARANCE_MOTORIZED_VEHICLE_SCOOTER \
                                             ((0x023 << 6) | 0x05)

/**
 * @def           BLE_APPEARANCE_DOMESTIC_APPLIANCE
 * @brief         Domestic Appliance.
 */
#define BLE_APPEARANCE_DOMESTIC_APPLIANCE    ((0x024 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_DOMESTIC_APPLIANCE_REFRIGERATOR
 * @brief         Refrigerator.
 */
#define BLE_APPEARANCE_DOMESTIC_APPLIANCE_REFRIGERATOR \
                                             ((0x024 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_DOMESTIC_APPLIANCE_WASHING_MACHINE
 * @brief         Washing Machine.
 */
#define BLE_APPEARANCE_DOMESTIC_APPLIANCE_WASHING_MACHINE \
                                             ((0x024 << 6) | 0x06)

/**
 * @def           BLE_APPEARANCE_WEARABLE_AUDIO_DEVICE
 * @brief         Wearable Audio Device.
 */
#define BLE_APPEARANCE_WEARABLE_AUDIO_DEVICE \
                                             ((0x025 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_WEARABLE_AUDIO_DEVICE_EARBUD
 * @brief         Earbud.
 */
#define BLE_APPEARANCE_WEARABLE_AUDIO_DEVICE_EARBUD \
                                             ((0x025 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_AIRCRAFT
 * @brief         Aircraft.
 */
#define BLE_APPEARANCE_AIRCRAFT              ((0x026 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_AIRCRAFT_LIGHT_AIRCRAFT
 * @brief         Light Aircraft.
 */
#define BLE_APPEARANCE_AIRCRAFT_LIGHT_AIRCRAFT \
                                             ((0x026 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_AV_EQUIPMENT
 * @brief         AV Equipment.
 */
#define BLE_APPEARANCE_AV_EQUIPMENT          ((0x027 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_AV_EQUIPMENT_AMPLIFIER
 * @brief         Amplifier.
 */
#define BLE_APPEARANCE_AV_EQUIPMENT_AMPLIFIER \
                                             ((0x027 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_DISPLAY_EQUIPMENT
 * @brief         Display Equipment.
 */
#define BLE_APPEARANCE_DISPLAY_EQUIPMENT     ((0x028 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_DISPLAY_EQUIPMENT_TELEVISION
 * @brief         Television.
 */
#define BLE_APPEARANCE_DISPLAY_EQUIPMENT_TELEVISION \
                                             ((0x028 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_HEARING_AID
 * @brief         Hearing aid.
 */
#define BLE_APPEARANCE_HEARING_AID           ((0x029 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_HEARING_AID_IN_EAR_HEARING_AID
 * @brief         In-ear hearing aid.
 */
#define BLE_APPEARANCE_HEARING_AID_IN_EAR_HEARING_AID \
                                             ((0x029 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_GAMING
 * @brief         Gaming.
 */
#define BLE_APPEARANCE_GAMING                ((0x02A << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_GAMING_HOME_VIDEO_GAME_CONSOLE
 * @brief         Home Video Game Console.
 */
#define BLE_APPEARANCE_GAMING_HOME_VIDEO_GAME_CONSOLE \
                                             ((0x02A << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_SIGNAGE
 * @brief         Signage.
 */
#define BLE_APPEARANCE_SIGNAGE               ((0x02B << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_SIGNAGE_DIGITAL_SIGNAGE
 * @brief         Digital Signage.
 */
#define BLE_APPEARANCE_SIGNAGE_DIGITAL_SIGNAGE \
                                             ((0x02B << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_PULSE_OXIMETER
 * @brief         Pulse Oximeter.
 */
#define BLE_APPEARANCE_PULSE_OXIMETER        ((0x031 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_WEIGHT_SCALE
 * @brief         Weight Scale.
 */
#define BLE_APPEARANCE_WEIGHT_SCALE          ((0x032 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_PERSONAL_MOBILITY_DEVICE
 * @brief         Personal Mobility Device.
 */
#define BLE_APPEARANCE_PERSONAL_MOBILITY_DEVICE \
                                             ((0x033 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_CONTINUOUS_GLUCOSE_MONITOR
 * @brief         Continuous Glucose Monitor.
 */
#define BLE_APPEARANCE_CONTINUOUS_GLUCOSE_MONITOR \
                                             ((0x034 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_INSULIN_PUMP
 * @brief         Insulin Pump.
 */
#define BLE_APPEARANCE_INSULIN_PUMP          ((0x035 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_INSULIN_PUMP_DURABLE_PUMP
 * @brief         Insulin Pump durable pump.
 */
#define BLE_APPEARANCE_INSULIN_PUMP_DURABLE_PUMP \
                                             ((0x035 << 6) | 0x01)

/**
 * @def           BLE_APPEARANCE_INSULIN_PUMP_PATCH_PUMP
 * @brief         Insulin Pump patch pump.
 */
#define BLE_APPEARANCE_INSULIN_PUMP_PATCH_PUMP \
                                             ((0x035 << 6) | 0x04)

/**
 * @def           BLE_APPEARANCE_SPIROMETER
 * @brief         Spirometer.
 */
#define BLE_APPEARANCE_SPIROMETER            ((0x037 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY
 * @brief         Outdoor Sports Activity.
 */
#define BLE_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY \
                                             ((0x051 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_INDUSTRIAL_MEASUREMENT_DEVICE
 * @brief         Industrial Measurement Device.
 */
#define BLE_APPEARANCE_INDUSTRIAL_MEASUREMENT_DEVICE \
                                             ((0x052 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_INDUSTRIAL_TOOLS
 * @brief         Industrial Tools.
 */
#define BLE_APPEARANCE_INDUSTRIAL_TOOLS      ((0x053 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_COOKWARE_DEVICE
 * @brief         Cookware Device.
 */
#define BLE_APPEARANCE_COOKWARE_DEVICE       ((0x054 << 6) | 0x00)

/**
 * @def           BLE_APPEARANCE_COOKWARE_DEVICE_PRESSURE_COOKER
 * @brief         Pressure Cooker.
 */
#define BLE_APPEARANCE_COOKWARE_DEVICE_PRESSURE_COOKER \
                                             ((0x054 << 6) | 0x02)

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                 STRUCTURES                                 */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                                   UNIONS                                   */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                              EXTERN VARIABLES                              */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                              EXTERN FUNCTIONS                              */
/*                                                                            */
/******************************************************************************/

#endif //!_APPEARANCE_VALUES_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
