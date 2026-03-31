/**
 * @file          PublicCharacteristicUUIDs.h
 * @brief         Header file containing Public Characteristic UUIDs.
 * @date          12/02/2026
 * @author        Shivam Chudasama [SC]
 * @copyright     Bajaj Auto Technology Limited (BATL)
 */

#ifndef _PUBLIC_CHARACTERISTIC_UUIDS_H
#define _PUBLIC_CHARACTERISTIC_UUIDS_H

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
 * @def           BLE_CHAR_DEVICE_NAME_UUID
 * @brief         Device Name.
 */
#define BLE_CHAR_DEVICE_NAME_UUID            (0x2A00)

/**
 * @def           BLE_CHAR_APPEARANCE_UUID
 * @brief         Appearance.
 */
#define BLE_CHAR_APPEARANCE_UUID             (0x2A01)

/**
 * @def           BLE_CHAR_PERIPHERAL_PRIVACY_FLAG_UUID
 * @brief         Peripheral Privacy Flag.
 */
#define BLE_CHAR_PERIPHERAL_PRIVACY_FLAG_UUID \
                                             (0x2A02)

/**
 * @def           BLE_CHAR_RECONNECTION_ADDRESS_UUID
 * @brief         Reconnection Address.
 */
#define BLE_CHAR_RECONNECTION_ADDRESS_UUID   (0x2A03)

/**
 * @def           BLE_CHAR_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS_UUID
 * @brief         Peripheral Preferred Connection Parameters.
 */
#define BLE_CHAR_PERIPHERAL_PREFERRED_CONNECTION_PARAMETERS_UUID \
                                             (0x2A04)

/**
 * @def           BLE_CHAR_SERVICE_CHANGED_UUID
 * @brief         Service Changed.
 */
#define BLE_CHAR_SERVICE_CHANGED_UUID        (0x2A05)

/**
 * @def           BLE_CHAR_ALERT_LEVEL_UUID
 * @brief         Alert Level.
 */
#define BLE_CHAR_ALERT_LEVEL_UUID            (0x2A06)

/**
 * @def           BLE_CHAR_TX_POWER_LEVEL_UUID
 * @brief         Tx Power Level.
 */
#define BLE_CHAR_TX_POWER_LEVEL_UUID         (0x2A07)

/**
 * @def           BLE_CHAR_DATE_TIME_UUID
 * @brief         Date Time.
 */
#define BLE_CHAR_DATE_TIME_UUID              (0x2A08)

/**
 * @def           BLE_CHAR_DAY_OF_WEEK_UUID
 * @brief         Day of Week.
 */
#define BLE_CHAR_DAY_OF_WEEK_UUID            (0x2A09)

/**
 * @def           BLE_CHAR_DAY_DATE_TIME_UUID
 * @brief         Day Date Time.
 */
#define BLE_CHAR_DAY_DATE_TIME_UUID          (0x2A0A)

/**
 * @def           BLE_CHAR_EXACT_TIME_256_UUID
 * @brief         Exact Time 256.
 */
#define BLE_CHAR_EXACT_TIME_256_UUID         (0x2A0C)

/**
 * @def           BLE_CHAR_DST_OFFSET_UUID
 * @brief         DST Offset.
 */
#define BLE_CHAR_DST_OFFSET_UUID             (0x2A0D)

/**
 * @def           BLE_CHAR_TIME_ZONE_UUID
 * @brief         Time Zone.
 */
#define BLE_CHAR_TIME_ZONE_UUID              (0x2A0E)

/**
 * @def           BLE_CHAR_LOCAL_TIME_INFORMATION_UUID
 * @brief         Local Time Information.
 */
#define BLE_CHAR_LOCAL_TIME_INFORMATION_UUID (0x2A0F)

/**
 * @def           BLE_CHAR_TIME_WITH_DST_UUID
 * @brief         Time with DST.
 */
#define BLE_CHAR_TIME_WITH_DST_UUID          (0x2A11)

/**
 * @def           BLE_CHAR_TIME_ACCURACY_UUID
 * @brief         Time Accuracy.
 */
#define BLE_CHAR_TIME_ACCURACY_UUID          (0x2A12)

/**
 * @def           BLE_CHAR_TIME_SOURCE_UUID
 * @brief         Time Source.
 */
#define BLE_CHAR_TIME_SOURCE_UUID            (0x2A13)

/**
 * @def           BLE_CHAR_REFERENCE_TIME_INFORMATION_UUID
 * @brief         Reference Time Information.
 */
#define BLE_CHAR_REFERENCE_TIME_INFORMATION_UUID \
                                             (0x2A14)

/**
 * @def           BLE_CHAR_TIME_UPDATE_CONTROL_POINT_UUID
 * @brief         Time Update Control Point.
 */
#define BLE_CHAR_TIME_UPDATE_CONTROL_POINT_UUID \
                                             (0x2A16)

/**
 * @def           BLE_CHAR_TIME_UPDATE_STATE_UUID
 * @brief         Time Update State.
 */
#define BLE_CHAR_TIME_UPDATE_STATE_UUID      (0x2A17)

/**
 * @def           BLE_CHAR_GLUCOSE_MEASUREMENT_UUID
 * @brief         Glucose Measurement.
 */
#define BLE_CHAR_GLUCOSE_MEASUREMENT_UUID    (0x2A18)

/**
 * @def           BLE_CHAR_BATTERY_LEVEL_UUID
 * @brief         Battery Level.
 */
#define BLE_CHAR_BATTERY_LEVEL_UUID          (0x2A19)

/**
 * @def           BLE_CHAR_TEMPERATURE_MEASUREMENT_UUID
 * @brief         Temperature Measurement.
 */
#define BLE_CHAR_TEMPERATURE_MEASUREMENT_UUID \
                                             (0x2A1C)

/**
 * @def           BLE_CHAR_TEMPERATURE_TYPE_UUID
 * @brief         Temperature Type.
 */
#define BLE_CHAR_TEMPERATURE_TYPE_UUID       (0x2A1D)

/**
 * @def           BLE_CHAR_INTERMEDIATE_TEMPERATURE_UUID
 * @brief         Intermediate Temperature.
 */
#define BLE_CHAR_INTERMEDIATE_TEMPERATURE_UUID \
                                             (0x2A1E)

/**
 * @def           BLE_CHAR_MEASUREMENT_INTERVAL_UUID
 * @brief         Measurement Interval.
 */
#define BLE_CHAR_MEASUREMENT_INTERVAL_UUID   (0x2A21)

/**
 * @def           BLE_CHAR_BOOT_KEYBOARD_INPUT_REPORT_UUID
 * @brief         Boot Keyboard Input Report.
 */
#define BLE_CHAR_BOOT_KEYBOARD_INPUT_REPORT_UUID \
                                             (0x2A22)

/**
 * @def           BLE_CHAR_SYSTEM_ID_UUID
 * @brief         System ID.
 */
#define BLE_CHAR_SYSTEM_ID_UUID              (0x2A23)

/**
 * @def           BLE_CHAR_MODEL_NUMBER_STRING_UUID
 * @brief         Model Number String.
 */
#define BLE_CHAR_MODEL_NUMBER_STRING_UUID    (0x2A24)

/**
 * @def           BLE_CHAR_SERIAL_NUMBER_STRING_UUID
 * @brief         Serial Number String.
 */
#define BLE_CHAR_SERIAL_NUMBER_STRING_UUID   (0x2A25)

/**
 * @def           BLE_CHAR_FIRMWARE_REVISION_STRING_UUID
 * @brief         Firmware Revision String.
 */
#define BLE_CHAR_FIRMWARE_REVISION_STRING_UUID \
                                             (0x2A26)

/**
 * @def           BLE_CHAR_HARDWARE_REVISION_STRING_UUID
 * @brief         Hardware Revision String.
 */
#define BLE_CHAR_HARDWARE_REVISION_STRING_UUID \
                                             (0x2A27)

/**
 * @def           BLE_CHAR_SOFTWARE_REVISION_STRING_UUID
 * @brief         Software Revision String.
 */
#define BLE_CHAR_SOFTWARE_REVISION_STRING_UUID \
                                             (0x2A28)

/**
 * @def           BLE_CHAR_MANUFACTURER_NAME_STRING_UUID
 * @brief         Manufacturer Name String.
 */
#define BLE_CHAR_MANUFACTURER_NAME_STRING_UUID \
                                             (0x2A29)

/**
 * @def           BLE_CHAR_IEEE_11073_20601_REGULATORY_CERTIFICATION_DATA_LIST_UUID
 * @brief         IEEE 11073-20601 Regulatory Certification Data List.
 */
#define BLE_CHAR_IEEE_11073_20601_REGULATORY_CERTIFICATION_DATA_LIST_UUID \
                                             (0x2A2A)

/**
 * @def           BLE_CHAR_CURRENT_TIME_UUID
 * @brief         Current Time.
 */
#define BLE_CHAR_CURRENT_TIME_UUID           (0x2A2B)

/**
 * @def           BLE_CHAR_MAGNETIC_DECLINATION_UUID
 * @brief         Magnetic Declination.
 */
#define BLE_CHAR_MAGNETIC_DECLINATION_UUID   (0x2A2C)


/**
 * @def           BLE_CHAR_SCAN_REFRESH_UUID
 * @brief         Scan Refresh.
 */
#define BLE_CHAR_SCAN_REFRESH_UUID           (0x2A31)

/**
 * @def           BLE_CHAR_BOOT_KEYBOARD_OUTPUT_REPORT_UUID
 * @brief         Boot Keyboard Output Report.
 */
#define BLE_CHAR_BOOT_KEYBOARD_OUTPUT_REPORT_UUID \
                                             (0x2A32)

/**
 * @def           BLE_CHAR_BOOT_MOUSE_INPUT_REPORT_UUID
 * @brief         Boot Mouse Input Report.
 */
#define BLE_CHAR_BOOT_MOUSE_INPUT_REPORT_UUID \
                                             (0x2A33)

/**
 * @def           BLE_CHAR_GLUCOSE_MEASUREMENT_CONTEXT_UUID
 * @brief         Glucose Measurement Context.
 */
#define BLE_CHAR_GLUCOSE_MEASUREMENT_CONTEXT_UUID \
                                             (0x2A34)

/**
 * @def           BLE_CHAR_BLOOD_PRESSURE_MEASUREMENT_UUID
 * @brief         Blood Pressure Measurement.
 */
#define BLE_CHAR_BLOOD_PRESSURE_MEASUREMENT_UUID \
                                             (0x2A35)

/**
 * @def           BLE_CHAR_INTERMEDIATE_CUFF_PRESSURE_UUID
 * @brief         Intermediate Cuff Pressure.
 */
#define BLE_CHAR_INTERMEDIATE_CUFF_PRESSURE_UUID \
                                             (0x2A36)

/**
 * @def           BLE_CHAR_HEART_RATE_MEASUREMENT_UUID
 * @brief         Heart Rate Measurement.
 */
#define BLE_CHAR_HEART_RATE_MEASUREMENT_UUID (0x2A37)

/**
 * @def           BLE_CHAR_BODY_SENSOR_LOCATION_UUID
 * @brief         Body Sensor Location.
 */
#define BLE_CHAR_BODY_SENSOR_LOCATION_UUID   (0x2A38)

/**
 * @def           BLE_CHAR_HEART_RATE_CONTROL_POINT_UUID
 * @brief         Heart Rate Control Point.
 */
#define BLE_CHAR_HEART_RATE_CONTROL_POINT_UUID \
                                             (0x2A39)

/**
 * @def           BLE_CHAR_ALERT_STATUS_UUID
 * @brief         Alert Status.
 */
#define BLE_CHAR_ALERT_STATUS_UUID           (0x2A3F)

/**
 * @def           BLE_CHAR_RINGER_CONTROL_POINT_UUID
 * @brief         Ringer Control Point.
 */
#define BLE_CHAR_RINGER_CONTROL_POINT_UUID   (0x2A40)

/**
 * @def           BLE_CHAR_RINGER_SETTING_UUID
 * @brief         Ringer Setting.
 */
#define BLE_CHAR_RINGER_SETTING_UUID         (0x2A41)

/**
 * @def           BLE_CHAR_ALERT_CATEGORY_ID_BIT_MASK_UUID
 * @brief         Alert Category ID Bit Mask.
 */
#define BLE_CHAR_ALERT_CATEGORY_ID_BIT_MASK_UUID \
                                             (0x2A42)

/**
 * @def           BLE_CHAR_ALERT_CATEGORY_ID_UUID
 * @brief         Alert Category ID.
 */
#define BLE_CHAR_ALERT_CATEGORY_ID_UUID      (0x2A43)

/**
 * @def           BLE_CHAR_ALERT_NOTIFICATION_CONTROL_POINT_UUID
 * @brief         Alert Notification Control Point.
 */
#define BLE_CHAR_ALERT_NOTIFICATION_CONTROL_POINT_UUID \
                                             (0x2A44)

/**
 * @def           BLE_CHAR_UNREAD_ALERT_STATUS_UUID
 * @brief         Unread Alert Status.
 */
#define BLE_CHAR_UNREAD_ALERT_STATUS_UUID    (0x2A45)

/**
 * @def           BLE_CHAR_NEW_ALERT_UUID
 * @brief         New Alert.
 */
#define BLE_CHAR_NEW_ALERT_UUID              (0x2A46)

/**
 * @def           BLE_CHAR_SUPPORTED_NEW_ALERT_CATEGORY_UUID
 * @brief         Supported New Alert Category.
 */
#define BLE_CHAR_SUPPORTED_NEW_ALERT_CATEGORY_UUID \
                                             (0x2A47)

/**
 * @def           BLE_CHAR_SUPPORTED_UNREAD_ALERT_CATEGORY_UUID
 * @brief         Supported Unread Alert Category.
 */
#define BLE_CHAR_SUPPORTED_UNREAD_ALERT_CATEGORY_UUID \
                                             (0x2A48)

/**
 * @def           BLE_CHAR_BLOOD_PRESSURE_FEATURE_UUID
 * @brief         Blood Pressure Feature.
 */
#define BLE_CHAR_BLOOD_PRESSURE_FEATURE_UUID (0x2A49)

/**
 * @def           BLE_CHAR_HID_INFORMATION_UUID
 * @brief         HID Information.
 */
#define BLE_CHAR_HID_INFORMATION_UUID        (0x2A4A)

/**
 * @def           BLE_CHAR_REPORT_MAP_UUID
 * @brief         Report Map.
 */
#define BLE_CHAR_REPORT_MAP_UUID             (0x2A4B)

/**
 * @def           BLE_CHAR_HID_CONTROL_POINT_UUID
 * @brief         HID Control Point.
 */
#define BLE_CHAR_HID_CONTROL_POINT_UUID      (0x2A4C)

/**
 * @def           BLE_CHAR_REPORT_UUID
 * @brief         Report.
 */
#define BLE_CHAR_REPORT_UUID                 (0x2A4D)

/**
 * @def           BLE_CHAR_PROTOCOL_MODE_UUID
 * @brief         Protocol Mode.
 */
#define BLE_CHAR_PROTOCOL_MODE_UUID          (0x2A4E)

/**
 * @def           BLE_CHAR_SCAN_INTERVAL_WINDOW_UUID
 * @brief         Scan Interval Window.
 */
