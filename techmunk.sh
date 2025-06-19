cd Dockerfiles/oc-dev
docker build . -t ocbuild --target oc-dev-edk2

cd ../../

docker run \
  -t \
  --volume .:/oc \
  --env ARCHS=X64 \
  --env TARGETS=RELEASE \
  --env TOOLCHAINS=CLANGDWARF \
  ocbuild \
  /oc/build_duet.tool
