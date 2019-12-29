# MCU = atmega32u4
# F_CPU = 8000000
# BLUETOOTH_ENABLE = no
# BLUETOOTH = AdafruitBLE

# TAP_DANCE_ENABLE = yes		# 1208b (with mappings), 700b + 508b mappings
MOUSEKEY_ENABLE = yes			# 2614b

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