#define BLE_CHAR_SCAN_INTERVAL_WINDOW_UUID   (0x2A4F)

/**
 * @def           BLE_CHAR_PNP_ID_UUID
 * @brief         PnP ID.
 */
#define BLE_CHAR_PNP_ID_UUID                 (0x2A50)

/**
 * @def           BLE_CHAR_GLUCOSE_FEATURE_UUID
 * @brief         Glucose Feature.
 */
#define BLE_CHAR_GLUCOSE_FEATURE_UUID        (0x2A51)

/**
 * @def           BLE_CHAR_RECORD_ACCESS_CONTROL_POINT_UUID
 * @brief         Record Access Control Point.
 */
#define BLE_CHAR_RECORD_ACCESS_CONTROL_POINT_UUID \
                                             (0x2A52)
/**
 * @def           BLE_CHAR_RSC_MEASUREMENT_UUID
 * @brief         RSC Measurement.
 */
#define BLE_CHAR_RSC_MEASUREMENT_UUID        (0x2A53)

/**
 * @def           BLE_CHAR_RSC_FEATURE_UUID
 * @brief         RSC Feature.
 */
#define BLE_CHAR_RSC_FEATURE_UUID            (0x2A54)

/**
 * @def           BLE_CHAR_SC_CONTROL_POINT_UUID
 * @brief         SC Control Point.
 */
#define BLE_CHAR_SC_CONTROL_POINT_UUID       (0x2A55)

/**
 * @def           BLE_CHAR_AGGREGATE_UUID
 * @brief         Aggregate.
 */
#define BLE_CHAR_AGGREGATE_UUID              (0x2A5A)

/**
 * @def           BLE_CHAR_CSC_MEASUREMENT_UUID
 * @brief         CSC Measurement.
 */
#define BLE_CHAR_CSC_MEASUREMENT_UUID        (0x2A5B)

/**
 * @def           BLE_CHAR_CSC_FEATURE_UUID
 * @brief         CSC Feature.
 */
#define BLE_CHAR_CSC_FEATURE_UUID            (0x2A5C)

/**
 * @def           BLE_CHAR_SENSOR_LOCATION_UUID
 * @brief         Sensor Location.
 */
#define BLE_CHAR_SENSOR_LOCATION_UUID        (0x2A5D)

/**
 * @def           BLE_CHAR_PLX_SPOT_CHECK_MEASUREMENT_UUID
 * @brief         PLX Spot-Check Measurement.
 */
#define BLE_CHAR_PLX_SPOT_CHECK_MEASUREMENT_UUID \
                                             (0x2A5E)

/**
 * @def           BLE_CHAR_PLX_CONTINUOUS_MEASUREMENT_UUID
 * @brief         PLX Continuous Measurement.
 */
#define BLE_CHAR_PLX_CONTINUOUS_MEASUREMENT_UUID \
                                             (0x2A5F)

/**
 * @def           BLE_CHAR_PLX_FEATURES_UUID
 * @brief         PLX Features.
 */
#define BLE_CHAR_PLX_FEATURES_UUID           (0x2A60)

/**
 * @def           BLE_CHAR_CYCLING_POWER_MEASUREMENT_UUID
 * @brief         Cycling Power Measurement.
 */
#define BLE_CHAR_CYCLING_POWER_MEASUREMENT_UUID \
                                             (0x2A63)

/**
 * @def           BLE_CHAR_CYCLING_POWER_VECTOR_UUID
 * @brief         Cycling Power Vector.
 */
#define BLE_CHAR_CYCLING_POWER_VECTOR_UUID   (0x2A64)

/**
 * @def           BLE_CHAR_CYCLING_POWER_FEATURE_UUID
 * @brief         Cycling Power Feature.
 */
#define BLE_CHAR_CYCLING_POWER_FEATURE_UUID  (0x2A65)

/**
 * @def           BLE_CHAR_CYCLING_POWER_CONTROL_POINT_UUID
 * @brief         Cycling Power Control Point.
 */
#define BLE_CHAR_CYCLING_POWER_CONTROL_POINT_UUID \
                                             (0x2A66)

/**
 * @def           BLE_CHAR_LOCATION_AND_SPEED_UUID
 * @brief         Location and Speed.
 */
#define BLE_CHAR_LOCATION_AND_SPEED_UUID     (0x2A67)

/**
 * @def           BLE_CHAR_NAVIGATION_UUID
 * @brief         Navigation.
 */
#define BLE_CHAR_NAVIGATION_UUID             (0x2A68)

/**
 * @def           BLE_CHAR_POSITION_QUALITY_UUID
 * @brief         Position Quality.
 */
#define BLE_CHAR_POSITION_QUALITY_UUID       (0x2A69)

/**
 * @def           BLE_CHAR_LN_FEATURE_UUID
 * @brief         LN Feature.
 */
#define BLE_CHAR_LN_FEATURE_UUID             (0x2A6A)

/**
 * @def           BLE_CHAR_LN_CONTROL_POINT_UUID
 * @brief         LN Control Point.
 */
#define BLE_CHAR_LN_CONTROL_POINT_UUID       (0x2A6B)

/**
 * @def           BLE_CHAR_ELEVATION_UUID
 * @brief         Elevation.
 */
#define BLE_CHAR_ELEVATION_UUID              (0x2A6C)

/**
 * @def           BLE_CHAR_PRESSURE_UUID
 * @brief         Pressure.
 */
#define BLE_CHAR_PRESSURE_UUID               (0x2A6D)

/**
 * @def           BLE_CHAR_TEMPERATURE_UUID
 * @brief         Temperature.
 */
#define BLE_CHAR_TEMPERATURE_UUID            (0x2A6E)

/**
 * @def           BLE_CHAR_HUMIDITY_UUID
 * @brief         Humidity.
 */
#define BLE_CHAR_HUMIDITY_UUID               (0x2A6F)

/**
 * @def           BLE_CHAR_TRUE_WIND_SPEED_UUID
 * @brief         True Wind Speed.
 */
#define BLE_CHAR_TRUE_WIND_SPEED_UUID        (0x2A70)

/**
 * @def           BLE_CHAR_TRUE_WIND_DIRECTION_UUID
 * @brief         True Wind Direction.
 */
#define BLE_CHAR_TRUE_WIND_DIRECTION_UUID    (0x2A71)

/**
 * @def           BLE_CHAR_APPARENT_WIND_SPEED_UUID
 * @brief         Apparent Wind Speed.
 */
#define BLE_CHAR_APPARENT_WIND_SPEED_UUID    (0x2A72)

/**
 * @def           BLE_CHAR_APPARENT_WIND_DIRECTION_UUID
 * @brief         Apparent Wind Direction.
 */
#define BLE_CHAR_APPARENT_WIND_DIRECTION_UUID \
                                             (0x2A73)

/**
 * @def           BLE_CHAR_GUST_FACTOR_UUID
 * @brief         Gust Factor.
 */
#define BLE_CHAR_GUST_FACTOR_UUID            (0x2A74)

/**
 * @def           BLE_CHAR_POLLEN_CONCENTRATION_UUID
 * @brief         Pollen Concentration.
 */
#define BLE_CHAR_POLLEN_CONCENTRATION_UUID   (0x2A75)

/**
 * @def           BLE_CHAR_UV_INDEX_UUID
 * @brief         UV Index.
 */
#define BLE_CHAR_UV_INDEX_UUID               (0x2A76)

/**
 * @def           BLE_CHAR_IRRADIANCE_UUID
 * @brief         Irradiance.
 */
#define BLE_CHAR_IRRADIANCE_UUID             (0x2A77)

/**
 * @def           BLE_CHAR_RAINFALL_UUID
 * @brief         Rainfall.
 */
#define BLE_CHAR_RAINFALL_UUID               (0x2A78)

/**
 * @def           BLE_CHAR_WIND_CHILL_UUID
 * @brief         Wind Chill.
 */
#define BLE_CHAR_WIND_CHILL_UUID             (0x2A79)

/**
 * @def           BLE_CHAR_HEAT_INDEX_UUID
 * @brief         Heat Index.
 */
#define BLE_CHAR_HEAT_INDEX_UUID             (0x2A7A)

/**
 * @def           BLE_CHAR_DEW_POINT_UUID
 * @brief         Dew Point.
 */
#define BLE_CHAR_DEW_POINT_UUID              (0x2A7B)

/**
 * @def           BLE_CHAR_DESCRIPTOR_VALUE_CHANGED_UUID
 * @brief         Descriptor Value Changed.
 */
#define BLE_CHAR_DESCRIPTOR_VALUE_CHANGED_UUID \
                                             (0x2A7D)

/**
 * @def           BLE_CHAR_AEROBIC_HEART_RATE_LOWER_LIMIT_UUID
 * @brief         Aerobic Heart Rate Lower Limit.
 */
#define BLE_CHAR_AEROBIC_HEART_RATE_LOWER_LIMIT_UUID \
                                             (0x2A7E)

/**
 * @def           BLE_CHAR_AEROBIC_THRESHOLD_UUID
 * @brief         Aerobic Threshold.
 */
#define BLE_CHAR_AEROBIC_THRESHOLD_UUID      (0x2A7F)

/**
 * @def           BLE_CHAR_AGE_UUID
 * @brief         Age.
 */
#define BLE_CHAR_AGE_UUID                    (0x2A80)

/**
 * @def           BLE_CHAR_ANAEROBIC_HEART_RATE_LOWER_LIMIT_UUID
 * @brief         Anaerobic Heart Rate Lower Limit.
 */
#define BLE_CHAR_ANAEROBIC_HEART_RATE_LOWER_LIMIT_UUID \
                                             (0x2A81)

/**
 * @def           BLE_CHAR_ANAEROBIC_HEART_RATE_UPPER_LIMIT_UUID
 * @brief         Anaerobic Heart Rate Upper Limit.
 */
#define BLE_CHAR_ANAEROBIC_HEART_RATE_UPPER_LIMIT_UUID \
                                             (0x2A82)

/**
 * @def           BLE_CHAR_ANAEROBIC_THRESHOLD_UUID
 * @brief         Anaerobic Threshold.
 */
#define BLE_CHAR_ANAEROBIC_THRESHOLD_UUID    (0x2A83)

/**
 * @def           BLE_CHAR_AEROBIC_HEART_RATE_UPPER_LIMIT_UUID
 * @brief         Aerobic Heart Rate Upper Limit.
 */
#define BLE_CHAR_AEROBIC_HEART_RATE_UPPER_LIMIT_UUID \
                                             (0x2A84)

/**
 * @def           BLE_CHAR_DATE_OF_BIRTH_UUID
 * @brief         Date of Birth.
 */
#define BLE_CHAR_DATE_OF_BIRTH_UUID          (0x2A85)

/**
 * @def           BLE_CHAR_DATE_OF_THRESHOLD_ASSESSMENT_UUID
 * @brief         Date of Threshold Assessment.
 */
#define BLE_CHAR_DATE_OF_THRESHOLD_ASSESSMENT_UUID \
                                             (0x2A86)

/**
 * @def           BLE_CHAR_EMAIL_ADDRESS_UUID
 * @brief         Email Address.
 */
#define BLE_CHAR_EMAIL_ADDRESS_UUID          (0x2A87)

/**
 * @def           BLE_CHAR_FAT_BURN_HEART_RATE_LOWER_LIMIT_UUID
 * @brief         Fat Burn Heart Rate Lower Limit.
 */
#define BLE_CHAR_FAT_BURN_HEART_RATE_LOWER_LIMIT_UUID \
                                             (0x2A88)

/**
 * @def           BLE_CHAR_FAT_BURN_HEART_RATE_UPPER_LIMIT_UUID
 * @brief         Fat Burn Heart Rate Upper Limit.
 */
#define BLE_CHAR_FAT_BURN_HEART_RATE_UPPER_LIMIT_UUID \
                                             (0x2A89)

/**
 * @def           BLE_CHAR_FIRST_NAME_UUID
 * @brief         First Name.
 */
#define BLE_CHAR_FIRST_NAME_UUID             (0x2A8A)

/**
 * @def           BLE_CHAR_FIVE_ZONE_HEART_RATE_LIMITS_UUID
 * @brief         Five Zone Heart Rate Limits.
 */
#define BLE_CHAR_FIVE_ZONE_HEART_RATE_LIMITS_UUID \
                                             (0x2A8B)

/**
 * @def           BLE_CHAR_GENDER_UUID
 * @brief         Gender.
 */
#define BLE_CHAR_GENDER_UUID                 (0x2A8C)

/**
 * @def           BLE_CHAR_HEART_RATE_MAX_UUID
 * @brief         Heart Rate Max.
 */
#define BLE_CHAR_HEART_RATE_MAX_UUID         (0x2A8D)

/**
 * @def           BLE_CHAR_HEIGHT_UUID
 * @brief         Height.
 */
#define BLE_CHAR_HEIGHT_UUID                 (0x2A8E)

/**
 * @def           BLE_CHAR_HIP_CIRCUMFERENCE_UUID
 * @brief         Hip Circumference.
 */
#define BLE_CHAR_HIP_CIRCUMFERENCE_UUID      (0x2A8F)

/**
 * @def           BLE_CHAR_LAST_NAME_UUID
 * @brief         Last Name.
 */
#define BLE_CHAR_LAST_NAME_UUID              (0x2A90)

/**
 * @def           BLE_CHAR_MAXIMUM_RECOMMENDED_HEART_RATE_UUID
 * @brief         Maximum Recommended Heart Rate.
 */
#define BLE_CHAR_MAXIMUM_RECOMMENDED_HEART_RATE_UUID \
                                             (0x2A91)

/**
 * @def           BLE_CHAR_RESTING_HEART_RATE_UUID
 * @brief         Resting Heart Rate.
 */
#define BLE_CHAR_RESTING_HEART_RATE_UUID     (0x2A92)

/**
 * @def           BLE_CHAR_SPORT_TYPE_FOR_AEROBIC_AND_ANAEROBIC_THRESHOLDS_UUID
 * @brief         Sport Type for Aerobic and Anaerobic Thresholds.
 */
#define BLE_CHAR_SPORT_TYPE_FOR_AEROBIC_AND_ANAEROBIC_THRESHOLDS_UUID \
                                             (0x2A93)

/**
 * @def           BLE_CHAR_THREE_ZONE_HEART_RATE_LIMITS_UUID
 * @brief         Three Zone Heart Rate Limits.
 */
#define BLE_CHAR_THREE_ZONE_HEART_RATE_LIMITS_UUID \
                                             (0x2A94)

/**
 * @def           BLE_CHAR_TWO_ZONE_HEART_RATE_LIMITS_UUID
 * @brief         Two Zone Heart Rate Limits.
 */
#define BLE_CHAR_TWO_ZONE_HEART_RATE_LIMITS_UUID \
                                             (0x2A95)

/**
 * @def           BLE_CHAR_VO2_MAX_UUID
 * @brief         VO2 Max.
 */
#define BLE_CHAR_VO2_MAX_UUID                (0x2A96)

/**
 * @def           BLE_CHAR_WAIST_CIRCUMFERENCE_UUID
 * @brief         Waist Circumference.
 */
#define BLE_CHAR_WAIST_CIRCUMFERENCE_UUID    (0x2A97)

