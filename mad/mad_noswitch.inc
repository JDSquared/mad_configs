[HOSTMOT2]
DRIVER=hm2_soc_ol
BOARD=jdcb
DEVNAME=hm2-socfpga0
CONFIG="firmware=zynq/dtbo/zturn_jd2cb_r2_7z010_ol.dtbo num_encoders=0 num_pwmgens=0 num_stepgens=5"

[EMCIO]
EMCIO = io
CYCLE_TIME=0.1
TOOL_TABLE = tool.tbl

[TASK]
TASK = milltask
CYCLE_TIME = 0.010

[RS274NGC]
FEATURES=12
PARAMETER_FILE = mad.var
SUBROUTINE_PATH = ~/jd2/mad/nc_files/
REMAP=G11 modalgroup=1 argspec=Pxyza ngc=safe_go
REMAP=G15 modalgroup=1 argspec=Zp ngc=probe_z
REMAP=M100 modalgroup=10 ngc=el_probe_on
REMAP=M101 modalgroup=10 ngc=el_probe_off
REMAP=M103 modalgroup=10 ngc=torch_on
REMAP=M104 modalgroup=10 argspec=P ngc=torch_voltage
REMAP=M105 modalgroup=10 argspec=p ngc=torch_off
REMAP=M106 modalgroup=10 argspec=P ngc=attoffset
REMAP=M130 modalgroup=10 ngc=thc_on
REMAP=M131 modalgroup=10 ngc=thc_off
REMAP=M150 modalgroup=10 argspec=Pq ngc=auxout_on
REMAP=M151 modalgroup=10 argspec=Pq ngc=auxout_off
ON_ABORT_COMMAND=o<on_abort> call

[EMCMOT]
EMCMOT = motmod
COMM_TIMEOUT = 1.0
COMM_WAIT = 0.010
SERVO_PERIOD = 1000000
NUM_DIO = 14

[HAL]
HALFILE = mad_noswitch.hal

[TRAJ]
ARC_BLEND_ENABLE = 1
ARC_BLEND_FALLBACK_ENABLE = 0
ARC_BLEND_OPTIMIZATION_DEPTH = 50
ARC_BLEND_GAP_CYCLES = 4
ARC_BLEND_RAMP_FREQ = 20

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
STEP_SCALE = 6400.0

MAX_LIMIT = 0.001
MIN_LIMIT = -3.625
