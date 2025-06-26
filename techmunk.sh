#!/bin/bash

docker build Dockerfiles/oc-dev -t ocbuild --target oc-dev-edk2

mkdir -p build
rm -rf build/*

# Remove UDK for a clean build
#sudo rm -rf UDK

docker run \
  -t \
  --volume .:/oc \
  --volume ./build:/build \
  --env ARCHS=X64 \
  --env TARGETS=RELEASE \
  --env TOOLCHAINS=CLANGDWARF \
  ocbuild \
    bash -c "
      # Make boot0 and boot1 files
      DESTDIR=/build make -C /oc/Legacy/BootLoader

      # Build boot program
      bash /oc/build_duet.tool
      cp /oc/UDK/Build/OpenDuetPkg/RELEASE_CLANGDWARF/X64/boot* /build
    "