/**
 * @def           BLE_CHAR_WEIGHT_UUID
 * @brief         Weight.
 */
#define BLE_CHAR_WEIGHT_UUID                 (0x2A98)

/**
 * @def           BLE_CHAR_DATABASE_CHANGE_INCREMENT_UUID
 * @brief         Database Change Increment.
 */
#define BLE_CHAR_DATABASE_CHANGE_INCREMENT_UUID \
                                             (0x2A99)

/**
 * @def           BLE_CHAR_USER_INDEX_UUID
 * @brief         User Index.
 */
#define BLE_CHAR_USER_INDEX_UUID             (0x2A9A)

/**
 * @def           BLE_CHAR_BODY_COMPOSITION_FEATURE_UUID
 * @brief         Body Composition Feature.
 */
#define BLE_CHAR_BODY_COMPOSITION_FEATURE_UUID \
                                             (0x2A9B)

/**
 * @def           BLE_CHAR_BODY_COMPOSITION_MEASUREMENT_UUID
 * @brief         Body Composition Measurement.
 */
#define BLE_CHAR_BODY_COMPOSITION_MEASUREMENT_UUID \
                                             (0x2A9C)

/**
 * @def           BLE_CHAR_WEIGHT_MEASUREMENT_UUID
 * @brief         Weight Measurement.
 */
#define BLE_CHAR_WEIGHT_MEASUREMENT_UUID     (0x2A9D)

/**
 * @def           BLE_CHAR_WEIGHT_SCALE_FEATURE_UUID
 * @brief         Weight Scale Feature.
 */
#define BLE_CHAR_WEIGHT_SCALE_FEATURE_UUID   (0x2A9E)

/**
 * @def           BLE_CHAR_USER_CONTROL_POINT_UUID
 * @brief         User Control Point.
 */
#define BLE_CHAR_USER_CONTROL_POINT_UUID     (0x2A9F)

/**
 * @def           BLE_CHAR_MAGNETIC_FLUX_DENSITY_2D_UUID
 * @brief         Magnetic Flux Density - 2D.
 */
#define BLE_CHAR_MAGNETIC_FLUX_DENSITY_2D_UUID \
                                             (0x2AA0)

/**
 * @def           BLE_CHAR_MAGNETIC_FLUX_DENSITY_3D_UUID
 * @brief         Magnetic Flux Density - 3D.
 */
#define BLE_CHAR_MAGNETIC_FLUX_DENSITY_3D_UUID \
                                             (0x2AA1)

/**
 * @def           BLE_CHAR_LANGUAGE_UUID
 * @brief         Language.
 */
#define BLE_CHAR_LANGUAGE_UUID               (0x2AA2)

/**
 * @def           BLE_CHAR_BAROMETRIC_PRESSURE_TREND_UUID
 * @brief         Barometric Pressure Trend.
 */
#define BLE_CHAR_BAROMETRIC_PRESSURE_TREND_UUID \
                                             (0x2AA3)

/**
 * @def           BLE_CHAR_BOND_MANAGEMENT_CONTROL_POINT_UUID
 * @brief         Bond Management Control Point.
 */
#define BLE_CHAR_BOND_MANAGEMENT_CONTROL_POINT_UUID \
                                             (0x2AA4)

/**
 * @def           BLE_CHAR_BOND_MANAGEMENT_FEATURE_UUID
 * @brief         Bond Management Feature.
 */
#define BLE_CHAR_BOND_MANAGEMENT_FEATURE_UUID \
                                             (0x2AA5)

/**
 * @def           BLE_CHAR_CENTRAL_ADDRESS_RESOLUTION_UUID
 * @brief         Central Address Resolution.
 */
#define BLE_CHAR_CENTRAL_ADDRESS_RESOLUTION_UUID \
                                             (0x2AA6)

/**
 * @def           BLE_CHAR_CGM_MEASUREMENT_UUID
 * @brief         CGM Measurement.
 */
#define BLE_CHAR_CGM_MEASUREMENT_UUID        (0x2AA7)

/**
 * @def           BLE_CHAR_CGM_FEATURE_UUID
 * @brief         CGM Feature.
 */
#define BLE_CHAR_CGM_FEATURE_UUID            (0x2AA8)

/**
 * @def           BLE_CHAR_CGM_STATUS_UUID
 * @brief         CGM Status.
 */
#define BLE_CHAR_CGM_STATUS_UUID             (0x2AA9)

/**
 * @def           BLE_CHAR_CGM_SESSION_START_TIME_UUID
 * @brief         CGM Session Start Time.
 */
#define BLE_CHAR_CGM_SESSION_START_TIME_UUID (0x2AAA)

/**
 * @def           BLE_CHAR_CGM_SESSION_RUN_TIME_UUID
 * @brief         CGM Session Run Time.
 */
#define BLE_CHAR_CGM_SESSION_RUN_TIME_UUID   (0x2AAB)

/**
 * @def           BLE_CHAR_CGM_SPECIFIC_OPS_CONTROL_POINT_UUID
 * @brief         CGM Specific Ops Control Point.
 */
#define BLE_CHAR_CGM_SPECIFIC_OPS_CONTROL_POINT_UUID \
                                             (0x2AAC)

/**
 * @def           BLE_CHAR_INDOOR_POSITIONING_CONFIGURATION_UUID
 * @brief         Indoor Positioning Configuration.
 */
#define BLE_CHAR_INDOOR_POSITIONING_CONFIGURATION_UUID \
                                             (0x2AAD)

/**
 * @def           BLE_CHAR_LATITUDE_UUID
 * @brief         Latitude.
 */
#define BLE_CHAR_LATITUDE_UUID               (0x2AAE)

/**
 * @def           BLE_CHAR_LONGITUDE_UUID
 * @brief         Longitude.
 */
#define BLE_CHAR_LONGITUDE_UUID              (0x2AAF)

/**
 * @def           BLE_CHAR_LOCAL_NORTH_COORDINATE_UUID
 * @brief         Local North Coordinate.
 */
#define BLE_CHAR_LOCAL_NORTH_COORDINATE_UUID (0x2AB0)

/**
 * @def           BLE_CHAR_LOCAL_EAST_COORDINATE_UUID
 * @brief         Local East Coordinate.
 */
#define BLE_CHAR_LOCAL_EAST_COORDINATE_UUID  (0x2AB1)

/**
 * @def           BLE_CHAR_FLOOR_NUMBER_UUID
 * @brief         Floor Number.
 */
#define BLE_CHAR_FLOOR_NUMBER_UUID           (0x2AB2)

/**
 * @def           BLE_CHAR_ALTITUDE_UUID
 * @brief         Altitude.
 */
#define BLE_CHAR_ALTITUDE_UUID               (0x2AB3)

/**
 * @def           BLE_CHAR_UNCERTAINTY_UUID
 * @brief         Uncertainty.
 */
#define BLE_CHAR_UNCERTAINTY_UUID            (0x2AB4)

/**
 * @def           BLE_CHAR_LOCATION_NAME_UUID
 * @brief         Location Name.
 */
#define BLE_CHAR_LOCATION_NAME_UUID          (0x2AB5)

/**
 * @def           BLE_CHAR_URI_UUID
 * @brief         URI.
 */
#define BLE_CHAR_URI_UUID                    (0x2AB6)

/**
 * @def           BLE_CHAR_HTTP_HEADERS_UUID
 * @brief         HTTP Headers.
 */
#define BLE_CHAR_HTTP_HEADERS_UUID           (0x2AB7)

/**
 * @def           BLE_CHAR_HTTP_STATUS_CODE_UUID
 * @brief         HTTP Status Code.
 */
#define BLE_CHAR_HTTP_STATUS_CODE_UUID       (0x2AB8)

/**
 * @def           BLE_CHAR_HTTP_ENTITY_BODY_UUID
 * @brief         HTTP Entity Body.
 */
#define BLE_CHAR_HTTP_ENTITY_BODY_UUID       (0x2AB9)

/**
 * @def           BLE_CHAR_HTTP_CONTROL_POINT_UUID
 * @brief         HTTP Control Point.
 */
#define BLE_CHAR_HTTP_CONTROL_POINT_UUID     (0x2ABA)

/**
 * @def           BLE_CHAR_HTTPS_SECURITY_UUID
 * @brief         HTTPS Security.
 */
#define BLE_CHAR_HTTPS_SECURITY_UUID         (0x2ABB)

/**
 * @def           BLE_CHAR_TDS_CONTROL_POINT_UUID
 * @brief         TDS Control Point.
 */
#define BLE_CHAR_TDS_CONTROL_POINT_UUID      (0x2ABC)

/**
 * @def           BLE_CHAR_OTS_FEATURE_UUID
 * @brief         OTS Feature.
 */
#define BLE_CHAR_OTS_FEATURE_UUID            (0x2ABD)

/**
 * @def           BLE_CHAR_OBJECT_NAME_UUID
 * @brief         Object Name.
 */
#define BLE_CHAR_OBJECT_NAME_UUID            (0x2ABE)

/**
 * @def           BLE_CHAR_OBJECT_TYPE_UUID
 * @brief         Object Type.
 */
#define BLE_CHAR_OBJECT_TYPE_UUID            (0x2ABF)

/**
 * @def           BLE_CHAR_OBJECT_SIZE_UUID
 * @brief         Object Size.
 */
#define BLE_CHAR_OBJECT_SIZE_UUID            (0x2AC0)

/**
 * @def           BLE_CHAR_OBJECT_FIRST_CREATED_UUID
 * @brief         Object First-Created.
 */
#define BLE_CHAR_OBJECT_FIRST_CREATED_UUID   (0x2AC1)

/**
 * @def           BLE_CHAR_OBJECT_LAST_MODIFIED_UUID
 * @brief         Object Last-Modified.
 */
#define BLE_CHAR_OBJECT_LAST_MODIFIED_UUID   (0x2AC2)

/**
 * @def           BLE_CHAR_OBJECT_ID_UUID
 * @brief         Object ID.
 */
#define BLE_CHAR_OBJECT_ID_UUID              (0x2AC3)

/**
 * @def           BLE_CHAR_OBJECT_PROPERTIES_UUID
 * @brief         Object Properties.
 */
#define BLE_CHAR_OBJECT_PROPERTIES_UUID      (0x2AC4)

/**
 * @def           BLE_CHAR_OBJECT_ACTION_CONTROL_POINT_UUID
 * @brief         Object Action Control Point.
 */
#define BLE_CHAR_OBJECT_ACTION_CONTROL_POINT_UUID \
                                             (0x2AC5)

/**
 * @def           BLE_CHAR_OBJECT_LIST_CONTROL_POINT_UUID
 * @brief         Object List Control Point.
 */
#define BLE_CHAR_OBJECT_LIST_CONTROL_POINT_UUID \
                                             (0x2AC6)

/**
 * @def           BLE_CHAR_OBJECT_LIST_FILTER_UUID
 * @brief         Object List Filter.
 */
#define BLE_CHAR_OBJECT_LIST_FILTER_UUID     (0x2AC7)

/**
 * @def           BLE_CHAR_OBJECT_CHANGED_UUID
 * @brief         Object Changed.
 */
#define BLE_CHAR_OBJECT_CHANGED_UUID         (0x2AC8)

/**
 * @def           BLE_CHAR_RESOLVABLE_PRIVATE_ADDRESS_ONLY_UUID
 * @brief         Resolvable Private Address Only.
 */
#define BLE_CHAR_RESOLVABLE_PRIVATE_ADDRESS_ONLY_UUID \
                                             (0x2AC9)

/**
 * @def           BLE_CHAR_FITNESS_MACHINE_FEATURE_UUID
 * @brief         Fitness Machine Feature.
 */
#define BLE_CHAR_FITNESS_MACHINE_FEATURE_UUID \
                                             (0x2ACC)

/**
 * @def           BLE_CHAR_TREADMILL_DATA_UUID
 * @brief         Treadmill Data.
 */
#define BLE_CHAR_TREADMILL_DATA_UUID         (0x2ACD)

/**
 * @def           BLE_CHAR_CROSS_TRAINER_DATA_UUID
 * @brief         Cross Trainer Data.
 */
#define BLE_CHAR_CROSS_TRAINER_DATA_UUID     (0x2ACE)

/**
 * @def           BLE_CHAR_STEP_CLIMBER_DATA_UUID
 * @brief         Step Climber Data.
 */
#define BLE_CHAR_STEP_CLIMBER_DATA_UUID      (0x2ACF)

/**
 * @def           BLE_CHAR_STAIR_CLIMBER_DATA_UUID
 * @brief         Stair Climber Data.
 */
#define BLE_CHAR_STAIR_CLIMBER_DATA_UUID     (0x2AD0)

/**
 * @def           BLE_CHAR_ROWER_DATA_UUID
 * @brief         Rower Data.
 */
#define BLE_CHAR_ROWER_DATA_UUID             (0x2AD1)

/**
 * @def           BLE_CHAR_INDOOR_BIKE_DATA_UUID
 * @brief         Indoor Bike Data.
 */
#define BLE_CHAR_INDOOR_BIKE_DATA_UUID       (0x2AD2)

/**
 * @def           BLE_CHAR_TRAINING_STATUS_UUID
 * @brief         Training Status.
 */
#define BLE_CHAR_TRAINING_STATUS_UUID        (0x2AD3)

/**
 * @def           BLE_CHAR_SUPPORTED_SPEED_RANGE_UUID
 * @brief         Supported Speed Range.
 */
#define BLE_CHAR_SUPPORTED_SPEED_RANGE_UUID  (0x2AD4)

/**
 * @def           BLE_CHAR_SUPPORTED_INCLINATION_RANGE_UUID
 * @brief         Supported Inclination Range.
 */
#define BLE_CHAR_SUPPORTED_INCLINATION_RANGE_UUID \
                                             (0x2AD5)

/**
 * @def           BLE_CHAR_SUPPORTED_RESISTANCE_LEVEL_RANGE_UUID
 * @brief         Supported Resistance Level Range.
 */
#define BLE_CHAR_SUPPORTED_RESISTANCE_LEVEL_RANGE_UUID \
                                             (0x2AD6)

/**
 * @def           BLE_CHAR_SUPPORTED_HEART_RATE_RANGE_UUID
 * @brief         Supported Heart Rate Range.
 */
#define BLE_CHAR_SUPPORTED_HEART_RATE_RANGE_UUID \
                                             (0x2AD7)

/**
 * @def           BLE_CHAR_SUPPORTED_POWER_RANGE_UUID
 * @brief         Supported Power Range.
 */
#define BLE_CHAR_SUPPORTED_POWER_RANGE_UUID  (0x2AD8)

/**
 * @def           BLE_CHAR_FITNESS_MACHINE_CONTROL_POINT_UUID
 * @brief         Fitness Machine Control Point.
 */
#define BLE_CHAR_FITNESS_MACHINE_CONTROL_POINT_UUID \
                                             (0x2AD9)

/**
 * @def           BLE_CHAR_FITNESS_MACHINE_STATUS_UUID
 * @brief         Fitness Machine Status.
 */
#define BLE_CHAR_FITNESS_MACHINE_STATUS_UUID (0x2ADA)

/**
 * @def           BLE_CHAR_MESH_PROVISIONING_DATA_IN_UUID
 * @brief         Mesh Provisioning Data In.
 */
