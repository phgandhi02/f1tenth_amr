#Refer to this for info: https://github.com/microsoft/wslg/blob/main/samples/container/Containers.md
FROM kaspergrontved/px4:v1.14

# ** [Optional] Uncomment this section to install additional packages. **
#
# ENV DEBIAN_FRONTEND=noninteractive
# RUN apt-get update \
#    && apt-get -y install --no-install-recommends <your-package-list-here> \
#    #
#    # Clean up
#    && apt-get autoremove -y \
#    && apt-get clean -y \
#    && rm -rf /var/lib/apt/lists/*
# ENV DEBIAN_FRONTEND=dialog

# Add an environment variable for the workspace
ARG WORKSPACE
RUN echo "if [ -f ${WORKSPACE}/install/setup.bash ]; then source ${WORKSPACE}/install/setup.bash; fi" >> /home/ros/.bashrc
RUN echo "source /home/ros/ws_sensor_combined/install/setup.bash" >> /home/ros/.bashrc

ARG DEBIAN_FRONTEND=noninteractive

RUN apt update && \
   apt install -y x11-apps

RUN apt update && \
    apt install -y mesa-utils

RUN apt update && apt install -y \
vainfo \
mesa-va-drivers

ENV LIBVA_DRIVER_NAME=d3d12
ENV LD_LIBRARY_PATH=/usr/lib/wsl/lib
# CMD vainfo --display drm --device /dev/dri/card0
# CMD /usr/bin/xclock
CMD /bin/bash