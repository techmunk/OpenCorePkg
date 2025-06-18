cd Dockerfiles/oc-dev
docker build . -t ocbuild --target oc-dev-edk2

cd ../../

docker run --volume .:/data -it ocbuild
  cd /data
  ./build_duet.tool