#define BLE_CHAR_MESH_PROVISIONING_DATA_IN_UUID \
                                             (0x2ADB)

/**
 * @def           BLE_CHAR_MESH_PROVISIONING_DATA_OUT_UUID
 * @brief         Mesh Provisioning Data Out.
 */
#define BLE_CHAR_MESH_PROVISIONING_DATA_OUT_UUID \
                                             (0x2ADC)

/**
 * @def           BLE_CHAR_MESH_PROXY_DATA_IN_UUID
 * @brief         Mesh Proxy Data In.
 */
#define BLE_CHAR_MESH_PROXY_DATA_IN_UUID     (0x2ADD)

/**
 * @def           BLE_CHAR_MESH_PROXY_DATA_OUT_UUID
 * @brief         Mesh Proxy Data Out.
 */
#define BLE_CHAR_MESH_PROXY_DATA_OUT_UUID    (0x2ADE)

/**
 * @def           BLE_CHAR_AVERAGE_CURRENT_UUID
 * @brief         Average Current.
 */
#define BLE_CHAR_AVERAGE_CURRENT_UUID        (0x2AE0)

/**
 * @def           BLE_CHAR_AVERAGE_VOLTAGE_UUID
 * @brief         Average Voltage.
 */
#define BLE_CHAR_AVERAGE_VOLTAGE_UUID        (0x2AE1)

/**
 * @def           BLE_CHAR_BOOLEAN_UUID
 * @brief         Boolean.
 */
#define BLE_CHAR_BOOLEAN_UUID                (0x2AE2)

/**
 * @def           BLE_CHAR_CHROMATIC_DISTANCE_FROM_PLANCKIAN_UUID
 * @brief         Chromatic Distance from Planckian.
 */
#define BLE_CHAR_CHROMATIC_DISTANCE_FROM_PLANCKIAN_UUID \
                                             (0x2AE3)

/**
 * @def           BLE_CHAR_CHROMATICITY_COORDINATES_UUID
 * @brief         Chromaticity Coordinates.
 */
#define BLE_CHAR_CHROMATICITY_COORDINATES_UUID \
                                             (0x2AE4)

/**
 * @def           BLE_CHAR_CHROMATICITY_IN_CCT_AND_DUV_VALUES_UUID
 * @brief         Chromaticity in CCT and Duv Values.
 */
#define BLE_CHAR_CHROMATICITY_IN_CCT_AND_DUV_VALUES_UUID \
                                             (0x2AE5)

/**
 * @def           BLE_CHAR_CHROMATICITY_TOLERANCE_UUID
 * @brief         Chromaticity Tolerance.
 */
#define BLE_CHAR_CHROMATICITY_TOLERANCE_UUID (0x2AE6)

/**
 * @def           BLE_CHAR_CIE_13_3_1995_COLOR_RENDERING_INDEX_UUID
 * @brief         CIE 13.3-1995 Color Rendering Index.
 */
#define BLE_CHAR_CIE_13_3_1995_COLOR_RENDERING_INDEX_UUID \
                                             (0x2AE7)

/**
 * @def           BLE_CHAR_COEFFICIENT_UUID
 * @brief         Coefficient.
 */
#define BLE_CHAR_COEFFICIENT_UUID            (0x2AE8)

/**
 * @def           BLE_CHAR_CORRELATED_COLOR_TEMPERATURE_UUID
 * @brief         Correlated Color Temperature.
 */
#define BLE_CHAR_CORRELATED_COLOR_TEMPERATURE_UUID \
                                             (0x2AE9)

/**
 * @def           BLE_CHAR_COUNT_16_UUID
 * @brief         Count 16.
 */
#define BLE_CHAR_COUNT_16_UUID               (0x2AEA)

/**
 * @def           BLE_CHAR_COUNT_24_UUID
 * @brief         Count 24.
 */
#define BLE_CHAR_COUNT_24_UUID               (0x2AEB)

/**
 * @def           BLE_CHAR_COUNTRY_CODE_UUID
 * @brief         Country Code.
 */
#define BLE_CHAR_COUNTRY_CODE_UUID           (0x2AEC)

/**
 * @def           BLE_CHAR_DATE_UTC_UUID
 * @brief         Date UTC.
 */
#define BLE_CHAR_DATE_UTC_UUID               (0x2AED)

/**
 * @def           BLE_CHAR_ELECTRIC_CURRENT_UUID
 * @brief         Electric Current.
 */
#define BLE_CHAR_ELECTRIC_CURRENT_UUID       (0x2AEE)

/**
 * @def           BLE_CHAR_ELECTRIC_CURRENT_RANGE_UUID
 * @brief         Electric Current Range.
 */
#define BLE_CHAR_ELECTRIC_CURRENT_RANGE_UUID (0x2AEF)

/**
 * @def           BLE_CHAR_ELECTRIC_CURRENT_SPECIFICATION_UUID
 * @brief         Electric Current Specification.
 */
#define BLE_CHAR_ELECTRIC_CURRENT_SPECIFICATION_UUID \
                                             (0x2AF0)

/**
 * @def           BLE_CHAR_ELECTRIC_CURRENT_STATISTICS_UUID
 * @brief         Electric Current Statistics.
 */
#define BLE_CHAR_ELECTRIC_CURRENT_STATISTICS_UUID \
                                             (0x2AF1)

/**
 * @def           BLE_CHAR_ENERGY_UUID
 * @brief         Energy.
 */
#define BLE_CHAR_ENERGY_UUID                 (0x2AF2)

/**
 * @def           BLE_CHAR_ENERGY_IN_A_PERIOD_OF_DAY_UUID
 * @brief         Energy in a Period of Day.
 */
#define BLE_CHAR_ENERGY_IN_A_PERIOD_OF_DAY_UUID \
                                             (0x2AF3)

/**
 * @def           BLE_CHAR_EVENT_STATISTICS_UUID
 * @brief         Event Statistics.
 */
#define BLE_CHAR_EVENT_STATISTICS_UUID       (0x2AF4)

/**
 * @def           BLE_CHAR_FIXED_STRING_16_UUID
 * @brief         Fixed String 16.
 */
#define BLE_CHAR_FIXED_STRING_16_UUID        (0x2AF5)

/**
 * @def           BLE_CHAR_FIXED_STRING_24_UUID
 * @brief         Fixed String 24.
 */
#define BLE_CHAR_FIXED_STRING_24_UUID        (0x2AF6)

/**
 * @def           BLE_CHAR_FIXED_STRING_36_UUID
 * @brief         Fixed String 36.
 */
#define BLE_CHAR_FIXED_STRING_36_UUID        (0x2AF7)

/**
 * @def           BLE_CHAR_FIXED_STRING_8_UUID
 * @brief         Fixed String 8.
 */
#define BLE_CHAR_FIXED_STRING_8_UUID         (0x2AF8)

/**
 * @def           BLE_CHAR_GENERIC_LEVEL_UUID
 * @brief         Generic Level.
 */
#define BLE_CHAR_GENERIC_LEVEL_UUID          (0x2AF9)

/**
 * @def           BLE_CHAR_GLOBAL_TRADE_ITEM_NUMBER_UUID
 * @brief         Global Trade Item Number.
 */
#define BLE_CHAR_GLOBAL_TRADE_ITEM_NUMBER_UUID \
                                             (0x2AFA)

/**
 * @def           BLE_CHAR_ILLUMINANCE_UUID
 * @brief         Illuminance.
 */
#define BLE_CHAR_ILLUMINANCE_UUID            (0x2AFB)

/**
 * @def           BLE_CHAR_LUMINOUS_EFFICACY_UUID
 * @brief         Luminous Efficacy.
 */
#define BLE_CHAR_LUMINOUS_EFFICACY_UUID      (0x2AFC)

/**
 * @def           BLE_CHAR_LUMINOUS_ENERGY_UUID
 * @brief         Luminous Energy.
 */
#define BLE_CHAR_LUMINOUS_ENERGY_UUID        (0x2AFD)

/**
 * @def           BLE_CHAR_LUMINOUS_EXPOSURE_UUID
 * @brief         Luminous Exposure.
 */
#define BLE_CHAR_LUMINOUS_EXPOSURE_UUID      (0x2AFE)

/**
 * @def           BLE_CHAR_LUMINOUS_FLUX_UUID
 * @brief         Luminous Flux.
 */
#define BLE_CHAR_LUMINOUS_FLUX_UUID          (0x2AFF)

/**
 * @def           BLE_CHAR_LUMINOUS_FLUX_RANGE_UUID
 * @brief         Luminous Flux Range.
 */
#define BLE_CHAR_LUMINOUS_FLUX_RANGE_UUID    (0x2B00)

/**
 * @def           BLE_CHAR_LUMINOUS_INTENSITY_UUID
 * @brief         Luminous Intensity.
 */
#define BLE_CHAR_LUMINOUS_INTENSITY_UUID     (0x2B01)

/**
 * @def           BLE_CHAR_MASS_FLOW_UUID
 * @brief         Mass Flow.
 */
#define BLE_CHAR_MASS_FLOW_UUID              (0x2B02)

/**
 * @def           BLE_CHAR_PERCEIVED_LIGHTNESS_UUID
 * @brief         Perceived Lightness.
 */
#define BLE_CHAR_PERCEIVED_LIGHTNESS_UUID    (0x2B03)

/**
 * @def           BLE_CHAR_PERCENTAGE_8_UUID
 * @brief         Percentage 8.
 */
#define BLE_CHAR_PERCENTAGE_8_UUID           (0x2B04)

/**
 * @def           BLE_CHAR_POWER_UUID
 * @brief         Power.
 */
#define BLE_CHAR_POWER_UUID                  (0x2B05)

/**
 * @def           BLE_CHAR_POWER_SPECIFICATION_UUID
 * @brief         Power Specification.
 */
#define BLE_CHAR_POWER_SPECIFICATION_UUID    (0x2B06)

/**
 * @def           BLE_CHAR_RELATIVE_RUNTIME_IN_A_CURRENT_RANGE_UUID
 * @brief         Relative Runtime in a Current Range.
 */
#define BLE_CHAR_RELATIVE_RUNTIME_IN_A_CURRENT_RANGE_UUID \
                                             (0x2B07)

/**
 * @def           BLE_CHAR_RELATIVE_RUNTIME_IN_A_GENERIC_LEVEL_RANGE_UUID
 * @brief         Relative Runtime in a Generic Level Range.
 */
#define BLE_CHAR_RELATIVE_RUNTIME_IN_A_GENERIC_LEVEL_RANGE_UUID \
                                             (0x2B08)

/**
 * @def           BLE_CHAR_RELATIVE_VALUE_IN_A_VOLTAGE_RANGE_UUID
 * @brief         Relative Value in a Voltage Range.
 */
#define BLE_CHAR_RELATIVE_VALUE_IN_A_VOLTAGE_RANGE_UUID \
                                             (0x2B09)

/**
 * @def           BLE_CHAR_RELATIVE_VALUE_IN_AN_ILLUMINANCE_RANGE_UUID
 * @brief         Relative Value in an Illuminance Range.
 */
#define BLE_CHAR_RELATIVE_VALUE_IN_AN_ILLUMINANCE_RANGE_UUID \
                                             (0x2B0A)

/**
 * @def           BLE_CHAR_RELATIVE_VALUE_IN_A_PERIOD_OF_DAY_UUID
 * @brief         Relative Value in a Period of Day.
 */
#define BLE_CHAR_RELATIVE_VALUE_IN_A_PERIOD_OF_DAY_UUID \
                                             (0x2B0B)

/**
 * @def           BLE_CHAR_RELATIVE_VALUE_IN_A_TEMPERATURE_RANGE_UUID
 * @brief         Relative Value in a Temperature Range.
 */
#define BLE_CHAR_RELATIVE_VALUE_IN_A_TEMPERATURE_RANGE_UUID \
                                             (0x2B0C)

/**
 * @def           BLE_CHAR_TEMPERATURE_8_UUID
 * @brief         Temperature 8.
 */
#define BLE_CHAR_TEMPERATURE_8_UUID          (0x2B0D)

/**
 * @def           BLE_CHAR_TEMPERATURE_8_IN_A_PERIOD_OF_DAY_UUID
 * @brief         Temperature 8 in a Period of Day.
 */
#define BLE_CHAR_TEMPERATURE_8_IN_A_PERIOD_OF_DAY_UUID \
                                             (0x2B0E)

/**
 * @def           BLE_CHAR_TEMPERATURE_8_STATISTICS_UUID
 * @brief         Temperature 8 Statistics.
 */
#define BLE_CHAR_TEMPERATURE_8_STATISTICS_UUID \
                                             (0x2B0F)

/**
 * @def           BLE_CHAR_TEMPERATURE_RANGE_UUID
 * @brief         Temperature Range.
 */
#define BLE_CHAR_TEMPERATURE_RANGE_UUID      (0x2B10)

/**
 * @def           BLE_CHAR_TEMPERATURE_STATISTICS_UUID
 * @brief         Temperature Statistics.
 */
#define BLE_CHAR_TEMPERATURE_STATISTICS_UUID (0x2B11)

/**
 * @def           BLE_CHAR_TIME_DECIHOUR_8_UUID
 * @brief         Time Decihour 8.
 */
#define BLE_CHAR_TIME_DECIHOUR_8_UUID        (0x2B12)

/**
 * @def           BLE_CHAR_TIME_EXPONENTIAL_8_UUID
 * @brief         Time Exponential 8.
 */
#define BLE_CHAR_TIME_EXPONENTIAL_8_UUID     (0x2B13)

/**
 * @def           BLE_CHAR_TIME_HOUR_24_UUID
 * @brief         Time Hour 24.
 */
#define BLE_CHAR_TIME_HOUR_24_UUID           (0x2B14)

/**
 * @def           BLE_CHAR_TIME_MILLISECOND_24_UUID
 * @brief         Time Millisecond 24.
 */
#define BLE_CHAR_TIME_MILLISECOND_24_UUID    (0x2B15)

/**
 * @def           BLE_CHAR_TIME_SECOND_16_UUID
 * @brief         Time Second 16.
 */
#define BLE_CHAR_TIME_SECOND_16_UUID         (0x2B16)

/**
 * @def           BLE_CHAR_TIME_SECOND_8_UUID
 * @brief         Time Second 8.
 */
#define BLE_CHAR_TIME_SECOND_8_UUID          (0x2B17)

/**
 * @def           BLE_CHAR_VOLTAGE_UUID
 * @brief         Voltage.
 */
#define BLE_CHAR_VOLTAGE_UUID                (0x2B18)

/**
 * @def           BLE_CHAR_VOLTAGE_SPECIFICATION_UUID
 * @brief         Voltage Specification.
 */
#define BLE_CHAR_VOLTAGE_SPECIFICATION_UUID  (0x2B19)

/**
 * @def           BLE_CHAR_VOLTAGE_STATISTICS_UUID
 * @brief         Voltage Statistics.
 */
#define BLE_CHAR_VOLTAGE_STATISTICS_UUID     (0x2B1A)

/**
 * @def           BLE_CHAR_VOLUME_FLOW_UUID
 * @brief         Volume Flow.
 */
#define BLE_CHAR_VOLUME_FLOW_UUID            (0x2B1B)

