# Workflow Steps:

### Pre-requisites:
1. WSL2 is installed. 
1. Docker Desktop is installed.
1. VS Code is installed.
1. Repository is downloaded and the folder is open in VS Code.

### Steps:
1. Use keyboard shortcut: (Ctrl + Shift + P) in order to open the command pallete. Then type "WSL: Connect to WSL".
1. Once the window has finished loading then use keyboard shortcut: (Ctrl + Shift + P) in order to open the command pallete. Then type "Dev Containers: Reopen in container".
1. Allow container to be built. This may take some time so be patient.
1. Open the terminal using the keyboard shortcut (Ctrl + `). The host name should be ros@... 
1. Enter the following command in the terminal: "source /opt/ros/humble/setup.bash"
1. Enter the following command in the terminal: "rviz2". Rviz2 should open up as a new window on the computer.


