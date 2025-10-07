#pragma once

//头文件
#include<stdint.h>
// #include"Platform/sp_sys.h"
// #include"Platform/sp_spi.h"

//初始化
uint8_t icm42688_init();
//读温度
uint8_t icm42688_read_temp(int16_t*temp);
//读加速度
uint8_t icm42688_read_accel(int16_t*accel_x,int16_t*accel_y,int16_t*accel_z);
//读陀螺仪
uint8_t icm42688_read_gyro(int16_t*gyro_x,int16_t*gyro_y,int16_t*gyro_z);
//配置加速度计
uint8_t icm42688_conf_accel(uint8_t conf);
//配置陀螺仪
uint8_t icm42688_conf_gyro(uint8_t conf);

//加速度计配置：
// BIT NAME FUNCTION 
// 7:5 ACCEL_FS_SEL 
// Full scale select for accelerometer UI interface output 
// 000: ±16g (default) 
// 001: ±8g 
// 010: ±4g 
// 011: ±2g 
// 100: Reserved 
// 101: Reserved 
// 110: Reserved 
// 111: Reserved 
// 4 - Reserved 
// 3:0 ACCEL_ODR 
// Accelerometer ODR selection for UI interface output 
// 0000: Reserved 
// 0001: 32kHz (LN mode) 
// 0010: 16kHz (LN mode) 
// 0011: 8kHz (LN mode) 
// 0100: 4kHz (LN mode) 
// 0101: 2kHz (LN mode) 
// 0110: 1kHz (LN mode) (default) 
// 0111: 200Hz (LP or LN mode)  
// 1000: 100Hz (LP or LN mode) 
// 1001: 50Hz (LP or LN mode) 
// 1010: 25Hz (LP or LN mode) 
// 1011: 12.5Hz (LP or LN mode) 
// 1100: 6.25Hz (LP mode) 
// 1101: 3.125Hz (LP mode) 
// 1110: 1.5625Hz (LP mode) 
// 1111: 500Hz (LP or LN mode) 
// ACCEL_FS_SEL 
// Full scale select for accelerometer UI interface output 
// 000: ±16g (default) 
// 001: ±8g 
// 010: ±4g 
// 011: ±2g 
// 100: Reserved 
// 101: Reserved 
// 110: Reserved 
// 111: Reserved 
// Sensitivity Scale Factor 
// ACCEL_FS_SEL =0  2,048  LSB/g 2 
// ACCEL_FS_SEL =1  4,096  LSB/g 2 
// ACCEL_FS_SEL =2  8,192  LSB/g 2 
// ACCEL_FS_SEL =3  16,384  LSB/g 2 

//陀螺仪配置：
// BIT NAME FUNCTION 
// 7:5 GYRO_FS_SEL 
// Full scale select for gyroscope UI interface output 
// 000: ±2000dps (default) 
// 001: ±1000dps 
// 010: ±500dps 
// 011: ±250dps 
// 100: ±125dps 
// 101: ±62.5dps 
// 110: ±31.25dps 
// 111: ±15.625dps 
// 4 - Reserved 
// 3:0 GYRO_ODR 
// Gyroscope ODR selection for UI interface output 
// 0000: Reserved 
// 0001: 32kHz 
// 0010: 16kHz 
// 0011: 8kHz 
// 0100: 4kHz 
// 0101: 2kHz 
// 0110: 1kHz (default) 
// 0111: 200Hz  
// 1000: 100Hz 
// 1001: 50Hz 
// 1010: 25Hz 
// 1011: 12.5Hz 
// 1100: Reserved 
// 1101: Reserved 
// 1110: Reserved 
// 1111: 500Hz 
// GYRO_FS_SEL 
// Full scale select for gyroscope UI interface output 
// 000: ±2000dps (default) 
// 001: ±1000dps 
// 010: ±500dps 
// 011: ±250dps 
// 100: ±125dps 
// 101: ±62.5dps 
// 110: ±31.25dps 
// 111: ±15.625dps 
// Sensitivity Scale Factor 
// GYRO_FS_SEL=0  16.4  LSB/(º/s) 2 
// GYRO_FS_SEL =1  32.8  LSB/(º/s) 2 
// GYRO_FS_SEL =2  65.5  LSB/(º/s) 2 
// GYRO_FS_SEL =3  131  LSB/(º/s) 2 
// GYRO_FS_SEL =4  262  LSB/(º/s) 2 
// GYRO_FS_SEL =5  524.3  LSB/(º/s) 2 
// GYRO_FS_SEL =6  1048.6  LSB/(º/s) 2 
// GYRO_FS_SEL =7  2097.2  LSB/(º/s) 2 
