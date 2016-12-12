#!/usr/bin/python
import sys
import os
import subprocess
import argparse
from time import sleep
from machinekit import launcher

if sys.version_info >= (3, 0):
    import configparser
else:
    import ConfigParser as configparser


parser = argparse.ArgumentParser(description='starts JD Squared configs')
parser.add_argument('config', nargs=1, help='path to config file')

args = parser.parse_args()

configName = args.config[0]

launcher.register_exit_handler()
launcher.set_debug_level(3)
os.chdir(os.path.dirname(os.path.realpath(__file__)))

if not os.path.isfile(configName):
    sys.stderr.write('Config file %s does not exist' % configName)
    exit(1)

try:
    launcher.check_installation()
    launcher.cleanup_session()

    cfg = configparser.ConfigParser({'NAME': ''})
    cfg.read(configName)
    machineName = cfg.get('EMC', 'NAME')

    command = 'configserver'
    if machineName is not '':
        command += ' -n %s' % machineName
    launcher.start_process(command)
    launcher.start_process('linuxcnc ' + configName)
    while True:
        launcher.check_processes()
        sleep(1)
except subprocess.CalledProcessError:
    launcher.end_session()
    exit(1)

exit(0)
