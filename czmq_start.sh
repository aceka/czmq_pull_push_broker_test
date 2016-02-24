#!/bin/bash
gnome-terminal -e "bash -ic \"./device; exec bash\"" &
gnome-terminal -e "bash -ic \"./server; exec bash\"" &
gnome-terminal -e "bash -ic \"./client1; exec bash\"" &
gnome-terminal -e "bash -ic \"./client2; exec bash\"" &
gnome-terminal -e "bash -ic \"./client3; exec bash\"" &
gnome-terminal -e "bash -ic \"./client4; exec bash\""