/**
 * @def           BLE_CHAR_CHROMATICITY_COORDINATE_UUID
 * @brief         Chromaticity Coordinate.
 */
#define BLE_CHAR_CHROMATICITY_COORDINATE_UUID \
                                             (0x2B1C)

/**
 * @def           BLE_CHAR_RC_FEATURE_UUID
 * @brief         RC Feature.
 */
#define BLE_CHAR_RC_FEATURE_UUID             (0x2B1D)

/**
 * @def           BLE_CHAR_RC_SETTINGS_UUID
 * @brief         RC Settings.
 */
#define BLE_CHAR_RC_SETTINGS_UUID            (0x2B1E)

/**
 * @def           BLE_CHAR_RECONNECTION_CONFIGURATION_CONTROL_POINT_UUID
 * @brief         Reconnection Configuration Control Point.
 */
#define BLE_CHAR_RECONNECTION_CONFIGURATION_CONTROL_POINT_UUID \
                                             (0x2B1F)

/**
 * @def           BLE_CHAR_IDD_STATUS_CHANGED_UUID
 * @brief         IDD Status Changed.
 */
#define BLE_CHAR_IDD_STATUS_CHANGED_UUID     (0x2B20)

/**
 * @def           BLE_CHAR_IDD_STATUS_UUID
 * @brief         IDD Status.
 */
#define BLE_CHAR_IDD_STATUS_UUID             (0x2B21)

/**
 * @def           BLE_CHAR_IDD_ANNUNCIATION_STATUS_UUID
 * @brief         IDD Annunciation Status.
 */
#define BLE_CHAR_IDD_ANNUNCIATION_STATUS_UUID \
                                             (0x2B22)

/**
 * @def           BLE_CHAR_IDD_FEATURES_UUID
 * @brief         IDD Features.
 */
#define BLE_CHAR_IDD_FEATURES_UUID           (0x2B23)

/**
 * @def           BLE_CHAR_IDD_STATUS_READER_CONTROL_POINT_UUID
 * @brief         IDD Status Reader Control Point.
 */
#define BLE_CHAR_IDD_STATUS_READER_CONTROL_POINT_UUID \
                                             (0x2B24)

/**
 * @def           BLE_CHAR_IDD_COMMAND_CONTROL_POINT_UUID
 * @brief         IDD Command Control Point.
 */
#define BLE_CHAR_IDD_COMMAND_CONTROL_POINT_UUID \
                                             (0x2B25)

/**
 * @def           BLE_CHAR_IDD_COMMAND_DATA_UUID
 * @brief         IDD Command Data.
 */
#define BLE_CHAR_IDD_COMMAND_DATA_UUID       (0x2B26)

/**
 * @def           BLE_CHAR_IDD_RECORD_ACCESS_CONTROL_POINT_UUID
 * @brief         IDD Record Access Control Point.
 */
#define BLE_CHAR_IDD_RECORD_ACCESS_CONTROL_POINT_UUID \
                                             (0x2B27)

/**
 * @def           BLE_CHAR_IDD_HISTORY_DATA_UUID
 * @brief         IDD History Data.
 */
#define BLE_CHAR_IDD_HISTORY_DATA_UUID       (0x2B28)

/**
 * @def           BLE_CHAR_CLIENT_SUPPORTED_FEATURES_UUID
 * @brief         Client Supported Features.
 */
#define BLE_CHAR_CLIENT_SUPPORTED_FEATURES_UUID \
                                             (0x2B29)

/**
 * @def           BLE_CHAR_DATABASE_HASH_UUID
 * @brief         Database Hash.
 */
#define BLE_CHAR_DATABASE_HASH_UUID          (0x2B2A)

/**
 * @def           BLE_CHAR_BSS_CONTROL_POINT_UUID
 * @brief         BSS Control Point.
 */
#define BLE_CHAR_BSS_CONTROL_POINT_UUID      (0x2B2B)

/**
 * @def           BLE_CHAR_BSS_RESPONSE_UUID
 * @brief         BSS Response.
 */
#define BLE_CHAR_BSS_RESPONSE_UUID           (0x2B2C)

/**
 * @def           BLE_CHAR_EMERGENCY_ID_UUID
 * @brief         Emergency ID.
 */
#define BLE_CHAR_EMERGENCY_ID_UUID           (0x2B2D)

/**
 * @def           BLE_CHAR_EMERGENCY_TEXT_UUID
 * @brief         Emergency Text.
 */
#define BLE_CHAR_EMERGENCY_TEXT_UUID         (0x2B2E)

/**
 * @def           BLE_CHAR_ACS_STATUS_UUID
 * @brief         ACS Status.
 */
#define BLE_CHAR_ACS_STATUS_UUID             (0x2B2F)

/**
 * @def           BLE_CHAR_ACS_DATA_IN_UUID
 * @brief         ACS Data In.
 */
#define BLE_CHAR_ACS_DATA_IN_UUID            (0x2B30)

/**
 * @def           BLE_CHAR_ACS_DATA_OUT_NOTIFY_UUID
 * @brief         ACS Data Out Notify.
 */
#define BLE_CHAR_ACS_DATA_OUT_NOTIFY_UUID    (0x2B31)

/**
 * @def           BLE_CHAR_ACS_DATA_OUT_INDICATE_UUID
 * @brief         ACS Data Out Indicate.
 */
#define BLE_CHAR_ACS_DATA_OUT_INDICATE_UUID  (0x2B32)

/**
 * @def           BLE_CHAR_ACS_CONTROL_POINT_UUID
 * @brief         ACS Control Point.
 */
#define BLE_CHAR_ACS_CONTROL_POINT_UUID      (0x2B33)

/**
 * @def           BLE_CHAR_ENHANCED_BLOOD_PRESSURE_MEASUREMENT_UUID
 * @brief         Enhanced Blood Pressure Measurement.
 */
#define BLE_CHAR_ENHANCED_BLOOD_PRESSURE_MEASUREMENT_UUID \
                                             (0x2B34)

/**
 * @def           BLE_CHAR_ENHANCED_INTERMEDIATE_CUFF_PRESSURE_UUID
 * @brief         Enhanced Intermediate Cuff Pressure.
 */
#define BLE_CHAR_ENHANCED_INTERMEDIATE_CUFF_PRESSURE_UUID \
                                             (0x2B35)

/**
 * @def           BLE_CHAR_BLOOD_PRESSURE_RECORD_UUID
 * @brief         Blood Pressure Record.
 */
#define BLE_CHAR_BLOOD_PRESSURE_RECORD_UUID  (0x2B36)

/**
 * @def           BLE_CHAR_REGISTERED_USER_UUID
 * @brief         Registered User.
 */
#define BLE_CHAR_REGISTERED_USER_UUID        (0x2B37)

/**
 * @def           BLE_CHAR_BR_EDR_HANDOVER_DATA_UUID
 * @brief         BR-EDR Handover Data.
 */
#define BLE_CHAR_BR_EDR_HANDOVER_DATA_UUID   (0x2B38)

/**
 * @def           BLE_CHAR_BLUETOOTH_SIG_DATA_UUID
 * @brief         Bluetooth SIG Data.
 */
#define BLE_CHAR_BLUETOOTH_SIG_DATA_UUID     (0x2B39)

/**
 * @def           BLE_CHAR_SERVER_SUPPORTED_FEATURES_UUID
 * @brief         Server Supported Features.
 */
#define BLE_CHAR_SERVER_SUPPORTED_FEATURES_UUID \
                                             (0x2B3A)

/**
 * @def           BLE_CHAR_PHYSICAL_ACTIVITY_MONITOR_FEATURES_UUID
 * @brief         Physical Activity Monitor Features.
 */
#define BLE_CHAR_PHYSICAL_ACTIVITY_MONITOR_FEATURES_UUID \
                                             (0x2B3B)

/**
 * @def           BLE_CHAR_GENERAL_ACTIVITY_INSTANTANEOUS_DATA_UUID
 * @brief         General Activity Instantaneous Data.
 */
#define BLE_CHAR_GENERAL_ACTIVITY_INSTANTANEOUS_DATA_UUID \
                                             (0x2B3C)

/**
 * @def           BLE_CHAR_GENERAL_ACTIVITY_SUMMARY_DATA_UUID
 * @brief         General Activity Summary Data.
 */
#define BLE_CHAR_GENERAL_ACTIVITY_SUMMARY_DATA_UUID \
                                             (0x2B3D)

/**
 * @def           BLE_CHAR_CARDIORESPIRATORY_ACTIVITY_INSTANTANEOUS_DATA_UUID
 * @brief         CardioRespiratory Activity Instantaneous Data.
 */
#define BLE_CHAR_CARDIORESPIRATORY_ACTIVITY_INSTANTANEOUS_DATA_UUID \
                                             (0x2B3E)

/**
 * @def           BLE_CHAR_CARDIORESPIRATORY_ACTIVITY_SUMMARY_DATA_UUID
 * @brief         CardioRespiratory Activity Summary Data.
 */
#define BLE_CHAR_CARDIORESPIRATORY_ACTIVITY_SUMMARY_DATA_UUID \
                                             (0x2B3F)

/**
 * @def           BLE_CHAR_STEP_COUNTER_ACTIVITY_SUMMARY_DATA_UUID
 * @brief         Step Counter Activity Summary Data.
 */
#define BLE_CHAR_STEP_COUNTER_ACTIVITY_SUMMARY_DATA_UUID \
                                             (0x2B40)

/**
 * @def           BLE_CHAR_SLEEP_ACTIVITY_INSTANTANEOUS_DATA_UUID
 * @brief         Sleep Activity Instantaneous Data.
 */
#define BLE_CHAR_SLEEP_ACTIVITY_INSTANTANEOUS_DATA_UUID \
                                             (0x2B41)

/**
 * @def           BLE_CHAR_SLEEP_ACTIVITY_SUMMARY_DATA_UUID
 * @brief         Sleep Activity Summary Data.
 */
#define BLE_CHAR_SLEEP_ACTIVITY_SUMMARY_DATA_UUID \
                                             (0x2B42)

/**
 * @def           BLE_CHAR_PHYSICAL_ACTIVITY_MONITOR_CONTROL_POINT_UUID
 * @brief         Physical Activity Monitor Control Point.
 */
#define BLE_CHAR_PHYSICAL_ACTIVITY_MONITOR_CONTROL_POINT_UUID \
                                             (0x2B43)

/**
 * @def           BLE_CHAR_PHYSICAL_ACTIVITY_CURRENT_SESSION_UUID
 * @brief         Physical Activity Current Session.
 */
#define BLE_CHAR_PHYSICAL_ACTIVITY_CURRENT_SESSION_UUID \
                                             (0x2B44)

/**
 * @def           BLE_CHAR_PHYSICAL_ACTIVITY_SESSION_DESCRIPTOR_UUID
 * @brief         Physical Activity Session Descriptor.
 */
#define BLE_CHAR_PHYSICAL_ACTIVITY_SESSION_DESCRIPTOR_UUID \
                                             (0x2B45)

/**
 * @def           BLE_CHAR_PREFERRED_UNITS_UUID
 * @brief         Preferred Units.
 */
#define BLE_CHAR_PREFERRED_UNITS_UUID        (0x2B46)

/**
 * @def           BLE_CHAR_HIGH_RESOLUTION_HEIGHT_UUID
 * @brief         High Resolution Height.
 */
#define BLE_CHAR_HIGH_RESOLUTION_HEIGHT_UUID (0x2B47)

/**
 * @def           BLE_CHAR_MIDDLE_NAME_UUID
 * @brief         Middle Name.
 */
#define BLE_CHAR_MIDDLE_NAME_UUID            (0x2B48)

/**
 * @def           BLE_CHAR_STRIDE_LENGTH_UUID
 * @brief         Stride Length.
 */
#define BLE_CHAR_STRIDE_LENGTH_UUID          (0x2B49)

/**
 * @def           BLE_CHAR_HANDEDNESS_UUID
 * @brief         Handedness.
 */
#define BLE_CHAR_HANDEDNESS_UUID             (0x2B4A)

/**
 * @def           BLE_CHAR_DEVICE_WEARING_POSITION_UUID
 * @brief         Device Wearing Position.
 */
#define BLE_CHAR_DEVICE_WEARING_POSITION_UUID \
                                             (0x2B4B)

/**
 * @def           BLE_CHAR_FOUR_ZONE_HEART_RATE_LIMITS_UUID
 * @brief         Four Zone Heart Rate Limits.
 */
#define BLE_CHAR_FOUR_ZONE_HEART_RATE_LIMITS_UUID \
                                             (0x2B4C)

/**
 * @def           BLE_CHAR_HIGH_INTENSITY_EXERCISE_THRESHOLD_UUID
 * @brief         High Intensity Exercise Threshold.
 */
#define BLE_CHAR_HIGH_INTENSITY_EXERCISE_THRESHOLD_UUID \
                                             (0x2B4D)

/**
 * @def           BLE_CHAR_ACTIVITY_GOAL_UUID
 * @brief         Activity Goal.
 */
#define BLE_CHAR_ACTIVITY_GOAL_UUID          (0x2B4E)

/**
 * @def           BLE_CHAR_SEDENTARY_INTERVAL_NOTIFICATION_UUID
 * @brief         Sedentary Interval Notification.
 */
#define BLE_CHAR_SEDENTARY_INTERVAL_NOTIFICATION_UUID \
                                             (0x2B4F)

/**
 * @def           BLE_CHAR_CALORIC_INTAKE_UUID
 * @brief         Caloric Intake.
 */
#define BLE_CHAR_CALORIC_INTAKE_UUID         (0x2B50)

/**
 * @def           BLE_CHAR_TMAP_ROLE_UUID
 * @brief         TMAP Role.
 */
#define BLE_CHAR_TMAP_ROLE_UUID              (0x2B51)

/**
 * @def           BLE_CHAR_AUDIO_INPUT_STATE_UUID
 * @brief         Audio Input State.
 */
#define BLE_CHAR_AUDIO_INPUT_STATE_UUID      (0x2B77)

/**
 * @def           BLE_CHAR_GAIN_SETTINGS_ATTRIBUTE_UUID
 * @brief         Gain Settings Attribute.
 */
#define BLE_CHAR_GAIN_SETTINGS_ATTRIBUTE_UUID \
                                             (0x2B78)

/**
 * @def           BLE_CHAR_AUDIO_INPUT_TYPE_UUID
 * @brief         Audio Input Type.
 */
#define BLE_CHAR_AUDIO_INPUT_TYPE_UUID       (0x2B79)

/**
 * @def           BLE_CHAR_AUDIO_INPUT_STATUS_UUID
 * @brief         Audio Input Status.
 */
#define BLE_CHAR_AUDIO_INPUT_STATUS_UUID     (0x2B7A)

/**
 * @def           BLE_CHAR_AUDIO_INPUT_CONTROL_POINT_UUID
 * @brief         Audio Input Control Point.
 */
#define BLE_CHAR_AUDIO_INPUT_CONTROL_POINT_UUID \
                                             (0x2B7B)

/**
 * @def           BLE_CHAR_AUDIO_INPUT_DESCRIPTION_UUID
 * @brief         Audio Input Description.
 */
#define BLE_CHAR_AUDIO_INPUT_DESCRIPTION_UUID \
                                             (0x2B7C)

