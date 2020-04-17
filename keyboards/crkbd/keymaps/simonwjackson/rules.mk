COMBO_ENABLE = yes 				#  408b
# BLUETOOTH = AdafruitBLE		# 4748b
# RGBLIGHT_ENABLE = yes			# 3780b
MOUSEKEY_ENABLE = yes			# 2614b
# OLED_DRIVER_ENABLE = yes	# 1582b
# UNICODEMAP_ENABLE = yes		# 1228b (with mappings), 4b per key
UNICODE_ENABLE = yes
TAP_DANCE_ENABLE = yes		# 1208b (with mappings), 700b + 508b mappings
EXTRAKEY_ENABLE = yes			#  450b, media keys
# LEADER_ENABLE = yes 			#  200b
# NKRO_ENABLE = no
BACKLIGHT_ENABLE = no 
COMMAND_ENABLE = no 
CONSOLE_ENABLE = no
EXTRAFLAGS += -flto 

# If you want to change the display of OLED, you need to change here
# SRC +=  ./lib/glcdfont.c \
#         ./lib/rgb_state_reader.c \
#         ./lib/layer_state_reader.c \
#         ./lib/logo_reader.c \
#         ./lib/keylogger.c \
#         # ./lib/mode_icon_reader.c \
#         # ./lib/host_led_state_reader.c \
#         # ./lib/timelogger.c \
