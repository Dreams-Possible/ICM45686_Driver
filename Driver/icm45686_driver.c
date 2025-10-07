#include"icm45686_driver.h"

//ID寄存器
#define WHO_AM_I 0x72
//配置寄存器
#define REG_MISC2 0x7f
//电源寄存器
#define PWR_MGMT0 0x10
//温度寄存器起始
#define TEMP_DATA1_UI 0x0c
//加速度寄存器起始
#define ACCEL_DATA_X1_UI 0x00
//陀螺仪寄存器起始
#define GYRO_DATA_X1_UI 0x06
//加速度计配置寄存器
#define ACCEL_CONFIG0 0x1b
//陀螺仪配置寄存器
#define GYRO_CONFIG0 0x1c

//SPI发送
static uint8_t spi_tx(uint8_t*data,uint16_t len);
//SPI接收
static uint8_t spi_rx(uint8_t*data,uint16_t len);
//SPI片选
static uint8_t spi_start(uint8_t st);
//延时
static void delay(uint16_t ms);
//初始化传感器
static uint8_t icm_init();
//读传感器
static uint8_t icm_read(uint8_t reg,uint8_t*data,uint16_t len);
//写传感器
static uint8_t icm_write(uint8_t reg,uint8_t*data,uint16_t len);
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

//SPI发送
static uint8_t spi_tx(uint8_t*data,uint16_t len)
{
    // sp_spi1_tx(data,len);
    return 0;
}
//SPI接收
static uint8_t spi_rx(uint8_t*data,uint16_t len)
{
    // sp_spi1_rx(data,len);
    return 0;
}
//SPI片选
static uint8_t spi_start(uint8_t st)
{
    // sp_spi1_ns(!st);
    return 0;
}
//延时
static void delay(uint16_t ms)
{
    // osDelay(ms);
}
//读传感器
static uint8_t icm_read(uint8_t reg,uint8_t*data,uint16_t len)
{
    uint8_t tx=reg|0x80;
    spi_start(1);
    if(spi_tx(&tx,1))
    {
        spi_start(0);
        return 1;
    }
    if(spi_rx(data,len))
    {
        spi_start(0);
        return 2;
    }
    spi_start(0);
    return 0;
}
//写传感器
static uint8_t icm_write(uint8_t reg,uint8_t*data,uint16_t len)
{
    uint8_t tx=reg&0x7f;
    spi_start(1);
    if(spi_tx(&tx,1))
    {
        spi_start(0);
        return 1;
    }
    if(spi_tx(data,len))
    {
        spi_start(0);
        return 2;
    }
    spi_start(0);
    return 0;
}
//初始化传感器
static uint8_t icm_init()
{
    uint8_t data=0;
    //读取ID
    if(icm_read(WHO_AM_I,&data,1))
    {
        return 1;
    }
    //检查ID
    if(data!=0xe9)
    {
        return 2;
    }
    data=0x02;
    //软复位
    if(icm_write(REG_MISC2,&data,1))
    {
        return 3;
    }
    //等待复位
    delay(1);
    //启动电源
    data=0x0f;
    if(icm_write(PWR_MGMT0,&data,1))
    {
        return 4;
    }
    return 0;
}
//初始化
uint8_t icm45686_init()
{
    return icm_init();
}
//读温度
uint8_t icm45686_read_temp(int16_t*temp)
{
    uint8_t buf[2];
    if(icm_read(TEMP_DATA1_UI,buf,2))
    {
        return 2;
    }
    if(temp)
    {
        // *temp=(int16_t)(buf[0]<<8|buf[1]);
        *temp=(int16_t)(buf[1]<<8|buf[0]);
    }
    return 0;
}
//读加速度
uint8_t icm45686_read_accel(int16_t*accel_x,int16_t*accel_y,int16_t*accel_z)
{
    uint8_t buf[6];
    if(icm_read(ACCEL_DATA_X1_UI,buf,6))
    {
        return 1;
    }
    if(accel_x)
    {
        // *accel_x=(int16_t)(buf[0]<<8|buf[1]);
        *accel_x=(int16_t)(buf[1]<<8|buf[0]);
    }
    if(accel_x)
    {
        // *accel_y=(int16_t)(buf[2]<<8|buf[3]);
        *accel_y=(int16_t)(buf[3]<<8|buf[2]);
    }
    if(accel_z)
    {
        // *accel_z=(int16_t)(buf[4]<<8|buf[5]);
        *accel_z=(int16_t)(buf[5]<<8|buf[4]);
    }
    return 0;
}
//读陀螺仪
uint8_t icm45686_read_gyro(int16_t*gyro_x,int16_t*gyro_y,int16_t*gyro_z)
{
    uint8_t buf[6];
    if(icm_read(GYRO_DATA_X1_UI,buf,6))
    {
        return 2;
    }
    if(gyro_x)
    {
        // *gyro_x=(int16_t)(buf[0]<<8|buf[1]);
        *gyro_x=(int16_t)(buf[1]<<8|buf[0]);
    }
    if(gyro_y)
    {
        // *gyro_y=(int16_t)(buf[2]<<8|buf[3]);
        *gyro_y=(int16_t)(buf[3]<<8|buf[2]);
    }
    if(gyro_z)
    {
        // *gyro_z=(int16_t)(buf[4]<<8|buf[5]);
        *gyro_z=(int16_t)(buf[5]<<8|buf[4]);
    }
    return 0;
}
//配置加速度计
uint8_t icm45686_conf_accel(uint8_t conf)
{
    uint8_t data=conf;
    if(icm_write(ACCEL_CONFIG0,&data,1))
    {
        return 1;
    }
    return 0;
}
//配置陀螺仪
uint8_t icm45686_conf_gyro(uint8_t conf)
{
    uint8_t data=conf;
    if(icm_write(GYRO_CONFIG0,&data,1))
    {
        return 1;
    }
    return 0;
}
