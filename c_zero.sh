#!/bin/bash
gnome-terminal -e "bash -ic \"./d1; exec bash\"" &
gnome-terminal -e "bash -ic \"./s1; exec bash\"" &
gnome-terminal -e "bash -ic \"./c1; exec bash\"" &
gnome-terminal -e "bash -ic \"./c2; exec bash\"" &
gnome-terminal -e "bash -ic \"./c3; exec bash\"" &
gnome-terminal -e "bash -ic \"./c4; exec bash\""