/**
 * @def           BLE_CHAR_VOLUME_STATE_UUID
 * @brief         Volume State.
 */
#define BLE_CHAR_VOLUME_STATE_UUID           (0x2B7D)

/**
 * @def           BLE_CHAR_VOLUME_CONTROL_POINT_UUID
 * @brief         Volume Control Point.
 */
#define BLE_CHAR_VOLUME_CONTROL_POINT_UUID   (0x2B7E)

/**
 * @def           BLE_CHAR_VOLUME_FLAGS_UUID
 * @brief         Volume Flags.
 */
#define BLE_CHAR_VOLUME_FLAGS_UUID           (0x2B7F)

/**
 * @def           BLE_CHAR_VOLUME_OFFSET_STATE_UUID
 * @brief         Volume Offset State.
 */
#define BLE_CHAR_VOLUME_OFFSET_STATE_UUID    (0x2B80)

/**
 * @def           BLE_CHAR_AUDIO_LOCATION_UUID
 * @brief         Audio Location.
 */
#define BLE_CHAR_AUDIO_LOCATION_UUID         (0x2B81)

/**
 * @def           BLE_CHAR_VOLUME_OFFSET_CONTROL_POINT_UUID
 * @brief         Volume Offset Control Point.
 */
#define BLE_CHAR_VOLUME_OFFSET_CONTROL_POINT_UUID \
                                             (0x2B82)

/**
 * @def           BLE_CHAR_AUDIO_OUTPUT_DESCRIPTION_UUID
 * @brief         Audio Output Description.
 */
#define BLE_CHAR_AUDIO_OUTPUT_DESCRIPTION_UUID \
                                             (0x2B83)

/**
 * @def           BLE_CHAR_SET_IDENTITY_RESOLVING_KEY_UUID
 * @brief         Set Identity Resolving Key.
 */
#define BLE_CHAR_SET_IDENTITY_RESOLVING_KEY_UUID \
                                             (0x2B84)

/**
 * @def           BLE_CHAR_COORDINATED_SET_SIZE_UUID
 * @brief         Coordinated Set Size.
 */
#define BLE_CHAR_COORDINATED_SET_SIZE_UUID   (0x2B85)

/**
 * @def           BLE_CHAR_SET_MEMBER_LOCK_UUID
 * @brief         Set Member Lock.
 */
#define BLE_CHAR_SET_MEMBER_LOCK_UUID        (0x2B86)

/**
 * @def           BLE_CHAR_SET_MEMBER_RANK_UUID
 * @brief         Set Member Rank.
 */
#define BLE_CHAR_SET_MEMBER_RANK_UUID        (0x2B87)

/**
 * @def           BLE_CHAR_ENCRYPTED_DATA_KEY_MATERIAL_UUID
 * @brief         Encrypted Data Key Material.
 */
#define BLE_CHAR_ENCRYPTED_DATA_KEY_MATERIAL_UUID \
                                             (0x2B88)

/**
 * @def           BLE_CHAR_APPARENT_ENERGY_32_UUID
 * @brief         Apparent Energy 32.
 */
#define BLE_CHAR_APPARENT_ENERGY_32_UUID     (0x2B89)

/**
 * @def           BLE_CHAR_APPARENT_POWER_UUID
 * @brief         Apparent Power.
 */
#define BLE_CHAR_APPARENT_POWER_UUID         (0x2B8A)

/**
 * @def           BLE_CHAR_LIVE_HEALTH_OBSERVATIONS_UUID
 * @brief         Live Health Observations.
 */
#define BLE_CHAR_LIVE_HEALTH_OBSERVATIONS_UUID \
                                             (0x2B8B)

/**
 * @def           BLE_CHAR_CO2_CONCENTRATION_UUID
 * @brief         CO\textsubscript{2} Concentration.
 */
#define BLE_CHAR_CO2_CONCENTRATION_UUID      (0x2B8C)

/**
 * @def           BLE_CHAR_COSINE_OF_THE_ANGLE_UUID
 * @brief         Cosine of the Angle.
 */
#define BLE_CHAR_COSINE_OF_THE_ANGLE_UUID    (0x2B8D)

/**
 * @def           BLE_CHAR_DEVICE_TIME_FEATURE_UUID
 * @brief         Device Time Feature.
 */
#define BLE_CHAR_DEVICE_TIME_FEATURE_UUID    (0x2B8E)

/**
 * @def           BLE_CHAR_DEVICE_TIME_PARAMETERS_UUID
 * @brief         Device Time Parameters.
 */
#define BLE_CHAR_DEVICE_TIME_PARAMETERS_UUID (0x2B8F)

/**
 * @def           BLE_CHAR_DEVICE_TIME_UUID
 * @brief         Device Time.
 */
#define BLE_CHAR_DEVICE_TIME_UUID            (0x2B90)

/**
 * @def           BLE_CHAR_DEVICE_TIME_CONTROL_POINT_UUID
 * @brief         Device Time Control Point.
 */
#define BLE_CHAR_DEVICE_TIME_CONTROL_POINT_UUID \
                                             (0x2B91)

/**
 * @def           BLE_CHAR_TIME_CHANGE_LOG_DATA_UUID
 * @brief         Time Change Log Data.
 */
#define BLE_CHAR_TIME_CHANGE_LOG_DATA_UUID   (0x2B92)

/**
 * @def           BLE_CHAR_MEDIA_PLAYER_NAME_UUID
 * @brief         Media Player Name.
 */
#define BLE_CHAR_MEDIA_PLAYER_NAME_UUID      (0x2B93)

/**
 * @def           BLE_CHAR_MEDIA_PLAYER_ICON_OBJECT_ID_UUID
 * @brief         Media Player Icon Object ID.
 */
#define BLE_CHAR_MEDIA_PLAYER_ICON_OBJECT_ID_UUID \
                                             (0x2B94)

/**
 * @def           BLE_CHAR_MEDIA_PLAYER_ICON_URL_UUID
 * @brief         Media Player Icon URL.
 */
#define BLE_CHAR_MEDIA_PLAYER_ICON_URL_UUID  (0x2B95)

/**
 * @def           BLE_CHAR_TRACK_CHANGED_UUID
 * @brief         Track Changed.
 */
#define BLE_CHAR_TRACK_CHANGED_UUID          (0x2B96)

/**
 * @def           BLE_CHAR_TRACK_TITLE_UUID
 * @brief         Track Title.
 */
#define BLE_CHAR_TRACK_TITLE_UUID            (0x2B97)

/**
 * @def           BLE_CHAR_TRACK_DURATION_UUID
 * @brief         Track Duration.
 */
#define BLE_CHAR_TRACK_DURATION_UUID         (0x2B98)

/**
 * @def           BLE_CHAR_TRACK_POSITION_UUID
 * @brief         Track Position.
 */
#define BLE_CHAR_TRACK_POSITION_UUID         (0x2B99)

/**
 * @def           BLE_CHAR_PLAYBACK_SPEED_UUID
 * @brief         Playback Speed.
 */
#define BLE_CHAR_PLAYBACK_SPEED_UUID         (0x2B9A)

/**
 * @def           BLE_CHAR_SEEKING_SPEED_UUID
 * @brief         Seeking Speed.
 */
#define BLE_CHAR_SEEKING_SPEED_UUID          (0x2B9B)

/**
 * @def           BLE_CHAR_CURRENT_TRACK_SEGMENTS_OBJECT_ID_UUID
 * @brief         Current Track Segments Object ID.
 */
#define BLE_CHAR_CURRENT_TRACK_SEGMENTS_OBJECT_ID_UUID \
                                             (0x2B9C)

/**
 * @def           BLE_CHAR_CURRENT_TRACK_OBJECT_ID_UUID
 * @brief         Current Track Object ID.
 */
#define BLE_CHAR_CURRENT_TRACK_OBJECT_ID_UUID \
                                             (0x2B9D)

/**
 * @def           BLE_CHAR_NEXT_TRACK_OBJECT_ID_UUID
 * @brief         Next Track Object ID.
 */
#define BLE_CHAR_NEXT_TRACK_OBJECT_ID_UUID   (0x2B9E)

/**
 * @def           BLE_CHAR_PARENT_GROUP_OBJECT_ID_UUID
 * @brief         Parent Group Object ID.
 */
#define BLE_CHAR_PARENT_GROUP_OBJECT_ID_UUID (0x2B9F)

/**
 * @def           BLE_CHAR_CURRENT_GROUP_OBJECT_ID_UUID
 * @brief         Current Group Object ID.
 */
#define BLE_CHAR_CURRENT_GROUP_OBJECT_ID_UUID \
                                             (0x2BA0)

/**
 * @def           BLE_CHAR_PLAYING_ORDER_UUID
 * @brief         Playing Order.
 */
#define BLE_CHAR_PLAYING_ORDER_UUID          (0x2BA1)

/**
 * @def           BLE_CHAR_PLAYING_ORDERS_SUPPORTED_UUID
 * @brief         Playing Orders Supported.
 */
#define BLE_CHAR_PLAYING_ORDERS_SUPPORTED_UUID \
                                             (0x2BA2)

/**
 * @def           BLE_CHAR_MEDIA_STATE_UUID
 * @brief         Media State.
 */
#define BLE_CHAR_MEDIA_STATE_UUID            (0x2BA3)

/**
 * @def           BLE_CHAR_MEDIA_CONTROL_POINT_UUID
 * @brief         Media Control Point.
 */
#define BLE_CHAR_MEDIA_CONTROL_POINT_UUID    (0x2BA4)

/**
 * @def           BLE_CHAR_MEDIA_CONTROL_POINT_OPCODES_SUPPORTED_UUID
 * @brief         Media Control Point Opcodes Supported.
 */
#define BLE_CHAR_MEDIA_CONTROL_POINT_OPCODES_SUPPORTED_UUID \
                                             (0x2BA5)

/**
 * @def           BLE_CHAR_SEARCH_RESULTS_OBJECT_ID_UUID
 * @brief         Search Results Object ID.
 */
#define BLE_CHAR_SEARCH_RESULTS_OBJECT_ID_UUID \
                                             (0x2BA6)

/**
 * @def           BLE_CHAR_SEARCH_CONTROL_POINT_UUID
 * @brief         Search Control Point.
 */
#define BLE_CHAR_SEARCH_CONTROL_POINT_UUID   (0x2BA7)

/**
 * @def           BLE_CHAR_ENERGY_32_UUID
 * @brief         Energy 32.
 */
#define BLE_CHAR_ENERGY_32_UUID              (0x2BA8)

/**
 * @def           BLE_CHAR_CONSTANT_TONE_EXTENSION_ENABLE_UUID
 * @brief         Constant Tone Extension Enable.
 */
#define BLE_CHAR_CONSTANT_TONE_EXTENSION_ENABLE_UUID \
                                             (0x2BAD)

/**
 * @def           BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_MINIMUM_LENGTH_UUID
 * @brief         Advertising Constant Tone Extension Minimum Length.
 */
#define BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_MINIMUM_LENGTH_UUID \
                                             (0x2BAE)

/**
 * @def           BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_MINIMUM_TRANSMIT_COUNT_UUID
 * @brief         Advertising Constant Tone Extension Minimum Transmit Count.
 */
#define BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_MINIMUM_TRANSMIT_COUNT_UUID \
                                             (0x2BAF)

/**
 * @def           BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_TRANSMIT_DURATION_UUID
 * @brief         Advertising Constant Tone Extension Transmit Duration.
 */
#define BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_TRANSMIT_DURATION_UUID \
                                             (0x2BB0)

/**
 * @def           BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_INTERVAL_UUID
 * @brief         Advertising Constant Tone Extension Interval.
 */
#define BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_INTERVAL_UUID \
                                             (0x2BB1)

/**
 * @def           BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_PHY_UUID
 * @brief         Advertising Constant Tone Extension PHY.
 */
#define BLE_CHAR_ADVERTISING_CONSTANT_TONE_EXTENSION_PHY_UUID \
                                             (0x2BB2)

/**
 * @def           BLE_CHAR_BEARER_PROVIDER_NAME_UUID
 * @brief         Bearer Provider Name.
 */
#define BLE_CHAR_BEARER_PROVIDER_NAME_UUID   (0x2BB3)

/**
 * @def           BLE_CHAR_BEARER_UCI_UUID
 * @brief         Bearer UCI.
 */
#define BLE_CHAR_BEARER_UCI_UUID             (0x2BB4)

/**
 * @def           BLE_CHAR_BEARER_TECHNOLOGY_UUID
 * @brief         Bearer Technology.
 */
#define BLE_CHAR_BEARER_TECHNOLOGY_UUID      (0x2BB5)

/**
 * @def           BLE_CHAR_BEARER_URI_SCHEMES_SUPPORTED_LIST_UUID
 * @brief         Bearer URI Schemes Supported List.
 */
#define BLE_CHAR_BEARER_URI_SCHEMES_SUPPORTED_LIST_UUID \
                                             (0x2BB6)

/**
 * @def           BLE_CHAR_BEARER_SIGNAL_STRENGTH_UUID
 * @brief         Bearer Signal Strength.
 */
#define BLE_CHAR_BEARER_SIGNAL_STRENGTH_UUID (0x2BB7)

/**
 * @def           BLE_CHAR_BEARER_SIGNAL_STRENGTH_REPORTING_INTERVAL_UUID
 * @brief         Bearer Signal Strength Reporting Interval.
 */
#define BLE_CHAR_BEARER_SIGNAL_STRENGTH_REPORTING_INTERVAL_UUID \
                                             (0x2BB8)

/**
 * @def           BLE_CHAR_BEARER_LIST_CURRENT_CALLS_UUID
 * @brief         Bearer List Current Calls.
 */
#define BLE_CHAR_BEARER_LIST_CURRENT_CALLS_UUID \
                                             (0x2BB9)

/**
 * @def           BLE_CHAR_CONTENT_CONTROL_ID_UUID
 * @brief         Content Control ID.
 */
#define BLE_CHAR_CONTENT_CONTROL_ID_UUID     (0x2BBA)

/**
 * @def           BLE_CHAR_STATUS_FLAGS_UUID
 * @brief         Status Flags.
 */
#define BLE_CHAR_STATUS_FLAGS_UUID           (0x2BBB)

/**
 * @def           BLE_CHAR_INCOMING_CALL_TARGET_BEARER_URI_UUID
 * @brief         Incoming Call Target Bearer URI.
 */
#define BLE_CHAR_INCOMING_CALL_TARGET_BEARER_URI_UUID \
                                             (0x2BBC)

/**
 * @def           BLE_CHAR_CALL_STATE_UUID
 * @brief         Call State.
 */
#define BLE_CHAR_CALL_STATE_UUID             (0x2BBD)

/**
 * @def           BLE_CHAR_CALL_CONTROL_POINT_UUID
 * @brief         Call Control Point.
 */
#define BLE_CHAR_CALL_CONTROL_POINT_UUID     (0x2BBE)

/**
 * @def           BLE_CHAR_CALL_CONTROL_POINT_OPTIONAL_OPCODES_UUID
 * @brief         Call Control Point Optional Opcodes.
 */
#define BLE_CHAR_CALL_CONTROL_POINT_OPTIONAL_OPCODES_UUID \
                                             (0x2BBF)

