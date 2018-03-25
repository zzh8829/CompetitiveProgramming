#!/usr/bin/env python
#
# This client connects to the centralized game server
# via http. After creating a new game on the game
# server, it spaws an AI subprocess called "dropblox_ai."
# For each turn, this client passes in the current game
# state to a new instance of dropblox_ai, waits ten seconds
# for a response, then kills the AI process and sends
# back the move list.
#

import contextlib
import httplib
import os
import platform
import sys
import threading
import time
import urllib2

import json

from subprocess import Popen, PIPE

from helpers import messaging
from helpers import urllib2_file

# Subprocess
LEFT_CMD = 'left'
RIGHT_CMD = 'right'
UP_CMD = 'up'
DOWN_CMD = 'down'
ROTATE_CMD = 'rotate'
VALID_CMDS = [LEFT_CMD, RIGHT_CMD, UP_CMD, DOWN_CMD, ROTATE_CMD]

MY_DIR = os.path.dirname(os.path.realpath(__file__))
CONFIG_FILE_PATH = os.path.join(MY_DIR, "config.txt")
NUM_HTTP_RETRIES = 2 # number of times to retry if http connection fails

is_windows = platform.system() == "Windows"

# Printing utilities
# TODO(astaley): Consider vetting and using colorama module for windows support

# default to no colors
colorred = '{0}'
colorgrn = colorred

class Command(object):
    def __init__(self, cmd, *args):
        self.cmd = cmd
        self.args = list(args)

    def run(self, timeout):
        cmds = []
        process = Popen([self.cmd] + self.args, stdout=PIPE, universal_newlines=True)
        def target():
            for line in iter(process.stdout.readline, ''):
                line = line.rstrip('\n')
                if line not in VALID_CMDS:
                    print 'INVALID COMMAND:', line # Forward debug output to terminal
                else:
                    cmds.append(line)

        thread = threading.Thread(target=target)
        thread.start()

        thread.join(timeout)
        print colorred.format('Terminating process')
        try:
            process.terminate()
            thread.join(60)
        except Exception:
            pass
        print colorgrn.format('commands received: %s' % cmds)
        return cmds

ai_executable_absolute = "samples/C++/dropblox_ai"

ai_arg_one = """{"preview": [{"type": 17, "center": {"i": 8, "j": 6}, "offsets": [{"i": 0, "j": 0}, {"i": -1, "j": 0}, {"i": 1, "j": 0}, {"i": 0, "j": -1}, {"i": 1, "j": -1}]}, {"type": 14, "center": {"i": 7, "j": 6}, "offsets": [{"i": 0, "j": 0}, {"i": -1, "j": 0}, {"i": 0, "j": 1}, {"i": 1, "j": 0}, {"i": 2, "j": 0}]}, {"type": 22, "center": {"i": 8, "j": 6}, "offsets": [{"i": 0, "j": 0}, {"i": -1, "j": 0}, {"i": 1, "j": 0}, {"i": 0, "j": -1}, {"i": 1, "j": 1}]}, {"type": 2, "center": {"i": 8, "j": 6}, "offsets": [{"i": 0, "j": 0}, {"i": -1, "j": 0}, {"i": 1, "j": 0}]}, {"type": 14, "center": {"i": 7, "j": 6}, "offsets": [{"i": 0, "j": 0}, {"i": -1, "j": 0}, {"i": 0, "j": 1}, {"i": 1, "j": 0}, {"i": 2, "j": 0}]}], "state": "playing", "score": 0, "block": {"type": 17, "center": {"i": 8, "j": 6}, "offsets": [{"i": 0, "j": 0}, {"i": -1, "j": 0}, {"i": 1, "j": 0}, {"i": 0, "j": -1}, {"i": 1, "j": -1}]}, "bitmap": [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]}"""

ai_arg_two = "100"

command = Command(ai_executable_absolute, ai_arg_one, ai_arg_two)
ai_cmds = command.run(timeout=float(ai_arg_two))
print(ai_cmds)
sys.exit(0)
