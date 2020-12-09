F405_TARGETS    += $(TARGET)
FEATURES        += SDCARD VCP

TARGET_SRC = \
            drivers/accgyro_mpu6500.c \
            drivers/accgyro_spi_mpu6500.c \
            drivers/barometer_bmp280.c \
            drivers/barometer_ms5611.c \
            drivers/compass_ak8963.c \
            drivers/compass_hmc5883l.c