/**
 * @def           BLE_CHAR_TERMINATION_REASON_UUID
 * @brief         Termination Reason.
 */
#define BLE_CHAR_TERMINATION_REASON_UUID     (0x2BC0)

/**
 * @def           BLE_CHAR_INCOMING_CALL_UUID
 * @brief         Incoming Call.
 */
#define BLE_CHAR_INCOMING_CALL_UUID          (0x2BC1)

/**
 * @def           BLE_CHAR_CALL_FRIENDLY_NAME_UUID
 * @brief         Call Friendly Name.
 */
#define BLE_CHAR_CALL_FRIENDLY_NAME_UUID     (0x2BC2)

/**
 * @def           BLE_CHAR_MUTE_UUID
 * @brief         Mute.
 */
#define BLE_CHAR_MUTE_UUID                   (0x2BC3)

/**
 * @def           BLE_CHAR_SINK_ASE_UUID
 * @brief         Sink ASE.
 */
#define BLE_CHAR_SINK_ASE_UUID               (0x2BC4)

/**
 * @def           BLE_CHAR_SOURCE_ASE_UUID
 * @brief         Source ASE.
 */
#define BLE_CHAR_SOURCE_ASE_UUID             (0x2BC5)

/**
 * @def           BLE_CHAR_ASE_CONTROL_POINT_UUID
 * @brief         ASE Control Point.
 */
#define BLE_CHAR_ASE_CONTROL_POINT_UUID      (0x2BC6)

/**
 * @def           BLE_CHAR_BROADCAST_AUDIO_SCAN_CONTROL_POINT_UUID
 * @brief         Broadcast Audio Scan Control Point.
 */
#define BLE_CHAR_BROADCAST_AUDIO_SCAN_CONTROL_POINT_UUID \
                                             (0x2BC7)

/**
 * @def           BLE_CHAR_BROADCAST_RECEIVE_STATE_UUID
 * @brief         Broadcast Receive State.
 */
#define BLE_CHAR_BROADCAST_RECEIVE_STATE_UUID \
                                             (0x2BC8)

/**
 * @def           BLE_CHAR_SINK_PAC_UUID
 * @brief         Sink PAC.
 */
#define BLE_CHAR_SINK_PAC_UUID               (0x2BC9)

/**
 * @def           BLE_CHAR_SINK_AUDIO_LOCATIONS_UUID
 * @brief         Sink Audio Locations.
 */
#define BLE_CHAR_SINK_AUDIO_LOCATIONS_UUID   (0x2BCA)

/**
 * @def           BLE_CHAR_SOURCE_PAC_UUID
 * @brief         Source PAC.
 */
#define BLE_CHAR_SOURCE_PAC_UUID             (0x2BCB)

/**
 * @def           BLE_CHAR_SOURCE_AUDIO_LOCATIONS_UUID
 * @brief         Source Audio Locations.
 */
#define BLE_CHAR_SOURCE_AUDIO_LOCATIONS_UUID (0x2BCC)

/**
 * @def           BLE_CHAR_AVAILABLE_AUDIO_CONTEXTS_UUID
 * @brief         Available Audio Contexts.
 */
#define BLE_CHAR_AVAILABLE_AUDIO_CONTEXTS_UUID \
                                             (0x2BCD)

/**
 * @def           BLE_CHAR_SUPPORTED_AUDIO_CONTEXTS_UUID
 * @brief         Supported Audio Contexts.
 */
#define BLE_CHAR_SUPPORTED_AUDIO_CONTEXTS_UUID \
                                             (0x2BCE)

/**
 * @def           BLE_CHAR_AMMONIA_CONCENTRATION_UUID
 * @brief         Ammonia Concentration.
 */
#define BLE_CHAR_AMMONIA_CONCENTRATION_UUID  (0x2BCF)

/**
 * @def           BLE_CHAR_CARBON_MONOXIDE_CONCENTRATION_UUID
 * @brief         Carbon Monoxide Concentration.
 */
#define BLE_CHAR_CARBON_MONOXIDE_CONCENTRATION_UUID \
                                             (0x2BD0)

/**
 * @def           BLE_CHAR_METHANE_CONCENTRATION_UUID
 * @brief         Methane Concentration.
 */
#define BLE_CHAR_METHANE_CONCENTRATION_UUID  (0x2BD1)

/**
 * @def           BLE_CHAR_NITROGEN_DIOXIDE_CONCENTRATION_UUID
 * @brief         Nitrogen Dioxide Concentration.
 */
#define BLE_CHAR_NITROGEN_DIOXIDE_CONCENTRATION_UUID \
                                             (0x2BD2)

/**
 * @def           BLE_CHAR_NON_METHANE_VOLATILE_ORGANIC_COMPOUNDS_CONCENTRATION_UUID
 * @brief         Non-Methane Volatile Organic Compounds Concentration.
 */
#define BLE_CHAR_NON_METHANE_VOLATILE_ORGANIC_COMPOUNDS_CONCENTRATION_UUID \
                                             (0x2BD3)

/**
 * @def           BLE_CHAR_OZONE_CONCENTRATION_UUID
 * @brief         Ozone Concentration.
 */
#define BLE_CHAR_OZONE_CONCENTRATION_UUID    (0x2BD4)

/**
 * @def           BLE_CHAR_PARTICULATE_MATTER_PM1_CONCENTRATION_UUID
 * @brief         Particulate Matter - PM1 Concentration.
 */
#define BLE_CHAR_PARTICULATE_MATTER_PM1_CONCENTRATION_UUID \
                                             (0x2BD5)

/**
 * @def           BLE_CHAR_PARTICULATE_MATTER_PM2_5_CONCENTRATION_UUID
 * @brief         Particulate Matter - PM2.5 Concentration.
 */
#define BLE_CHAR_PARTICULATE_MATTER_PM2_5_CONCENTRATION_UUID \
                                             (0x2BD6)

/**
 * @def           BLE_CHAR_PARTICULATE_MATTER_PM10_CONCENTRATION_UUID
 * @brief         Particulate Matter - PM10 Concentration.
 */
#define BLE_CHAR_PARTICULATE_MATTER_PM10_CONCENTRATION_UUID \
                                             (0x2BD7)

/**
 * @def           BLE_CHAR_SULFUR_DIOXIDE_CONCENTRATION_UUID
 * @brief         Sulfur Dioxide Concentration.
 */
#define BLE_CHAR_SULFUR_DIOXIDE_CONCENTRATION_UUID \
                                             (0x2BD8)

/**
 * @def           BLE_CHAR_SULFUR_HEXAFLUORIDE_CONCENTRATION_UUID
 * @brief         Sulfur Hexafluoride Concentration.
 */
#define BLE_CHAR_SULFUR_HEXAFLUORIDE_CONCENTRATION_UUID \
                                             (0x2BD9)

/**
 * @def           BLE_CHAR_HEARING_AID_FEATURES_UUID
 * @brief         Hearing Aid Features.
 */
#define BLE_CHAR_HEARING_AID_FEATURES_UUID   (0x2BDA)

/**
 * @def           BLE_CHAR_HEARING_AID_PRESET_CONTROL_POINT_UUID
 * @brief         Hearing Aid Preset Control Point.
 */
#define BLE_CHAR_HEARING_AID_PRESET_CONTROL_POINT_UUID \
                                             (0x2BDB)

/**
 * @def           BLE_CHAR_ACTIVE_PRESET_INDEX_UUID
 * @brief         Active Preset Index.
 */
#define BLE_CHAR_ACTIVE_PRESET_INDEX_UUID    (0x2BDC)

/**
 * @def           BLE_CHAR_STORED_HEALTH_OBSERVATIONS_UUID
 * @brief         Stored Health Observations.
 */
#define BLE_CHAR_STORED_HEALTH_OBSERVATIONS_UUID \
                                             (0x2BDD)

/**
 * @def           BLE_CHAR_FIXED_STRING_64_UUID
 * @brief         Fixed String 64.
 */
#define BLE_CHAR_FIXED_STRING_64_UUID        (0x2BDE)

/**
 * @def           BLE_CHAR_HIGH_TEMPERATURE_UUID
 * @brief         High Temperature.
 */
#define BLE_CHAR_HIGH_TEMPERATURE_UUID       (0x2BDF)

/**
 * @def           BLE_CHAR_HIGH_VOLTAGE_UUID
 * @brief         High Voltage.
 */
#define BLE_CHAR_HIGH_VOLTAGE_UUID           (0x2BE0)

/**
 * @def           BLE_CHAR_LIGHT_DISTRIBUTION_UUID
 * @brief         Light Distribution.
 */
#define BLE_CHAR_LIGHT_DISTRIBUTION_UUID     (0x2BE1)

/**
 * @def           BLE_CHAR_LIGHT_OUTPUT_UUID
 * @brief         Light Output.
 */
#define BLE_CHAR_LIGHT_OUTPUT_UUID           (0x2BE2)

/**
 * @def           BLE_CHAR_LIGHT_SOURCE_TYPE_UUID
 * @brief         Light Source Type.
 */
#define BLE_CHAR_LIGHT_SOURCE_TYPE_UUID      (0x2BE3)

/**
 * @def           BLE_CHAR_NOISE_UUID
 * @brief         Noise.
 */
#define BLE_CHAR_NOISE_UUID                  (0x2BE4)

/**
 * @def           BLE_CHAR_RELATIVE_RUNTIME_IN_A_CORRELATED_COLOR_TEMPERATURE_RANGE_UUID
 * @brief         Relative Runtime in a Correlated Color Temperature Range.
 */
#define BLE_CHAR_RELATIVE_RUNTIME_IN_A_CORRELATED_COLOR_TEMPERATURE_RANGE_UUID \
                                             (0x2BE5)

/**
 * @def           BLE_CHAR_TIME_SECOND_32_UUID
 * @brief         Time Second 32.
 */
#define BLE_CHAR_TIME_SECOND_32_UUID         (0x2BE6)

/**
 * @def           BLE_CHAR_VOC_CONCENTRATION_UUID
 * @brief         VOC Concentration.
 */
#define BLE_CHAR_VOC_CONCENTRATION_UUID      (0x2BE7)

/**
 * @def           BLE_CHAR_VOLTAGE_FREQUENCY_UUID
 * @brief         Voltage Frequency.
 */
#define BLE_CHAR_VOLTAGE_FREQUENCY_UUID      (0x2BE8)

/**
 * @def           BLE_CHAR_BATTERY_CRITICAL_STATUS_UUID
 * @brief         Battery Critical Status.
 */
#define BLE_CHAR_BATTERY_CRITICAL_STATUS_UUID \
                                             (0x2BE9)

/**
 * @def           BLE_CHAR_BATTERY_HEALTH_STATUS_UUID
 * @brief         Battery Health Status.
 */
#define BLE_CHAR_BATTERY_HEALTH_STATUS_UUID  (0x2BEA)

/**
 * @def           BLE_CHAR_BATTERY_HEALTH_INFORMATION_UUID
 * @brief         Battery Health Information.
 */
#define BLE_CHAR_BATTERY_HEALTH_INFORMATION_UUID \
                                             (0x2BEB)

/**
 * @def           BLE_CHAR_BATTERY_INFORMATION_UUID
 * @brief         Battery Information.
 */
#define BLE_CHAR_BATTERY_INFORMATION_UUID    (0x2BEC)

/**
 * @def           BLE_CHAR_BATTERY_LEVEL_STATUS_UUID
 * @brief         Battery Level Status.
 */
#define BLE_CHAR_BATTERY_LEVEL_STATUS_UUID   (0x2BED)

/**
 * @def           BLE_CHAR_BATTERY_TIME_STATUS_UUID
 * @brief         Battery Time Status.
 */
#define BLE_CHAR_BATTERY_TIME_STATUS_UUID    (0x2BEE)

/**
 * @def           BLE_CHAR_ESTIMATED_SERVICE_DATE_UUID
 * @brief         Estimated Service Date.
 */
#define BLE_CHAR_ESTIMATED_SERVICE_DATE_UUID (0x2BEF)

/**
 * @def           BLE_CHAR_BATTERY_ENERGY_STATUS_UUID
 * @brief         Battery Energy Status.
 */
#define BLE_CHAR_BATTERY_ENERGY_STATUS_UUID  (0x2BF0)

/**
 * @def           BLE_CHAR_OBSERVATION_SCHEDULE_CHANGED_UUID
 * @brief         Observation Schedule Changed.
 */
#define BLE_CHAR_OBSERVATION_SCHEDULE_CHANGED_UUID \
                                             (0x2BF1)

/**
 * @def           BLE_CHAR_CURRENT_ELAPSED_TIME_UUID
 * @brief         Current Elapsed Time.
 */
#define BLE_CHAR_CURRENT_ELAPSED_TIME_UUID   (0x2BF2)

/**
 * @def           BLE_CHAR_HEALTH_SENSOR_FEATURES_UUID
 * @brief         Health Sensor Features.
 */
#define BLE_CHAR_HEALTH_SENSOR_FEATURES_UUID (0x2BF3)

/**
 * @def           BLE_CHAR_GHS_CONTROL_POINT_UUID
 * @brief         GHS Control Point.
 */
#define BLE_CHAR_GHS_CONTROL_POINT_UUID      (0x2BF4)

/**
 * @def           BLE_CHAR_LE_GATT_SECURITY_LEVELS_UUID
 * @brief         LE GATT Security Levels.
 */
#define BLE_CHAR_LE_GATT_SECURITY_LEVELS_UUID \
                                             (0x2BF5)

/**
 * @def           BLE_CHAR_ESL_ADDRESS_UUID
 * @brief         ESL Address.
 */
#define BLE_CHAR_ESL_ADDRESS_UUID            (0x2BF6)

/**
 * @def           BLE_CHAR_AP_SYNC_KEY_MATERIAL_UUID
 * @brief         AP Sync Key Material.
 */
#define BLE_CHAR_AP_SYNC_KEY_MATERIAL_UUID   (0x2BF7)

/**
 * @def           BLE_CHAR_ESL_RESPONSE_KEY_MATERIAL_UUID
 * @brief         ESL Response Key Material.
 */
#define BLE_CHAR_ESL_RESPONSE_KEY_MATERIAL_UUID \
                                             (0x2BF8)

/**
 * @def           BLE_CHAR_ESL_CURRENT_ABSOLUTE_TIME_UUID
 * @brief         ESL Current Absolute Time.
 */
#define BLE_CHAR_ESL_CURRENT_ABSOLUTE_TIME_UUID \
                                             (0x2BF9)

/**
 * @def           BLE_CHAR_ESL_DISPLAY_INFORMATION_UUID
 * @brief         ESL Display Information.
 */
#define BLE_CHAR_ESL_DISPLAY_INFORMATION_UUID \
                                             (0x2BFA)

/**
 * @def           BLE_CHAR_ESL_IMAGE_INFORMATION_UUID
 * @brief         ESL Image Information.
 */
#define BLE_CHAR_ESL_IMAGE_INFORMATION_UUID  (0x2BFB)

/**
 * @def           BLE_CHAR_ESL_SENSOR_INFORMATION_UUID
 * @brief         ESL Sensor Information.
 */
#define BLE_CHAR_ESL_SENSOR_INFORMATION_UUID (0x2BFC)

/**
 * @def           BLE_CHAR_ESL_LED_INFORMATION_UUID
 * @brief         ESL LED Information.
 */
