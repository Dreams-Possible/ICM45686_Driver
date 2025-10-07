#pragma once

//头文件
#include<stdint.h>
// #include"Platform/sp_sys.h"
// #include"Platform/sp_spi.h"

//初始化
uint8_t icm45686_init();
//读温度
uint8_t icm45686_read_temp(int16_t*temp);
//读加速度
uint8_t icm45686_read_accel(int16_t*accel_x,int16_t*accel_y,int16_t*accel_z);
//读陀螺仪
uint8_t icm45686_read_gyro(int16_t*gyro_x,int16_t*gyro_y,int16_t*gyro_z);
//配置加速度计
uint8_t icm45686_conf_accel(uint8_t conf);
//配置陀螺仪
uint8_t icm45686_conf_gyro(uint8_t conf);

//加速度计配置：
// BIT NAME FUNCTION 
// 7 - Reserved 
// 6:4 ACCEL_UI_FS_SEL 
// Full scale select for accelerometer UI interface output 
// 000: ±32g (default) 
// 001: ±16g 
// 010: ±8g 
// 011: ±4g 
// 100: ±2g 
// 101: Reserved 
// 110: Reserved 
// 111: Reserved 
// 3:0 ACCEL_ODR 
// Accelerometer ODR selection for UI interface output 
// 0000: Reserved 
// 0001: Reserved 
// 0010: Reserved 
// 0011: 6.4kHz (LN mode) 
// 0100: 3.2kHz (LN mode) 
// 0101: 1.6kHz (LN mode) 
// 0110: 800Hz (LN mode) (default) 
// 0111: 400Hz (LP or LN mode) 
// 1000: 200Hz (LP or LN mode) 
// 1001: 100Hz (LP or LN mode) 
// 1010: 50Hz (LP or LN mode) 
// 1011: 25Hz (LP or LN mode) 
// 1100: 12.5Hz (LP or LN mode) 
// 1101: 6.25Hz (LP mode) 
// 1110: 3.125Hz (LP mode) 
// 1111: 1.5625Hz (LP mode) 
// ACCEL_UI_FS_SEL 
// Full scale select for accelerometer UI interface output 
// 000: ±32g 
// 001: ±16g 
// 010: ±8g 
// 011: ±4g 
// 100: ±2g 
// 101: Reserved 
// 110: Reserved 
// 111: Reserved 
// Sensitivity Scale Factor 
// ACCEL_UI_FS_SEL = 0; ACCEL_AUX1_FS_SEL = 0  1,024  LSB/g 3 
// ACCEL_UI_FS_SEL = 1; ACCEL_AUX1_FS_SEL = 1  2,048  LSB/g 3 
// ACCEL_UI_FS_SEL = 2; ACCEL_AUX1_FS_SEL = 2  4,096  LSB/g 3 
// ACCEL_UI_FS_SEL = 3; ACCEL_AUX1_FS_SEL = 3  8,192  LSB/g 3 
// ACCEL_UI_FS_SEL = 4; ACCEL_AUX1_FS_SEL = 4  16,384  LSB/g 3 

//陀螺仪配置：
// BIT NAME FUNCTION 
// 7:4 GYRO_UI_FS_SEL 
// Full scale select for gyroscope UI interface output 
// 0000: ±4000dps (default) 
// 0001: ±2000dps 
// 0010: ±1000dps 
// 0011: ±500dps 
// 0100: ±250dps 
// 0101: ±125dps 
// 0110: ±62.5dps 
// 0111: ±31.25dps 
// 1000: ±15.625dps 
// Rest of the settings are reserved 
// 3:0 GYRO_ODR 
// Gyroscope ODR selection for UI interface output 
// 0000: Reserved 
// 0001: Reserved 
// 0010: Reserved 
// 0011: 6.4kHz (LN mode) 
// 0100: 3.2kHz (LN mode) 
// 0101: 1.6kHz (LN mode) 
// 0110: 800Hz (LN mode) (default) 
// 0111: 400Hz (LP or LN mode) 
// 1000: 200Hz (LP or LN mode) 
// 1001: 100Hz (LP or LN mode) 
// 1010: 50Hz (LP or LN mode) 
// 1011: 25Hz (LP or LN mode) 
// 1100: 12.5Hz (LP or LN mode) 
// 1101: 6.25Hz (LP mode) 
// 1110: 3.125Hz (LP mode) 
// 1111: 1.5625Hz (LP mode) 
// GYRO_UI_FS_SEL 
// Full scale select for gyroscope UI interface output 
// 0000: ±4000dps 
// 0001: ±2000dps 
// 0010: ±1000dps 
// 0011: ±500dps 
// 0100: ±250dps 
// 0101: ±125dps 
// 0110: ±62.5dps 
// 0111: ±31.25dps 
// 1000: ±15.625dps 
// Rest of the settings are reserved 
// Sensitivity Scale Factor 
// GYRO_UI_FS_SEL =0; GYRO_AUX1_FS_SEL =0  8.2  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =1; GYRO_AUX1_FS_SEL =1  16.4  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =2; GYRO_AUX1_FS_SEL =2  32.8  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =3; GYRO_AUX1_FS_SEL =3  65.5  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =4; GYRO_AUX1_FS_SEL =4  131  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =5; GYRO_AUX1_FS_SEL =5  262  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =6; GYRO_AUX1_FS_SEL =6  524.3  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =7; GYRO_AUX1_FS_SEL =7  1048.6  LSB/(º/s) 3 
// GYRO_UI_FS_SEL =8; GYRO_AUX1_FS_SEL =8  2097.2  LSB/(º/s) 3 
