[HOSTMOT2]
DRIVER=hm2_soc_ol
BOARD=jdcb
DEVNAME=hm2-socfpga0
CONFIG="firmware=zynq/dtbo/zturn_jd2cb_7z010_ol.dtbo num_encoders=0 num_pwmgens=0 num_stepgens=5"

[EMCIO]
EMCIO = io
CYCLE_TIME=0.1
TOOL_TABLE = tool.tbl

[TASK]
TASK = milltask
CYCLE_TIME = 0.010

[RS274NGC]
PARAMETER_FILE = mad.var
SUBROUTINE_PATH = ~/jd2/mad/nc_files/
REMAP=G11 modalgroup=1 argspec=Pxyza ngc=safe_go

[EMCMOT]
EMCMOT = motmod
COMM_TIMEOUT = 1.0
COMM_WAIT = 0.010
SERVO_PERIOD = 1000000

[HAL]
HALFILE = mad_noswitch.hal

[TRAJ]
AXES = 3
COORDINATES = X Y Z
LINEAR_UNITS = in
ANGULAR_UNITS = deg
CYCLE_TIME = 0.010
DEFAULT_VELOCITY = 3.50
MAX_LINEAR_VELOCITY = 19.166666667
MAX_VELOCITY = 19.166666667

#********************
# Axis Z
#********************
[AXIS_2]
TYPE = LINEAR
FERROR = 0.015
MIN_FERROR = 0.015
MAX_VELOCITY = 5.0
MAX_ACCELERATION = 300.0
# The values below should be 25% larger than MAX_VELOCITY and MAX_ACCELERATION
# If using BACKLASH compensation STEPGEN_MAXACCEL should be 100% larger.
STEPGEN_MAXVEL = 6.875
STEPGEN_MAXACCEL = 375.0

# these are in nanoseconds
DIRSETUP   = 750
DIRHOLD    = 1500
STEPLEN    = 1500
STEPSPACE  = 1500
STEP_SCALE = 6773.3333

MAX_LIMIT = 0.001
MIN_LIMIT = -3.625