#define BLE_CHAR_ESL_LED_INFORMATION_UUID    (0x2BFD)

/**
 * @def           BLE_CHAR_ESL_CONTROL_POINT_UUID
 * @brief         ESL Control Point.
 */
#define BLE_CHAR_ESL_CONTROL_POINT_UUID      (0x2BFE)

/**
 * @def           BLE_CHAR_UDI_FOR_MEDICAL_DEVICES_UUID
 * @brief         UDI for Medical Devices.
 */
#define BLE_CHAR_UDI_FOR_MEDICAL_DEVICES_UUID \
                                             (0x2BFF)

/**
 * @def           BLE_CHAR_GMAP_ROLE_UUID
 * @brief         GMAP Role.
 */
#define BLE_CHAR_GMAP_ROLE_UUID              (0x2C00)

/**
 * @def           BLE_CHAR_UGG_FEATURES_UUID
 * @brief         UGG Features.
 */
#define BLE_CHAR_UGG_FEATURES_UUID           (0x2C01)

/**
 * @def           BLE_CHAR_UGT_FEATURES_UUID
 * @brief         UGT Features.
 */
#define BLE_CHAR_UGT_FEATURES_UUID           (0x2C02)

/**
 * @def           BLE_CHAR_BGS_FEATURES_UUID
 * @brief         BGS Features.
 */
#define BLE_CHAR_BGS_FEATURES_UUID           (0x2C03)

/**
 * @def           BLE_CHAR_BGR_FEATURES_UUID
 * @brief         BGR Features.
 */
#define BLE_CHAR_BGR_FEATURES_UUID           (0x2C04)

/**
 * @def           BLE_CHAR_PERCENTAGE_8_STEPS_UUID
 * @brief         Percentage 8 Steps.
 */
#define BLE_CHAR_PERCENTAGE_8_STEPS_UUID     (0x2C05)

/**
 * @def           BLE_CHAR_ACCELERATION_UUID
 * @brief         Acceleration.
 */
#define BLE_CHAR_ACCELERATION_UUID           (0x2C06)

/**
 * @def           BLE_CHAR_FORCE_UUID
 * @brief         Force.
 */
#define BLE_CHAR_FORCE_UUID                  (0x2C07)

/**
 * @def           BLE_CHAR_LINEAR_POSITION_UUID
 * @brief         Linear Position.
 */
#define BLE_CHAR_LINEAR_POSITION_UUID        (0x2C08)

/**
 * @def           BLE_CHAR_ROTATIONAL_SPEED_UUID
 * @brief         Rotational Speed.
 */
#define BLE_CHAR_ROTATIONAL_SPEED_UUID       (0x2C09)

/**
 * @def           BLE_CHAR_LENGTH_UUID
 * @brief         Length.
 */
#define BLE_CHAR_LENGTH_UUID                 (0x2C0A)

/**
 * @def           BLE_CHAR_TORQUE_UUID
 * @brief         Torque.
 */
#define BLE_CHAR_TORQUE_UUID                 (0x2C0B)

/**
 * @def           BLE_CHAR_IMD_STATUS_UUID
 * @brief         IMD Status.
 */
#define BLE_CHAR_IMD_STATUS_UUID             (0x2C0C)

/**
 * @def           BLE_CHAR_IMDS_DESCRIPTOR_VALUE_CHANGED_UUID
 * @brief         IMDS Descriptor Value Changed.
 */
#define BLE_CHAR_IMDS_DESCRIPTOR_VALUE_CHANGED_UUID \
                                             (0x2C0D)

/**
 * @def           BLE_CHAR_FIRST_USE_DATE_UUID
 * @brief         First Use Date.
 */
#define BLE_CHAR_FIRST_USE_DATE_UUID         (0x2C0E)

/**
 * @def           BLE_CHAR_LIFE_CYCLE_DATA_UUID
 * @brief         Life Cycle Data.
 */
#define BLE_CHAR_LIFE_CYCLE_DATA_UUID        (0x2C0F)

/**
 * @def           BLE_CHAR_WORK_CYCLE_DATA_UUID
 * @brief         Work Cycle Data.
 */
#define BLE_CHAR_WORK_CYCLE_DATA_UUID        (0x2C10)

/**
 * @def           BLE_CHAR_SERVICE_CYCLE_DATA_UUID
 * @brief         Service Cycle Data.
 */
#define BLE_CHAR_SERVICE_CYCLE_DATA_UUID     (0x2C11)

/**
 * @def           BLE_CHAR_IMD_CONTROL_UUID
 * @brief         IMD Control.
 */
#define BLE_CHAR_IMD_CONTROL_UUID            (0x2C12)

/**
 * @def           BLE_CHAR_IMD_HISTORICAL_DATA_UUID
 * @brief         IMD Historical Data.
 */
#define BLE_CHAR_IMD_HISTORICAL_DATA_UUID    (0x2C13)

/**
 * @def           BLE_CHAR_RAS_FEATURES_UUID
 * @brief         RAS Features.
 */
#define BLE_CHAR_RAS_FEATURES_UUID           (0x2C14)

/**
 * @def           BLE_CHAR_REAL_TIME_RANGING_DATA_UUID
 * @brief         Real-time Ranging Data.
 */
#define BLE_CHAR_REAL_TIME_RANGING_DATA_UUID (0x2C15)

/**
 * @def           BLE_CHAR_ON_DEMAND_RANGING_DATA_UUID
 * @brief         On-demand Ranging Data.
 */
#define BLE_CHAR_ON_DEMAND_RANGING_DATA_UUID (0x2C16)

/**
 * @def           BLE_CHAR_RAS_CONTROL_POINT_UUID
 * @brief         RAS Control Point.
 */
#define BLE_CHAR_RAS_CONTROL_POINT_UUID      (0x2C17)

/**
 * @def           BLE_CHAR_RANGING_DATA_READY_UUID
 * @brief         Ranging Data Ready.
 */
#define BLE_CHAR_RANGING_DATA_READY_UUID     (0x2C18)

/**
 * @def           BLE_CHAR_RANGING_DATA_OVERWRITTEN_UUID
 * @brief         Ranging Data Overwritten.
 */
#define BLE_CHAR_RANGING_DATA_OVERWRITTEN_UUID \
                                             (0x2C19)

/**
 * @def           BLE_CHAR_COORDINATED_SET_NAME_UUID
 * @brief         Coordinated Set Name.
 */
#define BLE_CHAR_COORDINATED_SET_NAME_UUID   (0x2C1A)

/**
 * @def           BLE_CHAR_HUMIDITY_8_UUID
 * @brief         Humidity 8.
 */
#define BLE_CHAR_HUMIDITY_8_UUID             (0x2C1B)

/**
 * @def           BLE_CHAR_ILLUMINANCE_16_UUID
 * @brief         Illuminance 16.
 */
#define BLE_CHAR_ILLUMINANCE_16_UUID         (0x2C1C)

/**
 * @def           BLE_CHAR_ACCELERATION_3D_UUID
 * @brief         Acceleration - 3D.
 */
#define BLE_CHAR_ACCELERATION_3D_UUID        (0x2C1D)

/**
 * @def           BLE_CHAR_PRECISE_ACCELERATION_3D_UUID
 * @brief         Precise Acceleration - 3D.
 */
#define BLE_CHAR_PRECISE_ACCELERATION_3D_UUID \
                                             (0x2C1E)

/**
 * @def           BLE_CHAR_ACCELERATION_DETECTION_STATUS_UUID
 * @brief         Acceleration Detection Status.
 */
#define BLE_CHAR_ACCELERATION_DETECTION_STATUS_UUID \
                                             (0x2C1F)

/**
 * @def           BLE_CHAR_DOOR_WINDOW_STATUS_UUID
 * @brief         Door/Window Status.
 */
#define BLE_CHAR_DOOR_WINDOW_STATUS_UUID     (0x2C20)

/**
 * @def           BLE_CHAR_PUSHBUTTON_STATUS_8_UUID
 * @brief         Pushbutton Status 8.
 */
#define BLE_CHAR_PUSHBUTTON_STATUS_8_UUID    (0x2C21)

/**
 * @def           BLE_CHAR_CONTACT_STATUS_8_UUID
 * @brief         Contact Status 8.
 */
#define BLE_CHAR_CONTACT_STATUS_8_UUID       (0x2C22)

/**
 * @def           BLE_CHAR_HID_ISO_PROPERTIES_UUID
 * @brief         HID ISO Properties.
 */
#define BLE_CHAR_HID_ISO_PROPERTIES_UUID     (0x2C23)

/**
 * @def           BLE_CHAR_LE_HID_OPERATION_MODE_UUID
 * @brief         LE HID Operation Mode.
 */
#define BLE_CHAR_LE_HID_OPERATION_MODE_UUID  (0x2C24)

/**
 * @def           BLE_CHAR_COOKWARE_DESCRIPTION_UUID
 * @brief         Cookware Description.
 */
#define BLE_CHAR_COOKWARE_DESCRIPTION_UUID   (0x2C25)

/**
 * @def           BLE_CHAR_RECIPE_CONTROL_UUID
 * @brief         Recipe Control.
 */
#define BLE_CHAR_RECIPE_CONTROL_UUID         (0x2C26)

/**
 * @def           BLE_CHAR_RECIPE_PARAMETERS_UUID
 * @brief         Recipe Parameters.
 */
#define BLE_CHAR_RECIPE_PARAMETERS_UUID      (0x2C27)

/**
 * @def           BLE_CHAR_COOKING_STEP_STATUS_UUID
 * @brief         Cooking Step Status.
 */
#define BLE_CHAR_COOKING_STEP_STATUS_UUID    (0x2C28)

/**
 * @def           BLE_CHAR_COOKING_ZONE_CAPABILITIES_UUID
 * @brief         Cooking Zone Capabilities.
 */
#define BLE_CHAR_COOKING_ZONE_CAPABILITIES_UUID \
                                             (0x2C29)

/**
 * @def           BLE_CHAR_COOKING_ZONE_DESIRED_COOKING_CONDITIONS_UUID
 * @brief         Cooking Zone Desired Cooking Conditions.
 */
#define BLE_CHAR_COOKING_ZONE_DESIRED_COOKING_CONDITIONS_UUID \
                                             (0x2C2A)

/**
 * @def           BLE_CHAR_COOKING_ZONE_ACTUAL_COOKING_CONDITIONS_UUID
 * @brief         Cooking Zone Actual Cooking Conditions.
 */
#define BLE_CHAR_COOKING_ZONE_ACTUAL_COOKING_CONDITIONS_UUID \
                                             (0x2C2B)

/**
 * @def           BLE_CHAR_COOKWARE_SENSOR_DATA_UUID
 * @brief         Cookware Sensor Data.
 */
#define BLE_CHAR_COOKWARE_SENSOR_DATA_UUID   (0x2C2C)

/**
 * @def           BLE_CHAR_COOKWARE_SENSOR_AGGREGATE_UUID
 * @brief         Cookware Sensor Aggregate.
 */
#define BLE_CHAR_COOKWARE_SENSOR_AGGREGATE_UUID \
                                             (0x2C2D)

/**
 * @def           BLE_CHAR_COOKING_TEMPERATURE_UUID
 * @brief         Cooking Temperature.
 */
#define BLE_CHAR_COOKING_TEMPERATURE_UUID    (0x2C2E)

/**
 * @def           BLE_CHAR_COOKING_ZONE_PRECEIVED_POWER_UUID
 * @brief         Cooking Zone Perceived Power.
 */
#define BLE_CHAR_COOKING_ZONE_PRECEIVED_POWER_UUID \
                                             (0x2C2F)

/**
 * @def           BLE_CHAR_KITCHEN_APPLIANCE_AIRFLOW_UUID
 * @brief         Kitchen Appliance Airflow.
 */
#define BLE_CHAR_KITCHEN_APPLIANCE_AIRFLOW_UUID \
                                             (0x2C30)

/**
 * @def           BLE_CHAR_VOICE_ASSISTANT_NAME_UUID
 * @brief         Voice Assistant Name.
 */
#define BLE_CHAR_VOICE_ASSISTANT_NAME_UUID   (0x2C31)

/**
 * @def           BLE_CHAR_VOICE_ASSISTANT_UUID_UUID
 * @brief         Voice Assistant UUID.
 */
#define BLE_CHAR_VOICE_ASSISTANT_UUID_UUID   (0x2C32)

/**
 * @def           BLE_CHAR_VOICE_ASSISTANT_SERVICE_CONTROL_POINT_UUID
 * @brief         Voice Assistant Service Control Point.
 */
#define BLE_CHAR_VOICE_ASSISTANT_SERVICE_CONTROL_POINT_UUID \
                                             (0x2C33)

/**
 * @def           BLE_CHAR_INSTALLED_LOCATION_UUID
 * @brief         Installed Location.
 */
#define BLE_CHAR_INSTALLED_LOCATION_UUID     (0x2C34)

/**
 * @def           BLE_CHAR_VOICE_ASSISTANT_SESSION_STATE_UUID
 * @brief         Voice Assistant Session State.
 */
#define BLE_CHAR_VOICE_ASSISTANT_SESSION_STATE_UUID \
                                             (0x2C35)

/**
 * @def           BLE_CHAR_VOICE_ASSISTANT_SESSION_FLAG_UUID
 * @brief         Voice Assistant Session Flag.
 */
#define BLE_CHAR_VOICE_ASSISTANT_SESSION_FLAG_UUID \
                                             (0x2C36)

/**
 * @def           BLE_CHAR_VOICE_ASSISTANT_SUPPORTED_LANGUAGES_UUID
 * @brief         Voice Assistant Supported Languages.
 */
#define BLE_CHAR_VOICE_ASSISTANT_SUPPORTED_LANGUAGES_UUID \
                                             (0x2C37)

/**
 * @def           BLE_CHAR_VOICE_ASSISTANT_SUPPORTED_FEATURES_UUID
 * @brief         Voice Assistant Supported Features.
 */
#define BLE_CHAR_VOICE_ASSISTANT_SUPPORTED_FEATURES_UUID \
                                             (0x2C38)

/******************************************************************************/
/*                                                                            */
/*                                   ENUMS                                    */
/*                                                                            */
/******************************************************************************/
/**
 * @enum          <Enum name>
 * @brief         <Enum details>.
 */

/******************************************************************************/
/*                                                                            */
/*                                 STRUCTURES                                 */
/*                                                                            */
/******************************************************************************/
/**
 * @struct        <Structure name>
 * @brief         <Structure details>.
 */

/******************************************************************************/
/*                                                                            */
/*                                   UNIONS                                   */
/*                                                                            */
/******************************************************************************/
/**
 * @union         <Union name>
 * @brief         <Union details>.
 */

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

#endif //!_PUBLIC_CHARACTERISTIC_UUIDS_H

/**
 * Copyright(c) Bajaj Auto Technology Limited (BATL) as an unpublished work.
 * THIS SOFTWARE AND/OR MATERIAL IS THE PROPERTY OF BATL.
 * ALL USE, DISCLOSURE, AND/OR REPRODUCTION NOT SPECIFICALLY AUTHORIZED BY
 * BATL IS PROHIBITED.
 *
 * @author:Shivam Chudasama [SC]
 */
