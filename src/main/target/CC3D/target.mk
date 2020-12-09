F1_TARGETS  += $(TARGET)
FEATURES    = ONBOARDFLASH HIGHEND VCP

TARGET_SRC = \
            drivers/accgyro_mpu.c \
            drivers/accgyro_spi_mpu6000.c \
            drivers/barometer_bmp085.c \
            drivers/barometer_bmp280.c \
            drivers/barometer_ms5611.c \
            drivers/compass_hmc5883l.c

